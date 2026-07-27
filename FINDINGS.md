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
work/gun_bridge --log                    # seize + print reports
work/gun_bridge --block                  # seize + swallow everything
work/gun_bridge --app RetroArch          # forward only while RetroArch is frontmost
```

It needs **Input Monitoring** (to seize) and **Accessibility** (to post events) for the host
process. Start it before plugging the gun in — it waits for the device and grabs it on arrival,
so the cursor never gets hijacked. **Seize is confirmed working on hardware.** It is also why
HID reads returned nothing in §8: macOS had the device open and would not share it.

### Measured behaviour of the pointer stream

Captured with `--log` while the gun sat on a desk, not aimed at a display:

| | |
|---|---|
| Report rate | **~278 Hz** in one 10 s capture, **~28 Hz** in another — highly variable |
| X range | 99 … 9900 (full span) |
| Y range | 99 … 9900 (full span) |
| Mean per-report jump | \|dX\| 93.5, \|dY\| 86.6 counts |
| Worst single jump | 4841 counts — about half the screen in one report |
| `in_range` | **set in 2781 / 2781 reports**, while producing the above |

Two things matter here. First, the declared logical range is 0..10000 but the gun clamps to
**99..9900**, so that is what should be mapped to screen coordinates. Second, **the `in_range`
bit is asserted continuously even while the output is garbage**, so it is useless as a validity
gate — an earlier guess that it would make a good filter was wrong.

With no valid screen lock the gun does not jitter gently around a point; it sweeps the entire
coordinate space. For an *absolute* pointer at up to 278 Hz that means the cursor is teleported
hundreds of times a second and the desktop becomes unusable, which is exactly the reported
symptom. Hence rejecting outliers geometrically: a median-of-5 spike filter plus a max-jump gate,
with a run of 6 consecutive "outliers" accepted anyway so genuine fast aiming still tracks. On
resting garbage that rejects ~16% of reports; the thresholds still need tuning against data from
a gun actually aimed at a display.

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

### FEL mode confirmed on hardware

The console was observed in FEL mode as **`0x1f3a:0xefe8`** (USB full speed, 300 mA) — the
standard Allwinner FEL device ID that `sunxi-fel` targets, *not* the `0x1000` efex PID in
`LiveSuit.cfg`. A read-only `sunxi-fel version` returned:

```
AWUSBFEX soc=00001890(A523) 00000001 ver=0001 44 08 scratchpad=00061500
```

**`soc = 0x1890` (A523 family)** independently confirms the `sun55iw3` identification from the
factory boot log in §1, this time from the live device. It also means the documented entry
sequence (hold the pinhole Programming button, insert USB-C into the power port) genuinely lands
in the SoC's ROM loader.

Practical significance: FEL is a **read/write** loader reachable over plain USB with `sunxi-tools`,
no soldering and no vendor software. It can read and write DRAM and drive the boot medium, so it is
both the easiest way to dump the console and the easiest way to brick it. Build it with:

```bash
git clone --depth 1 https://github.com/linux-sunxi/sunxi-tools && cd sunxi-tools
PKG_CONFIG_PATH="$(brew --prefix libusb)/lib/pkgconfig" make sunxi-fel
```

Note this is the **console**, not the gun. The gun's main IC is a ~96-pin QFN (§10) and cannot be
an A523, which is a large BGA octa-core Cortex-A55.

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

## 10. Modifying the firmware — ADB is reachable, and the boot chain is unverified

The console's boot chain performs **no verification at any stage**, so a modified image is
accepted as readily as a stock one:

| Check | State |
|---|---|
| Secure boot fuse | `secure enable bit: 0` in the factory U-Boot log — not fused |
| AVB | vbmeta flags `0x00000000`, and the word "avb" appears **zero** times in the whole factory boot log |
| dm-verity | fstab has **no `avb=` and no `verify` flag** on system, vendor, product or the dlkm partitions |
| Kernel cmdline | no `androidboot.vbmeta.*`, no `dm=`, no `verifiedbootstate` |

The only integrity check anywhere is the `V*.fex` members, and those are trivial: **a 32-bit
little-endian sum of the partition's 32-bit words**. Confirmed against `vbmeta.fex`, `boot.fex`,
`dtbo.fex` and `super.fex` — all four match their stored `V*` value exactly. The flasher checks
it, so it has to be recomputed after any edit, but it is not a cryptographic barrier.

### Why adbd is off, precisely

`adbd` already ships in the image (the stock `com.android.adbd` APEX) — nothing needs adding.
It is off for two independent reasons:

1. `ro.debuggable=0`, `ro.adb.secure=1`, `ro.secure=1` in `/system/build.prop`.
2. Every `start adbd` trigger in `init.usb.rc` / `init.usb.configfs.rc` is gated on
   `sys.usb.configfs` being `0` or `1`, but the vendor HAL sets it to **`2`** — so on this
   device *no init trigger can ever start adbd*. Composition is delegated to
   `/vendor/bin/hw/android.hardware.usb.gadget@1.2-service.aw`, which is driven by the
   framework. In Kiosk mode there is no Settings UI to ask it.

That HAL does implement the path — it contains `setCurrentUsbFunctions Adb`, `ffs.adb`,
`/dev/usb-ffs/adb/ep1`, `/sys/class/udc/` and writes `/config/usb_gadget/g1/UDC`. The vendor rc
already creates `functions/ffs.adb` and mounts functionfs at boot. So the machinery is all
present and merely never asked to run.

The rear USB-C port is wired as a **device** port (`usb_port_type = <0x00>` on `usbc0`,
`udc-controller@4100000`, `allwinner,sunxi-udc`), which is why FEL works there — and it means
ADB-over-USB is physically possible on the same port. FEL flashing already runs the console off
PC USB power, so powering it from a host is proven.

### The patch

`tools/gaime_patch.py`. Every edit is **byte-length preserving**, which is the whole trick:
`/system/build.prop` happens to be stored *uncompressed* in the system EROFS, so it can be
edited in place with no filesystem rebuild, no re-sparsing and no IMAGEWTY re-layout. That
matters a lot — rebuilding the EROFS off-device would lose every SELinux label and every
uid/gid and produce an unbootable system.

```
ro.secure=1     -> ro.secure=0
ro.adb.secure=1 -> ro.adb.secure=0   (both occurrences)
ro.debuggable=0 -> ro.debuggable=1
'####…' (36 B)  -> 'persist.sys.usb.config=adb\n#########'   (also exactly 36 B)
```

The last one is the interesting one: a 36-byte comment line is overwritten with a real property
plus a shorter comment, so a property is *added* without changing a single offset. Vsuper is
then recomputed.

Bonus from `ro.debuggable=1`: the image contains `on property:ro.debuggable=1` →
`service console /system/bin/sh`, so this also spawns a **root shell on the debug UART**
(PB09/PB10, 115200) for anyone who opens the case.

### Verification performed

- Patched image unpacks cleanly through the full chain (IMAGEWTY → sparse → LP → EROFS).
- `build.prop` reads back exactly as intended.
- **Exactly one file differs out of 3251** in the system partition: `system/build.prop`.
- `tools/gaime_encrypt.py` re-encrypting the *unmodified* image with the original nonce
  reproduces the stock `d8a21f90.dat` **byte for byte** (same SHA-256) — proof the container
  is fully understood and that the vendor updater will accept our output.
- Patched `.dat` decrypts back to the patched `.img` bit-exactly.

```bash
python3 tools/gaime_decrypt.py <sku>.dat -o work
python3 tools/gaime_patch.py   work/<sku>.img -o work/<sku>_adb.img
python3 tools/gaime_encrypt.py work/<sku>_adb.img work/<sku>_adb.dat
```

Then replace the matching `.dat` in `GAIMEUpdater_v4.0.3/GAIME_Tools/Firmware/4.0.3/` and flash
with the stock Windows updater — filenames and sizes are unchanged, so it needs no other edits.

### What is NOT verified

**None of this has been flashed.** Specifically unproven:

- ~~That `ro.debuggable=1` + `persist.sys.usb.config=adb` is enough to make the framework ask
  the gadget HAL for adb.~~ **Disproved — see §11.** Decompiling the *device's own*
  `SettingsProvider` shows `loadGlobalSettings` never seeds `adb_enabled` at all, so
  `ro.debuggable` does not switch the framework path on. The patched 4.0.3 `.dat` in §10 would
  therefore have flashed and booted cleanly and produced no adb. §11 has the version that
  actually works.
- That `Vsuper` is the *only* thing the flasher validates.
- SELinux stays enforcing (`user` build compiles out `androidboot.selinux=permissive`), so
  `adb shell` should work in the `shell` domain but `adb root` may not — the `su` domain is
  typically absent from user-build policy.

**Recovery:** flashing is FEL via the SoC boot ROM, which lives in silicon and is entered with
the pinhole button, so a bad system image is recoverable rather than a brick. All three stock
`.dat` files are public and re-flashable with the same tool.

### SSH

Not worth doing in the image. Adding an `sshd`/dropbear binary means new files, which means a
real EROFS rebuild with correct SELinux contexts — the one thing this patch carefully avoids.
There is also **no network hardware** on the console. The far better route is to get adb first,
then `adb push` a static dropbear into `/data` (writable, no rebuild) and reach it over USB
networking — the vendor rc already creates an `ncm.gs6` (USB ethernet) gadget function.

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

---

## 11. Getting a shell on the installed firmware (patch planned, not yet written)

§10's plan was wrong in one load-bearing way. This section supersedes it.

### Why `ro.debuggable=1` is not enough

Decompiling the **device's own** `SettingsProvider` (from the flash dump, not the download)
shows `loadGlobalSettings` never seeds `adb_enabled`. So the framework path — the one the
vendor's gadget HAL listens to — stays off regardless of `ro.debuggable`. Checking this
against real code rather than assuming AOSP behaviour is the only reason it was caught.

Two further blockers, both confirmed against the dump:

- Every `start adbd` trigger in `init.usb.rc` / `init.usb.configfs.rc` requires
  `sys.usb.configfs` to be `0` or `1`. The vendor HAL sets it to **`2`**, so none can fire.
- **Nothing in this build sets `sys.usb.controller`** — it is only ever read, and there is no
  `ro.boot.usbcontroller` → `sys.usb.controller` mapping in `init.rc`. Without it the
  `write /config/usb_gadget/g1/UDC ${sys.usb.controller}` step writes an empty string and the
  gadget never binds.

### The patch

Six edits, all byte-length preserving, all inside `super`. `build.prop` and the vendor
`.rc` both happen to be stored **uncompressed** in EROFS, so no filesystem rebuild is needed —
which matters, because rebuilding EROFS off-device would destroy every SELinux label.

| Edit | Purpose |
|---|---|
| `setprop sys.usb.configfs 2` → `1` | lets the stock adb triggers fire |
| `persist.sys.usb.config=adb` (into a `####` comment line) | sets `sys.usb.config=adb` at boot |
| `sys.usb.controller=sunxi_usb_udc` (into a `####` comment line) | so the gadget can bind the UDC |
| `ro.adb.secure=1` → `0` (×2) | no auth key needed |
| `ro.debuggable=0` → `1` | root shell; also spawns a root console on the debug UART |

