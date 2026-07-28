# G'AIM'E gun modifications

Every change made to the gun's writable `/app` partition, kept here so they can
be re-applied after a revert to stock. Each is a small, reversible change to a
file the vendor's own boot flow reads; nothing touches the read-only rootfs or
the firmware. Pristine copies of every stock file live in `backup/gun/app_fs/`
(from the verified NAND dump) — reverting means restoring those.

## The mods

### gun-camera-tap/  — grab the frames the CV uses, over USB
`frame_tap.c` is an LD_PRELOAD shim that hooks `video_stream_set_frame_cb`, wraps
gun's own frame callback to copy each frame, and forwards to gun. Installed via
`gun.wrapper` (put at `/app/bin/gun`, original moved to `/app/bin/gun.real`).
Also here: `cam_grab.c` (standalone bring-up attempt) and `v4l2_probe.c`
(node inspector). See `docs/gun-camera-abi.md`. Blocked only by camera hardware.

### gun-usb-storage/  — expose the NAND read-only over USB
Corrected `g_msc.sh` (points the LUN at `/dev/nandblk` read-only, sets the IAD
device class) plus the `gadget_ctrl.sh` flags `CFG_UVC_ENABLE=0` +
`CFG_MSC_ENABLE=1`. See its README. Verified working (host binds an 83 MB
read-only disk while HID/aiming still works).

### gun-stable-serial/  — one fixed USB serial instead of a random one per boot
One-line change to `usb_gadget.sh`. Stops macOS re-prompting on every plug-in.

## Full stock md5 reference (backup/gun/app_fs)

    bin/gun                          b073cf7dff7f9ccf29cd332777d19595
    bin/usb_monitor                  9c6a498936301c1accb6309ca82ec843
    shell/app.sh                     186646f71c255d9c4185ca9bf77cc362
    shell/usb/gadget_ctrl.sh         b1e65175ffb45d42bb0a9c9f0f45ac85
    shell/usb/gadget/g_msc.sh        a8f357af36ef4091eb3d086a4d7f81b1
    shell/usb/gadget/usb_gadget.sh   d361b7f97202475a91a4a70c806d14f6
    system_info.json                 e7a6cac3e8304d18e49ff71f0a4e3ef8

A reverted device whose `/app` files all match these hashes is byte-for-byte
stock — the check that no software change was left behind.
