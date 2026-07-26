#!/usr/bin/env python3
"""Convert an Android sparse image to a raw image."""

import argparse
import struct
import sys
from pathlib import Path

SPARSE_MAGIC = 0xED26FF3A
RAW, FILL, DONT_CARE, CRC32 = 0xCAC1, 0xCAC2, 0xCAC3, 0xCAC4


def convert(src: Path, dst: Path) -> None:
    with src.open("rb") as f, dst.open("wb") as out:
        hdr = f.read(28)
        (magic, _major, _minor, file_hdr_sz, chunk_hdr_sz,
         blk_sz, total_blks, total_chunks, _csum) = struct.unpack("<IHHHHIIII", hdr)
        if magic != SPARSE_MAGIC:
            raise SystemExit(f"{src}: not an Android sparse image")
        f.seek(file_hdr_sz)

        for i in range(total_chunks):
            ctype, _res, chunk_blks, total_sz = struct.unpack("<HHII", f.read(chunk_hdr_sz))
            body = total_sz - chunk_hdr_sz
            if ctype == RAW:
                remaining = chunk_blks * blk_sz
                while remaining:
                    block = f.read(min(1 << 22, remaining))
                    out.write(block)
                    remaining -= len(block)
            elif ctype == FILL:
                out.write(f.read(4) * (chunk_blks * blk_sz // 4))
            elif ctype == DONT_CARE:
                out.seek(chunk_blks * blk_sz, 1)
            elif ctype == CRC32:
                f.read(body)
            else:
                raise SystemExit(f"unknown chunk type {ctype:#x} at chunk {i}")
        out.truncate(total_blks * blk_sz)
    print(f"{src.name} -> {dst} ({total_blks * blk_sz} bytes)", file=sys.stderr)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("src", type=Path)
    ap.add_argument("dst", type=Path)
    convert(*vars(ap.parse_args()).values())


if __name__ == "__main__":
    main()