Properties are *added* by overwriting 36-byte `####################################` comment
lines with a real property plus a shorter comment — same 36 bytes, so every offset in the
image is unchanged.

`tools/gaime_shell_patch.py` computes this against a dump of the device's own super and emits
a sector-level plan plus the original bytes of every touched sector. Result:

```
3 sector(s) to write (1536 bytes):
  super sector    710825 -> FES sector  1301673  (63 bytes differ)
  super sector    710831 -> FES sector  1301679  ( 1 byte  differs)
  super sector   1611180 -> FES sector  2202028  ( 1 byte  differs)
```

### The writer

`tools/gaime_fes_write.py` is the only tool here that writes to the device, and is scoped hard:

- the sole write opcode is `FES_DOWNLOAD` (0x206); `FES_FORCE_ERASE` (0x220) and
  `FES_FORCE_ERASE_KEY` (0x221) are not defined in the file at all;
- the `mbr` (0x7F01) and `erase` (0x7F04) tags are explicitly refused — the mbr tag makes the
  device erase;
- only whole 512-byte sectors named in the plan are written; any other payload size is refused;
- before writing, each sector must currently match either the recorded original or the
  recorded patched content — anything else aborts rather than overwriting the unexpected;
- every sector is read back and compared after writing, aborting on the first mismatch;
- `revert` restores the originals, `verify` reports which state each sector is in.

