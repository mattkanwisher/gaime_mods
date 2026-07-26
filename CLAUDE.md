# G'AIM'E Light Gun — Reverse Engineering Brief

Handoff document for Claude Code. Everything below is what's known as of July 2026, plus a ranked plan of attack.

---

## 1. The device

**G'AIM'E TIME CRISIS Lightgun** — made by **Tassei Denki Co., Ltd.** (達成電器), Tokyo. Officially licensed by Bandai Namco for the Time Crisis 30th anniversary. Launched November 2025 via Kickstarter, then retail.

A small HDMI mini-console plus a camera-based light gun. The gun's camera identifies the boundaries of the TV screen and derives an aim point from that geometry — same conceptual family as Sinden (which uses a white border) rather than IR-emitter systems (Wii, AimTrak, Gun4IR) or true CRT light guns.

**Bundles:**

| SKU | JP price | USD | Contents |
|---|---|---|---|
| Basic | ¥13,200 | $99 | Console + 1 gun |
| Premium | ¥19,800 | $149 | + foot pedal, 30th anniversary pin |
| Ultimate | ¥29,700 | $199 | + 2nd gun, diorama stand |

**Bundled games:** TIME CRISIS, POINT BLANK, STEEL GUNNER, STEEL GUNNER 2 (Premium/Ultimate). Basic is Time Crisis only.

Two regional variants exist: JP (Japanese text, black/orange gun) and overseas (English text, arcade-blue gun). **Unit in hand is the JP retail version, purchased in Akihabara, July 2026.**

---

## 2. Known hardware facts

### Console
- PS1-jewel-case form factor.
- **Front:** two USB-C ports (gun 1 / gun 2 or pedal), RESET button, POWER switch.
- **Back:** power input, HDMI out.
- **No Wi-Fi, no Bluetooth, no network stack of any kind.** All updates are wired.
- SoC unknown — no public teardown exists as of this writing. Given the price point, form factor and the flashing tool behaviour (see §3), a Rockchip or Allwinner application processor is the leading hypothesis.

### Gun
- Connects over USB-C via a braided cable (orange on JP units).
- Contains its own camera and enough compute to do the screen-edge CV. Whether the vision processing runs in the gun or the console is **unresolved and is a key open question** — it determines whether the gun can ever be repointed at arbitrary displays.
- **Critical known behaviour:** plugged directly into a laptop, the gun enumerates as a **USB HID mouse with absolute positioning**, and reportedly needs no calibration to produce a usable pointer. Community report notes the pointer **jumps/jitters on trigger pull**, suggesting the trigger event perturbs the CV pipeline or shares a code path with the coordinate report.

### Firmware
- Current public version: **V4.0.3** (released 9 March 2026).
- V4.0.3 added "Background Environment Assist Mode" — user-selectable colour bars (black / white / pink) drawn at the screen edges to improve boundary detection in visually busy rooms. This confirms the CV approach is **edge/contrast detection against the display border**, not IR and not sub-pixel timing.

---

## 3. Firmware update mechanism (most important finding)

Download page: <https://www.mygaime.com/downloads>

Direct link (V4.0.3, English):
`https://www.mygaime.com/_files/archives/43de19_a33fa7728c374b15bbc4c0597ff62d20.zip?dn=GAIME_FWUpdate_V4.0.3.zip`

Video tutorial: <https://youtu.be/SI-Kp2lVABU>

**Key observations:**

1. **The package is ~4GB.** That is not a delta patch. That is a full system image — filesystem, emulator binary, and game ROM payload all included. This is the single highest-value artifact in the whole project and it is a public, unauthenticated download.
2. **Windows-only vendor tool.** macOS and Linux are unsupported. Windows 10 preferred; Windows 11 requires disabling driver signature enforcement.
3. **Point 2 is a strong fingerprint.** Unsigned kernel driver + full-image write + proprietary GUI flasher is the standard signature of the Rockchip (`RKDevTool` / `DriverAssistant` / `rockusb`) or Allwinner (`PhoenixSuit` / `LiveSuit` / FEL) flashing stacks. Identify which and the whole boot chain becomes known territory.
4. **Which port is used for flashing is not documented publicly.** The instructions inside the zip specify it. The likely candidates are one of the front USB-C ports switching to device mode, or the rear power jack doubling as USB-C data. The front RESET button is a plausible loader/MaskROM entry combo (hold RESET while applying power).
5. Early pre-launch press claimed updates would be done via an Android/iOS app. **That is outdated** — the shipped method is the Windows PC tool.

