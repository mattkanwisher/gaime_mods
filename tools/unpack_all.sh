#!/usr/bin/env bash
# Full unpack chain for one decrypted G'AIM'E .img: IMAGEWTY -> super -> logical parts -> EROFS.
# Usage: tools/unpack_all.sh work/d8a21f90.img ultimate
set -euo pipefail

IMG="$1"
TAG="$2"
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="$ROOT/work/$TAG"

mkdir -p "$OUT"
python3 "$ROOT/tools/imagewty_unpack.py" "$IMG" -o "$OUT/fex" >"$OUT/imagewty.txt"
python3 "$ROOT/tools/simg2img.py" "$OUT/fex/super.fex" "$OUT/super.img"
python3 "$ROOT/tools/lpunpack.py" "$OUT/super.img" -o "$OUT/parts" >"$OUT/lp.txt"

for p in system vendor product vendor_dlkm system_dlkm; do
    [ -s "$OUT/parts/${p}_a.img" ] || continue
    fsck.erofs --extract="$OUT/ex_$p" "$OUT/parts/${p}_a.img" >/dev/null 2>&1 \
        || echo "note: $p is not EROFS, left as raw image"
done

echo "unpacked $TAG -> $OUT"