### Residual uncertainty

`sunxi_usb_udc` is the best reading of the UDC name (the string in the kernel; the DT node is
`udc-controller@4100000`). Forcing `configfs=1` may also contend with the vendor HAL, which
expects to own gadget composition. If either is wrong, adb simply will not appear — nothing
breaks, and `revert` puts all three sectors back byte-exactly.

---

## 10. Gun PCB — first teardown (photo, 2026-07-26)

No public teardown of this device existed before this (§9), so everything here is new. Readings
below are from a single top-side photo at moderate resolution; items marked *(confirm)* need a
close-up before being treated as fact.

### Board identification

| | |
|---|---|
| Main board | **`LBQ-1585-C-V1.1`**, dated **`2025.7.23`** |
| Trigger/grip daughterboard | **`LBQ-1585-D-V1.1`**, same date, carries `FPC1` |
| Extra marking | `D1 2535` near the left edge |

**The board number embeds the USB product ID.** PID `0x0631` = **1585** decimal, and the boards
are `LBQ-`**`1585`**`-C` and `-D`. So `LBQ-1585` is the internal project number for the gun, and
the USB PID was assigned from it. Useful for searching Chinese supplier and FCC databases.

### The important find: J3 is a UART header — CONFIRMED

Along the bottom edge of the main board, **`J3`: four unpopulated plated through-holes,
silkscreened `GND` / `TX` / `RX` / `V3.3` in that order.** Confirmed at high magnification
(`docs/photos/gun-front-closeup-soc-and-j3-uart.jpg`), no longer provisional.

On the **reverse** side of the same holes, the outermost pad is **square while the other three are
round** — the standard pin-1 marker. Use it to orient, but still confirm `GND` with a continuity
check to the USB shield or a ground plane before connecting anything.

This is the serial console predicted in §7a, and after the flash finding below it is now clearly
the *best* route in, not merely the cheapest.

### Other legible features

- **Power rails called out as test points: `1.8V`** (top left) and what reads as a **~`0.9V`**
  rail near `U9` *(confirm)*. A sub-1V core rail implies an **application-class SoC**, which is
  consistent with the vendor's "runs Linux, 1 GB RAM" claim (§9) and inconsistent with a
  microcontroller.
- **Camera on a separate module** at the muzzle end — a barrel-mounted lens assembly on a ribbon
  into a white FPC connector near `U5`. The sensor is therefore a discrete, inspectable,
  potentially replaceable part rather than being on the main PCB.
- **USB connector**: white multi-pin connector mid-board with `GND` / `D+` / `D-` / `VBUS`
  silkscreen. This is where the captive cable lands — note the cable is non-removable from the
  outside (§9), but it is evidently connectorised *internally*.
- **`CN1`** at top left with red/black wires and **`Motor`** silkscreen beside it — the recoil
  actuator. A second small connector sits below it.
- `Y1` crystal near centre-right; inductors `L1`, `L3`, `L4`; a small regulator at `U4`; three blue
  tactile switches (`SW2`, `SW6` and one more); LEDs `D5`, `D6`, `D10`, `D11`, `D12`; a 2D
  datamatrix sticker mid-board; a dense field of test points `T1`–`T36`.

### The SoC (`U8`) is deliberately unmarked

The large central IC is a **QFN/LGA package with roughly 24 pads per side (~96 pins), and its top
is completely blank** — no laser etch, no logo, nothing, at full magnification
(`docs/photos/gun-front-closeup-soc-and-j3-uart.jpg`). That is a house-marked or unmarked part.

**Consequence: the SoC cannot be identified from the package.** It has to come from the UART boot
log. That single fact makes J3 the whole ballgame.

### The boot flash: GigaDevice SPI NAND at `U6`

An 8-pad leadless package near the camera end, marked:

```
GigaDevice
[?]J2352
[?]F1G[??]UEY1G      <- partly hidden under orange QC paint
ULB400
```

`GigaDevice` is unambiguous. The `…UEY1G` suffix and the `F1G` fragment point to the
**`GD5F1G…` family: 1 Gbit (128 MiB) SPI NAND, 1.8 V, WSON-8**. The `1.8V` rail called out
elsewhere on the board is consistent with a 1.8 V part. `J2352` reads as a 2023-week-52 date code
and `ULB400` as a lot code. The exact suffix is obscured — **isopropyl should lift the QC paint and
settle it**, and that is worth doing before ordering any tooling.

### Correction: this changes the flash-dump plan

§7a suggested "an SPI-NOR chip in an SOIC-8 can be read in place with a clip." Both halves of that
are now wrong for this board:

- It is **NAND, not NOR**. A bare CH341A and `flashrom` will not read it — flashrom does not do
  SPI NAND. You need tooling that speaks SPI NAND with GD5F support.
- It is **WSON-8, not SOIC-8**. The pads are underneath the package, so **a SOIC clip cannot
  attach**. An in-place read would mean a WSON test socket, and getting there means hot-air
  removal.

So the practical order is inverted from what §7a implied: **get UART, interrupt the bootloader or
reach a shell, and dump the NAND in-circuit through the SoC** (`/proc/mtd`, `nanddump`, or `dd`
from `/dev/mtdblock*`). Desoldering becomes the fallback, not the first move.

### The back of the main board is essentially bare

`docs/photos/gun-mainboard-back.jpg`: two tactile switches (`SW1` and one more), a handful of
0402-class passives (`R6`, `R9`, `R21`, `R23`, `C2`, `C13`, `C39`, `C40`, `D2`), mounting holes
`M6`–`M9`, an EMI/ground pad area behind the camera FPC connector, the reverse of `J3`, and the
reverse of the USB connector's through-holes. **No DRAM. No second flash. No debug header beyond
J3.**

