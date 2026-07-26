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

## 6. The gun — verified on hardware

Confirmed against the physical gun on macOS. `tools/gun_probe.py` does the enumeration,
reading and command sending.

```
GAIME v1 — Tassei Denki Co.,Ltd — VID 0x2E2C  PID 0x0631
bcdDevice 0x0419, serial 9165, USB 2.0 full/high speed, 500 mA
bDeviceClass 0xEF / sub 2 / proto 1  (composite, interface association)
```

Five interfaces:

| # | Class | What it is | Endpoints |
|---|---|---|---|
| 0 | HID | Boot keyboard, 8-byte reports | 2 |
| 1 | HID | **Digitizer / touch screen — the pointer** | 2 |
| 2 | HID | Vendor page 0xFF00, 64-byte in/out — config | 2 |
| 3 | Video | UVC VideoControl | 1 |
| 4 | Video | UVC VideoStreaming | 0 (alt 0) |

**Correction to an earlier reading of the firmware:** the config interface is **2**, not 1 —
`GaimeService` builds its write device with `factory(…, 2, …)`. The `claimSpecificInterface(1)`
call does something different and more interesting: it claims the *digitizer* interface with
`force = true`, detaching it from the Android input stack for the duration of a calibration
transfer, then releases it. That is presumably to stop the pointer jumping while coefficients
are being pushed, and it is a strong hint about the reported trigger jitter.

### Interface 1 — the pointer (report descriptor decoded)

```
Usage Page (Digitizer) / Usage (Touch Screen), Report ID 1
  Tip Switch    1 bit    <- trigger
  In Range      1 bit    <- gun has screen lock
  padding       6 bits
  X, Y          16 bits each, Logical/Physical 0..10000, Input(Data,Var,Abs)
```

So a 6-byte report: `01 <flags> <X lo> <X hi> <Y lo> <Y hi>`. **X and Y are absolute** over a
normalised 0–10000 space — exactly what light gun use requires, and why it works as a
no-calibration absolute pointer on a bare PC. The `In Range` bit is a free "do I see the
screen" signal that a `uinput` bridge can gate on.

**All computer vision runs in the gun.** The console has no camera hardware at all (§1), and
the gun reports derived coordinates while receiving calibration coefficients back. The
console is therefore optional for pointing — Tier 2 does not depend on Tier 3.

### The gun also exposes its camera over standard UVC

Interfaces 3 and 4 present the gun's own camera to any host as **"Dashine UVC"**
(`UVC Camera VendorID_11820 ProductID_1585`). Supported modes:

```
320x240   @ 30 / 20 / 15 fps      1280x720  @ 10 / 5 / 2 fps
640x360   @ 30 / 20 / 15 fps      1920x1080 @ 5 / 2 fps
pixel formats: uyvy422, yuyv422, nv12, 0rgb, bgr0
```

The 30 fps modes are almost certainly what the tracking would run on. **But the stream does
not carry the camera's view — see §7.**

### Interface 2 wire format

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

### Protocol confirmed against the real gun

The decoded format was validated end to end, with **no console involved**:

```
$ python3 tools/gun_probe.py gunmode 0
hid_write returned 65  error='Success'
packet: 05 01 05 00 00 00 00 83 d1 …
reply:  05 01 05 00 00 00 01 42 11 …
```

The gun accepts the command and returns a well-formed 64-byte ack: same function code (5),
same sub-function (5), byte 6 = `0x01`, and a **valid Modbus CRC-16** (`0x1142`, verified
independently). The ack is identical for mode 0 and mode 1, so byte 6 reads as a success flag
rather than a mode echo. Sending single-shot mode was the last write, which is the default.

**A host can talk to this gun directly over interface 2, today, with no vendor software.**

## 7. The UVC stream is a test pattern, not the camera view

The video feed was captured (640x360, 30 fps, 185 frames — `work/cam/gunfeed.mov`, single frame
at `work/cam/gunfeed_frame0.png`) and it is **not imagery**. It is a synthetic scrolling gradient:
alternating magenta and green horizontal bands with smooth grey transitions.

Measured properties:

- **Every row is perfectly uniform horizontally** — per-row standard deviation across x is
  exactly `0.000` in all three channels. No lens or sensor can produce that.
