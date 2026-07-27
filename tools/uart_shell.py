#!/usr/bin/env python3
"""Two-way serial console for the G'AIM'E board (header J2, 115200 8N1).

No pyserial dependency — configures the port with termios directly, which also
sidesteps the macOS quirk where settings on /dev/cu.* revert as soon as the last
file descriptor closes (stty in one process, read in another, silently falls
back to 9600). Here one fd does both.

Requires the TX wire: adapter TXD -> J2 RX. Receive-only wiring still works for
`listen`, but `send`/`run` will appear to do nothing.

    uart_shell.py listen [seconds]
    uart_shell.py send "text"          # sends text + newline, prints the reply
    uart_shell.py run  "cmd" [...]     # several commands in sequence
    uart_shell.py probe                # is anything there, and does TX work?
"""

import os
import sys
import termios
import time
import glob

BAUD = termios.B115200


def find_port() -> str:
    for pat in ("/dev/cu.usbserial*", "/dev/cu.SLAB*", "/dev/cu.wchusbserial*",
                "/dev/cu.usbmodem*"):
        hits = sorted(glob.glob(pat))
        if hits:
            return hits[0]
    sys.exit("no USB serial adapter found")


def open_port(path: str) -> int:
    fd = os.open(path, os.O_RDWR | os.O_NOCTTY | os.O_NONBLOCK)
    attrs = termios.tcgetattr(fd)
    iflag, oflag, cflag, lflag, ispeed, ospeed, cc = attrs
    # 8N1, no flow control, receiver on, ignore modem lines
    cflag = termios.CS8 | termios.CREAD | termios.CLOCAL
    iflag = 0                      # no translation, no XON/XOFF
    oflag = 0                      # no output post-processing
    lflag = 0                      # raw: no echo, no canonical mode
    cc = list(cc)
    cc[termios.VMIN] = 0
    cc[termios.VTIME] = 0
    termios.tcsetattr(fd, termios.TCSANOW,
                      [iflag, oflag, cflag, lflag, BAUD, BAUD, cc])
    termios.tcflush(fd, termios.TCIOFLUSH)
    return fd


def drain(fd: int, seconds: float) -> bytes:
    out, end = bytearray(), time.time() + seconds
    while time.time() < end:
        try:
            chunk = os.read(fd, 4096)
        except BlockingIOError:
            chunk = b""
        except OSError:
            break
        if chunk:
            out += chunk
        else:
            time.sleep(0.02)
    return bytes(out)


def show(data: bytes):
    sys.stdout.write(data.decode("utf-8", "replace"))
    sys.stdout.flush()


def main() -> None:
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    action = sys.argv[1]
    port = find_port()
    fd = open_port(port)
    print(f"[{port} @ 115200]", file=sys.stderr)
    try:
        if action == "listen":
            secs = float(sys.argv[2]) if len(sys.argv) > 2 else 10
            show(drain(fd, secs))

        elif action == "probe":
            print("[quiet listen 2s]", file=sys.stderr)
            before = drain(fd, 2)
            show(before)
            print(f"\n[sending newline — needs adapter TXD -> J2 RX]", file=sys.stderr)
            os.write(fd, b"\r\n")
            after = drain(fd, 2)
            show(after)
            if not before and not after:
                print("\n[nothing at all: board idle/off, or board TX not wired to "
                      "adapter RXD]", file=sys.stderr)
            elif not after:
                print("\n[no reply to newline: TX wire missing, or no console on "
                      "this port]", file=sys.stderr)
            else:
                print("\n[got a reply — two-way link is up]", file=sys.stderr)

        elif action in ("send", "run"):
            for cmd in sys.argv[2:]:
                os.write(fd, cmd.encode() + b"\r\n")
                time.sleep(0.15)
                show(drain(fd, 2.5))
        else:
            sys.exit(__doc__)
    finally:
        os.close(fd)


if __name__ == "__main__":
    main()