Combined with the front, that settles §7a's open question: the GigaDevice NAND is the *only*
external memory, so the **DRAM must be stacked in-package with the unmarked SoC**. A ~1 GB SiP with
in-package DDR and a separate 128 MiB SPI NAND for storage is a coherent, conventional design for a
Linux-class vision part, and matches the vendor's published spec (§9).

Board outline measures roughly **90 × 45 mm** against the cutting mat.

### Next steps on the hardware

**UART first — this is the high-value, low-risk step.** You need a **USB-to-TTL serial adapter**
(sold as a "USB-UART bridge" or "FTDI cable"). CP2102, FT232RL and CH340 all work on current macOS
without installing anything.

**Verified working on hardware.** A red `CP2102 MODULES / USB TO TTL` board is a **genuine
Silicon Labs CP2102** — macOS enumerates it as `0x10c4:0xea60`, "CP2102 USB to UART Bridge
Controller", Silicon Labs, serial `0001`, 100 mA, and creates `/dev/cu.usbserial-0001` with no
driver install. `stty` configures it fine.

*(An earlier note here claimed this board was a mislabelled CH340. That was wrong — a `0x1a86:0x7523`
CH340 was separately present on the bus at the time and got conflated with it. Both work; check
`system_profiler SPUSBDataType` if you have several adapters around.)*

**Two macOS gotchas worth knowing before you waste an evening:**

1. **termios settings evaporate when the port closes.** Running `stty -f /dev/cu.X 115200` and then
   `cat /dev/cu.X` as two separate processes silently reverts to **9600 baud** — verified: a re-open
   right after setting 115200 reports `speed 9600 baud`. The port must be held open on a file
   descriptor across both the `stty` and the read. `tools/uart_capture.sh` does this; a naive
   `stty && cat` one-liner does not, and will hand you garbage that looks like a wiring fault.
2. **A plain CP2102 tops out at 1 Mbaud.** The scan confirms this: `1500000` comes back
   "unsupported by this adapter" while 921600 and below configure cleanly. If the gun's console
   turns out to run at 1.5 Mbaud you need a CP2102N, FT232H or CH343.

**Logic levels.** A CP2102 idles its TX/RX at **3.3 V**, which is exactly what `J3` advertises, so
the board in hand is already correct. Many CH340 boards instead run from USB 5 V and idle at 5 V, so
if you swap adapters, re-check. For **read-only** capture none of this matters at all:
the gun drives the line and the adapter only listens, and a 3.3 V signal is comfortably above a
5 V-tolerant input's logic-high threshold. It matters only if the adapter's TXD is ever connected to
the gun's RX. Before doing that, measure TXD to GND while idle — ~3.3 V is fine, ~5 V needs a level
shifter (or at minimum a series resistor and the knowledge that the pin is being over-driven). If
the board has a 5V/3V3 jumper, set it to 3.3 V.

**Two wires are enough to read**, and reading is where all the value is:

- `J3 GND` → adapter `GND`
- `J3 TX` → adapter `RX`  (the data lines cross)

Add `J3 RX` ← adapter `TX` only when you actually want to type at the bootloader. Leaving it off
until then makes the setup **read-only and incapable of damaging anything**, which also sidesteps a
real risk: the board has a 1.8 V rail and 1.8 V flash, so if the SoC's I/O turns out to be 1.8 V
rather than the 3.3 V that `J3` advertises, a 3.3 V TX could over-drive its RX pin. The boot log
will tell you which world you are in before you commit.

- **Leave `V3.3` unconnected.** The gun is powered from its own USB cable; feeding 3.3 V in from
  the adapter risks back-powering a rail that is already driven.
- `tools/uart_capture.sh` handles the host side with no dependencies — `scan` tries the common baud
  rates and scores each by how much printable text comes back, then `read <baud> <file>` captures.
- Start at **115200 8N1**. If that produces garbage, try 921600 and 1500000 (Allwinner-family
  parts commonly use both).
- Capture from a *cold* start: attach the adapter, open the terminal, then plug the gun's USB in —
  the boot log is the payload, and it should name the SoC outright.
- Watch for a bootloader autoboot countdown that can be interrupted.
- Once there is a shell or a bootloader prompt, dump the NAND in-circuit — that is now the cheapest
  path to the firmware image, given the WSON-8 SPI NAND (above).

### Photos

Stripped, upright copies live in `docs/photos/`. **The raw camera originals carried GPS EXIF** —
precise coordinates — and are gitignored (`docs/photos/IMG_*.jpeg`) rather than committed. Anything
published from here should come from the stripped `.jpg` copies.

Close-ups still wanted: the camera module's own markings (it sits behind the barrel assembly, and
the FPC itself is shielded and unmarked), `U5` and `U9`, and the GigaDevice part **after cleaning
off the orange paint**. The `J3` silkscreen, the SoC package and the reverse of the main board are
all now covered and need no re-shoot. The grip daughterboard `LBQ-1585-D` has not been photographed
on either side.

## 12. There is no console feedback channel over USB (dead end, recorded)

Tested on hardware: `FES_GET_MSG` (0x204) **is not implemented in this U-Boot**. The FES
handler table contains exactly these commands and no others:

```
fes_down  fes_flash_set_off  fes_flash_set_on  fes_flash_size_probe  fes_force_erase
fes_force_erase_key  fes_memset  fes_pmu  fes_query_info  fes_query_secure
fes_query_storage  fes_run  fes_tool_mode  fes_trans  fes_unseqmem_read
fes_unseqmem_write  fes_up  fes_verify  fes_verify_status  fes_verify_value
```

`FES_INFO` (0x203) returns `csw_status=255` and wedges the endpoint until a replug.

So **U-Boot's console output cannot be retrieved over USB** — it goes to the UART only.
That closes the idea of using FES as a diagnostic channel, and it is why four flash patches
produced no observable result: there was never any way to see what the device did with them.

`FES_RUN` (0x202) does execute code at an address, so booting modified code from RAM
(stub → `run_command("bootm …")`) remains possible. But it would be built and debugged with
no output at all, verifiable only by whether the console visibly boots.

