#!/usr/bin/env python3
"""Plan the one-byte revert of ro.secure=0 back to 1.

Why: with ro.secure clear, adbd's should_drop_privileges() returns false, so it
tries to stay root and calls selinux_android_setcon(u:r:su:s0). A `user` build's
policy has no such transition, the kernel denies setcurrent, and adbd LOG(FATAL)s
in a five-second loop. Confirmed on the device via logcat over the serial console.

So the patch meant to loosen security is exactly what stopped adb working, and
reverting it is the permanent fix. ro.debuggable stays 1 so that
`service console /system/bin/sh` — the serial shell — keeps running.

Planned against a reconstruction of the device's current flash state (pristine
dump plus every patch already applied), so gaime_fes_write.py's
must-match-recorded-content check still means something.
"""

import json
import mmap
import shutil
import sys
from pathlib import Path

SECTOR = 512
SUPER_LBA = 631808
FES_OFFSET = 40960

ROOT = Path(__file__).resolve().parent.parent
PRISTINE = ROOT / "backup/device/super.img"
CURRENT = ROOT / "work/super_current_all.img"
APPLIED = ["work/shellpatch", "work/shellpatch2", "work/shellpatch3"]

OLD = b"ro.secure=0"
NEW = b"ro.secure=1"


def build_current() -> Path:
    """Pristine dump + every patch already written to the device."""
    if not CURRENT.exists():
        print(f"reconstructing device state -> {CURRENT.name}")
        shutil.copyfile(PRISTINE, CURRENT)
        with CURRENT.open("r+b") as fh:
            for d in APPLIED:
                plan = json.loads((ROOT / d / "plan.json").read_text())
                for s in plan["sectors"]:
                    blob = (ROOT / d / "patched" / f'{s["super_sector"]}.bin').read_bytes()
                    fh.seek(s["super_sector"] * SECTOR)
                    fh.write(blob)
                print(f"  applied {d} ({len(plan['sectors'])} sectors)")
    return CURRENT


def main() -> None:
    src = build_current()
    out = ROOT / "work/rosecure"
    out.mkdir(parents=True, exist_ok=True)
    (out / "original").mkdir(exist_ok=True)
    (out / "patched").mkdir(exist_ok=True)

    data = bytearray(src.read_bytes())
    orig = bytes(data)

    with src.open("rb") as fh:
        m = mmap.mmap(fh.fileno(), 0, access=mmap.ACCESS_READ)
        hits, i = [], m.find(OLD)
        while i != -1:
            hits.append(i)
            i = m.find(OLD, i + 1)
        m.close()

    if len(hits) != 1:
        sys.exit(f"expected exactly one {OLD!r}, found {len(hits)} — refusing")
    off = hits[0]
    data[off:off + len(NEW)] = NEW
    print(f"\n  0x{off:09x}  {OLD.decode()} -> {NEW.decode()}")

    plan = {"super_lba": SUPER_LBA, "fes_offset": FES_OFFSET,
            "fes_base": SUPER_LBA - FES_OFFSET, "sectors": []}
    s = off // SECTOR
    o = orig[s * SECTOR:(s + 1) * SECTOR]
    p = bytes(data[s * SECTOR:(s + 1) * SECTOR])
    (out / "original" / f"{s}.bin").write_bytes(o)
    (out / "patched" / f"{s}.bin").write_bytes(p)
    plan["sectors"].append({"super_sector": s, "fes_sector": SUPER_LBA - FES_OFFSET + s,
                            "diff_bytes": sum(x != y for x, y in zip(o, p))})
    (out / "plan.json").write_text(json.dumps(plan, indent=2))

    print(f"\n1 sector: super {s} -> FES {SUPER_LBA - FES_OFFSET + s} "
          f"({plan['sectors'][0]['diff_bytes']} byte differs)")
    print(f"plan -> {out}")


if __name__ == "__main__":
    main()
