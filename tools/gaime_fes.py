#!/usr/bin/env python3
"""Read-only FES client for the G'AIM'E console (Allwinner A523 / sun55iw3).

Dumps flash without writing to it. See docs/fes-protocol.md for how the wire
format and opcodes were derived.

SAFETY: only read-direction opcodes are defined below. FES_DOWNLOAD (0x206),
FES_FORCE_ERASE (0x220) and FES_FORCE_ERASE_KEY (0x221) are deliberately absent
so this tool cannot issue them even by mistake. FES_TRANSMITE is always sent
with the read flag; the write flag is never constructed.

The device must already be in FES mode:

    sunxi-fel write 0x4c000 fes1.fex exe 0x4c000
    sunxi-fel write 0x4a000000 u-boot.fex writel 0x4a0000e0 0x10 exe 0x4a000000

`sunxi-fel version` should then report ver=0002 (FES) rather than 0001 (FEL).
"""

import argparse
import ctypes
import struct
import sys
import time
from pathlib import Path

VID, PID = 0x1F3A, 0xEFE8
SECTOR = 512
CHUNK = 64 * 1024                      # bytes per FES_TRANSMITE read

USB_READ, USB_WRITE = 0x11, 0x12

FEL_VERIFY_DEVICE = 0x001
FES_UPLOAD = 0x207                     # the read command (FEX_CMD_fes_up)
FES_QUERY_STORAGE = 0x209
FES_FLASH_SET_ON = 0x20A
FES_FLASH_SET_OFF = 0x20B
FES_FLASH_SIZE_PROBE = 0x20E

# AWTags. Leaving the dram tag clear is what selects flash rather than memory.
TAG_NONE, TAG_DRAM = 0x0000, 0x7F00

STORAGE = {0: "nand", 1: "sd/mmc card", 2: "emmc", 3: "spi nor", 4: "spi nand"}


class _Endpoint(ctypes.Structure):
    _fields_ = [("bLength", ctypes.c_ubyte), ("bDescriptorType", ctypes.c_ubyte),
                ("bEndpointAddress", ctypes.c_ubyte), ("bmAttributes", ctypes.c_ubyte),
                ("wMaxPacketSize", ctypes.c_uint16), ("bInterval", ctypes.c_ubyte),
                ("bRefresh", ctypes.c_ubyte), ("bSynchAddress", ctypes.c_ubyte),
                ("extra", ctypes.c_void_p), ("extra_length", ctypes.c_int)]


class _AltSetting(ctypes.Structure):
    _fields_ = [("bLength", ctypes.c_ubyte), ("bDescriptorType", ctypes.c_ubyte),
                ("bInterfaceNumber", ctypes.c_ubyte), ("bAlternateSetting", ctypes.c_ubyte),
                ("bNumEndpoints", ctypes.c_ubyte), ("bInterfaceClass", ctypes.c_ubyte),
                ("bInterfaceSubClass", ctypes.c_ubyte), ("bInterfaceProtocol", ctypes.c_ubyte),
                ("iInterface", ctypes.c_ubyte), ("endpoint", ctypes.POINTER(_Endpoint)),
                ("extra", ctypes.c_void_p), ("extra_length", ctypes.c_int)]


class _Interface(ctypes.Structure):
    _fields_ = [("altsetting", ctypes.POINTER(_AltSetting)), ("num_altsetting", ctypes.c_int)]


class _Config(ctypes.Structure):
    _fields_ = [("bLength", ctypes.c_ubyte), ("bDescriptorType", ctypes.c_ubyte),
                ("wTotalLength", ctypes.c_uint16), ("bNumInterfaces", ctypes.c_ubyte),
                ("bConfigurationValue", ctypes.c_ubyte), ("iConfiguration", ctypes.c_ubyte),
                ("bmAttributes", ctypes.c_ubyte), ("MaxPower", ctypes.c_ubyte),
                ("interface", ctypes.POINTER(_Interface)), ("extra", ctypes.c_void_p),
                ("extra_length", ctypes.c_int)]


