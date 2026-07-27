# Reversing the gun's custom binaries

The five binaries unique to the G'AIM'E gun, decompiled and — where honestly
possible — reconstructed into rebuildable C.

Everything here derives from `backup/gun/` (the verified NAND dump). Nothing
came from the vendor as source.

## The honest status of each binary

| Binary | Size | Decompiled | Reconstructed | Rebuilds | Runs on device |
|---|---|---|---|---|---|
| `usb_monitor` | 9.8 KB | ✅ | ✅ `src/usb_monitor.c` | ✅ | ✅ verified |
| `fw_upgrade` | 12.7 KB | ✅ | ✅ `src/fw_upgrade.c` | ✅ | not run (writes `misc` + reboots) |
| `fw_ab_upgrade` | 26 KB | ✅ | ⚠️ reference only | — | — |
| `gun` | 72 KB | ✅ | ❌ reference only | — | — |
| `libnn_gaime.so` | 130 KB | ✅ | ❌ reference only | — | — |

- **Decompiled**: full Ghidra pseudo-C in `../decompiled/<name>.c`.
- **Reconstructed**: clean, readable C written from that decompilation, in
  `src/`, that compiles to a functionally equivalent program.
- **Rebuilds / runs**: cross-compiled for the N7V5 and confirmed to load against
  the device's own glibc.

### Why two are rebuilt and three are not

`usb_monitor` and `fw_upgrade` are small, plain **C** with clear control flow, so
a faithful clean-room rewrite is achievable and worth doing. `usb_monitor` is
proven end to end: reconstructed → cross-compiled → `LD_TRACE_LOADED_OBJECTS=1`
on the gun shows `libc.so.6 => /lib/libc.so.6` and the correct interpreter, so
the device's loader binds it.

`fw_ab_upgrade`, `gun` and `libnn_gaime.so` are a different problem:

- `gun` and `libnn_gaime.so` are **C++** against OpenCV, Eigen and the STL.
  Ghidra gives correct-behaving pseudo-C per function, but turning inlined STL,
  template instantiations and reconstructed class layouts back into source that
  compiles to the same object is a manual reverse-engineering project measured in
  weeks. Anyone claiming a one-command "rebuild" of these is showing you pseudo-C
  that does not compile.
- What is genuinely useful for those three is captured elsewhere: the OTA/HID
  protocol `gun` speaks is fully reconstructed as a working tool
  (`../tools/gun_ota.py`), and the aiming pipeline is documented in FINDINGS
  sections 19–20. That is the reusable knowledge; the object code is reference.

So this directory does not pretend to resurrect all five. It rebuilds the two
that can be rebuilt honestly, and keeps the full decompilation of the other three
for study.

## Building

Target: **ARMv7 Cortex-A7, Linux, glibc 2.25, hard-float** — what the gun runs.

```bash
# macOS (approve the tap first — it runs third-party install code):
brew trust messense/macos-cross-toolchains
brew install arm-unknown-linux-gnueabihf
make                       # -> out/usb_monitor, out/fw_upgrade

# Linux:
sudo apt install gcc-arm-linux-gnueabihf
make CROSS=arm-linux-gnueabihf-

make check                 # host-compile the portable logic, no toolchain needed
```

## Deploying to the gun

The gun has no adb — the only wired path is the `J3` serial console. `make
deploy` pushes over it (base64 in paced chunks, md5-verified both ends):

```bash
make deploy T=usb_monitor          # -> /app/bin/usb_monitor.new on the gun
```

It lands as `<name>.new` on purpose. Inspect it over serial, and only then
decide whether to replace the original. Note that `/app` is ext4 and writable,
so a replacement persists across reboots; keep the dump as your restore path.

Verify it will run without executing it (this is what was done for
`usb_monitor` — it prints the shared-library resolution and exits, never
reaching `main`):

```
LD_TRACE_LOADED_OBJECTS=1 /app/bin/usb_monitor.new
```

## A caution on the two that write flash

`fw_upgrade` and `fw_ab_upgrade` stage a bootloader command in the `misc`
partition and reboot. **Nothing on the device invokes them** (see FINDINGS
section 20), and the update path the gun actually uses is the HID OTA in
`gun_ota.py`. Do not run the rebuilt `fw_upgrade` on hardware unless you know
exactly what bootloader command you are staging — a bad one leaves the device
trying to apply an update that isn't there.
