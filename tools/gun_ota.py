#!/usr/bin/env python3
"""Talk to the G'AIM'E gun's OTA/config protocol over USB HID.

Reconstructed from /app/bin/gun (see decompiled/gun.c and FINDINGS section 20).
The gun's hid_handler thread reads 64-byte reports on the vendor HID interface
(usage page 0xFF00) and dispatches on the function code in byte 0.

Wire format — two shapes:

  Control/query (func 1,2,4,5,6,7,8):
      [0]      function code
      [1]      payload length  (0..56)
      [2:6]    index           (uint32 little-endian)
      [6:6+n]  payload
      [6+n:]   CRC-16/Modbus, little-endian, over bytes [0 .. 6+n)

  File data (func 3) — a raw fast path, NO index and NO CRC:
      [0]      0x03
      [1]      length           (0..56)
      [2:2+n]  data

Everything is padded to a 64-byte report. hidapi wants a report-id byte in
front, so writes are 65 bytes with a leading 0x00.

Function codes, from the dispatcher in gun.c:
    0x01 connect      index 0            create /app/temp_file.bin, reset state
    0x02 file_info    index 0 u16        total data frames
                      index 2 16 bytes   expected MD5
                      index 4 path       destination path (1..55 chars)
    0x03 file_data                       raw payload appended to temp file
    0x04 status       index 0            transfer state byte (0 idle)
                      index 1            u32 received | u32 total
                      index 2            last update result (Success/Failed)
    0x05 system       index 0 REBOOT     index 1 FACTORY RESET  (both guarded here)
                      index 2            "model_ver: .., fw_ver: .."  (read-only)
                      index 3            clear cache
    0x06 set_info     index 0            modify system_info.json
    0x07 get_info     index 0 key        read a system_info.json key
    0x08 echo/ping

When received frames reach the declared total, the gun runs verify+update by
itself: it MD5-checks the temp file and, on match, rename()s it onto the target
path. rename() needs both on one filesystem, and the temp file is on /app, so a
target must live on /app too — this tool refuses anything else.
"""

import argparse
import ctypes
import hashlib
import struct
import sys
import time

VID, PID = 0x2E2C, 0x0631
VENDOR_PAGE = 0xFF00
REPORT = 64
MAX_PAYLOAD = 56           # 0x38, enforced by parse_frame / handle_file_data

# Only /app is writable and shares a filesystem with /app/temp_file.bin, so a
# rename-based update can only ever land there. Refuse everything else outright.
ALLOWED_PREFIX = "/app/"

LIB = "/opt/homebrew/lib/libhidapi.dylib"


# ------------------------------------------------------------------ hidapi glue

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
    h.hid_enumerate.argtypes = [ctypes.c_ushort, ctypes.c_ushort]
    h.hid_open_path.restype = ctypes.c_void_p
    h.hid_open_path.argtypes = [ctypes.c_char_p]
    h.hid_write.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t]
    h.hid_write.restype = ctypes.c_int
    h.hid_read_timeout.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_size_t, ctypes.c_int]
    h.hid_read_timeout.restype = ctypes.c_int
    h.hid_error.restype = ctypes.c_wchar_p
    h.hid_error.argtypes = [ctypes.c_void_p]
    h.hid_close.argtypes = [ctypes.c_void_p]
    h.hid_free_enumeration.argtypes = [ctypes.POINTER(DevInfo)]
    if h.hid_init() != 0:
        sys.exit("hid_init failed")
    return h


def open_vendor(h):
    """Open the 0xFF00 vendor interface and return an opaque handle."""
    head = h.hid_enumerate(VID, PID)
    if not head:
        sys.exit("gun not found (VID 0x2E2C / PID 0x0631). Plug it into this Mac.")
    path = None
    cur = head
    while cur:
        d = cur.contents
        if d.usage_page == VENDOR_PAGE:
            path = d.path
            break
        cur = d.next
    if path is None:
        h.hid_free_enumeration(head)
        sys.exit("vendor HID interface (usage page 0xFF00) not found")
    dev = h.hid_open_path(path)
    h.hid_free_enumeration(head)
    if not dev:
        sys.exit("hid_open_path failed (another process may hold the interface)")
    return dev


# --------------------------------------------------------------- frame builders

def modbus_crc16(buf):
    crc = 0xFFFF
    for b in buf:
        crc ^= b
        for _ in range(8):
            crc = (crc >> 1) ^ 0xA001 if crc & 1 else crc >> 1
    return crc & 0xFFFF


def frame(func, index, payload=b""):
    """A CRC-framed control/query report (funcs 1,2,4,5,6,7,8)."""
    if len(payload) > MAX_PAYLOAD:
        raise ValueError("payload too long")
    body = bytes([func, len(payload)]) + struct.pack("<I", index) + payload
    crc = modbus_crc16(body)
    body += struct.pack("<H", crc)
    return body.ljust(REPORT, b"\x00")


def data_frame(chunk):
    """A raw file-data report (func 3): [03][len][data], no index, no CRC."""
    if len(chunk) > MAX_PAYLOAD:
        raise ValueError("chunk too long")
    return (bytes([0x03, len(chunk)]) + chunk).ljust(REPORT, b"\x00")