**Conclusion: the debug UART (PB09 TX / PB10 RX / GND, 115200) is the only feedback channel
this device has.** `console=ttyAS0,115200` is already in the bootargs, and `ro.debuggable=1`
is already written to flash, so `service console /system/bin/sh` should give a root shell the
moment a serial adapter is attached — the shell and the diagnostics in one step.

## 13. ADB over USB: five patches, still no enumeration — stopping here

All of the following are on flash and read-back verified on the device:

```
persist.sys.usb0device=1                     rear port into device mode
setprop sys.usb.configfs 2 -> 1              lets the stock start-adbd triggers fire
persist.sys.usb.config=adb                   selects the adb function at boot
sys.usb.controller=4100000.udc-controller    UDC to bind (corrected from sunxi_usb_udc)
ro.adb.secure=1 -> 0, ro.debuggable=0 -> 1   no auth prompt, root shell
```

After a normal boot the console still does not enumerate at all — not as adb, not as
anything. It only ever appears on USB while the pinhole is held (BROM FEL).

**What is nonetheless established.** Replacing the U-Boot boot logo worked and is visible on
the TV, which proves flash writes land *and* are read by a real boot. So these properties are
genuinely present and being consumed; the failure is somewhere in the Android USB gadget path,
not in getting bytes onto the device.

**Remaining unknowns, none resolvable without a console:**

1. Whether a `persist.` property set from `build.prop` actually fires an `on property:` init
   trigger during early boot — if not, the device-mode switch never runs.
2. Whether `sunxi_usb_udc.ko` (a vendor_boot ramdisk module) loads at all.
3. Whether forcing `configfs=1` contends with the vendor gadget HAL, which expects to own
   composition and sets 2 itself.
4. Whether `4100000.udc-controller` is the actual entry in `/sys/class/udc` — derived from
   Linux's DT naming rule, never observed.

Each needs one line of shell to settle and cannot be inferred from the images. Five blind
attempts is enough; **the debug UART is the only remaining route** (PB09 TX / PB10 RX / GND,
115200). `console=ttyAS0,115200` is already in the bootargs and `ro.debuggable=1` is already
applied, so `service console /system/bin/sh` should offer a root shell as soon as a serial
adapter is attached — the diagnosis and the shell in the same step.

## 14. Console teardown — the debug UART is a labelled 3-pin header

Board opened 2026-07-26. No public teardown of this device existed before this.

```
LBQ-1585-A-V1.1      2025-7-23
```

**Component side.** Allwinner A523 under a large black pin-fin heatsink; eMMC in the
package immediately right of it (silkscreened `EMMC`). USB-C at top left silkscreened
**`POWIN`** — this is the power/FEL port we have been driving. HDMI is `J1`. `SW2` is
silkscreened **`AP-RESET`**. `UP1` is a ~20-pin IC on the left (PMIC, consistent with the
AXP2202 in the boot log), with `UP5`/`UP8` smaller regulators and crystal `Y2`.

Three unpopulated headers along the right edge, all clearly labelled:

| Header | Pins | Notes |
|---|---|---|
| **`J2`** | `GND` · `TX` · `RX` | **the debug UART** — through-holes, no fine-pitch soldering |
| `J3` | `+` · `TDI` · `TMS` · `TCK` · `TDO` · `GND` | full **JTAG** |
| `J4` | `GND` · `GND` · `GND` | extra grounds |

**Solder side.** `SW1` is silkscreened **`FEL`** — the pinhole programming button, named for
exactly what it does. `U2` is the FFC connector to the front panel (the gun USB-C ports).
Test points `T1`–`T18`, `T35`/`T36` beside SW1, and many `CP*` pads.

### Why this matters

§12 established that FES exposes no console output, and §13 stopped after five blind patches
precisely because nothing could be observed. `J2` removes that limitation entirely, and it is
a plain 3-pin 0.1" header rather than pads that need microscope work.

`console=ttyAS0,115200` is already in the bootargs and `ro.debuggable=1` is already written to
flash, so `service console /system/bin/sh` should present a **root shell** as soon as an
adapter is attached — diagnosis and shell in one step. That settles all four open unknowns
from §13 with about four commands:

```
cat /proc/modules | grep udc          # does sunxi_usb_udc.ko load at all?
ls /sys/class/udc                     # the real UDC name
getprop | grep -E 'usb|debuggable'    # did our properties actually apply?
dmesg | grep -iE 'udc|gadget|usbc0'   # what the gadget is doing
```

### Wiring, and one hardware caution

Cross TX and RX; leave the adapter's power pin disconnected — the board is self-powered:

```
adapter GND  ->  J2 GND
adapter RX   ->  J2 TX
adapter TX   ->  J2 RX      (omit for a safe receive-only capture)
115200 8N1, no flow control
```

**The A523's UART pins are 3.3 V.** A 5 V TTL adapter driving `J2 RX` can damage the SoC.
Set the adapter to 3.3 V, or — if in any doubt — connect only `GND` and `J2 TX` first. That is
receive-only, cannot damage anything, and still yields the full boot log, which is most of the
diagnostic value. Add the TX wire afterwards for an interactive shell.

### UART confirmed working on J2

First capture off header `J2` at 115200 8N1, receive-only (adapter `RXD` ← `J2 TX`, grounds
common, both adapter power pins left disconnected — on a CP2102 board `3V3` and `+5V` are
power *outputs*, not a logic-level selector, and the CP2102's own TX is 3.3 V so it is safe
against the A523 directly).

```
[143]HELLO! BOOT0 is starting!      BOOT0 commit : 1cbb5ea8b3
[160]PMU: AXP2202                   [165]PMU: AXP1530
[286]enable_jtag
[349][mmc]: MMC 5.1                 [357][mmc]: 59640 MB
[377]DRAM CLK =1200 MHZ             DRAM Type =8 (LPDDR4)
[550]Jump to second Boot.
NOTICE:  BL31: v2.5(debug):55b180a27, Built : 11:09:52, Sep 18 2023
NOTICE:  [SCP] :sunxi-arisc driver is starting
```

Three things this settles:

