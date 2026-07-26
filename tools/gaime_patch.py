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
import mmap
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


def wordsum(mm, offset, length):
    """Sum of the region's little-endian 32-bit words, mod 2^32."""
    total = 0
    end = offset + (length // 4) * 4
    for pos in range(offset, end, 1 << 22):
        blk = mm[pos:min(pos + (1 << 22), end)]
        total += sum(struct.unpack(f"<{len(blk) // 4}I", blk))
    return total & 0xFFFFFFFF


def find_all(mm, needle, start, length):
    """Every offset of needle within [start, start+length)."""
    hits, end = [], start + length
    i = mm.find(needle, start, end)
    while i != -1:
        hits.append(i)
        i = mm.find(needle, i + 1, end)
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

        mm = mmap.mmap(fh.fileno(), 0)
        try:
            before = wordsum(mm, sup["offset"], sup["length"])
            stored = struct.unpack_from("<I", mm, vsup["offset"])[0]
            print(f"Vsuper before: 0x{before:08x} (stored 0x{stored:08x})")
            if stored != before:
                sys.exit("Vsuper mismatch — image already altered?")

            applied = {}
            for old, new, expect in PATCHES:
                hits = find_all(mm, old, sup["offset"], sup["length"])
                if expect is not None and len(hits) != expect:
                    sys.exit(f"{old!r}: expected {expect} occurrence(s), found {len(hits)}")
                if not hits:
                    sys.exit(f"{old!r}: not found")
                for off in hits:
                    mm[off:off + len(new)] = new
                applied[old] = hits
                print(f"  {old.decode():18s} -> {new.decode():18s} at "
                      f"{', '.join(hex(h) for h in hits)}")

            # Anchor on the offset we just patched. Re-searching for "ro.debuggable=1"
            # would instead hit `on property:ro.debuggable=1` inside an init .rc file.
            anchor = applied[b"ro.debuggable=0"][0]
            spot = find_all(mm, COMMENT, anchor, 4096)
            if not spot:
                sys.exit("no 36-byte '####' comment line within 4 KiB after ro.debuggable")
            mm[spot[0]:spot[0] + len(ADB_PROP)] = ADB_PROP
            print(f"  {'add adb prop':18s} -> {'persist.sys.usb.config=adb':18s} at {hex(spot[0])}")

            after = wordsum(mm, sup["offset"], sup["length"])
            struct.pack_into("<I", mm, vsup["offset"], after)
            print(f"Vsuper after:  0x{after:08x}  (written at {vsup['offset']})")
            mm.flush()
        finally:
            mm.close()

    print(f"\npatched: {target}")


if __name__ == "__main__":
    main()
