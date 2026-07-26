#!/usr/bin/env python3
"""Write specific sectors back to the console over FES, then verify by reading.

This is the one tool in the repo that writes to the device. It is deliberately
narrow:

  * the only write opcode it knows is FES_DOWNLOAD (0x206);
  * FES_FORCE_ERASE (0x220) and FES_FORCE_ERASE_KEY (0x221) are not defined here
    at all, so it cannot issue them;
  * the erase (0x7F04) and mbr (0x7F01) tags are never constructed — the mbr tag
    triggers an erase on the device, so it is explicitly refused below;
  * it only writes whole 512-byte sectors named in a plan produced by
    gaime_shell_patch.py, and refuses any payload that is not sector-sized;
  * every sector is read back and compared after writing, and the run aborts on
    the first mismatch.

Usage:
    gaime_fes_write.py apply  work/shellpatch      # write the patched sectors
    gaime_fes_write.py revert work/shellpatch      # restore the originals
    gaime_fes_write.py verify work/shellpatch      # read back, report state
"""

import argparse
import importlib.util
import json
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
_spec = importlib.util.spec_from_file_location("gaime_fes", HERE / "gaime_fes.py")
gfes = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(gfes)

SECTOR = 512
FES_DOWNLOAD = 0x206          # the only write opcode in this file
TAG_FINISH = 0x10000
FORBIDDEN_TAGS = {0x7F01: "mbr (triggers erase)", 0x7F04: "erase"}


def write_sector(fes, fes_sector: int, data: bytes):
    if len(data) != SECTOR:
        raise ValueError(f"refusing to write {len(data)} bytes; sectors only")
    flags = TAG_FINISH
    for bad, why in FORBIDDEN_TAGS.items():
        if flags & bad == bad:
            raise ValueError(f"refusing: flags would set {why}")
    fes._send(struct.pack("<HHIII", FES_DOWNLOAD, 0, fes_sector, len(data), flags))
    fes._send(data)
    fes._status()


def read_sector(fes, fes_sector: int) -> bytes:
    fes.cmd(gfes.FES_UPLOAD, address=fes_sector, length=SECTOR, flags=gfes.TAG_NONE)
    d = fes._recv(SECTOR)
    fes._status()
    return d


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("action", choices=("apply", "revert", "verify"))
    ap.add_argument("plandir", type=Path)
    ap.add_argument("--yes", action="store_true", help="skip the confirmation prompt")
    args = ap.parse_args()

    plan = json.loads((args.plandir / "plan.json").read_text())
    src = "patched" if args.action == "apply" else "original"
    sectors = plan["sectors"]

    print(f"plan: {len(sectors)} sector(s), {len(sectors) * SECTOR} bytes")
    for s in sectors:
        print(f"  FES sector {s['fes_sector']:>9d}  ({s['diff_bytes']} bytes differ)")

    usb = gfes.Usb()
    fes = gfes.Fes(usb)
    try:
        dev = fes.verify_device()
        if dev["mode"] != 2:
            sys.exit("device is not in FES mode — run tools/enter_fes.sh first")
        print(f'device: {dev["magic"]} mode=FES')
        fes.flash_set(True)

        if args.action == "verify":
            for s in sectors:
                cur = read_sector(fes, s["fes_sector"])
                o = (args.plandir / "original" / f'{s["super_sector"]}.bin').read_bytes()
                p = (args.plandir / "patched" / f'{s["super_sector"]}.bin').read_bytes()
                state = ("ORIGINAL" if cur == o else
                         "PATCHED" if cur == p else "UNKNOWN")
                print(f'  FES {s["fes_sector"]:>9d}: {state}')
            return

        if not args.yes:
            print(f"\nAbout to WRITE {len(sectors)} sector(s) to flash ({args.action}).")
            if input("Type 'write' to proceed: ").strip() != "write":
                sys.exit("aborted")

        for s in sectors:
            want = (args.plandir / src / f'{s["super_sector"]}.bin').read_bytes()
            other = (args.plandir / ("original" if src == "patched" else "patched")
                     / f'{s["super_sector"]}.bin').read_bytes()
            cur = read_sector(fes, s["fes_sector"])
            if cur == want:
                print(f'  FES {s["fes_sector"]:>9d}: already correct, skipping')
                continue
            if cur != other:
                sys.exit(f'  FES {s["fes_sector"]}: on-device content matches neither '
                         f'the original nor the patched sector — aborting rather than '
                         f'overwriting something unexpected')
            write_sector(fes, s["fes_sector"], want)
            back = read_sector(fes, s["fes_sector"])
            if back != want:
                sys.exit(f'  FES {s["fes_sector"]}: read-back MISMATCH after write — stop')
            print(f'  FES {s["fes_sector"]:>9d}: written and verified')
        print(f"\n{args.action} complete, all sectors verified")
    finally:
        usb.close()


if __name__ == "__main__":
    main()