- **`enable_jtag` is printed by BOOT0**, so the `J3` JTAG header is live rather than fused off.
- **59640 MB** independently corroborates the 58.24 GiB eMMC measured over FES (§ dump).
- The boot chain is BOOT0 → **BL31 (ARM Trusted Firmware v2.5)** → SCP/arisc → U-Boot, which is
  why a bare `u-boot.fex` is only part of the story and `boot_package.fex` exists.

A plain `cat /dev/cu.*` truncated the log exactly at the U-Boot handoff — the process exits on
the first hiccup. `tools/uart_watch.sh` reopens and appends instead, and keeps the macOS quirk
handled: termios on `/dev/cu.*` reverts the moment the last fd closes, so `stty` and the read
must share one descriptor or the port silently drops to 9600.

**Note:** the `SW1`/FEL button snapped off during disassembly. Not fatal — it is a momentary
switch, so briefly shorting its pads (or the adjacent `T35`/`T36` test points) does the same
thing. The UART is in any case the better access path for everything except writing flash.

## 15. ADB working, and our own app running on the console

```
$ adb devices
List of devices attached
<adb serial redacted>     device

$ adb shell getprop ro.product.model
A527 PRO
```

The adb serial is derived from the chip SID captured over FEL much earlier
(`<device SID redacted>`), so it is unmistakably this unit.

### What actually blocked it

Five patches were applied blind over several rounds and none produced enumeration. The
serial console found the reason in one `logcat`:

```
avc: denied { setcurrent } for scontext=u:r:adbd:s0 tcontext=u:r:adbd:s0 permissive=0
adbd: main.cpp:162] Could not set SELinux context
```