---

## 4. Plan of attack, ranked by payoff-to-effort

### Tier 1 — Firmware image analysis (non-destructive, do this first)

No disassembly, no risk to the unit, and it likely answers most open questions.

- Download `GAIME_FWUpdate_V4.0.3.zip` and extract.
- Inventory the contents: look for `.img`, `.bin`, `update.img`, `boot.img`, `rootfs`, `MiscInfo.txt`, `parameter.txt`, `sys_partition.fex` — the filenames alone will identify the SoC vendor immediately.
- Run entropy analysis to determine whether payloads are encrypted or merely packed.
- `binwalk -Me` the images; look for squashfs/ext4 signatures, a Linux kernel, U-Boot strings.
- If a rootfs mounts: identify the emulator. If it's a FBNeo/MAME derivative, ROM substitution becomes the realistic endgame.
- Examine the bundled Windows flasher binary and its driver `.inf` — the driver's hardware IDs give you USB VID/PID and confirm the vendor stack.

### Tier 2 — Gun as a generic USB light gun (highest practical value)

The goal: use the gun as a Sinden-class light gun on a PC for MAME / RetroArch / Batocera, at a third the price of a Sinden.

- Plug the gun into a Linux box. Capture `lsusb -v`, the full HID report descriptor, and `evtest` output.
- Confirm whether X/Y are reported as **absolute** (required for light gun use) or relative.
- Characterise the trigger jitter: log coordinate streams around button-down events and measure magnitude and duration of the disturbance.
- Mitigation: a userspace `uinput` bridge that reads the raw device, latches the last stable coordinate for ~50ms around a trigger event, and re-emits a clean absolute-mouse device. Equivalent on Windows via a Raw Input interposer.
- Validate in MAME with `lightgun 1`, `lightgun_device mouse`, and Sinden-style `ctrlr` mapping as a starting reference.

### Tier 3 — Console teardown

- Open the case, photograph the board at high resolution both sides, identify the SoC, RAM, and flash.
- Look for unpopulated UART pads. Budget consumer devices on Rockchip/Allwinner very frequently leave a serial console enabled.
- If UART is live, capture the full boot log — bootloader version, kernel cmdline, init sequence, emulator invocation.
- **No public teardown of this device exists.** Good board photos alone would be a genuine contribution to the retro hardware community.

### Tier 4 — Gun MCU

- Separate teardown of the gun grip. Identify the camera module and whatever MCU/SoC drives it (an ESP32-S3, K210, or similar camera-capable part is plausible).
- Determine where the CV actually executes. If it runs in the gun and the gun outputs clean absolute HID coordinates, Tier 2 is essentially free and the console becomes optional.

---

## 5. Open questions

- Which physical port carries the firmware update, and what is the loader entry sequence?
- Rockchip, Allwinner, or something else?
- Is the 4GB image encrypted or just packed?
- Is the emulator a known open-source core (which would carry GPL obligations and possibly a published source offer — check <https://www.mygaime.com/osi>)?
- Does CV run gun-side or console-side?
- Are the ROMs stored as recognisable MAME-set files or in a custom container?

**Note:** the site has an OSI page at <https://www.mygaime.com/osi>. If they're shipping GPL components, that page may list them — a free hint at the software stack before a single byte is unpacked.

---

## 6. Reference links

- Product / downloads: <https://www.mygaime.com/downloads>
- Official Discord (best source of undocumented behaviour): <https://discord.gg/MAhMpTZSsH>
- Time Extension review + comment thread (source of the USB-mouse observation): <https://www.timeextension.com/news/2025/11/review-gaime-coin-op-time-crisis-comes-home-with-this-ai-powered-light-gun>
- V4.0.3 firmware announcement: <https://www.timeextension.com/news/2026/03/gaime-gets-a-firmware-update-and-its-own-world-championship>
- Sinden MAME configuration reference (useful prior art for Tier 2): <https://www.sindenwiki.org/wiki/MAME>
- Batocera light gun guide: <https://wiki.batocera.org/emulators:lightgun_games>

---

## 7. Suggested first session for Claude Code

```
1. Fetch and extract GAIME_FWUpdate_V4.0.3.zip
2. Produce a full file tree with sizes and file(1) types
3. Entropy-scan every binary payload
4. binwalk -Me all candidate images
5. Report: SoC vendor, encryption status, filesystem types found,
   and any emulator/ROM artefacts identified
```

Do Tier 1 before opening anything. The image probably answers half the open questions for free.