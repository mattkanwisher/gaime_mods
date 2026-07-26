#!/usr/bin/env python3
"""Probe the FES stage for a feedback channel and a U-Boot command path.

Read-only / RAM-only. Nothing here touches flash:

  FES_INFO    (0x203)  32-byte status block
  FES_GET_MSG (0x204)  may return U-Boot console output — the feedback channel
                       we have been missing
  FES_QUERY_SECURE (0x230)  secure-boot state as the FES stage sees it

If GET_MSG returns console text, the next step is a small ARM32 stub that calls
U-Boot's run_command(), giving a bootloader shell over USB: load a kernel and
ramdisk into DRAM with the dram tag, then `bootm` them. Normal boot stays stock
because none of this is written to flash.
"""

import importlib.util
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
_spec = importlib.util.spec_from_file_location("gaime_fes", HERE / "gaime_fes.py")
gfes = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(gfes)

FES_RUN = 0x202
FES_INFO = 0x203
FES_GET_MSG = 0x204
FES_QUERY_SECURE = 0x230


def dump(label, data: bytes):
    print(f"  {label}: {len(data)} bytes")
    printable = "".join(chr(b) if 32 <= b < 127 else "." for b in data[:256])
    print(f"    hex   {data[:48].hex()}")
    print(f"    ascii {printable[:96]}")


def main() -> None:
    usb = gfes.Usb()
    fes = gfes.Fes(usb)
    try:
        dev = fes.verify_device()
        print(f'device: {dev["magic"]} board=0x{dev["board"]:08x} '
              f'mode={"FES" if dev["mode"] == 2 else dev["mode"]}')
        if dev["mode"] != 2:
            sys.exit("not in FES mode — run tools/enter_fes.sh first")

        print("\n== FES_INFO (0x203) ==")
        try:
            fes.cmd(FES_INFO)
            dump("info", fes._recv(32))
            fes._status()
        except Exception as e:
            print(f"  failed: {e}")

        print("\n== FES_QUERY_SECURE (0x230) ==")
        try:
            fes.cmd(FES_QUERY_SECURE)
            d = fes._recv(4)
            fes._status()
            print(f"  secure state = 0x{struct.unpack('<I', d)[0]:08x}")
        except Exception as e:
            print(f"  failed: {e}")

        print("\n== FES_GET_MSG (0x204) — looking for console output ==")
        for length in (1024, 256):
            try:
                fes.cmd(FES_GET_MSG, address=length)
                dump(f"get_msg({length})", fes._recv(length))
                fes._status()
                break
            except Exception as e:
                print(f"  len {length} failed: {e}")
    finally:
        usb.close()


if __name__ == "__main__":
    main()
