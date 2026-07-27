# Permanent read-only USB storage on the gun

Exposes the gun's entire NAND (`/dev/nandblk`, 83 MB) to any USB host as a
**read-only** removable disk, persistently across reboots — while the gun still
works as a light gun (HID aiming is untouched).

## How it works

The boot init `S30usb-gadget` runs the writable `/app/shell/usb/gadget_ctrl.sh`,
which builds the USB gadget from `CFG_*_ENABLE` flags. Two changes:

1. `gadget_ctrl.sh`: `CFG_UVC_ENABLE=0`, `CFG_MSC_ENABLE=1`.
2. Replace `/app/shell/usb/gadget/g_msc.sh` with the one here.

The stock `g_msc.sh` mounts a filesystem and its `error_info` exits on failure,
which aborts the whole gadget for a raw block device. This one points the LUN
straight at `/dev/nandblk` read-only, no mount.

**The non-obvious part:** the vendor sets the composite IAD device descriptor
(`bDeviceClass=0xEF/0x02/0x01`) *only* inside the UVC branch of `usb_gadget.sh`.
Drop UVC and `bDeviceClass` stays `0x00`, so a modern host can't resolve the
multi-interface device (HID x3 + MSC) and enumeration stalls at "addressed".
This `g_msc.sh` re-sets the IAD descriptor in `msc_start` (which runs before the
UDC is bound), which is what makes `hid+msc` enumerate cleanly.

## Apply (over the J3 serial console; the gun has no adb)

    python3 tools/uart_push.py mods/gun-usb-storage/g_msc.sh /app/shell/usb/gadget/g_msc.sh
    # then, preserving +x, flip the flags in place:
    #   sed -i 's/^CFG_UVC_ENABLE=1/CFG_UVC_ENABLE=0/; s/^CFG_MSC_ENABLE=0/CFG_MSC_ENABLE=1/' \
    #          /app/shell/usb/gadget_ctrl.sh
    # reboot

## Revert to stock

    python3 tools/uart_push.py backup/gun/app_fs/shell/usb/gadget/g_msc.sh /app/shell/usb/gadget/g_msc.sh
    # sed the two flags back (UVC=1, MSC=0), reboot

## Caveats

- **UVC is dropped.** That USB feed is a synthetic test pattern nothing consumes
  (FINDINGS 7/12), so the gun itself is unaffected — but whether the G'AIM'E
  **console** requires the gun to advertise a UVC interface during its accessory
  handshake is UNTESTED. If you use this gun on the console, revert first, or
  verify it's still recognised.
- The exposed disk is the live NAND read-only. Host reads are consistent; it is
  the same view the backup dump used.
- `gadget_ctrl.sh` must stay executable (`chmod +x`). A file pushed over serial
  loses its mode unless the pushed copy carries it — `uart_push.py` now
  reapplies the source mode, but flip the flags in place rather than pushing a
  replacement to be safe.