class Usb:
    """Minimal libusb-1.0 bulk transport."""

    def __init__(self, lib="/opt/homebrew/lib/libusb-1.0.dylib"):
        self.l = ctypes.CDLL(lib)
        self.l.libusb_open_device_with_vid_pid.restype = ctypes.c_void_p
        self.l.libusb_open_device_with_vid_pid.argtypes = [ctypes.c_void_p,
                                                           ctypes.c_uint16, ctypes.c_uint16]
        for fn in ("libusb_claim_interface", "libusb_release_interface",
                   "libusb_kernel_driver_active", "libusb_detach_kernel_driver"):
            getattr(self.l, fn).argtypes = [ctypes.c_void_p, ctypes.c_int]
        self.l.libusb_close.argtypes = [ctypes.c_void_p]
        self.l.libusb_bulk_transfer.argtypes = [ctypes.c_void_p, ctypes.c_ubyte,
                                                ctypes.c_char_p, ctypes.c_int,
                                                ctypes.POINTER(ctypes.c_int), ctypes.c_uint]
        if self.l.libusb_init(None) != 0:
            sys.exit("libusb_init failed")
        self.h = self.l.libusb_open_device_with_vid_pid(None, VID, PID)
        if not self.h:
            sys.exit(f"no device {VID:04x}:{PID:04x} — is it in FEL/FES mode?")
        self.l.libusb_claim_interface(self.h, 0)
        self.ep_in, self.ep_out = self._find_endpoints()

    def _find_endpoints(self):
        """Endpoint addresses differ between FEL and FES stages — always discover."""
        self.l.libusb_get_device.restype = ctypes.c_void_p
        self.l.libusb_get_device.argtypes = [ctypes.c_void_p]
        self.l.libusb_get_active_config_descriptor.argtypes = [
            ctypes.c_void_p, ctypes.POINTER(ctypes.POINTER(_Config))]
        cfg = ctypes.POINTER(_Config)()
        dev = self.l.libusb_get_device(self.h)
        if self.l.libusb_get_active_config_descriptor(dev, ctypes.byref(cfg)) != 0:
            sys.exit("could not read config descriptor")
        ep_in = ep_out = None
        alt = cfg.contents.interface[0].altsetting[0]
        for i in range(alt.bNumEndpoints):
            ep = alt.endpoint[i]
            if ep.bmAttributes & 0x03 != 0x02:      # bulk only
                continue
            if ep.bEndpointAddress & 0x80:
                ep_in = ep_in or ep.bEndpointAddress
            else:
                ep_out = ep_out or ep.bEndpointAddress
        if ep_in is None or ep_out is None:
            sys.exit("could not find bulk endpoints")
        return ep_in, ep_out

    def _xfer(self, ep, buf, length, timeout=60000):
        n = ctypes.c_int(0)
        rc = self.l.libusb_bulk_transfer(self.h, ep, buf, length, ctypes.byref(n), timeout)
        if rc != 0:
            raise IOError(f"bulk transfer failed on ep 0x{ep:02x}: rc={rc}")
        return n.value

    def write(self, data: bytes):
        buf = ctypes.create_string_buffer(data, len(data))
        return self._xfer(self.ep_out, buf, len(data))

    def read(self, length: int) -> bytes:
        buf = ctypes.create_string_buffer(length)
        got = self._xfer(self.ep_in, buf, length)
        return buf.raw[:got]

    def close(self):
        self.l.libusb_release_interface(self.h, 0)
        self.l.libusb_close(self.h)


def aw_header(length: int, cmd: int) -> bytes:
    return (b"AWUC" + struct.pack("<IIHBBBB", 0, length, 0, 0, 0x0C, cmd, 0)
            + struct.pack("<I", length) + b"\0" * 10)


