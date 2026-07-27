#!/usr/bin/env python3
"""Build a single self-contained HTML write-up of the G'AIM'E work.

Images are inlined as data URIs so the file works from anywhere — a local
double-click, a GitHub Pages deploy, or an email attachment — with no asset
directory to keep in sync.
"""

import base64
import datetime
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "docs" / "writeup.html"

SHOTS = {
    "bootlogo_stock": ("work/bootres/bootlogo_preview.png",
                       "The stock U-Boot splash, pulled out of the bootloader_a FAT16 partition."),
    "bootlogo_new": ("work/bootres/hello_preview.png",
                     "The replacement we wrote to flash — 12156 sectors, read back and verified."),
    "hello": ("work/screen.png",
              "Our own APK running on the console, captured with adb exec-out screencap."),
    "settings": ("work/settings.png",
                 "Stock Android Settings — present all along, unreachable behind the kiosk launcher."),
    "explorer": ("work/explorer.png",
                 "The file browser we built, listing / on the device."),
    "input_demo": ("work/input_demo.png",
                   "Driven remotely: adb shell input tap navigated into /etc."),
}


def data_uri(rel: str) -> str | None:
    p = ROOT / rel
    if not p.exists():
        return None
    return "data:image/png;base64," + base64.b64encode(p.read_bytes()).decode()


def git(*args) -> str:
    try:
        return subprocess.run(["git", *args], cwd=ROOT, capture_output=True,
                              text=True, check=True).stdout.strip()
    except Exception:
        return ""


def figure(key: str) -> str:
    rel, caption = SHOTS[key]
    uri = data_uri(rel)
    if not uri:
        return f'<p class="missing">[missing image: {rel}]</p>'
    return (f'<figure><img src="{uri}" alt="{caption}">'
            f'<figcaption>{caption}</figcaption></figure>')


CSS = """
:root{--bg:#0d1117;--panel:#161b22;--fg:#e6edf3;--dim:#9198a1;--line:#30363d;
--accent:#22d3ee;--warn:#f0883e;--ok:#3fb950}
@media(prefers-color-scheme:light){:root{--bg:#ffffff;--panel:#f6f8fa;--fg:#1f2328;
--dim:#59636e;--line:#d1d9e0;--accent:#0969da;--warn:#bc4c00;--ok:#1a7f37}}
:root[data-theme=dark]{--bg:#0d1117;--panel:#161b22;--fg:#e6edf3;--dim:#9198a1;
--line:#30363d;--accent:#22d3ee;--warn:#f0883e;--ok:#3fb950}
:root[data-theme=light]{--bg:#fff;--panel:#f6f8fa;--fg:#1f2328;--dim:#59636e;
--line:#d1d9e0;--accent:#0969da;--warn:#bc4c00;--ok:#1a7f37}
*{box-sizing:border-box}
body{margin:0;background:var(--bg);color:var(--fg);
font:16px/1.65 -apple-system,BlinkMacSystemFont,"Segoe UI",Helvetica,Arial,sans-serif}
.wrap{max-width:860px;margin:0 auto;padding:48px 20px 96px}
h1{font-size:2.1rem;line-height:1.2;margin:0 0 8px}
h2{font-size:1.4rem;margin:56px 0 14px;padding-bottom:8px;border-bottom:1px solid var(--line)}
h3{font-size:1.1rem;margin:32px 0 10px;color:var(--accent)}
.sub{color:var(--dim);margin:0 0 40px;font-size:1.05rem}
code{font-family:ui-monospace,SFMono-Regular,Menlo,monospace;font-size:.87em;
background:var(--panel);padding:.15em .4em;border-radius:4px}
pre{background:var(--panel);border:1px solid var(--line);border-radius:8px;
padding:14px 16px;overflow-x:auto}
pre code{background:none;padding:0;font-size:.85rem;line-height:1.5}
table{border-collapse:collapse;width:100%;margin:18px 0;display:block;overflow-x:auto}
th,td{border:1px solid var(--line);padding:8px 12px;text-align:left;font-size:.92rem}
th{background:var(--panel);font-weight:600}
figure{margin:24px 0}
img{max-width:100%;height:auto;border:1px solid var(--line);border-radius:8px;display:block}
figcaption{color:var(--dim);font-size:.87rem;margin-top:8px}
.callout{background:var(--panel);border-left:3px solid var(--accent);
border-radius:0 8px 8px 0;padding:14px 18px;margin:22px 0}
.callout.warn{border-left-color:var(--warn)}
.callout.ok{border-left-color:var(--ok)}
.missing{color:var(--warn);font-style:italic}
ul,ol{padding-left:22px}li{margin:6px 0}
footer{margin-top:72px;padding-top:20px;border-top:1px solid var(--line);
color:var(--dim);font-size:.87rem}
.kv{color:var(--dim)}
"""