- R and B are almost always clipped to 0 or 255 together while G ramps linearly at
  ~0.418/row, i.e. both chroma channels sweep together through a sawtooth.
- The pattern **scrolls vertically at exactly +1.6 rows per frame**, perfectly linear across
  60 frames (+8 rows at frame 5, +16 at 10, +48 at 30, +96 at 60).
- **Zero sensor noise.** Frame 0 rolled by 8 rows is *bit-identical* to frame 5, and rolled by
  16 rows is bit-identical to frame 10 — `max diff = 0`. A real sensor always shows read noise,
  so the frames are generated, not captured.

So the UVC bridge enumerates, negotiates a format and streams happily, but the sensor pipeline
behind it is not in imaging mode — what comes out is a built-in ramp test pattern.

**Why this is probably by design rather than a fault:** nothing in the console-side code ever
touches video. Across `GaimeService`, `GaimeCalibration` and the launcher there are only three
sub-function codes (5 gun mode, 6 calibration, 7 MD5 result) and no camera, UVC or video
command of any kind. The console has no camera hardware and never consumes a video stream — the
gun does all CV internally and reports coordinates. The UVC interfaces therefore look like a
factory/bring-up leftover that shipped disabled.

Getting real frames out, if it is possible at all, would mean finding whatever enables the
sensor path. Two candidate routes, neither attempted:

1. UVC **extension-unit** (vendor XU) controls on interface 3. `GET_INFO`/`GET_CUR` queries are
   passive and safe to enumerate.
2. An undocumented sub-function beyond 7 on interface 2. **Not** worth blind-scanning — an
   unknown function code on a device whose firmware is field-flashable could hit something
   persistent or destructive. Derive it from the gun's own firmware first.

Note the gun's own firmware was never obtained. Everything in §6 came from the *console* image;
the gun MCU's code is a separate target (Tier 4) and is where a video-enable path would live.

## 8. What is still blocked, and why

**`ffmpeg` cannot open any camera from this shell**, including the built-in FaceTime camera, so
capture had to go through QuickTime Player instead (recorded to a file, then analysed offline).
The responsible process for TCC purposes is `/Applications/Claude.app`, which does declare
`NSCameraUsageDescription`; granting Camera to it appears to need the app restarted before a
child process inherits the grant. Not worth chasing — the QuickTime route works and the file
analysis is better evidence anyway.

**HID input reports read as empty.** All three interfaces open successfully and writes
work, but `hid_read_timeout` returns nothing on the digitizer, keyboard, or vendor interface
(outside of command replies). Two candidate explanations, not yet separated:

1. macOS has claimed the digitizer as a system pointing device and will not deliver duplicate
   input reports without **Input Monitoring** permission — the same class of problem as the
   camera.
2. The gun genuinely does not stream pointer reports until it has screen lock, i.e. the
   `In Range` bit is false because it is not aimed at a lit display.

The write path succeeding on the same interface makes (1) the more likely explanation for the
vendor interface at least.

---

## Open questions remaining

- Trigger-pull jitter: still not characterised. Needs input reports flowing (§8).
- Whether the gun streams pointer reports without screen lock, or only once `In Range` is true.
- Whether real video can be enabled over UVC at all, and if so by what (§7).
- What the MD5 handshake (sub-function 7) covers, and whether it gates pointing or only game
  entitlement.
- Whether calibration coefficients can be pushed from a non-Android host — the framing is
  known and writes work, so this is now a small experiment.
- Where exactly inside `data.unity3d` the System 22 ROM data sits.

## Next actions

1. Get input reports flowing, then log coordinate streams around trigger events to quantify the
   jitter and build the `uinput`/Raw Input bridge that latches the last stable coordinate. Gate
   it on the `In Range` bit. Aim the gun at a lit display first — that may be all it takes.
2. Passively enumerate UVC extension-unit controls on interface 3 to see whether a video-enable
   path is exposed. Read-only queries only.
3. Tier 4 (dump the gun's own MCU firmware) is now the higher-value target than the console.
   It holds the CV, the real coordinate pipeline, and whatever gates the camera.
4. Flashing an Ultimate image onto a Basic console is trivially possible and reversible (all
   three images are public and decryptable). The first-launch accessory check is the thing to
   actually test.
