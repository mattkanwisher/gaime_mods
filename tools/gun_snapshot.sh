#!/usr/bin/env bash
# Snapshot the gun's USB identity so a bootloader-mode attempt can be diffed against it.
# Usage: tools/gun_snapshot.sh [label]     e.g. tools/gun_snapshot.sh trigger-held
set -euo pipefail
LABEL="${1:-baseline}"
OUT="$(cd "$(dirname "$0")/.." && pwd)/work/snapshots"
mkdir -p "$OUT"
{
    echo "== label: $LABEL"
    echo "== system_profiler (Tassei/GAIME entry)"
    system_profiler SPUSBDataType 2>/dev/null | grep -A10 -i 'GAIME' || echo "  (no GAIME device on the bus)"
    echo "== interfaces via hidapi"
    python3 "$(dirname "$0")/gun_probe.py" list 2>&1 || true
    echo "== interface classes via IOKit"
    ioreg -w0 -l -r -c IOUSBHostDevice 2>/dev/null \
      | sed -n '/GAIME v1@/,/^+-o [^ ]/p' \
      | grep -E 'o .*Interface@|bInterfaceClass|bInterfaceSubClass|bInterfaceNumber|bNumEndpoints' || true
} > "$OUT/$LABEL.txt"
echo "wrote $OUT/$LABEL.txt"
