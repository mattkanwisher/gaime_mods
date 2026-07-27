#!/usr/bin/env python3
"""Push a file to the console over the J2 serial console, no adb required.

The console has no network and its adb only exists over USB (and dies on every
reboot until `setprop service.adb.root 0` is re-applied). The serial console is
the one transport that is always there, so this makes it usable for getting a
file across — an APK, a script, whatever.

Payload is base64'd and appended in small chunks with `printf`, because the
console shell is a plain line-oriented tty with no flow control: writing fast
enough to overrun the receiver silently corrupts the stream. Every transfer is
verified with md5 on both ends and the tool exits non-zero on a mismatch, so a
corrupt push can never be mistaken for a good one.

    uart_push.py <local-file> <remote-path>

Throughput is roughly 4-5 KB/s of payload. Fine for an APK, not for an image.
"""

import base64
import hashlib
import os
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from uart_shell import find_port, open_port, drain          # noqa: E402

CHUNK = 256          # base64 chars per printf line
PACE = 0.06          # seconds between lines


def cmd(fd: int, line: str, settle: float = 0.25) -> bytes:
    os.write(fd, line.encode() + b"\r\n")
    time.sleep(settle)
    return drain(fd, settle)


def main() -> None:
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    local, remote = sys.argv[1], sys.argv[2]

    data = open(local, "rb").read()
    want = hashlib.md5(data).hexdigest()
    b64 = base64.b64encode(data).decode()
    lines = [b64[i:i + CHUNK] for i in range(0, len(b64), CHUNK)]

    print(f"{local} -> {remote}")
    print(f"  {len(data)} bytes, md5 {want}, {len(lines)} chunks")

    fd = open_port(find_port())
    try:
        # Stage in the same directory as the destination — the Android console
        # has /data/local/tmp but the gun's busybox rootfs only has /tmp, so a
        # fixed staging path silently produces an empty file on the wrong box.
        stage = os.path.dirname(remote.rstrip("/")) + "/.push.b64"
        cmd(fd, f"rm -f {stage} {remote}")

        started = time.time()
        for i, chunk in enumerate(lines):
            os.write(fd, f"printf %s '{chunk}' >> {stage}\r\n".encode())
            time.sleep(PACE)
            drain(fd, 0.01)                     # keep the echo from backing up
            if i % 20 == 0 or i == len(lines) - 1:
                pct = 100 * (i + 1) // len(lines)
                print(f"\r  {pct:3d}%  ({i + 1}/{len(lines)})", end="", flush=True)
        print(f"   {time.time() - started:.1f}s")

        cmd(fd, f"base64 -d {stage} > {remote}", settle=1.5)
        cmd(fd, f"rm -f {stage}", settle=0.5)

        # Decoding a few MB takes a while and the reply can arrive well after the
        # first drain returns, so poll for the digest instead of assuming a fixed
        # settle. Without this a perfectly good transfer reports as a mismatch.
        got, text = None, ""
        for _ in range(10):
            text += cmd(fd, f"md5sum {remote}", settle=1.0).decode("utf-8", "replace")
            got = next((tok for tok in text.split() if len(tok) == 32
                        and all(c in "0123456789abcdef" for c in tok)), None)
            if got:
                break
    finally:
        os.close(fd)

    if got == want:
        print(f"  md5 OK  {got}")
    else:
        print(f"  MD5 MISMATCH — want {want}, device reported {got}")
        print(text.strip()[-300:])
        sys.exit(1)


if __name__ == "__main__":
    main()
