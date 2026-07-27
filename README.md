# G'AIM'E light gun console — reverse engineering

Notes and tooling for the **G'AIM'E TIME CRISIS** console (Tassei Denki, ODM Dashine,
licensed by Bandai Namco). It ships as a sealed HDMI kiosk. This repository documents
taking it apart in software: the firmware encryption, the flash protocol, a full backup,
and eventually a root shell and our own apps running on it.

Everything here was done with the vendor's **publicly downloadable, unauthenticated**
firmware, a USB cable, and a serial adapter, on hardware I own.

**[Read the blog post →](docs/blog.html)** — the narrative version, covering both the console
and the gun, with the teardown photos.
**[Read the write-up →](docs/writeup.html)** — the console-focused technical write-up.

Both are self-contained HTML with images inlined.

## What's inside

| | |
|---|---|
| SoC | Allwinner A523 / A527 (`sun55iw3`), octa-core Cortex-A55 |
| OS | Android 13, `user` build, test-keys |
| RAM / storage | 512 MiB LPDDR4 · 58 GiB eMMC |
| Boot chain | BOOT0 → BL31 (ATF v2.5) → SCP/arisc → U-Boot 2018.07 |
| Board | `LBQ-1585-A-V1.1`, 2025-07-23 |
| Emulator | `libSys22Plugin.so` — *"(C)2021 BANDAI NAMCO Research Inc."* |

The emulator is a **licensed in-house Namco System 22 core** behind a Unity front end,
not MAME or FBNeo — with debug hooks left in.

## Findings

- **[FINDINGS.md](FINDINGS.md)** — the full log, including dead ends and corrections
- **[docs/fes-protocol.md](docs/fes-protocol.md)** — Allwinner FEL/FES wire format and opcodes
- **[docs/blog.html](docs/blog.html)** — narrative post covering the console *and* the gun
- **[docs/writeup.html](docs/writeup.html)** — console-focused write-up with screenshots

Highlights:

- The update package's `GAIMEENC` container is **AES-256-GCM with a hardcoded key** in the
  .NET updater. Re-encrypting an unmodified image reproduces the vendor's shipped `.dat`
  **byte for byte**.
- **No secure boot at any layer** — fuse clear, AVB flags zero, no dm-verity. The only
  integrity check is a 32-bit word sum.
- The three retail SKUs differ **only** in which game APKs are present.
- Full 27-partition flash backup, read-only, capturing a **factory firmware that exists
  nowhere else** (older than the public download).

## Tooling

```bash
python3 tools/gaime_decrypt.py <sku>.dat -o work     # GAIMEENC -> Allwinner IMAGEWTY
tools/unpack_all.sh work/<sku>.img <tag>             # -> super -> logical parts -> EROFS
tools/enter_fes.sh                                   # FEL -> FES (RAM only, nothing written)
python3 tools/gaime_fes.py dump backup/device        # read every partition
python3 tools/uart_shell.py probe                    # serial console on header J2
python3 tools/gun_probe.py list                      # light gun HID interfaces
```

`gaime_fes.py` is **read-only by construction** — `FES_DOWNLOAD` and `FES_FORCE_ERASE`
are not defined in it at all, so a bug can only produce a bad read.
`gaime_fes_write.py` is the only tool that writes: it refuses any sector whose current
contents match neither the recorded original nor the intended result, and reads back
everything it writes.

## Apps

Small APKs built with raw SDK tools (no Gradle), installed to `/data` so they cannot
affect boot and `adb uninstall` removes them cleanly:

- `apps/gaime-hello` — fullscreen splash, dismissed by the gun or any key
- `apps/gaime-explorer` — file browser and app launcher for the 24 activities the
  kiosk hides

## Status

Working: full firmware analysis, verified flash backup, FEL/FES read **and** write,
serial root console, adb, custom apps, replaced boot logo.

Open: making the adb fix permanent (one byte), the System 22 core's debug hooks, ROM
data inside `data.unity3d`, and the gun's own MCU — it does all its computer vision
internally and the console has no camera at all.

## Hardware rebuild

An Avaota A1-derived, deliberately non-fabrication-ready rebuild package for the Android console
board is in **[hardware/android-box-rebuild](hardware/android-box-rebuild/README.md)**.
It fixes the requested connector floorplan, records the AXP717/AXP323 software-port
decision, and defines the gated work needed for a JLCPCB prototype release.

## Notes

Device-unique identifiers (chip SID, adb serial, eFuse contents) are redacted. The
`backup/` images are not committed — they contain a full copy of licensed game software.

Not affiliated with Tassei Denki, Bandai Namco, or Dashine.
