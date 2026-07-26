#!/usr/bin/env python3
"""Unpack an Allwinner IMAGEWTY (PhoenixSuit / LiveSuit) firmware image.

Handles the plaintext v0x0300 layout used by the G'AIM'E console images.
"""

import argparse
import struct
from pathlib import Path

MAGIC = b"IMAGEWTY"


def cstr(b: bytes) -> str:
    return b.split(b"\0", 1)[0].decode("latin-1").strip()


def parse(path: Path):
    with path.open("rb") as f:
        head = f.read(0x400)
        if head[:8] != MAGIC:
            raise SystemExit(f"{path}: not an IMAGEWTY image")

        hdr = {
            "header_version": struct.unpack_from("<I", head, 0x08)[0],
            "header_size": struct.unpack_from("<I", head, 0x0C)[0],
            "ram_base": struct.unpack_from("<I", head, 0x10)[0],
            "version": struct.unpack_from("<I", head, 0x14)[0],
            "image_size": struct.unpack_from("<I", head, 0x18)[0],
            "image_header_size": struct.unpack_from("<I", head, 0x20)[0],
            "usb_pid": struct.unpack_from("<I", head, 0x24)[0],
            "usb_vid": struct.unpack_from("<I", head, 0x28)[0],
            "hardware_id": struct.unpack_from("<I", head, 0x2C)[0],
            "firmware_id": struct.unpack_from("<I", head, 0x30)[0],
            "num_files": struct.unpack_from("<I", head, 0x3C)[0],
        }

        items = []
        f.seek(hdr["image_header_size"])
        for _ in range(hdr["num_files"]):
            it = f.read(0x400)
            items.append({
                "main_type": cstr(it[0x08:0x10]),
                "sub_type": cstr(it[0x10:0x20]),
                "filename": cstr(it[0x24:0x124]),
                "stored_length": struct.unpack_from("<I", it, 0x124)[0],
                "original_length": struct.unpack_from("<I", it, 0x12C)[0],
                "offset": struct.unpack_from("<I", it, 0x134)[0],
            })
    return hdr, items


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("image", type=Path)
    ap.add_argument("-o", "--outdir", type=Path, help="extract files here (list only if omitted)")
    args = ap.parse_args()

    hdr, items = parse(args.image)
    print(f"IMAGEWTY v0x{hdr['header_version']:04x}  "
          f"fw_version=0x{hdr['version']:08x}  "
          f"VID:PID={hdr['usb_vid']:#06x}:{hdr['usb_pid']:#06x}  "
          f"hw_id=0x{hdr['hardware_id']:x} fw_id=0x{hdr['firmware_id']:x}")
    print(f"{hdr['num_files']} files, image_size={hdr['image_size']}\n")
    print(f"{'MAIN_TYPE':10s} {'SUB_TYPE':18s} {'FILENAME':28s} {'SIZE':>12s} {'OFFSET':>12s}")
    for it in items:
        print(f"{it['main_type']:10s} {it['sub_type']:18s} {it['filename']:28s} "
              f"{it['original_length']:12d} {it['offset']:12d}")

    if args.outdir:
        args.outdir.mkdir(parents=True, exist_ok=True)
        with args.image.open("rb") as f:
            for it in items:
                dst = args.outdir / it["filename"]
                f.seek(it["offset"])
                remaining = it["original_length"]
                with dst.open("wb") as out:
                    while remaining:
                        block = f.read(min(1 << 22, remaining))
                        if not block:
                            break
                        out.write(block)
                        remaining -= len(block)
        print(f"\nextracted {len(items)} files -> {args.outdir}")


if __name__ == "__main__":
    main()
