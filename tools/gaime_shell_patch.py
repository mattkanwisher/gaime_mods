#!/usr/bin/env python3
"""Plan a minimal in-place patch of the console's `super` partition to enable ADB.

Works against a dump of the device's own super partition, so it patches the
firmware actually installed rather than a downloaded image.

Why these specific edits. adbd already ships (stock com.android.adbd APEX), but:

  * every `start adbd` trigger in init.usb.rc / init.usb.configfs.rc requires
    sys.usb.configfs to be 0 or 1, and the vendor HAL sets it to 2, so none of
    them can ever fire;
  * nothing in this build sets sys.usb.controller, so even once a trigger fires
    the gadget would never bind to the UDC (there is no ro.boot.usbcontroller
    mapping either, so build.prop is the only place to set it);
  * ro.debuggable=1 on its own is NOT enough — this build's SettingsProvider
    never seeds adb_enabled in loadGlobalSettings, so the framework path stays
    off no matter what the property says.

Every edit preserves byte length, so no filesystem or image structure changes:
build.prop and the vendor .rc both happen to be stored uncompressed in EROFS.
Properties are added by overwriting 36-byte '####' comment lines with a real
property plus a shorter comment, which keeps every offset identical.

Emits a sector-level plan plus the original bytes for every touched sector, so
the change can be reverted exactly.
"""

import argparse
import json
import mmap
import sys
from pathlib import Path

SECTOR = 512

REPLACEMENTS = [
    (b"ro.secure=1", b"ro.secure=0", 1),
    (b"ro.adb.secure=1", b"ro.adb.secure=0", None),      # None = all occurrences
    (b"ro.debuggable=0", b"ro.debuggable=1", 1),
    (b"setprop sys.usb.configfs 2", b"setprop sys.usb.configfs 1", 1),
]

COMMENT = b"#" * 36
INSERTS = [
    b"persist.sys.usb.config=adb\n" + b"#" * 9,           # 27 + 9  = 36
    b"sys.usb.controller=sunxi_usb_udc\n" + b"#" * 3,     # 33 + 3  = 36
]


def find_all(mm, needle, start=0, end=None):
    hits, i = [], mm.find(needle, start, end if end is not None else len(mm))
    while i != -1:
        hits.append(i)
        i = mm.find(needle, i + 1, end if end is not None else len(mm))
    return hits


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("super_img", type=Path, help="dump of the device's super partition")
    ap.add_argument("outdir", type=Path)
    ap.add_argument("--super-lba", type=int, default=631808,
                    help="super's first LBA from the device GPT")
    ap.add_argument("--fes-offset", type=int, default=40960,
                    help="GPT LBA minus FES logical address")
    args = ap.parse_args()

    args.outdir.mkdir(parents=True, exist_ok=True)
    data = bytearray(args.super_img.read_bytes())
    mm = memoryview(data)
    orig = bytes(data)

    edits = []
    with args.super_img.open("rb") as fh:
        m = mmap.mmap(fh.fileno(), 0, access=mmap.ACCESS_READ)
        for old, new, expect in REPLACEMENTS:
            hits = find_all(m, old)
            if expect is not None and len(hits) != expect:
                sys.exit(f"{old!r}: expected {expect} hit(s), found {len(hits)}")
            if not hits:
                sys.exit(f"{old!r}: not found")
            for off in hits:
                data[off:off + len(new)] = new
                edits.append((off, old.decode(), new.decode()))

        anchor = find_all(m, b"ro.debuggable=0")[0]
        spots = find_all(m, COMMENT, anchor, anchor + 4096)
        if len(spots) < len(INSERTS):
            sys.exit(f"need {len(INSERTS)} comment lines after ro.debuggable, "
                     f"found {len(spots)}")
        for spot, ins in zip(spots, INSERTS):
            assert len(ins) == len(COMMENT)
            data[spot:spot + len(ins)] = ins
            edits.append((spot, "#" * 36, ins.decode().replace("\n", "\\n")))
        m.close()

    print("edits:")
    for off, a, b in edits:
        print(f"  0x{off:09x}  {a:38s} -> {b}")

    changed = sorted({off // SECTOR for off, _, _ in edits}
                     | {(off + 35) // SECTOR for off, _, _ in edits})
    fes_base = args.super_lba - args.fes_offset
    plan = {"super_lba": args.super_lba, "fes_offset": args.fes_offset,
            "fes_base": fes_base, "sectors": []}

    (args.outdir / "original").mkdir(exist_ok=True)
    (args.outdir / "patched").mkdir(exist_ok=True)
    for s in changed:
        o = orig[s * SECTOR:(s + 1) * SECTOR]
        p = bytes(data[s * SECTOR:(s + 1) * SECTOR])
        if o == p:
            continue
        (args.outdir / "original" / f"{s}.bin").write_bytes(o)
        (args.outdir / "patched" / f"{s}.bin").write_bytes(p)
        plan["sectors"].append({"super_sector": s, "fes_sector": fes_base + s,
                                "diff_bytes": sum(x != y for x, y in zip(o, p))})

    (args.outdir / "plan.json").write_text(json.dumps(plan, indent=2))
    print(f"\n{len(plan['sectors'])} sector(s) to write "
          f"({len(plan['sectors']) * SECTOR} bytes):")
    for s in plan["sectors"]:
        print(f"  super sector {s['super_sector']:>9d} -> FES sector "
              f"{s['fes_sector']:>9d}  ({s['diff_bytes']} bytes differ)")
    print(f"\nplan written to {args.outdir}")


if __name__ == "__main__":
    main()