class Fes:
    def __init__(self, usb: Usb):
        self.u = usb

    def _send(self, data: bytes):
        self.u.write(aw_header(len(data), USB_WRITE))
        self.u.write(data)
        self._csw()

    def _recv(self, length: int) -> bytes:
        self.u.write(aw_header(length, USB_READ))
        out = b""
        while len(out) < length:
            out += self.u.read(length - len(out))
        self._csw()
        return out

    def _csw(self):
        r = self.u.read(13)
        if len(r) < 13 or r[:4] != b"AWUS":
            raise IOError(f"bad AWUS status: {r!r}")
        if r[12] != 0:
            raise IOError(f"AWUS csw_status={r[12]}")

    def _status(self):
        s = self._recv(8)
        mark, tag, state = struct.unpack_from("<HHB", s, 0)
        if state != 0:
            raise IOError(f"command failed, state={state}")

    def cmd(self, code: int, address=0, length=0, flags=0):
        self._send(struct.pack("<HHIII", code, 0, address, length, flags))

    def verify_device(self):
        self.cmd(FEL_VERIFY_DEVICE)
        d = self._recv(32)
        self._status()
        magic, board, fw, mode = struct.unpack_from("<8sIIH", d, 0)
        return {"magic": magic.decode(errors="replace"), "board": board,
                "fw": fw, "mode": mode}

    def query_storage(self):
        self.cmd(FES_QUERY_STORAGE)
        d = self._recv(4)
        self._status()
        return struct.unpack("<I", d)[0]

    def flash_size_probe(self):
        self.cmd(FES_FLASH_SIZE_PROBE)
        d = self._recv(4)
        self._status()
        return struct.unpack("<I", d)[0]        # in sectors

    def flash_set(self, on: bool):
        self.cmd(FES_FLASH_SET_ON if on else FES_FLASH_SET_OFF)
        self._status()

    def read_sectors(self, sector: int, count: int, sink=None, progress=None) -> bytes:
        """Read `count` 512-byte sectors from flash starting at `sector`.

        Uses FES_UPLOAD with the dram tag clear, which is what selects flash.
        With the tag clear the device advances by sectors, not bytes.
        """
        out = bytearray()
        remaining = count * SECTOR
        addr, done = sector, 0
        while remaining:
            n = min(CHUNK, remaining)
            self.cmd(FES_UPLOAD, address=addr, length=n, flags=TAG_NONE)
            blk = self._recv(n)
            self._status()
            if sink is not None:
                sink.write(blk)
            else:
                out += blk
            remaining -= n
            addr += n // SECTOR
            done += n
            if progress:
                progress(done, count * SECTOR)
        return bytes(out)


def calibrate(fes: "Fes", parts) -> int:
    """Work out the gap between GPT LBAs and FES logical addresses.

    The device's GPT is self-consistent (my_lba=1 sits at FES sector 1) but its
    partition entries point 40960 sectors above where the data actually lives —
    FES logical addressing skips a reserved region the GPT does not describe.
    Rather than trust that constant, confirm it against a partition whose magic
    we know, and refuse to dump if nothing matches.
    """
    probes = [("boot_a", b"ANDROID!"), ("init_boot_a", b"ANDROID!"),
              ("vendor_boot_a", b"VNDRBOOT"), ("vbmeta_a", b"AVB0")]
    by_name = {p["name"]: p for p in parts}
    for offset in (40960, 0):
        for name, magic in probes:
            p = by_name.get(name)
            if not p or p["first"] < offset:
                continue
            fes.cmd(FES_UPLOAD, address=p["first"] - offset, length=SECTOR, flags=TAG_NONE)
            d = fes._recv(SECTOR)
            fes._status()
            if d.startswith(magic):
                return offset
    sys.exit("could not calibrate FES addressing — no known partition magic matched; "
             "refusing to dump rather than write out misaligned data")


def read_gpt(fes: "Fes"):
    """Partition table straight off the device, not from the firmware image."""
    head = fes.read_sectors(0, 64)
    off = head.find(b"EFI PART")
    if off < 0:
        sys.exit("no GPT found on device")
    part_lba = struct.unpack_from("<Q", head, off + 0x48)[0]
    num, esz = struct.unpack_from("<II", head, off + 0x50)
    base = part_lba * SECTOR
    parts = []
    for i in range(num):
        e = head[base + i * esz: base + (i + 1) * esz]
        if len(e) < esz or e[:16] == b"\0" * 16:
            continue
        first, last = struct.unpack_from("<QQ", e, 32)
        name = e[56:128].decode("utf-16le").split("\0")[0]
        parts.append({"name": name, "first": first, "sectors": last - first + 1})
    return parts


