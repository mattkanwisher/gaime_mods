#!/usr/bin/env python3
"""Capture a UART boot log without dropping bytes.

The shell version (uart_capture.sh) loses characters on the gun: whole runs go
missing mid-word, which reads like a baud error but is not — the text either
side is perfect. It opens the port twice (`exec 3<>` plus `stty -f`) and hands
the stream to `cat`, and something in that arrangement drops data on macOS.

This does what uart_shell.py already does reliably for the console: open the
port exactly once, configure termios on that same descriptor, and read it in a
tight loop, flushing to disk as it goes. One fd, one reader, no shell.

    uart_capture.py <baud> <outfile> [seconds]

Nothing is transmitted, so this is safe on a board whose logic level is not yet
known — wire only GND and the board's TX.
"""

import fcntl
import os
import struct
import sys
import termios
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from uart_shell import find_port, open_port                 # noqa: E402

# macOS termios only defines constants up to B230400 — there is no B460800 or
# B921600, so the table has to be built by lookup rather than written out.
# Anything missing goes through IOSSIOSPEED below.
STD_BAUDS = {b: getattr(termios, f"B{b}")
             for b in (9600, 19200, 38400, 57600, 115200, 230400)
             if hasattr(termios, f"B{b}")}

# _IOW('T', 2, speed_t) with speed_t = unsigned long (8 bytes). This is how you
# get a non-standard rate on macOS; it must be applied *after* tcsetattr, which
# would otherwise clobber it.
IOSSIOSPEED = 0x80085402


def set_baud(fd: int, baud: int) -> None:
    a = termios.tcgetattr(fd)
    a[4] = a[5] = STD_BAUDS.get(baud, termios.B9600)
    termios.tcsetattr(fd, termios.TCSANOW, a)
    if baud not in STD_BAUDS:
        try:
            fcntl.ioctl(fd, IOSSIOSPEED, struct.pack("L", baud))
        except OSError as e:
            sys.exit(f"adapter refused {baud} baud ({e}). A plain CP2102 tops "
                     f"out at 1 Mbaud; above that needs a CP2102N/FT232H/CH343.")
    termios.tcflush(fd, termios.TCIOFLUSH)


def main() -> None:
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    baud, out = int(sys.argv[1]), sys.argv[2]
    secs = float(sys.argv[3]) if len(sys.argv) > 3 else 300.0

    port = find_port()
    fd = open_port(port)
    set_baud(fd, baud)
    print(f"[{port} @ {baud}] -> {out}  ({secs:.0f}s, Ctrl-C to stop early)",
          file=sys.stderr)

    total, quiet, end = 0, 0.0, time.time() + secs
    try:
        with open(out, "wb", buffering=0) as f:
            while time.time() < end:
                try:
                    chunk = os.read(fd, 65536)
                except BlockingIOError:
                    chunk = b""
                except OSError:
                    break
                if chunk:
                    f.write(chunk)
                    total += len(chunk)
                    quiet = 0.0
                    print(f"\r  {total} bytes", end="", file=sys.stderr, flush=True)
                else:
                    # Poll fast enough that the tty buffer never backs up; a
                    # sleep here is what costs you characters during a burst.
                    time.sleep(0.0005)
                    quiet += 0.0005
    except KeyboardInterrupt:
        pass
    finally:
        os.close(fd)

    print(f"\n  {total} bytes captured", file=sys.stderr)


if __name__ == "__main__":
    main()