def txn(h, dev, report, read=True, timeout_ms=500):
    """Write one 64-byte report (with hidapi's leading report-id 0x00) and
    optionally read the 64-byte reply."""
    n = h.hid_write(dev, b"\x00" + report, REPORT + 1)
    if n < 0:
        raise IOError("hid_write failed: %r" % h.hid_error(dev))
    if not read:
        return None
    buf = ctypes.create_string_buffer(REPORT)
    got = h.hid_read_timeout(dev, buf, REPORT, timeout_ms)
    if got <= 0:
        return None
    return buf.raw[:got]


def parse_reply(reply):
    """Return (func, index, payload) from a CRC-framed reply, or None."""
    if not reply or len(reply) < 8:
        return None
    func = reply[0]
    length = reply[1]
    index = struct.unpack_from("<I", reply, 2)[0]
    payload = reply[6:6 + length]
    return func, index, payload


# ------------------------------------------------------------------- operations

def op_status(h, dev):
    r = parse_reply(txn(h, dev, frame(0x04, 0)))
    state = r[2][0] if r and r[2] else None
    names = {0: "idle", 1: "info-received", 2: "path-set/receiving",
             3: "verifying", 4: "update-success", 5: "update-failed"}
    print(f"transfer state = {state} ({names.get(state, '?')})")
    prog = parse_reply(txn(h, dev, frame(0x04, 1)))
    if prog and len(prog[2]) >= 8:
        rcv, tot = struct.unpack("<II", prog[2][:8])
        print(f"progress       = {rcv}/{tot} frames")


def op_get(h, dev, key):
    r = parse_reply(txn(h, dev, frame(0x07, 0, key.encode())))
    if not r:
        print(f"{key}: <no reply>")
        return
    val = r[2].split(b"\x00", 1)[0].decode("utf-8", "replace")
    print(f"{key} = {val}")


def op_version(h, dev):
    # func 5 index 2 — the read-only branch of the system command.
    r = parse_reply(txn(h, dev, frame(0x05, 2)))
    if r and r[2]:
        print(r[2].split(b"\x00", 1)[0].decode("utf-8", "replace"))
    else:
        print("<no reply>")


def op_push(h, dev, local, remote, chunk_delay):
    if not remote.startswith(ALLOWED_PREFIX):
        sys.exit(f"refusing: target must be under {ALLOWED_PREFIX} "
                 f"(the update is a rename() from /app/temp_file.bin, so it "
                 f"can only land on the /app filesystem). Got: {remote}")
    if len(remote) > MAX_PAYLOAD - 1:
        sys.exit(f"refusing: path too long ({len(remote)} > {MAX_PAYLOAD - 1})")

    data = open(local, "rb").read()
    md5 = hashlib.md5(data).digest()
    chunks = [data[i:i + MAX_PAYLOAD] for i in range(0, len(data), MAX_PAYLOAD)] or [b""]

    print(f"push {local} ({len(data)} B, md5 {md5.hex()}) -> {remote}")
    print(f"  {len(chunks)} data frames of <= {MAX_PAYLOAD} bytes")

    # 1) connect: create the temp file, reset state
    txn(h, dev, frame(0x01, 0), read=False)
    time.sleep(0.05)
    # 2) declare total frame count (uint16), MD5, then destination path
    txn(h, dev, frame(0x02, 0, struct.pack("<H", len(chunks))), read=False)
    time.sleep(0.02)
    txn(h, dev, frame(0x02, 2, md5), read=False)
    time.sleep(0.02)
    txn(h, dev, frame(0x02, 4, remote.encode()), read=False)
    time.sleep(0.02)
    # 3) stream the data (raw frames, no CRC)
    for i, c in enumerate(chunks):
        txn(h, dev, data_frame(c), read=False)
        time.sleep(chunk_delay)
        if i % 50 == 0 or i == len(chunks) - 1:
            print(f"\r  sent {i + 1}/{len(chunks)}", end="", flush=True)
    print()
    time.sleep(0.3)
    # 4) the gun auto-verifies once the count is reached; read the result
    op_status(h, dev)
    res = parse_reply(txn(h, dev, frame(0x04, 2)))
    if res and res[2]:
        print("update result =", res[2].split(b"\x00", 1)[0].decode("utf-8", "replace"))


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("status", help="read transfer state (read-only)")
    g = sub.add_parser("get", help="read a system_info.json key (read-only)")
    g.add_argument("key")
    sub.add_parser("version", help="read model/fw version (read-only)")
    p = sub.add_parser("push", help="upload a file to a path on /app")
    p.add_argument("local")
    p.add_argument("remote")
    p.add_argument("--chunk-delay", type=float, default=0.01,
                   help="seconds between data frames (default 0.01)")
    args = ap.parse_args()

    h = load()
    dev = open_vendor(h)
    try:
        if args.cmd == "status":
            op_status(h, dev)
        elif args.cmd == "get":
            op_get(h, dev, args.key)
        elif args.cmd == "version":
            op_version(h, dev)
        elif args.cmd == "push":
            op_push(h, dev, args.local, args.remote, args.chunk_delay)
    finally:
        h.hid_close(dev)


if __name__ == "__main__":
    main()
