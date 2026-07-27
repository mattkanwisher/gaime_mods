#!/usr/bin/env python3
"""Minimal fastboot client for the G'AIM'E console's U-Boot.

Google's `fastboot` will not talk to this device: it matches on the USB
interface class/subclass/protocol (0xff/0x42/0x03) and Allwinner's gadget does
not advertise those, and the `-i <vid>` override was removed from modern
platform-tools. The protocol itself is trivial, so this speaks it directly.

Reached with `adb reboot bootloader`, which lands in U-Boot's fastboot loop —
a software route into a flashing mode, with no need to short the FEL pads.
The gadget appears as 1f3a:1010 "sunxi".

Protocol: send an ASCII command on bulk OUT; read replies on bulk IN until one
starts with OKAY or FAIL. INFO lines are progress, DATA introduces a transfer.

    fastboot_client.py getvar product
    fastboot_client.py devices
    fastboot_client.py reboot
"""

import ctypes
import sys

VID, PID = 0x1F3A, 0x1010


class _EP(ctypes.Structure):
    _fields_ = [("bLength", ctypes.c_ubyte), ("bDescriptorType", ctypes.c_ubyte),
                ("bEndpointAddress", ctypes.c_ubyte), ("bmAttributes", ctypes.c_ubyte),
                ("wMaxPacketSize", ctypes.c_uint16), ("bInterval", ctypes.c_ubyte),
                ("bRefresh", ctypes.c_ubyte), ("bSynchAddress", ctypes.c_ubyte),
                ("extra", ctypes.c_void_p), ("extra_length", ctypes.c_int)]


class _ALT(ctypes.Structure):
    _fields_ = [("bLength", ctypes.c_ubyte), ("bDescriptorType", ctypes.c_ubyte),
                ("bInterfaceNumber", ctypes.c_ubyte), ("bAlternateSetting", ctypes.c_ubyte),
                ("bNumEndpoints", ctypes.c_ubyte), ("bInterfaceClass", ctypes.c_ubyte),
                ("bInterfaceSubClass", ctypes.c_ubyte), ("bInterfaceProtocol", ctypes.c_ubyte),
                ("iInterface", ctypes.c_ubyte), ("endpoint", ctypes.POINTER(_EP)),
                ("extra", ctypes.c_void_p), ("extra_length", ctypes.c_int)]


class _INTF(ctypes.Structure):
    _fields_ = [("altsetting", ctypes.POINTER(_ALT)), ("num_altsetting", ctypes.c_int)]


class _CFG(ctypes.Structure):
    _fields_ = [("bLength", ctypes.c_ubyte), ("bDescriptorType", ctypes.c_ubyte),
                ("wTotalLength", ctypes.c_uint16), ("bNumInterfaces", ctypes.c_ubyte),
                ("bConfigurationValue", ctypes.c_ubyte), ("iConfiguration", ctypes.c_ubyte),
                ("bmAttributes", ctypes.c_ubyte), ("MaxPower", ctypes.c_ubyte),
                ("interface", ctypes.POINTER(_INTF)), ("extra", ctypes.c_void_p),
                ("extra_length", ctypes.c_int)]


class Fastboot:
    def __init__(self, lib="/opt/homebrew/lib/libusb-1.0.dylib"):
        self.l = ctypes.CDLL(lib)
        self.l.libusb_open_device_with_vid_pid.restype = ctypes.c_void_p
        self.l.libusb_open_device_with_vid_pid.argtypes = [ctypes.c_void_p,
                                                           ctypes.c_uint16, ctypes.c_uint16]
        self.l.libusb_claim_interface.argtypes = [ctypes.c_void_p, ctypes.c_int]
        self.l.libusb_release_interface.argtypes = [ctypes.c_void_p, ctypes.c_int]
        self.l.libusb_close.argtypes = [ctypes.c_void_p]
        self.l.libusb_get_device.restype = ctypes.c_void_p
        self.l.libusb_get_device.argtypes = [ctypes.c_void_p]
        self.l.libusb_get_active_config_descriptor.argtypes = [
            ctypes.c_void_p, ctypes.POINTER(ctypes.POINTER(_CFG))]
        self.l.libusb_bulk_transfer.argtypes = [ctypes.c_void_p, ctypes.c_ubyte,
                                                ctypes.c_char_p, ctypes.c_int,
                                                ctypes.POINTER(ctypes.c_int), ctypes.c_uint]
        if self.l.libusb_init(None) != 0:
            sys.exit("libusb_init failed")
        self.h = self.l.libusb_open_device_with_vid_pid(None, VID, PID)
        if not self.h:
            sys.exit(f"no {VID:04x}:{PID:04x} — try: adb reboot bootloader")
        self.iface, self.ep_in, self.ep_out = self._descriptors()
        self.l.libusb_claim_interface(self.h, self.iface)

    def _descriptors(self):
        cfg = ctypes.POINTER(_CFG)()
        dev = self.l.libusb_get_device(self.h)
        if self.l.libusb_get_active_config_descriptor(dev, ctypes.byref(cfg)) != 0 or not cfg:
            sys.exit("could not read config descriptor")
        c = cfg.contents
        for i in range(c.bNumInterfaces):
            a = c.interface[i].altsetting[0]
            ep_in = ep_out = None
            for e in range(a.bNumEndpoints):
                ep = a.endpoint[e]
                if ep.bmAttributes & 3 != 2:
                    continue
                if ep.bEndpointAddress & 0x80:
                    ep_in = ep_in or ep.bEndpointAddress
                else:
                    ep_out = ep_out or ep.bEndpointAddress
            print(f"[intf {a.bInterfaceNumber} class=0x{a.bInterfaceClass:02x} "
                  f"sub=0x{a.bInterfaceSubClass:02x} proto=0x{a.bInterfaceProtocol:02x}]",
                  file=sys.stderr)
            if ep_in and ep_out:
                return a.bInterfaceNumber, ep_in, ep_out
        sys.exit("no bulk in/out pair found")

    def _xfer(self, ep, buf, length, timeout=10000):
        n = ctypes.c_int(0)
        rc = self.l.libusb_bulk_transfer(self.h, ep, buf, length, ctypes.byref(n), timeout)
        if rc != 0:
            raise IOError(f"bulk transfer rc={rc} on ep 0x{ep:02x}")
        return n.value

    def command(self, cmd: str):
        data = cmd.encode()
        self._xfer(self.ep_out, ctypes.create_string_buffer(data, len(data)), len(data))
        out = []
        while True:
            buf = ctypes.create_string_buffer(256)
            got = self._xfer(self.ep_in, buf, 256)
            reply = buf.raw[:got].decode("utf-8", "replace")
            out.append(reply)
            if reply.startswith(("OKAY", "FAIL")):
                return out
            if reply.startswith("DATA"):
                return out

    def close(self):
        self.l.libusb_release_interface(self.h, self.iface)
        self.l.libusb_close(self.h)


def main() -> None:
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    fb = Fastboot()
    try:
        action = sys.argv[1]
        if action == "devices":
            for var in ("product", "version", "serialno", "secure", "max-download-size"):
                try:
                    print(f"  {var:20s} {' '.join(fb.command('getvar:' + var))!r}")
                except IOError as e:
                    print(f"  {var:20s} error: {e}")
        elif action == "getvar":
            print(fb.command("getvar:" + sys.argv[2]))
        elif action == "reboot":
            print(fb.command("reboot"))
        else:
            print(fb.command(" ".join(sys.argv[1:])))
    finally:
        fb.close()


if __name__ == "__main__":
    main()