def build() -> str:
    commits = git("log", "--oneline") .count("\n") + 1
    today = datetime.date.today().isoformat()

    return f"""<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>G'AIM'E light gun console — reverse engineering write-up</title>
<style>{CSS}</style>
<div class="wrap">

<h1>G'AIM'E TIME CRISIS console — reverse engineering</h1>
<p class="sub">From a sealed HDMI kiosk to a root shell, a full flash backup, and our own
software running on it. {commits} commits, one day. Last updated {today}.</p>

<div class="callout">
<strong>What this is.</strong> A Bandai Namco–licensed light gun console (Tassei Denki, ODM
Dashine) that ships as a locked kiosk. Everything below was done with the publicly downloadable
firmware, a USB cable, and eventually a $5 serial adapter. Nothing was destroyed and every
change is reversible from a verified backup.
</div>

<h2>What the hardware turned out to be</h2>
<table>
<tr><th>SoC</th><td>Allwinner A523 / A527 (<code>sun55iw3</code>), octa-core Cortex-A55</td></tr>
<tr><th>OS</th><td>Android 13 (SDK 33), <code>user</code> build, test-keys</td></tr>
<tr><th>RAM / storage</th><td>512 MiB LPDDR4 @1200 MHz · 58 GiB eMMC (MMC 5.1)</td></tr>
<tr><th>Boot chain</th><td>BOOT0 → BL31 (ARM Trusted Firmware v2.5) → SCP/arisc → U-Boot 2018.07</td></tr>
<tr><th>Board</th><td><code>LBQ-1585-A-V1.1</code>, dated 2025-07-23</td></tr>
<tr><th>Emulator</th><td><code>libSys22Plugin.so</code> — <em>“(C)2021 BANDAI NAMCO Research Inc.”</em></td></tr>
</table>

<p>The emulator is the surprise: not MAME or FBNeo but a <strong>licensed in-house Namco System 22
core</strong> wrapped in a Unity front end, with debug hooks left in
(<code>Sys22Plugin_DebugReadMemory</code>, <code>SetRom</code>, EEPROM accessors). No GPL
obligations to lean on, and ROM data lives inside a Unity asset rather than as MAME sets.</p>

<h2>1. The firmware encryption</h2>

<p>The vendor's 4 GB update package wraps its payloads in a custom <code>GAIMEENC</code>
container. The updater is a .NET 8 single-file bundle; extracting <code>GAIMEUpdater.dll</code>
from it and decompiling <code>FirmwareDecryptor</code> yields the whole scheme — including a
<strong>hardcoded AES-256-GCM key</strong>.</p>

<pre><code>"GAIMEENC" (8) · version=1 (1) · max chunk size (4, LE = 4 MiB) · base nonce (12)
then repeating: length (4, LE) · ciphertext · GCM tag (16)

Per-chunk nonce = base nonce with the LE int32 at bytes 8..12 XORed with the chunk index.</code></pre>

<p>Underneath sits a plaintext Allwinner <strong>IMAGEWTY</strong> image. We wrote a decryptor,
an IMAGEWTY unpacker, a sparse-image converter and an <code>lpunpack</code> for Android's
dynamic partitions — enough to take a stock download apart completely.</p>

<div class="callout ok">
<strong>Proof the format was fully understood:</strong> re-encrypting the <em>unmodified</em>
image with its original nonce reproduces the vendor's shipped <code>.dat</code>
<strong>byte for byte</strong> — same SHA-256.
</div>

<h3>SKU differences</h3>
<p>The three retail bundles differ only in which game APKs are present. Premium and Ultimate are
identical everywhere except the launcher APK, which differs by 5 bytes of compression noise — so
the “Premium vs Ultimate” distinction is <em>not in the firmware at all</em>; it is runtime
accessory detection.</p>

<h2>2. There is no secure boot</h2>

<table>
<tr><th>Check</th><th>State</th></tr>
<tr><td>Secure boot fuse</td><td><code>secure enable bit: 0</code> — not fused</td></tr>
<tr><td>AVB</td><td>vbmeta flags <code>0x00000000</code>; “avb” appears zero times in the boot log</td></tr>
<tr><td>dm-verity</td><td>no <code>avb=</code> or <code>verify</code> flag on any partition</td></tr>
<tr><td>Integrity check</td><td>only <code>V*.fex</code> — a 32-bit sum of the partition's words</td></tr>
</table>

<p>The one integrity mechanism is arithmetic, not cryptographic, and we reproduced it exactly.</p>

<h2>3. Talking to the hardware</h2>

<p>The console enters Allwinner <strong>FEL</strong> (boot ROM) mode as <code>1f3a:efe8</code>,
reporting SoC <code>0x1890</code>. That gives arbitrary memory read/write before any device code
runs — but the boot ROM has no storage driver, so reading flash needed the vendor's own FES path:
load <code>fes1.fex</code> to bring up DRAM, then U-Boot, then speak FES.</p>

<p>We rebuilt that path from the protocol rather than the binary. Three things had to be
corrected, each caught by checking against known-good data instead of assuming:</p>

<ul>
<li><strong>Load addresses come from each image's own header</strong>, not sunxi-fel's table.
<code>fes1</code> loads at <code>0x4c000</code>; <code>0x44000</code> is <em>boot0's</em> address.</li>
<li><strong>The read opcode is <code>FES_UPLOAD</code> (0x207)</strong>, not
<code>FES_TRANSMITE</code> (0x201).</li>
<li><strong>FES addressing sits 40960 sectors below the GPT's own LBAs.</strong> The first dump
ran without this and produced 15 files that looked perfectly fine and were entirely wrong —
<code>private.img</code> actually contained <code>media_data</code>. Only checking filesystem
magics caught it.</li>
</ul>

<div class="callout warn">
That last one is the whole argument for verification. The tooling now calibrates against a known
magic and <strong>refuses to dump</strong> if nothing matches, rather than writing out
plausible-looking garbage.
</div>

<h3>The backup</h3>
<p>All 27 partitions, 58 GiB, entirely read-only. It captured something that exists nowhere else:
the console runs <strong>factory firmware built 2025-10-09</strong>, older than the public 4.0.3
download and never published. One update would have destroyed it.</p>

<h2>4. Changing what it does at boot</h2>

<p>With no feedback channel, early patches were guesswork. The breakthrough was realising the
<strong>TV is a feedback channel</strong>: <code>bootloader_a</code> is a plain FAT16 filesystem
holding the boot splash U-Boot paints before Linux starts — no SELinux labels to preserve, and
the result is visible from the sofa.</p>

{figure('bootlogo_stock')}
{figure('bootlogo_new')}

<p>12156 sectors written, each read back and compared, then the whole 32 MiB partition read back
off the device and confirmed byte-identical. It appeared on the TV — proving flash writes land
<em>and</em> that a real boot reads them, which four earlier patches had never confirmed either way.</p>

<h2>5. The bug that cost a dozen rounds</h2>

<p>Five property patches to enable ADB produced nothing. No enumeration, no errors, no way to
tell whether they had applied. Then the debug UART — a labelled 3-pin header <code>J2</code> on
the mainboard — gave a root shell, and <code>logcat</code> answered in one line:</p>

<pre><code>avc: denied {{ setcurrent }} for scontext=u:r:adbd:s0 tcontext=u:r:adbd:s0
adbd: main.cpp:162] Could not set SELinux context</code></pre>

<div class="callout warn">
<strong><code>ro.secure=0</code> — one of our own patches — was what broke ADB.</strong>
With it cleared, adbd tries to stay root and switch to <code>u:r:su:s0</code>. A
<code>user</code> build's policy has no such transition, so the kernel denies it and adbd
<code>LOG(FATAL)</code>s every five seconds, forever. The patch intended to <em>loosen</em>
security is precisely what prevented ADB from running.
</div>

<p>Everything else had been correct the entire time — the UDC was present as
<code>4100000.udc-controller</code> (a name derived from Linux's device-tree naming rule),
functionfs was mounted, all five properties had applied. <strong>One wrong assumption masked four
correct ones</strong>, and no amount of static analysis would have shown it.</p>

<p>The fix is <code>setprop service.adb.root 0</code>, which forces adbd to drop privileges.</p>

<h2>6. Our own software on the console</h2>

{figure('hello')}
{figure('explorer')}
{figure('settings')}

<p>The kiosk hides a lot: <strong>106 packages, 24 launchable activities</strong>, including the
complete stock Android Settings. The launcher was simply the only door.</p>

<p>Both apps install to <code>/data</code> rather than the firmware, so they cannot affect boot
and <code>adb uninstall</code> removes them completely. Neither needs root.</p>

{figure('input_demo')}

<h2>Tooling written</h2>
<table>
<tr><th>Tool</th><th>Purpose</th></tr>
<tr><td><code>gaime_decrypt.py</code> / <code>gaime_encrypt.py</code></td><td>GAIMEENC container, both directions</td></tr>
<tr><td><code>imagewty_unpack.py</code></td><td>Allwinner IMAGEWTY images</td></tr>
<tr><td><code>simg2img.py</code> / <code>lpunpack.py</code></td><td>Android sparse and dynamic partitions</td></tr>
<tr><td><code>gaime_fes.py</code></td><td>read-only FES client — no write opcodes exist in it</td></tr>
<tr><td><code>gaime_fes_write.py</code></td><td>the only tool that writes; refuses anything unexpected</td></tr>
<tr><td><code>uart_shell.py</code> / <code>uart_watch.sh</code></td><td>serial console, two-way</td></tr>
<tr><td><code>gun_probe.py</code></td><td>light gun HID interfaces and vendor protocol</td></tr>
</table>

<div class="callout">
<strong>Safety by construction.</strong> The read client contains no write opcodes at all —
<code>FES_DOWNLOAD</code> and <code>FES_FORCE_ERASE</code> are simply absent, so a bug can only
ever produce a bad <em>read</em>. The writer refuses to touch a sector whose current contents
match neither the recorded original nor the intended result, and reads back every sector it writes.
</div>

<h2>Open threads</h2>
<ul>
<li>Making the ADB fix permanent — a one-byte revert of <code>ro.secure</code>, needing FEL entry
(the button snapped off during disassembly).</li>
<li>The Namco System 22 core's debug hooks — memory read/write into a licensed arcade emulator.</li>
<li>ROM data inside <code>data.unity3d</code>.</li>
<li>The gun's own MCU: it does all its computer vision internally and the console has no camera at
all, so the gun is the more interesting target now.</li>
</ul>

<footer>
Write-up generated from the repository. All work performed on hardware owned by the author,
using firmware the vendor publishes publicly and without authentication.
</footer>

</div>
"""


def main() -> None:
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(build())
    kb = OUT.stat().st_size / 1024
    print(f"wrote {OUT.relative_to(ROOT)}  ({kb:.0f} KiB, images inlined)")


if __name__ == "__main__":
    main()
