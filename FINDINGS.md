# G'AIM'E — Findings, session 1 (2026-07-26)

Source: `GAIME_FWUpdate_V4.0.3` (public, unauthenticated download). Nothing was
flashed and the console was never opened. All results are from static analysis.

Tooling written this session lives in `tools/`. Outputs land in `work/` (gitignored).

```bash
python3 tools/gaime_decrypt.py <sku>.dat -o work      # GAIMEENC -> Allwinner .img
tools/unpack_all.sh work/<sku>.img <tag>              # .img -> super -> EROFS trees
python3 tools/gun_probe.py list                       # gun HID interfaces
swiftc -O -swift-version 5 -o work/gun_bridge tools/gun_bridge.swift
work/gun_bridge --log                                 # seize the digitizer (frees the cursor)
```

### Using the gun on macOS without wrecking the desktop

macOS matches interface 1 as a system pointing device, so the gun drives the cursor and its
tracking noise makes the machine unusable. `tools/gun_bridge.swift` seizes the digitizer
(`kIOHIDOptionsTypeSeizeDevice`), which stops macOS routing it anywhere, and can re-emit clean
mouse events only while a chosen app is frontmost:

```bash
work/gun_bridge --log                                    # seize + print reports
work/gun_bridge --block                                  # seize + swallow everything
work/gun_bridge --app RetroArch --require-in-range       # forward only to RetroArch
```

It needs **Input Monitoring** (to seize) and **Accessibility** (to post events) for the host
process. Start it before plugging the gun in — it waits for the device and grabs it on arrival,
so the cursor never gets hijacked. Seizing is also why HID reads returned nothing in §8: macOS
had the device and would not share it.

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

One corroborating detail: the vendor's own string descriptor for interface 4 (VideoStreaming)
reads **"Video Inactive"**. Read with care — in UVC, alt setting 0 of a streaming interface is
conventionally the zero-bandwidth "inactive" alt, and interface 4 does report
`bNumEndpoints = 0` at alt 0, so the string may just be labelling that. It is suggestive, not
proof. The test-pattern measurements above are the load-bearing evidence.

Note the gun's own firmware was never obtained. Everything in §6 came from the *console* image;
the gun MCU's code is a separate target (Tier 4) and is where a video-enable path would live.

## 7a. Can the gun's MCU be updated over USB? No visible path.

Asked directly, and the answer from every angle available without opening the gun is no.

**The gun exposes no update interface.** `bNumConfigurations = 1` — a single USB configuration,
no alternate config hiding anything. Its five interfaces are three HID (classes 3) and two Video
(class 14). There is **no DFU interface** (class 0xFE / subclass 0x01) and **no vendor-class
interface** (class 0xFF). Nothing to flash into.

**The console never updates the gun.** Two independent checks:

- No gun firmware blob exists anywhere in any SKU's image. Searching all of system, vendor and
  product for `*.bin`, `*fw*`, `*firmware*`, `*.hex`, `*.dfu`, `*gun*` turns up only stock
  Allwinner BSP leftovers (a `gslX680` touchscreen blob, `amp_dsp0.bin`, a whole unused face-id
  model set). Every large member of the GAIME APKs is accounted for as dex, resources, images or
  an MP4.
- No code references it. Grepping `GaimeService`, `GaimeCalibration` and the launcher for
  `bootloader`, `dfu`, `upgrade`, `updateFirmware`, `gunVersion` and similar returns **zero
  hits**. `Update.apk` is stock Allwinner OTA (`com.softwinner.update`) for the console's own
  system image, nothing to do with the gun.

The gun's version is reported only as `bcdDevice = 0x0419` and is independent of the console's
`V4.0.3` version space. Taken together, the gun's firmware looks **factory-programmed only**.

What this does *not* rule out, and what to look for once it is open:

- A bootloader entered by a **button/trigger combo held while plugging in**. Extremely common on
  this class of device and completely invisible from the descriptors. Cheap to test before
  opening anything: hold the trigger (and/or any recessed button) while connecting, then re-run
  `python3 tools/gun_probe.py list` and check whether the VID/PID or interface set changes.
- An undocumented **sub-function beyond 7** on interface 2 that jumps to a loader. Do not
  blind-scan this: an unknown function code on a device with a writable loader is exactly how a
  unit gets bricked.
