#!/usr/bin/env python3
"""Patch a decrypted G'AIM'E firmware image to enable ADB.

Every edit is byte-length preserving, so nothing about the image layout changes:
no filesystem rebuild, no re-sparsing, no IMAGEWTY re-layout. That matters because
rebuilding the system EROFS off-device would lose SELinux labels and ownership and
produce an unbootable image.

Edits, all inside /system/build.prop which EROFS happens to store uncompressed:

    ro.secure=1        -> ro.secure=0
    ro.adb.secure=1    -> ro.adb.secure=0      (every occurrence)
    ro.debuggable=0    -> ro.debuggable=1
    a 36-byte '####' comment line immediately after the property block becomes
    'persist.sys.usb.config=adb\\n#########' — same 36 bytes, adds the property
    that actually makes the gadget HAL bring up adb.

Then Vsuper.fex is recomputed. The V*.fex members are a 32-bit little-endian sum of
the partition's 32-bit words; the flasher checks them, so a stale one fails the write.
"""

import argparse
import shutil
import struct
import sys
from pathlib import Path

ITEM_SIZE = 0x400
COMMENT = b"#" * 36
ADB_PROP = b"persist.sys.usb.config=adb\n" + b"#" * 9   # exactly 36 bytes

PATCHES = [
    (b"ro.secure=1", b"ro.secure=0", 1),
    (b"ro.adb.secure=1", b"ro.adb.secure=0", None),   # None = all occurrences
    (b"ro.debuggable=0", b"ro.debuggable=1", 1),
]


def items(fh):
    fh.seek(0)
    head = fh.read(0x400)
    if head[:8] != b"IMAGEWTY":
        sys.exit("not an IMAGEWTY image — decrypt the .dat first with gaime_decrypt.py")
    num = struct.unpack_from("<I", head, 0x3C)[0]
    hdr_size = struct.unpack_from("<I", head, 0x20)[0]
    out = {}
    fh.seek(hdr_size)
    for _ in range(num):
        it = fh.read(ITEM_SIZE)
        name = it[0x24:0x124].split(b"\0")[0].decode()
        out[name] = {
            "length": struct.unpack_from("<I", it, 0x12C)[0],
            "offset": struct.unpack_from("<I", it, 0x134)[0],
        }
    return out


def wordsum(fh, offset, length):
    fh.seek(offset)
    total, remaining = 0, length
    while remaining:
        blk = fh.read(min(1 << 22, remaining))
        if not blk:
            break
        remaining -= len(blk)
        n = len(blk) // 4 * 4
        total = (total + sum(struct.unpack(f"<{n // 4}I", blk[:n]))) & 0xFFFFFFFF
    return total


def find_all(fh, needle, start, length):
    """Offsets of needle within [start, start+length), streamed."""
    hits, pos, overlap = [], start, len(needle) - 1
    end = start + length
    while pos < end:
        fh.seek(pos)
        blk = fh.read(min(1 << 24, end - pos))
        if not blk:
            break
        i = blk.find(needle)
        while i != -1:
            hits.append(pos + i)
            i = blk.find(needle, i + 1)
        pos += len(blk) - overlap
    return hits


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("image", type=Path, help="decrypted .img (modified in place unless -o)")
    ap.add_argument("-o", "--output", type=Path, help="write to a copy instead")
    args = ap.parse_args()

    target = args.image
    if args.output:
        print(f"copying {args.image} -> {args.output}")
        shutil.copyfile(args.image, args.output)
        target = args.output

    with target.open("r+b") as fh:
        table = items(fh)
        for need in ("super.fex", "Vsuper.fex"):
            if need not in table:
                sys.exit(f"image has no {need}")
        sup, vsup = table["super.fex"], table["Vsuper.fex"]
        print(f"super.fex  offset={sup['offset']} length={sup['length']}")

        before = wordsum(fh, sup["offset"], sup["length"])
        print(f"Vsuper before: 0x{before:08x}")
        fh.seek(vsup["offset"])
        stored = struct.unpack("<I", fh.read(4))[0]
        if stored != before:
            sys.exit(f"Vsuper mismatch (stored 0x{stored:08x}) — image already altered?")

        for old, new, expect in PATCHES:
            hits = find_all(fh, old, sup["offset"], sup["length"])
            if expect is not None and len(hits) != expect:
                sys.exit(f"{old!r}: expected {expect} occurrence(s), found {len(hits)}")
            if not hits:
                sys.exit(f"{old!r}: not found")
            for off in hits:
                fh.seek(off)
                fh.write(new)
            print(f"  {old.decode():18s} -> {new.decode():18s} at "
                  f"{', '.join(hex(h) for h in hits)}")

        # Anchor the property insert on the (now unique) patched ro.debuggable line so we
        # can only ever land inside this build.prop.
        anchor = find_all(fh, b"ro.debuggable=1", sup["offset"], sup["length"])[0]
        window = 4096
        spot = find_all(fh, COMMENT, anchor, window)
        if not spot:
            sys.exit("no 36-byte '####' comment line within 4 KiB after ro.debuggable")
        fh.seek(spot[0])
        fh.write(ADB_PROP)
        print(f"  {'insert adb prop':18s} -> {'persist.sys.usb.config=adb':18s} at {hex(spot[0])}")

        after = wordsum(fh, sup["offset"], sup["length"])
        fh.seek(vsup["offset"])
        fh.write(struct.pack("<I", after))
        print(f"Vsuper after:  0x{after:08x}  (written to offset {vsup['offset']})")

    print(f"\npatched: {target}")


if __name__ == "__main__":
    main()
