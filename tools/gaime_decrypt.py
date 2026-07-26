#!/usr/bin/env python3
"""Decrypt G'AIM'E GAIMEENC firmware containers into raw Allwinner .img files.

Container layout (from GAIMEUpdater.FirmwareDecryptor, v4.0.3):

    magic       8   "GAIMEENC"
    version     1   must be 1
    chunk_max   4   int32 LE, 0x00400000 (4 MiB)
    nonce      12   base GCM nonce
    repeated until EOF:
        length  4   int32 LE, 0 < length <= chunk_max
        data    length
        tag    16   AES-GCM tag

Per-chunk nonce is the base nonce with the int32 LE at bytes 8..12 XORed
with the zero-based chunk index. No additional authenticated data.
"""

import argparse
import struct
import sys
from pathlib import Path

from cryptography.hazmat.primitives.ciphers.aead import AESGCM

MAGIC = b"GAIMEENC"
KEY = bytes.fromhex("2C4B5B4D84F9A5E0E4D4C2F78B6A1D9E0A0B1C2D3E4F5061728394A5B6C7D8E9")


def chunk_nonce(base: bytes, index: int) -> bytes:
    counter = struct.unpack_from("<I", base, 8)[0] ^ (index & 0xFFFFFFFF)
    return base[:8] + struct.pack("<I", counter)


def decrypt(src: Path, dst: Path) -> None:
    aes = AESGCM(KEY)
    total = src.stat().st_size

    with src.open("rb") as fin, dst.open("wb") as fout:
        if fin.read(8) != MAGIC:
            raise SystemExit(f"{src.name}: bad magic, not a GAIMEENC container")

        version = fin.read(1)[0]
        if version != 1:
            raise SystemExit(f"{src.name}: unsupported container version {version}")

        chunk_max = struct.unpack("<i", fin.read(4))[0]
        base = fin.read(12)

        index = 0
        while True:
            raw = fin.read(4)
            if not raw:
                break
            length = struct.unpack("<i", raw)[0]
            if not 0 < length <= chunk_max:
                raise SystemExit(f"{src.name}: invalid chunk length {length} at chunk {index}")

            body = fin.read(length + 16)
            if len(body) != length + 16:
                raise SystemExit(f"{src.name}: truncated at chunk {index}")

            fout.write(aes.decrypt(chunk_nonce(base, index), body, None))
            index += 1

            if index % 32 == 0:
                pct = 100.0 * fin.tell() / total
                print(f"\r  {src.name}: {pct:5.1f}%  chunk {index}", end="", file=sys.stderr)

    print(f"\r  {src.name}: done, {index} chunks -> {dst}", file=sys.stderr)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("inputs", nargs="+", type=Path, help="*.dat / *.enc containers")
    ap.add_argument("-o", "--outdir", type=Path, default=Path("."), help="output directory")
    args = ap.parse_args()

    args.outdir.mkdir(parents=True, exist_ok=True)
    for src in args.inputs:
        decrypt(src, args.outdir / (src.stem + ".img"))


if __name__ == "__main__":
    main()