- **A serial console or a SoC loader mode on the PCB.** See the correction below — this is the
  realistic route, but look for UART rather than SWD first.

### Correction: the gun is not a microcontroller

Earlier guidance here assumed a Cortex-M class MCU and pointed at SWD. That is wrong. Per the
vendor's own published specs (§9), **each gun runs Linux with 1 GB of RAM and a 1080p camera in
the barrel.** That is an application processor with external DRAM and its own boot medium, not an
MCU with internal flash. Practical consequences:

- **Look for UART before SWD.** A Linux SoC almost always leaves a serial console; two or three
  lone pads near the SoC with a ground nearby. 3.3 V, most likely 115200 8N1. That gets you a
  boot log naming the SoC, and quite possibly a root shell or an interruptible bootloader — far
  cheaper than any silicon-level attack.
- **There is a separate boot medium to find** — eMMC, NAND, or SPI-NOR. An SPI-NOR chip in an
  SOIC-8 can be read in place with a clip and a cheap programmer, which would be the fastest
  path to a full firmware image.
- **The SoC likely has its own USB loader** (an FEL-style ROM recovery mode, if it is another
  Allwinner part — the OSI page's `libcedarx`/`libcedarc` entries show they are an Allwinner
  house). That would be entered by shorting a test point or holding a button at power-on, and
  would appear as a *different* VID/PID. `tools/gun_snapshot.sh` is set up to catch exactly that.
- Readout protection is much less of a concern than it would be on an MCU; the risk shifts to
  whether the rootfs is signed/verified, which matters for *writing* but not for *dumping*.

Worth photographing carefully once open: the SoC, the camera module, the DRAM, any flash chip,
every test pad and the full silkscreen both sides. No public teardown exists (§9), so good board
photos are a genuine contribution regardless of what else comes out of it.

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

## 9. The public record (researched 2026-07-26)

Searched in English, Japanese (達成電器 / ガイム / 分解) and Chinese (达成电器 / 拆解 / 拆机)
across YouTube, Bilibili, Reddit, shmups.system11.org, arcade-projects.com, sindenwiki.org,
wiki.batocera.org and the retro press.

### There is no teardown. At all.

**Zero PCB photos, zero chip markings, zero disassembly guides, zero screw or clip
documentation, no iFixit page, no repair thread.** Every "internals" claim in circulation traces
back to vendor PR rather than to anyone who opened one. The USB descriptor data in §6 is already
more hardware detail than the entire public record contains, and the gun's `4.19`/`4.25` version
strings appear to be **unpublished anywhere** — original information.

Two near-misses worth knowing about so they aren't chased twice:

