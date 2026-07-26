#!/usr/bin/env python3
"""Render a replacement U-Boot boot logo for the G'AIM'E console.

The stock logo lives in the `bootloader_a` partition, which is a plain FAT16
filesystem (no SELinux labels), so it can be rebuilt offline and written back
whole. U-Boot paints it on HDMI before Linux starts — which makes it the one
change to this device that is visible without a shell.

Output matches the stock file exactly in geometry and encoding:
1920x1080, 24 bpp, bottom-up BGR, so U-Boot's simple BMP reader is happy.

Run with a Pillow-capable interpreter, e.g. /tmp/pilvenv/bin/python.
"""

import argparse
from pathlib import Path

from PIL import Image, ImageDraw, ImageFont

W, H = 1920, 1080
BG = (16, 16, 24)
CYAN = (34, 211, 238)
WHITE = (245, 245, 245)
DIM = (120, 134, 150)


def pick_font(size, bold=True):
    for path in ("/System/Library/Fonts/Helvetica.ttc",
                 "/System/Library/Fonts/Supplemental/Arial Bold.ttf",
                 "/System/Library/Fonts/SFNS.ttf"):
        try:
            return ImageFont.truetype(path, size, index=1 if bold and path.endswith(".ttc") else 0)
        except Exception:
            continue
    return ImageFont.load_default()


def centred(draw, y, text, font, fill):
    box = draw.textbbox((0, 0), text, font=font)
    draw.text(((W - (box[2] - box[0])) // 2 - box[0], y), text, font=font, fill=fill)
    return box[3] - box[1]


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("out", type=Path)
    ap.add_argument("--text", default="hello")
    ap.add_argument("--sub", default="patched boot logo")
    args = ap.parse_args()

    img = Image.new("RGB", (W, H), BG)
    d = ImageDraw.Draw(img)

    # thin cyan rule top and bottom, so it is obviously not the stock splash
    d.rectangle([0, 0, W, 8], fill=CYAN)
    d.rectangle([0, H - 9, W, H], fill=CYAN)

    centred(d, 330, args.text, pick_font(300), CYAN)
    centred(d, 700, args.sub, pick_font(64), WHITE)
    centred(d, 810, "G'AIM'E console  ·  Allwinner A523  ·  booted from patched flash",
            pick_font(34), DIM)

    img.save(args.out, format="BMP")

    raw = args.out.read_bytes()
    print(f"wrote {args.out}  {len(raw)} bytes")
    import struct
    off = struct.unpack_from("<I", raw, 10)[0]
    w, h = struct.unpack_from("<ii", raw, 18)
    bpp = struct.unpack_from("<H", raw, 28)[0]
    print(f"  {w} x {h}, {bpp} bpp, pixel data at {off}")


if __name__ == "__main__":
    main()
