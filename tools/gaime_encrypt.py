#!/usr/bin/env python3
"""Re-wrap a raw Allwinner .img back into a GAIMEENC container.

Inverse of gaime_decrypt.py — see that file for the container layout. The nonce is
taken from the source container when one is given with --like, so a rebuilt package
is byte-comparable against the original everywhere except the payload; otherwise a
random one is generated (GCM requires a unique nonce per key, so never reuse one
across differing plaintexts).
"""

import argparse
import os
import struct
import sys
from pathlib import Path

from cryptography.hazmat.primitives.ciphers.aead import AESGCM

MAGIC = b"GAIMEENC"
KEY = bytes.fromhex("2C4B5B4D84F9A5E0E4D4C2F78B6A1D9E0A0B1C2D3E4F5061728394A5B6C7D8E9")
CHUNK = 0x00400000


def chunk_nonce(base: bytes, index: int) -> bytes:
    counter = struct.unpack_from("<I", base, 8)[0] ^ (index & 0xFFFFFFFF)
    return base[:8] + struct.pack("<I", counter)


def encrypt(src: Path, dst: Path, nonce: bytes, chunk_size: int) -> None:
    aes = AESGCM(KEY)
    total = src.stat().st_size

    with src.open("rb") as fin, dst.open("wb") as fout:
        fout.write(MAGIC)
        fout.write(bytes([1]))
        fout.write(struct.pack("<i", chunk_size))
        fout.write(nonce)

        index = 0
        while True:
            plain = fin.read(chunk_size)
            if not plain:
                break
            blob = aes.encrypt(chunk_nonce(nonce, index), plain, None)  # ct || tag
            fout.write(struct.pack("<i", len(plain)))
            fout.write(blob)
            index += 1
            if index % 32 == 0:
                print(f"\r  {dst.name}: {100.0 * fin.tell() / total:5.1f}%  chunk {index}",
                      end="", file=sys.stderr)
    print(f"\r  {dst.name}: done, {index} chunks", file=sys.stderr)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("image", type=Path, help="raw .img to wrap")
    ap.add_argument("output", type=Path, help="destination .dat")
    ap.add_argument("--like", type=Path,
                    help="reuse the nonce and chunk size from this existing container")
    args = ap.parse_args()

    nonce, chunk_size = os.urandom(12), CHUNK
    if args.like:
        with args.like.open("rb") as f:
            if f.read(8) != MAGIC:
                sys.exit(f"{args.like}: not a GAIMEENC container")
            version = f.read(1)[0]
            if version != 1:
                sys.exit(f"{args.like}: unsupported version {version}")
            chunk_size = struct.unpack("<i", f.read(4))[0]
            nonce = f.read(12)
        print(f"reusing nonce {nonce.hex()} and chunk size {chunk_size} from {args.like.name}")

    encrypt(args.image, args.output, nonce, chunk_size)


if __name__ == "__main__":
    main()