- *"Gaime LightGun and Console, Is it Worth Modding?"* (Vic_VP,
  <https://www.youtube.com/watch?v=za7GPY8yjHY>) — 16m39s, published 7 Nov 2025, i.e. **before
  retail units shipped**. Not a teardown; treat as speculation.
- The shmups thread (<https://shmups.system11.org/viewtopic.php?t=76854>, 43 posts) is entirely
  purchase and accuracy discussion. One member guesses the CV runs console-side; the PC evidence
  below contradicts that, and so does §1.

### Gun hardware — vendor-sourced, but it exists

RetroDodo's launch review is the only outlet that published a spec sheet
(<https://retrododo.com/a-day-with-gaime/>):

> Guns: **1080p camera inside the barrel, runs Linux, 1 GB RAM per gun.** Console: custom
> Android OS, 2 GB RAM, octa-core ARM Cortex-A55. Camera recessed inside the barrel to protect
> it. Cable non-removable; a replacement means buying a new gun (~£50–60).

Corroborating vendor language elsewhere: a "bespoke chipset" (Time Extension), and "a combination
of high-resolution cameras, **gyroscopes**, and AI chips"
(<https://lightgungamer.com/gaime-review-the-99-plug-play-lightgun-that-actually-works/>). The
gyroscope claim is unverified and does not appear in any HID descriptor on our unit.

**No source names a single chip.** Distrust anyone who claims otherwise.

Note one conflict with our own primary evidence: the console's factory U-Boot log reports
`DRAM: 512 MiB` (§1), while marketing says 2 GB. The boot log is the better source, though it
could plausibly come from a pre-production or differently-populated unit. Unresolved.

### Dashine is confirmed as the parent, and as the USB vendor

Strong corroboration for the `D:\Dashine\New Products\Lightgun\…` build path in §2:

- `USB\VID_2E2C = Dashine Electronics Co, Ltd` — <https://the-sz.com/products/usbid/index.php?v=0x2e2c>.
  Note this is the *only* public registry hit; 2E2C is absent from linux-usb.org's `usb.ids`.
- Tassei Denki KK (est. Nov 2021, Tokyo) is a **subsidiary of Dashine Electronics Group** — a
  HID/gamepad ODM operating since 2007, manufacturing in Huizhou and Shenzhen. <https://www.dashine.net/>
- **GAIME was first announced under the Dashine name at TGS 2024**, before the Bandai Namco
  licence was public — <https://www.gamespot.com/articles/time-crisis-is-coming-to-modern-tvs-through-an-ai-powered-light-gun-device/1100-6526692/>
- Retail listings still name Dashine as manufacturer of record.

Nothing connects "Dashine" to camera-module manufacturing, so the `Dashine UVC` string is just
the ODM's name stamped on a generic UVC bridge.

### The OSI page is the most useful public artifact

<https://www.mygaime.com/osi> (the HTML page lists more than the linked PDF). Load-bearing
entries:

- **`libcedarx` / `libcedarc`** — Allwinner's media framework and codec library
  (<https://linux-sunxi.org/CedarX>), alongside AOSP `libaaudio`/`libmedia`/`libgui`. Independent
  circumstantial confirmation of the Allwinner-on-Android stack in §1.
- **`onnxruntime` 1.19.0** and `opencv-python` 4.10 — **the on-device "AI" is an ONNX model**, not
  hand-written CV.
- **`torch` 2.4.0+cu118`, `torchvision`, `torch-tb-profiler`** — CUDA builds, i.e. their internal
  *training* pipeline leaked into the notice file.
- **`flutter_quad_annotator`** — a four-corner quadrilateral annotation widget.

Those last three together describe the whole pipeline: humans label screen quads in captured
frames, a model is trained, exported to ONNX, and inferred on device. Tassei Denki independently
described exactly this to Time Extension ("identifying regions that exhibit screen-like
features… determine the screen's boundaries and **vertices**"). Training-set size is quoted
inconsistently — 3,000 screens to Time Extension, "hundreds of thousands" to RetroDodo.

Also listed: `hidapi`, `openssl`, `dosfstools`, `box2d`, `openal`, Unity UI, and a full backend
stack. Plus **`electron-builder`/`electron-updater`/`sudo-prompt`** — see the correction below.

### The PC-as-light-gun reports, and the trigger jitter

Two independent primary sources, and both matter for Tier 2.

MP1st's review is the most detailed account in existence
(<https://mp1st.com/reviews/gaime-review-lightgun-fun-on-the-flatscreen>):

- Windows 11 names it **"GAIME v1" with a webcam icon**; the system cursor vanishes and tracks
  the gun "extremely erratically" — consistent with §6 and with why `gun_bridge` is needed.
- Button-to-keystroke map: **A = space, B = `b`, Coin = `c`, Start = `q`**. This is our keyboard
  interface (§6, interface 0) and saves a round of probing.
- Trigger acts as a mouse click; **"Windows saw it as a touch pointer when I moved it while the
  trigger was held"** — that is the digitizer interface asserting itself.
- The Recoil switch produces no host input (gun-local state only), and **the pedal is not
  detected by a PC at all**.
- Calibration is console-only, so bare-PC aim stays poor.

The trigger-pull jitter in the brief traces to one specific primary source — commenter #19
"benjaminer" on the Time Extension review (comments are JS-gated behind "Show Comments"):

> "I've plugged one of the guns into my laptop and behaves like as a mouse and **didn't need any
> calibration** … It seems that **pulling the trigger is part of what causes the inaccuracy** as
> I could see the mouse pointer jump around when I pulled the trigger."

Reproducible with the gun held still, per the same thread. VGC also reports someone running the
guns on PC **via a PS2 emulator with better accuracy than the G'AIM'E console itself**
(<https://www.videogameschronicle.com/review/gaime-light-gun-review-an-expensive-way-to-play-time-crisis-but-its-hiding-a-big-secret/>
— the headline's "big secret" *is* the USB-mouse behaviour).

"Gun runs Linux with 1 GB RAM" plus "usable absolute coordinates with zero calibration on a bare
laptop" independently confirms §6: **the vision runs gun-side.**

### Nobody has done Tier 2

No MAME, RetroArch, Batocera or Sinden integration exists anywhere — not in
wiki.batocera.org's light gun guide, not on sindenwiki.org, no GitHub project, no HID report
descriptor dump, no `uinput` bridge. The vendor HID page 0xFF00 (§6) is undocumented publicly.

### Correction to the brief (CLAUDE.md §3.5)

CLAUDE.md dismisses the pre-launch mobile-app update story as outdated. It is more tangled than
that. RetroDodo's **launch-day** review states updates require an Android or iOS app plugged into
the console, and the OSI page confirms both a real Flutter app *and* an Electron desktop app
(`electron-builder`, `electron-updater`, and `sudo-prompt` — that last one being the privilege
escalation for driver installation). The shipped V4.0.3 path is the Windows tool; the app route is
either parallel or abandoned, not nonexistent.

### No public gun-firmware update path either

Independently corroborates §7a. No DFU mode, no bootloader, no button combo, no separate gun
firmware download, and no gun version numbers documented anywhere. Only V4.0.3 (9 Mar 2026) is
public and it is explicitly a *console* release — the official post is titled "Firmware Update
V4.0.3 Available for the G'AIM'E TIME CRISIS **Mini-Console**"
(<https://www.mygaime.com/post/firmware-update-v4-0-3-available-for-the-g-aim-e-time-crisis-mini-console>).
Whether the console pushes anything to the guns is undocumented publicly; §7a shows it does not.

### Highest-value unexplored source

The **official Discord** (<https://discord.gg/MAhMpTZSsH>) is not indexed and was not readable by
the research pass. mygaime.com's FAQ points there for support and the site's own "community forum"
links 404, so it is very likely where gun firmware versions and any update mechanics are actually
discussed. Worth searching it for "firmware" before opening the grip. The site FAQ itself is
nearly empty — the "Product Specifics" tab is an unpopulated Wix tab with nothing behind it.

---

## Open questions remaining

- Trigger-pull jitter: not yet characterised on our unit, but now confirmed reproducible by an
  independent primary source (§9) with the gun held still. Quantifying it is the next real task.
- Whether the gun streams pointer reports without screen lock, or only once `In Range` is true.
- Whether real video can be enabled over UVC at all, and if so by what (§7).
- What the MD5 handshake (sub-function 7) covers, and whether it gates pointing or only game
  entitlement.
- Whether calibration coefficients can be pushed from a non-Android host. The framing is known
  and writes work, so this is a small experiment — and it is the thing that would make the
  console genuinely optional.
- The gun SoC's identity, its boot medium, and whether it has a UART console or a ROM loader.
  Nothing public exists (§9); this needs the teardown.
- The console DRAM conflict: factory boot log says 512 MiB, marketing says 2 GB (§1, §9).
- Where exactly inside `data.unity3d` the System 22 ROM data sits.

## Next actions

1. **Characterise the jitter.** Run `work/gun_bridge --log` aimed at a lit display and capture
   coordinate streams either side of trigger-down. The independent report in §9 says the pointer
   jumps on trigger pull with the gun stationary, so this should reproduce readily. Then build the
   latch-and-hold filter on top of the bridge, gated on `In Range`.
2. **Drive interface 2 for calibration.** Writes and acks already work (§6). Pushing calibration
   coefficients from macOS is the highest-leverage unproven step — it is what turns this into a
   general-purpose light gun rather than a console accessory. Nobody has done it (§9).
3. **Search the official Discord for "firmware"** before opening anything. It is unindexed and is
   the most likely place gun firmware versions and update mechanics are actually discussed (§9).
   Also try the button-combo-at-plug-in test with `tools/gun_snapshot.sh` — five minutes, and it
   would find a loader mode if one exists.
4. **Teardown.** Look for UART before SWD, and for a separate flash chip — the gun is a Linux SoC
   with 1 GB of RAM, not an MCU (§7a correction). No public teardown exists, so good board photos
   are worth publishing on their own merits.
5. Flashing an Ultimate image onto a Basic console is trivially possible and reversible. The
   first-launch accessory check is the thing to actually test.
6. Lower priority: the MAME/RetroArch side is completely undocumented for this device (§9). The
   button map from MP1st (`A`=space, `B`=b, Coin=c, Start=q) is a free head start on a `ctrlr`
   config once aiming is usable.