**`ro.secure=0` was the thing breaking adb.** With `ro.secure` clear, `should_drop_privileges()`
returns false, so adbd tries to stay root and calls `selinux_android_setcon(u:r:su:s0)`. A
`user` build's policy contains no such transition, the kernel denies `setcurrent`, and adbd
`LOG(FATAL)`s — restarting every five seconds forever. The patch intended to *loosen* security
is precisely what stopped adb running. Everything else had been correct all along: the UDC was
present as `4100000.udc-controller` (the name derived from Linux's DT naming rule was right),
functionfs was mounted, and all five properties had applied.

`service.adb.root` is not read-only, so `setprop service.adb.root 0` forces the drop at runtime
and adbd goes from `restarting` to `running` without touching flash.

### Our app on the device

```bash
adb install -r -g apps/gaime-hello/out/gaime-hello.apk
adb shell appops set nu.hyperworks.gaimehello SYSTEM_ALERT_WINDOW allow
adb shell am start -n nu.hyperworks.gaimehello/.HelloActivity
adb exec-out screencap -p > work/screen.png
```

Confirmed on screen. The app installs to `/data`, not the firmware, so it cannot affect boot
and `adb uninstall` removes it completely.

### Still to do

`service.adb.root` is runtime-only and does not survive a reboot, so it must be re-applied over
the serial console each boot. The permanent fix is a **one-byte revert of `ro.secure=0` back to
`1`** in `build.prop`, keeping `ro.debuggable=1` so the serial console service stays. That needs
FEL; the `SW1` button snapped off during disassembly but it is a momentary switch, so shorting
its pads (or `T35`/`T36` beside it) works.

Kernel, for the record: `Linux 5.15.119`, built `root@dashine-namco`, Fri Sep 12 2025,
`Machine model: sun55iw3`, CPU `0x412fd050` (Cortex-A55).

## 16. Fastboot is reachable in software (but is the wrong tool for a one-byte fix)

`adb reboot bootloader` lands in U-Boot's fastboot loop. The gadget appears as
**`1f3a:1010` "sunxi"**, serial `<adb serial redacted>` — the same serial adb reports, derived
from the chip SID. U-Boot has the full implementation: `Android Fastboot`,
`fastboot - enter USB Fastboot protocol`, `reboot-fastboot`, `fastboot oem`, lock/unlock
flags, and a `fastbootlogo.bmp` that is present in `bootloader_a`.

So there **is** a software route into a flashing mode — no FEL, no shorting pads. Two caveats:

- Google's `fastboot` will not talk to it. Modern platform-tools matches on the USB interface
  class/subclass/protocol (`0xff/0x42/0x03`) and dropped the `-i <vid>` override; Allwinner's
  gadget does not advertise those. `tools/fastboot_client.py` speaks the protocol directly, but
  currently fails at `libusb_get_active_config_descriptor` on this device — unfinished.
- Even working, fastboot flashes whole partitions. The pending fix is **one byte inside
  `super`**, so this route would mean pushing 3.5 GB to change it, against one 512-byte sector
  over FES.

Fastboot is therefore the right tool for writing a *whole rebuilt image* later, and the wrong
one for this. Recorded because the software route into it is genuinely useful to know.

**Note:** the console is left sitting in fastboot after `adb reboot bootloader`; it does not
print to the UART in that mode. Power-cycling returns it to Android.

## 17. The missing mouse cursor — vendor-blanked-artwork theory disproved

A USB mouse works on the console (first front port only — `usbc1` is EHCI/OHCI, `usbc2` is
dwc3/xHCI with `aw,vbus-shared-quirk`, so the two front ports are not equivalent). Motion
tracks and clicks land where aimed. **No arrow is ever drawn.**

The natural theory was that the vendor blanked the pointer artwork deliberately, since the
light gun games draw their own crosshair. **That is wrong.** From this unit's own
`framework-res.apk` in the dump:

```
res/drawable-mdpi-v4/pointer_arrow.png        22x28,  gray+alpha, 69% non-transparent
res/drawable-mdpi-v4/pointer_arrow_large.png  64x64,  gray+alpha, 42% non-transparent
```

Decoded and rendered as ASCII, both are a normal, fully opaque arrow. `ro.sf.lcd_density`
is 160 (mdpi), and mdpi is the only density shipped — so the resource that would be used is
present and intact.

Runtime state is equally healthy: the mouse enumerates as `Classes: CURSOR | EXTERNAL` with
`Cursor Input Mapper: Mode: POINTER`, `Pointer Gestures Enabled: true`, the viewport is a
normal active `INTERNAL` 1920x1080, `cmd overlay list` shows nothing pointer-related, and
there is no device owner.

**The actual lead:** `dumpsys SurfaceFlinger --list` contains **no `Sprite` layer at all**
(`grep -ic sprite` returns 0). AOSP's `SpriteController` creates that surface lazily, on the
first `setVisible(true)`, so its absence means `PointerController` never made the pointer
visible — the sprite is not hidden, it was never created. Note this proves less than it
looks if the mouse has not been *moved* since it was plugged in; the surface is created on
first show, not on device add. Re-check with the mouse moving:

```bash
python3 tools/uart_shell.py run 'dumpsys SurfaceFlinger --list | grep -i sprite'
```

`PointerIcon.TYPE_ARROW` was requested explicitly on the explorer's root, list and button
(an app can override the pointer for its own windows). Installed and launched; **no visible
change reported**. `screencap` never captures the cursor sprite, so this can only ever be
confirmed on the TV.

### Workflow caution: `adb` may not be the console

The console has no network, so it is only ever an *USB* adb target, and its adb dies on
every reboot (§15). If another Android device is on the network with wireless debugging on,
`adb` silently retargets it. During this session `adb devices` showed only:

```
adb-<redacted>._adb-tls-connect._tcp   device   model:AYN_Thor
```

— a Snapdragon 8 Gen 2 handheld, not the A527 console. A `framework-res.apk` pulled that way
is the wrong device's, and would have produced a confidently wrong conclusion. **Check
`adb shell getprop ro.product.model` returns `A527 PRO` before trusting anything from adb**,
or use the serial console, which cannot be confused for another device.

### Resolved: the vendor suppresses the cursor with PointerIcon.TYPE_NULL

Decompiling `GaimeCalibration.apk` with `jadx` answers it outright. **The vendor does not
draw a cursor — it destroys the system one**, in three places, all
`PointerIcon.getSystemIcon(ctx, 0)`, and `0` is `TYPE_NULL`:

```java
// GridRelativeLayout.java — unconditional, and this is the load-bearing one
public PointerIcon onResolvePointerIcon(MotionEvent e, int i) {
    return PointerIcon.getSystemIcon(getContext(), 0);
}

// CalibrationActivity.onCreate
getWindow().getDecorView().setPointerIcon(PointerIcon.getSystemIcon(this, 0));

// and again on every ImageView added at runtime (setInstructionImageView)
imageView.setPointerIcon(PointerIcon.getSystemIcon(this, 0));
```

The in-game crosshair is drawn by Unity, not by Android. So the original instinct in §17 was
right in substance — the suppression *is* deliberate, because the games draw their own
reticle — and wrong only in mechanism: the artwork is untouched, the icon type is forced to
null at the app layer.

This also explains the missing `Sprite` layer. `TYPE_NULL` fades the pointer to alpha 0, and
a sprite that is never made visible never has its surface created — so it is absent from
SurfaceFlinger entirely rather than present-but-hidden.

**Why the earlier fix failed.** §17 set `PointerIcon.TYPE_ARROW` on three views and nothing
changed. Icon resolution walks *down* to the view under the pointer, so an icon on a parent
loses to whatever child is being hovered — a `ListView`'s row `TextView`s here. Overriding
`onResolvePointerIcon` is what makes it stick, which is exactly why the vendor overrode it
rather than only calling `setPointerIcon`.

**What we did.** Mirrored their structure in `CursorLayout`: override `onResolvePointerIcon`
to return `TYPE_NULL` (so there can never be two cursors) and paint our own arrow in
`dispatchDraw`, fed from `dispatchGenericMotionEvent` (mouse hover) and `dispatchTouchEvent`
(the gun). Uses `getRawX/getRawY` minus `getLocationOnScreen`, because the content view sits
below the status bar and window-relative coordinates draw the arrow offset by the inset.
**Confirmed working on the TV.**

### tools/uart_push.py — files over the serial console

The console has no network and its adb only exists over USB, so with only the UART attached
there was no way to install a rebuilt APK. `uart_push.py` closes that: base64 in paced
256-byte `printf` chunks, because the console tty has **no flow control** and writing at full
speed corrupts the stream silently. Both ends are md5-verified and a mismatch exits non-zero,
so a corrupt push cannot be mistaken for a good one.

```bash
python3 tools/uart_push.py apps/gaime-explorer/out/gaime-explorer.apk /data/local/tmp/x.apk
python3 tools/uart_shell.py run 'pm install -r -g /data/local/tmp/x.apk'
```

16805 bytes in 7.7 s (~4-5 KB/s of payload), md5 `a46e82a3…` matching on both sides. Fine for
an APK, useless for an image. Note the first version reported a false mismatch because it
assumed a fixed settle for the `md5sum` reply; it now polls for the digest.

## 18. The gun opened up — SoC identified, root shell, full firmware dump

The single biggest unknown in the project is answered. **The unmarked QFN at `U8` is a
LomboTech N7V5.**

### Getting the boot log off J3

Wired receive-only first (`J3 GND` -> adapter GND, `J3 TX` -> adapter RXD), 115200 8N1.
Two false starts, both worth recording because neither was a hardware fault:

1. **227 bytes of `0x00`/`0xFF` only — four distinct values, split 50/50.** That is not a
   baud error (a real stream at the wrong rate gives a broad spread); it is a floating
   input on ambient EMI. It also excludes the obvious miswires: `GND` would give a
   continuous `0x00` torrent at 11.5 KB/s, `V3.3` would give silence. The gun simply was
   not powered — it draws from its own USB cable, which was unplugged.
2. **Mangled text with runs missing mid-word.** Diagnosed as a `uart_capture.sh` design
   fault and a Python rewrite was written. **That diagnosis was wrong.** The real cause:

   ```
   $ lsof /dev/cu.usbserial-0001
   Python  9986  ...      <- our capture
   bash    9991  ...      <- uart_watch.sh, 2h48m old, from the console work
   cat     9993  ...
   ```

   A `uart_watch.sh` left running from §14 kept reopening the port and taking half the
   bytes. Two readers on one tty split the stream. **Check `lsof` on the port before
   blaming a tool.** (`tools/uart_capture.py` was kept anyway — one fd, tight read loop,
   and it gained the macOS `IOSSIOSPEED` ioctl, since `termios` defines no constant above
   `B230400` on this platform.)

With the port to ourselves and `adapter TXD -> J3 RX` added, a single newline gives:

```
# id
uid=0(root) gid=0(root) groups=0(root),10(wheel)
```

**Root, no login, no password.** `telnetd` also runs permanently (`Starting telnetd: OK`)
but has no network interface to listen on.

### What it is

```
ro.product.chip=n7v5              ro.build.id=Virgo
ro.product.name=n7v5_alcor_lightgun   ro.build.user=dashine
ro.product.device=lightgun        ro.build.host=gaime-gun-001
                                  ro.build.date=Thu 09 Oct 2025 10:08:07 AM UTC
```

| | |
|---|---|
| SoC | **LomboTech N7V5**, ARMv7 `410fc075` = Cortex-A7, 48 BogoMIPS |
| Kernel | Linux 4.19.73, gcc 7.5.0 (Linaro 2019.12), `#1 PREEMPT` |
| RAM | **128 MiB**, 56 MiB carved out for the vision pipeline |
| Flash | GigaDevice SPI NAND, `snc_read_id` -> `c8 91`, 119808 KB |
| Root | squashfs (read-only), `init=/linuxrc`, BusyBox |
| Camera | `h63p` MIPI sensor on I2C, ISP registers `/dev/video1`, `video3`, `video4` |
| Accelerators | `AXNU` (NPU) and `AXVU`, plus an `[N7_VC]` hardware video codec |
| UART | `ttySLB0 @ 0x4003000`, irq 26, `base_baud = 1500000` |

`ro.build.user=dashine` is the **same ODM as the console**, confirming §2 from the gun side.

**Two corrections to §7a/§9.** The vendor's published spec of **1 GB RAM** is wrong — the
kernel reports 128 MiB. 1 Gbit is exactly 128 MB, so it reads as a bit/byte conflation of
the flash size. And "the gun has no update path" was right about the host side but wrong
about the device: `/usr/bin` carries `fw_upgrade`, `fw_ab_upgrade`, `fw_printenv` and
`fw_setenv`. Nothing on the console or over USB invokes them, so the vendor still never
updates the gun in the field.

The `lsm6ds3` driver loads for a **6-axis IMU that is not present** — `i2c-2 ... device
addr: 0x6a ... no ask for the 7bit address`, repeatedly. Unpopulated on this revision, or
on another bus.

### The backup — USB mass storage, not a 4-hour serial dump

117 MiB over a 115200 console is ~4 h of base64 and corrupts silently on any glitch. The
gun is a Linux USB gadget with `CONFIG_USB_CONFIGFS_MASS_STORAGE=y`, so expose the NAND to
the host read-only instead:

```sh
cd /sys/kernel/config/usb_gadget/g1
echo "" > UDC                                     # unbind
rm -f configs/c.1/uvc.0                           # uvc oopses in uvc_function_bind on re-register
mkdir -p functions/mass_storage.0
echo 1            > functions/mass_storage.0/lun.0/ro
echo /dev/nandblk > functions/mass_storage.0/lun.0/file
ln -s functions/mass_storage.0 configs/c.1/
echo lb_hdc.0     > UDC                           # rebind
```

**First attempt rebooted the gun after ~15 s.** Not the kernel watchdog — a vendor daemon,
`/app/bin/usb_monitor`, watches the gadget and resets the device when it breaks. Kill that
and `uvc-gadget` first and the swap holds.

Everything above is **configfs and process state — RAM only.** Nothing touches flash, the
LUN is read-only, and `S30usb-gadget` rebuilds the stock gadget at boot; the accidental
reboot demonstrated that, coming back as `uvc.0` + `hid.1/2/3` unaided.

Host sees 83,091,456 bytes matching `nandblk` exactly, GPT in **2048-byte sectors**.
**Verified end to end** — the gun computed the digest of the block device itself and it
matches the host's copy:

```
gun:    03c2ea90ad6098d39c651c9279933449  /dev/nandblk
local:  03c2ea90ad6098d39c651c9279933449  backup/gun/nandblk.img
```


| Partition | Offset | Size | Contents |
|---|---|---|---|
| `root_sq` | 16384 | 24 MiB | squashfs — `hsqs` |
| `private` | 25182208 | 1 MiB | never mounted — **1 MiB of pure zeros** |
| `cache` | 26230784 | 48 MiB | FAT, empty |
| `app` | 76562432 | 4 MiB | ext4 |
| `userdata` | 80756736 | 2.2 MiB | ext4 |

`private` being blank is a real result: whatever per-unit calibration exists, it is not
stored there.

**Not captured:** the bootloader region below `0x880000`. Only `misc` and `env` are exposed
as MTD partitions and the boot area sits outside the NFTL device.

### What is in it

```
bin/gun                  72 KB   ARM ELF — the computer vision process
bin/usb_monitor         9.8 KB   the thing that rebooted us
model/gaime/gaime.bin   1.2 MB   NPU model weights
model/gaime/gaime.ezb    143 KB  network description
system_info.json                 fw v2.5.1, model v1.0.1, sn "12345"
```

The aiming is a **72 KB binary driving a 1.2 MB neural network** on the N7V5's NPU.

And the vendor shipped a complete set of gadget scripts behind feature flags —
`shell/usb/gadget/{g_msc,g_rndis,g_mtp,g_uac1,g_adb,g_uvc,g_hid}.sh`:

```sh
CFG_UVC_ENABLE=1     CFG_ADB_ENABLE=0     CFG_MSC_ENABLE=0
CFG_RNDIS_ENABLE=0   CFG_MTP_ENABLE=0     CFG_HID_ENABLE=1
```

`g_adb.sh` is fully written (create `ffs.adb`, mount functionfs, run `adbd` — which is
present in `/usr/bin`). **The configfs surgery above reinvented something the vendor had
already built and switched off.** Note `CONFIG_USB_CONFIGFS_RNDIS` is *not* set in the
kernel, so `g_rndis.sh` would not work as shipped; ADB and MSC would.

Extraction on macOS: `brew install squashfs e2fsprogs`, then `unsquashfs` for `root_sq` and
`debugfs -R "rdump / out" app.img` for the ext4 partitions.
