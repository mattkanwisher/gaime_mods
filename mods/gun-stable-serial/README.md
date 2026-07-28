# Stable USB serial number

The gun's `usb_gadget.sh` sets a **random** serial every boot
(`USB_SERIAL=$(shuf -i 1-100000 -n 1)`), so macOS treats it as a new accessory
each time and re-prompts. Pin it to a constant:

    sed -i 's|^USB_SERIAL=.*|USB_SERIAL=GAIMEGUN0001|' /app/shell/usb/gadget/usb_gadget.sh

Revert: restore the stock `usb_gadget.sh` from `backup/gun/app_fs/` (md5
d361b7f97202475a91a4a70c806d14f6).
