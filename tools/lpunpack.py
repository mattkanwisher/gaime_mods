#!/usr/bin/env python3
"""Extract logical partitions from an Android `super` image (LP metadata v1.x)."""

import argparse
import struct
from pathlib import Path

GEOMETRY_MAGIC = 0x616C4467
HEADER_MAGIC = 0x414C5030
RESERVED = 4096
GEOMETRY_SIZE = 4096
SECTOR = 512
TARGET_LINEAR, TARGET_ZERO = 0, 1


def read_metadata(f):
    f.seek(RESERVED)
    magic, struct_size = struct.unpack("<II", f.read(8))
    if magic != GEOMETRY_MAGIC:
        raise SystemExit("no LP geometry — is this a raw super image?")
    f.seek(RESERVED + 40)
    _max_size, _slots, logical_block_size = struct.unpack("<IIQ", f.read(16))

    meta_start = RESERVED + GEOMETRY_SIZE * 2
    f.seek(meta_start)
    head = f.read(256)
    if struct.unpack_from("<I", head, 0)[0] != HEADER_MAGIC:
        raise SystemExit("no LP metadata header")
    major, minor = struct.unpack_from("<HH", head, 4)
    header_size = struct.unpack_from("<I", head, 8)[0]

    def descriptor(off):
        return struct.unpack_from("<III", head, off)  # offset, num_entries, entry_size

    p_off, p_num, p_sz = descriptor(80)
    e_off, e_num, e_sz = descriptor(92)

    tables = meta_start + header_size
    partitions = []
    for i in range(p_num):
        f.seek(tables + p_off + i * p_sz)
        raw = f.read(p_sz)
        name = raw[:36].split(b"\0", 1)[0].decode()
        attributes, first_extent, num_extents, _group = struct.unpack_from("<IIII", raw, 36)
        partitions.append((name, attributes, first_extent, num_extents))

    extents = []
    for i in range(e_num):
        f.seek(tables + e_off + i * e_sz)
        raw = f.read(e_sz)
        num_sectors, target_type, target_data, _src = struct.unpack_from("<QIQI", raw)
        extents.append((num_sectors, target_type, target_data))

    return (major, minor, logical_block_size), partitions, extents


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("super_img", type=Path)
    ap.add_argument("-o", "--outdir", type=Path, help="extract partitions here")
    args = ap.parse_args()

    with args.super_img.open("rb") as f:
        (major, minor, lbs), partitions, extents = read_metadata(f)
        print(f"LP metadata v{major}.{minor}, logical_block_size={lbs}, "
              f"{len(partitions)} partitions, {len(extents)} extents\n")

        if args.outdir:
            args.outdir.mkdir(parents=True, exist_ok=True)

        for name, attributes, first, count in partitions:
            size = sum(extents[first + i][0] for i in range(count)) * SECTOR
            print(f"  {name:24s} {size:12d} bytes  attrs=0x{attributes:x}  extents={count}")
            if not args.outdir:
                continue
            with (args.outdir / f"{name}.img").open("wb") as out:
                for i in range(count):
                    num_sectors, ttype, target_data = extents[first + i]
                    length = num_sectors * SECTOR
                    if ttype == TARGET_ZERO:
                        out.seek(length, 1)
                        continue
                    if ttype != TARGET_LINEAR:
                        raise SystemExit(f"{name}: unsupported extent type {ttype}")
                    f.seek(target_data * SECTOR)
                    while length:
                        block = f.read(min(1 << 22, length))
                        if not block:
                            break
                        out.write(block)
                        length -= len(block)
                out.truncate(size)

    if args.outdir:
        print(f"\nextracted -> {args.outdir}")


if __name__ == "__main__":
    main()
