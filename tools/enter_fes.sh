#!/usr/bin/env bash
# Bring the G'AIM'E console from BROM FEL into FES mode, so flash can be read.
#
# Nothing is written to flash. fes1 and U-Boot are loaded into SRAM/DRAM and run
# from there; a power cycle undoes all of it.
#
# Load addresses come from each image's own header (field @0x20 for the eGON
# images, @0x2c for the uboot image), not from sunxi-fel's built-in table --
# sunxi-fel's A523 spl_addr (0x44000) is boot0's address, not fes1's.
#
#   fes1.fex     load 0x0004c000   (its @0x1c, 0x4c340, points at the DRAM
#                                   parameter block, not an entry point)
#   u-boot.fex   load 0x4a000000, work-mode byte at +0xe0
#
# Work mode 0x10 = usb_product = FES; the factory boot log shows the vendor tool
# using exactly this ("sunxi work mode=0x10").
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
FEL="$ROOT/work/sunxi-fel"
FEX="${1:-$ROOT/work/basic_img}"

[ -x "$FEL" ] || { echo "sunxi-fel not found at $FEL" >&2; exit 1; }
for f in fes1.fex u-boot.fex; do
    [ -f "$FEX/$f" ] || { echo "missing $FEX/$f" >&2; exit 1; }
done

echo "== FEL state =="
"$FEL" version

echo "== stage 1: fes1 -> 0x4c000 (brings up DRAM) =="
"$FEL" write 0x4c000 "$FEX/fes1.fex" exe 0x4c000
sleep 1
"$FEL" version >/dev/null || { echo "device stopped responding after fes1" >&2; exit 1; }

echo "== DRAM check =="
"$FEL" writel 0x42000000 0xCAFEBABE
[ "$("$FEL" readl 0x42000000)" = "0xcafebabe" ] || { echo "DRAM not working" >&2; exit 1; }
echo "DRAM ok"

echo "== stage 2: u-boot -> 0x4a000000, work mode 0x10 (FES) =="
"$FEL" write 0x4a000000 "$FEX/u-boot.fex" writel 0x4a0000e0 0x00000010 exe 0x4a000000
sleep 3

echo "== result =="
"$FEL" version || true
echo
echo "ver=0002 above means FES mode. Now use: python3 tools/gaime_fes.py info"
