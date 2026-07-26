#!/usr/bin/env python3
"""Plan a diagnostic patch that gives us a feedback channel without a shell.

The vendor USB gadget .rc is stored uncompressed in EROFS and we have already
patched it twice successfully. init's `copy` builtin runs in init's own context,
can read /proc, and can write to a block device — so redirecting one line of
that .rc dumps a kernel-side file into an unused partition, which we then read
back over FES.

Target partition is `empty`: 15 MiB, no downloadfile in sys_partition.fex, not
referenced by the fstab, and not in the updater's write set. `/dev/block/by-name`
is used rather than an mmcblk path because the block-device number is not known
(the factory log mentions "card 2").

The line being replaced is the PTP functionfs mount. PTP is not used by this
console, and the gadget HAL only needs that mount if something asks it to
compose PTP. Everything else in the `on boot` block, including the adb
functionfs mount, is left untouched.

First question it answers: does sunxi_usb_udc.ko actually load? That is a real
unknown — the driver is a vendor_boot ramdisk module, not built into the kernel,
and if it never binds then the port can never be a USB device no matter what the
properties say.
"""

import json
import mmap
import sys
from pathlib import Path

SECTOR = 512
SUPER_LBA = 631808
FES_OFFSET = 40960

OLD = (b"    mount functionfs ptp /dev/usb-ffs/ptp "
       b"rmode=0770,fmode=0660,uid=1024,gid=1024,no_disconnect=1")
CMD = b"    copy /proc/modules /dev/block/by-name/empty"


def main() -> None:
    src = Path(sys.argv[1] if len(sys.argv) > 1 else "work/super_current.img")
    out = Path(sys.argv[2] if len(sys.argv) > 2 else "work/diagpatch")
    out.mkdir(parents=True, exist_ok=True)
    (out / "original").mkdir(exist_ok=True)
    (out / "patched").mkdir(exist_ok=True)

    pad = len(OLD) - len(CMD) - 1
    if pad < 0:
        sys.exit("replacement command is longer than the line it replaces")
    new = CMD + b"\n" + b"#" * pad
    assert len(new) == len(OLD)

    print(f"replacing {len(OLD)}-byte line:")
    print(f"  old: {OLD.decode()!r}")
    print(f"  new: {new.decode()!r}")

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
        sys.exit(f"expected exactly 1 occurrence, found {len(hits)} — refusing")
    off = hits[0]
    data[off:off + len(new)] = new
    print(f"\npatch offset 0x{off:09x}")

    plan = {"super_lba": SUPER_LBA, "fes_offset": FES_OFFSET,
            "fes_base": SUPER_LBA - FES_OFFSET, "sectors": []}
    for s in sorted({off // SECTOR, (off + len(new) - 1) // SECTOR}):
        o = orig[s * SECTOR:(s + 1) * SECTOR]
        p = bytes(data[s * SECTOR:(s + 1) * SECTOR])
        if o == p:
            continue
        (out / "original" / f"{s}.bin").write_bytes(o)
        (out / "patched" / f"{s}.bin").write_bytes(p)
        plan["sectors"].append({"super_sector": s,
                                "fes_sector": SUPER_LBA - FES_OFFSET + s,
                                "diff_bytes": sum(x != y for x, y in zip(o, p))})

    (out / "plan.json").write_text(json.dumps(plan, indent=2))
    print(f"\n{len(plan['sectors'])} sector(s) to write:")
    for s in plan["sectors"]:
        print(f"  super {s['super_sector']} -> FES {s['fes_sector']} "
              f"({s['diff_bytes']} bytes differ)")


if __name__ == "__main__":
    main()
