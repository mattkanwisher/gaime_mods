#!/usr/bin/env bash
# Resilient UART capture: keeps the port open and reconnects if it drops.
#
# A plain `cat /dev/cu.*` ends the moment the adapter glitches or the board
# power-cycles, which silently truncates the log right where it gets useful.
# This reopens and appends instead.
#
# macOS gotcha this preserves: termios on /dev/cu.* reverts as soon as the last
# fd closes, so stty and the read must share one open descriptor.
#
# Usage: tools/uart_watch.sh [baud] [logfile]
set -uo pipefail

BAUD="${1:-115200}"
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
LOG="${2:-$ROOT/work/uart/console.log}"
mkdir -p "$(dirname "$LOG")"

find_port() {
    ls -t /dev/cu.usbserial* /dev/cu.SLAB* /dev/cu.wchusbserial* /dev/cu.usbmodem* \
        2>/dev/null | head -1
}

echo "logging to $LOG at $BAUD (Ctrl-C to stop)" >&2
while true; do
    PORT="$(find_port)"
    if [ -z "$PORT" ]; then sleep 1; continue; fi
    (
        exec 3<>"$PORT" 2>/dev/null || exit 1
        stty -f "$PORT" "$BAUD" cs8 -cstopb -parenb -crtscts raw -echo 2>/dev/null || exit 1
        cat <&3 >> "$LOG"
    )
    sleep 0.3
done
