# G'AIM'E — Findings, session 1 (2026-07-26)

Source: `GAIME_FWUpdate_V4.0.3` (public, unauthenticated download). Nothing was
flashed and the console was never opened. All results are from static analysis.

Tooling written this session lives in `tools/`. Outputs land in `work/` (gitignored).

```bash
python3 tools/gaime_decrypt.py <sku>.dat -o work      # GAIMEENC -> Allwinner .img
tools/unpack_all.sh work/<sku>.img <tag>              # .img -> super -> EROFS trees
```

---

## 1. Hardware (answered)

| | |
|---|---|
| SoC | **Allwinner A527** (`sun55iw3`), board `a527-pro2` |
| DRAM | 512 MiB |
| PMIC | AXP2202 (main) + AXP1530 |
| Bootloader | U-Boot 2018.07, built 2025-12-30 |
| OS | **Android 13** (SDK 33), build `TQ2A.230405.003.B2`, dated 2026-02-05, `test-keys` |
| Debug UART | `uart_debug_tx = PB09`, `uart_debug_rx = PB10`, port 0 |
| Console camera | **none** — zero `csi`/`vind`/`camera`/`mipi` entries in `sys_config.fex` |

The vendor shipped three real factory U-Boot logs in
`GAIMEUpdater_v4.0.3/GAIME_Tools/PhoenixConsole/logfile/`. They contain the full boot
sequence and a complete MBR dump — that is where the SoC and partition data above
come from, no teardown required.

Partition layout is stock modern Android: 27 partitions, A/B slots, AVB
(`vbmeta`/`vbmeta_system`/`vbmeta_vendor`), `init_boot`, `vendor_boot`, and a 3.5 GB
`super` holding dynamic partitions.

## 2. Firmware update path (answered)

- Vendor stack is **Allwinner PhoenixSuit** (`PhoenixPro.cfg` → `www.allwinnertech.com`,
  author `AWA1746`). The unsigned kernel driver is Allwinner's `usbdrv.sys`.
- FEL/efex USB IDs: **VID `0x1f3a` / PID `0x1000`** (from `LiveSuit.cfg`).
- **Loader entry sequence:** hold the pinhole *Programming* button on the console, then
  insert USB-C into the **POWER PORT** (rear power jack is USB-C data). Release after
  ~5 s. The rear jack doubling as data was the correct hypothesis.
- `GAIMEUpdater.exe` decrypts the `.dat` to a plain `.img` in
  `%LOCALAPPDATA%\GAIMEUpdater\temp_firmware\<guid>.img`, then hands it to PhoenixSuit.
  A leftover dev path in `PhoenixPro.cfg` (`C:\Users\Ian\...`) exposed this.