def human(n: int) -> str:
    for unit in ("B", "KiB", "MiB", "GiB"):
        if n < 1024 or unit == "GiB":
            return f"{n:.1f} {unit}"
        n /= 1024


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("info", help="device mode, storage type, flash size")
    sub.add_parser("gpt", help="list partitions from the device's GPT")
    r = sub.add_parser("read", help="read sectors to a file")
    r.add_argument("sector", type=lambda s: int(s, 0))
    r.add_argument("count", type=lambda s: int(s, 0), help="in 512-byte sectors")
    r.add_argument("outfile", type=Path)
    d = sub.add_parser("dump", help="dump named partitions (or all) to a directory")
    d.add_argument("outdir", type=Path)
    d.add_argument("-p", "--partitions", nargs="*",
                   help="partition names; default is every partition")
    d.add_argument("--skip", nargs="*", default=[],
                   help="partition names to skip")
    args = ap.parse_args()

    usb = Usb()
    fes = Fes(usb)
    try:
        dev = fes.verify_device()
        mode = {1: "FEL", 2: "FES"}.get(dev["mode"], f'0x{dev["mode"]:x}')
        print(f'{dev["magic"]}  board=0x{dev["board"]:08x}  mode={mode}')
        if dev["mode"] != 2:
            sys.exit("device is not in FES mode — load fes1 + u-boot first")

        fes.flash_set(True)

        if args.cmd == "info":
            st = fes.query_storage()
            size = fes.flash_size_probe()
            print(f"storage    : {st} ({STORAGE.get(st, 'unknown')})")
            print(f"flash size : {size} sectors = {size * SECTOR / 2**30:.2f} GiB")

        elif args.cmd == "gpt":
            parts = read_gpt(fes)
            print(f"FES offset: {calibrate(fes, parts)} sectors\n")
            for p in parts:
                print(f'{p["name"]:18s} first={p["first"]:>10d} '
                      f'sectors={p["sectors"]:>10d}  {human(p["sectors"] * SECTOR)}')

        elif args.cmd == "read":
            t0 = time.time()
            data = fes.read_sectors(args.sector, args.count)
            args.outfile.write_bytes(data)
            print(f"read {len(data)} bytes from sector {args.sector} "
                  f"in {time.time() - t0:.1f}s -> {args.outfile}")

        else:
            args.outdir.mkdir(parents=True, exist_ok=True)
            parts = read_gpt(fes)
            offset = calibrate(fes, parts)
            print(f"FES addressing calibrated: GPT LBA - {offset} sectors\n")
            wanted = [p for p in parts
                      if (not args.partitions or p["name"] in args.partitions)
                      and p["name"] not in args.skip]
            if not wanted:
                sys.exit("no matching partitions")
            total = sum(p["sectors"] for p in wanted) * SECTOR
            print(f'dumping {len(wanted)} partitions, {human(total)} total\n')
            grand = time.time()
            for p in wanted:
                dst = args.outdir / f'{p["name"]}.img'
                nbytes = p["sectors"] * SECTOR
                t0 = time.time()

                def show(done, tot, _n=p["name"], _t=t0):
                    el = time.time() - _t
                    rate = done / el / 2**20 if el > 0 else 0
                    print(f"\r  {_n:16s} {100 * done / tot:5.1f}%  "
                          f"{human(done):>10s}  {rate:5.1f} MiB/s", end="", flush=True)

                with dst.open("wb") as fh:
                    fes.read_sectors(p["first"] - offset, p["sectors"],
                                     sink=fh, progress=show)
                dt = time.time() - t0
                print(f'\r  {p["name"]:16s} done   {human(nbytes):>10s}  '
                      f'in {dt:5.1f}s -> {dst.name}' + " " * 12)
            print(f"\ntotal {human(total)} in {time.time() - grand:.1f}s")
    finally:
        usb.close()


if __name__ == "__main__":
    main()
