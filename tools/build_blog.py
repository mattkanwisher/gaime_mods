#!/usr/bin/env python3
"""Build the self-contained HTML blog post about the G'AIM'E work.

Prose lives in tools/blog_content.html so it can be edited as HTML rather than
as a Python string. This script only handles the parts that need a program:
inlining images as data URIs, downscaling the teardown photos so the result is
a sane size, and stamping the commit it was built from.

    python3 tools/build_blog.py        ->  docs/blog.html

Photos are re-encoded through sips into a temp file before inlining, which also
drops any residual camera metadata. The raw originals in docs/photos/IMG_*.jpeg
carry GPS EXIF and are gitignored; never inline those directly.
"""

import base64
import datetime
import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CONTENT = Path(__file__).resolve().parent / "blog_content.html"
OUT = ROOT / "docs" / "blog.html"

# key -> (path relative to repo root, max width in px, jpeg quality, caption)
#
# Width 0 means "inline as-is", which is right for the PNG screenshots: they are
# already small and re-encoding would only blur the text. For the photos the whole
# page has to stay downloadable, so everything is squeezed hard except the SoC
# close-up — that one is evidence (a blank chip lid, a J3 silkscreen you have to be
# able to read) rather than decoration, so it keeps its detail.
FIGURES = {
    "gun_open": (
        "docs/photos/gun-front-overview-in-chassis.jpg", 1000, 48,
        "The gun opened up. Main board <code>LBQ-1585-C-V1.1</code>, the camera on a "
        "ribbon at the muzzle end, and the recoil motor bottom right."),
    "gun_soc": (
        "docs/photos/gun-front-closeup-soc-and-j3-uart.jpg", 1400, 58,
        "The two things that mattered: the completely unmarked SoC at <code>U8</code>, "
        "and <code>J3</code> — four holes silkscreened GND / TX / RX / V3.3."),
    "gun_back": (
        "docs/photos/gun-mainboard-back.jpg", 1000, 48,
        "The back of the board is nearly bare. No DRAM anywhere, which means it is "
        "stacked in-package with the SoC."),
    "gun_camera": (
        "docs/photos/gun-chassis-camera-and-motor.jpg", 1000, 48,
        "The camera module sits in the barrel on its own FPC — a discrete, "
        "replaceable part rather than something soldered down."),
    "gunfeed": (
        "work/cam/gunfeed_frame0.png", 0, 0,
        "One frame of the gun's UVC stream. Not a camera view: a synthetic ramp, "
        "uniform along every row, scrolling at exactly 1.6 rows per frame."),
    "bootlogo_stock": (
        "work/bootres/bootlogo_preview.png", 0, 0,
        "The stock U-Boot splash, extracted from the FAT16 filesystem inside "
        "<code>bootloader_a</code>."),
    "bootlogo_new": (
        "work/bootres/hello_preview.png", 0, 0,
        "Our replacement, written back over FES and read out again to verify. "
        "Seeing this on the TV was the first proof our writes reached real flash."),
    "hello": (
        "work/screen.png", 0, 0,
        "Our own APK on the console — the first code we wrote running on the device."),
    "settings": (
        "work/settings.png", 0, 0,
        "Stock Android Settings. It was installed the whole time, just unreachable "
        "behind the kiosk launcher."),
    "explorer": (
        "work/explorer.png", 0, 0,
        "The file browser we built, listing <code>/</code> on the console."),
    "input_demo": (
        "work/input_demo.png", 0, 0,
        "Driven remotely — <code>adb shell input tap</code> navigating into "
        "<code>/etc</code>."),
}


def data_uri(rel: str, max_width: int, quality: int) -> str | None:
    src = ROOT / rel
    if not src.exists():
        return None

    if max_width and src.suffix.lower() in (".jpg", ".jpeg"):
        with tempfile.TemporaryDirectory() as td:
            tmp = Path(td) / src.name
            r = subprocess.run(
                ["sips", "--resampleWidth", str(max_width), "-s", "format", "jpeg",
                 "-s", "formatOptions", str(quality), str(src), "--out", str(tmp)],
                capture_output=True)
            blob = tmp.read_bytes() if r.returncode == 0 and tmp.exists() \
                else src.read_bytes()
        return "data:image/jpeg;base64," + base64.b64encode(blob).decode()

    mime = "image/jpeg" if src.suffix.lower() in (".jpg", ".jpeg") else "image/png"
    return f"data:{mime};base64," + base64.b64encode(src.read_bytes()).decode()


def figure(key: str) -> str:
    rel, width, quality, caption = FIGURES[key]
    uri = data_uri(rel, width, quality)
    if not uri:
        return f'<p class="missing">[missing image: {rel}]</p>'
    alt = caption.replace("<code>", "").replace("</code>", "").replace('"', "&quot;")
    return (f'<figure><img loading="lazy" src="{uri}" alt="{alt}">'
            f'<figcaption>{caption}</figcaption></figure>')


def git(*args) -> str:
    try:
        return subprocess.run(["git", *args], cwd=ROOT, capture_output=True,
                              text=True, check=True).stdout.strip()
    except Exception:
        return ""


def main() -> None:
    html = CONTENT.read_text()

    for key in FIGURES:
        html = html.replace("{{FIG:%s}}" % key, figure(key))

    commit = git("rev-parse", "--short", "HEAD") or "uncommitted"
    html = html.replace("{{COMMIT}}", commit)
    html = html.replace("{{DATE}}", datetime.date.today().isoformat())

    leftover = [ln for ln in html.splitlines() if "{{" in ln]
    if leftover:
        print("warning: unsubstituted placeholders:")
        for ln in leftover:
            print("   ", ln.strip()[:100])

    OUT.write_text(html)
    print(f"wrote {OUT.relative_to(ROOT)}  ({OUT.stat().st_size // 1024} KiB)")


if __name__ == "__main__":
    main()
