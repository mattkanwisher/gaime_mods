#!/usr/bin/env python3
"""Enumerate and read the G'AIM'E gun's HID interfaces via hidapi.

The gun (VID 0x2E2C / PID 0x0631) presents three HID interfaces:

  usage page 0x01/0x06  boot keyboard, 8-byte input reports
  usage page 0x0D/0x04  digitizer/touchscreen — report ID 1, ABSOLUTE 16-bit
                        X/Y over a 0..10000 logical range, plus tip-switch
                        (trigger) and in-range bits
  usage page 0xFF00     vendor config, 64-byte in/out reports (Modbus CRC-16
                        framed; see FINDINGS.md section 6)

Usage:
  gun_probe.py list
  gun_probe.py read [--page 0xd] [--seconds 10]
"""

import argparse
import ctypes
import sys
import time

VID, PID = 0x2E2C, 0x0631
LIB = "/opt/homebrew/lib/libhidapi.dylib"


class DevInfo(ctypes.Structure):
    pass


DevInfo._fields_ = [
    ("path", ctypes.c_char_p),
    ("vendor_id", ctypes.c_ushort),
    ("product_id", ctypes.c_ushort),
    ("serial_number", ctypes.c_wchar_p),
    ("release_number", ctypes.c_ushort),
    ("manufacturer_string", ctypes.c_wchar_p),
    ("product_string", ctypes.c_wchar_p),
    ("usage_page", ctypes.c_ushort),
    ("usage", ctypes.c_ushort),
    ("interface_number", ctypes.c_int),
    ("next", ctypes.POINTER(DevInfo)),
    ("bus_type", ctypes.c_int),
]


def load():
    h = ctypes.CDLL(LIB)
    h.hid_enumerate.restype = ctypes.POINTER(DevInfo)
    h.hid_open_path.restype = ctypes.c_void_p
    h.hid_open_path.argtypes = [ctypes.c_char_p]
    h.hid_read_timeout.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t, ctypes.c_int]
    h.hid_write.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t]
    h.hid_write.restype = ctypes.c_int
    h.hid_read_timeout.restype = ctypes.c_int
    h.hid_error.restype = ctypes.c_wchar_p
    h.hid_error.argtypes = [ctypes.c_void_p]
    h.hid_close.argtypes = [ctypes.c_void_p]
    h.hid_close.restype = None
    h.hid_free_enumeration.argtypes = [ctypes.POINTER(DevInfo)]
    h.hid_free_enumeration.restype = None
    h.hid_init()
    return h


def modbus_crc16(data, n):
    crc = 0xFFFF
    for i in range(n):
        crc ^= data[i]
        for _ in range(8):
            crc = (crc >> 1) ^ 0xA001 if crc & 1 else crc >> 1
    return crc


def gun_mode_packet(mode):
    """FUN_CODE_SYSTEM_CMD / SUB_FUN_CODE_GUNMODE. mode 0 = single shot, 1 = multiple."""
    p = bytearray(64)
    p[0], p[1], p[2], p[6] = 5, 1, 5, mode
    crc = modbus_crc16(p, 7)
    p[7], p[8] = crc & 0xFF, (crc >> 8) & 0xFF
    return bytes(p)


def interfaces(h):
    out, node = [], h.hid_enumerate(VID, PID)
    cur = node
    while cur:
        d = cur.contents
        out.append({
            "path": d.path,
            "usage_page": d.usage_page,
            "usage": d.usage,
            "interface": d.interface_number,
            "product": d.product_string,
            "serial": d.serial_number,
            "release": d.release_number,
        })
        cur = d.next
    h.hid_free_enumeration(node)
    return out


def cmd_list(h):
    ifaces = interfaces(h)
    if not ifaces:
        sys.exit("no GAIME gun found (VID 0x2E2C / PID 0x0631)")
    for d in ifaces:
        print(f"iface={d['interface']} usage_page=0x{d['usage_page']:04x} usage=0x{d['usage']:02x} "
              f"product={d['product']!r} serial={d['serial']!r} "
              f"release={d['release'] >> 8}.{d['release'] & 0xFF}")
        print(f"    path={d['path'].decode()}")


def cmd_read(h, page, seconds):
    target = next((d for d in interfaces(h) if d["usage_page"] == page), None)
    if target is None:
        sys.exit(f"no interface with usage page 0x{page:04x}")
    print(f"reading iface={target['interface']} usage_page=0x{page:04x} for {seconds}s "
          f"(Ctrl-C to stop)", file=sys.stderr)

    dev = h.hid_open_path(target["path"])
    if not dev:
        sys.exit("hid_open_path failed — on macOS this usually means the process lacks "
                 "Input Monitoring permission for this device class")

    buf = ctypes.create_string_buffer(64)
    deadline = time.time() + seconds
    last = None
    while time.time() < deadline:
        n = h.hid_read_timeout(dev, buf, 64, 200)
        if n <= 0:
            continue
        raw = buf.raw[:n]
        if raw == last:
            continue
        last = raw
        line = raw.hex()
        if page == 0x0D and n >= 6 and raw[0] == 1:
            flags = raw[1]
            x = int.from_bytes(raw[2:4], "little")
            y = int.from_bytes(raw[4:6], "little")
            print(f"{line}   tip={flags & 1} in_range={(flags >> 1) & 1}  X={x:5d} Y={y:5d}")
        else:
            print(line)
    h.hid_close(dev)


def cmd_gunmode(h, mode):
    target = next((d for d in interfaces(h) if d["usage_page"] == 0xFF00), None)
    if target is None:
        sys.exit("vendor interface (usage page 0xFF00) not found")
    dev = h.hid_open_path(target["path"])
    if not dev:
        sys.exit("hid_open_path failed on the vendor interface")

    payload = gun_mode_packet(mode)
    # The vendor descriptor declares no Report ID, so hidapi wants a leading 0x00.
    n = h.hid_write(dev, b"\x00" + payload, len(payload) + 1)
    err = h.hid_error(dev)
    print(f"hid_write returned {n}" + (f"  error={err!r}" if err else ""))
    print(f"packet: {payload[:12].hex()}…  (mode={mode}, "
          f"{'single' if mode == 0 else 'multiple'} shot)")
    h.hid_close(dev)
    return n


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("list")
    r = sub.add_parser("read")
    r.add_argument("--page", type=lambda s: int(s, 0), default=0x0D)
    r.add_argument("--seconds", type=float, default=10)
    g = sub.add_parser("gunmode", help="send a SYSTEM_CMD/GUNMODE packet")
    g.add_argument("mode", type=int, choices=(0, 1))
    args = ap.parse_args()

    h = load()
    if args.cmd == "list":
        cmd_list(h)
    elif args.cmd == "read":
        cmd_read(h, args.page, args.seconds)
    else:
        cmd_gunmode(h, args.mode)


if __name__ == "__main__":
    main()