- ODM is **Dashine** — build path `D:\Dashine\New Products\Lightgun\Firmware\GaimeBox_Burn_Tools\`,
  and every app package is `com.dashine.*`.

## 3. The GAIMEENC container (broken)

`GAIMEUpdater.exe` is a .NET 8 single-file bundle. Extracting `GAIMEUpdater.dll` from the
bundle and decompiling `GAIMEUpdater.FirmwareDecryptor` gives the whole scheme, including a
**hardcoded AES-256-GCM key**:

```
2C4B5B4D84F9A5E0E4D4C2F78B6A1D9E0A0B1C2D3E4F5061728394A5B6C7D8E9
```

Layout: `"GAIMEENC"` (8) · version=1 (1) · max chunk size (4, LE = 4 MiB) · base nonce (12),
then repeating `{ length (4, LE), ciphertext, GCM tag (16) }`. Per-chunk nonce is the base
nonce with the LE int32 at bytes 8..12 XORed with the zero-based chunk index. No AAD.
Payload entropy is 7.9998 — genuinely encrypted, not packed.

Underneath is a plaintext **Allwinner IMAGEWTY** image (49 members, VID:PID `0x8743:0x1234`),
so no further layer to defeat.

## 4. SKU differences (answered)

The three `.dat` files are the three retail bundles.

| File | Size | SKU | Game APKs present | Launcher package |
|---|---|---|---|---|
| `9c4f1e3b.dat` | 1.19 GB | Basic | TimeCrisis only | `…hidcommunication_timecrisis_only` |
| `a4d7e9f0.dat` | 1.29 GB | Premium | all four | `com.dashine.hidcommunication` |
| `d8a21f90.dat` | 1.29 GB | Ultimate | all four | `com.dashine.hidcommunication` |

All three images carry odex/vdex stubs for all four games; Basic simply omits three of the
APKs. Verified by extracting all three and comparing.

Premium and Ultimate were compared file-by-file across every partition. **The only thing
that differs anywhere in either image is the launcher APK** (`hidcommunication.apk`, plus
its odex/vdex and the resulting `super`/`vbmeta_system` hashes). Games, vendor, product and
kernel modules are byte-identical. The two launchers share one package name, differ by 5
bytes, and their only differing strings are compression artefacts — so they are effectively
the same build.

That implies Premium vs Ultimate is **not** baked into the image at all; the first-launch
"authentication" (Premium: pedal; Ultimate: two guns) is just runtime accessory detection.
Premium and Ultimate images should therefore be interchangeable in practice.

## 5. Software stack (answered)

`system/app/` contains, alongside stock AOSP:

- `TimeCrisis`, `PointBlank`, `SteelGunner1`, `SteelGunner2` — one APK per game
- `GaimeService` — the USB driver and AIDL service
- `GaimeCalibration` — calibration UI
- `hidcommunication` — the launcher (package `com.dashine.hidcommunication_timecrisis_only`)

### The emulator is not open source

Each game is a **Unity** app (`libunity.so`, `libil2cpp.so`) wrapping a native core. For
Time Crisis that core is `libSys22Plugin.so`, stamped:

```
(C)2021 BANDAI NAMCO Research Inc.
```

This is a **licensed, in-house Namco System 22 emulator**, not FBNeo or MAME. So there are
no GPL obligations to lean on and no published source offer to expect. Its exported API is
unusually clean and includes debug hooks:

```
Sys22Plugin_SetRom            Sys22Plugin_DebugReadMemory
Sys22Plugin_SetInputPointing  Sys22Plugin_DebugWriteMemory
Sys22Plugin_SetEEPROM         Sys22Plugin_GetForceFeedback
Sys22Plugin_UpdateFrame       Sys22Plugin_Get/PutRankingData
```

ROM data is passed in via `Sys22Plugin_SetRom` from the C# layer, so it lives as a Unity
asset inside `assets/bin/Data/data.unity3d` (39 MB) rather than as loose MAME set files.
Audio goes through a separate `libaudioplugin_Quattro.so`.

## 6. The gun (answered on paper, not yet on hardware)

From `GaimeService`:

- **USB IDs: VID `0x2E2C` (11820), PID `0x0631` (1585).**
- Android matches it with `supportsSource(SOURCE_STYLUS)` — the gun's HID descriptor
  declares a **digitizer/pen, i.e. an absolute pointer**. That is exactly why it works as a
  no-calibration absolute mouse when plugged straight into a PC.
- Composite device. Interface 0 is the HID pointer consumed by the normal Android input
  stack. **Interface 1** is a vendor interface the service claims explicitly
  (`claimSpecificInterface(1)`) for configuration, using interrupt IN/OUT endpoints and
  64-byte reports.

**All computer vision runs in the gun.** The console has no camera hardware at all, and the
gun reports derived points while receiving calibration coefficients back. This means the
console is optional for pointing — Tier 2 does not depend on Tier 3.

### Interface 1 wire format

64-byte reports. The methods are named `encrypt*` but there is no encryption — it is
framing plus a **Modbus CRC-16** (little-endian) over the leading N bytes.

```
byte 0     function code      5 = SYSTEM_CMD
byte 1     data length        1 = gun mode, 33 = calibration
byte 2     sub-function       5 = gun mode, 6 = calibration, 7 = MD5 result
byte 3-5   reserved (zero)
byte 6     payload / flags
byte 7+    payload
last 2     Modbus CRC-16, LE
```

- **Gun mode** — `05 01 05 00 00 00 <mode>` + CRC over 7 bytes at [7],[8].
  `mode` 0 = single shot, 1 = multiple shot (autofire).
- **Calibration** — `05 21 06 ...`, six calibration points per report (X,Y as two bytes at
  stride 4) followed by two base points; byte 6 carries the chunk index (`& 7`); CRC over 39
  bytes. Sent in a loop with a 200 ms gap between reports. Grid constants are `ROW = 48`,
  `COL = 5`, `REPETITION_COUNT = 3`.
- **Sub-function 7** returns a bit-packed MD5 validation result to the gun. This is almost
  certainly the "accessory check" added in v4.0.3 — i.e. an anti-counterfeit handshake.

`GaimeService`'s AIDL surface (`IGaimeAidlInterface`) also exposes `sendBufferToDevice`,
`ReadBufferFromDevice`, `setFrameColorMode` (the v4.0.3 black/white/pink assist bars),
`setGunMode`, `setSwitchGun`, and per-player difficulty and flash-intensity settings.

---

## Open questions remaining

- Trigger-pull jitter: not characterised — needs the gun on a host.
- The exact HID report descriptor for interface 0 (field ranges, button map) — needs the gun.
- Whether interface 1 config (gun mode, calibration) can be driven from a Linux/macOS host
  as-is. The protocol is now known, so this is a small experiment rather than research.
- What the MD5 handshake covers, and whether it gates pointing or only game entitlement.
- Where exactly inside `data.unity3d` the System 22 ROM data sits.

## Next actions

1. **Plug the gun into this Mac.** Everything in Tier 2 is blocked on that and nothing else.
   Capture the HID report descriptor, confirm absolute vs relative axes, then log coordinate
   streams around trigger events to quantify the jitter.
2. Write a `hidapi` client for interface 1 using the format in §6 — gun mode and frame
   colour are the cheapest things to verify.
3. Flashing an Ultimate image onto a Basic console is now trivially possible and reversible
   (all three images are public and decryptable). The authentication gate on first launch is
   the thing to actually test.
