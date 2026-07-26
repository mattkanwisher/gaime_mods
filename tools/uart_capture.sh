#!/usr/bin/env bash
# Capture a boot log from the gun's J3 UART header, or work out its baud rate.
# No dependencies — uses stty and cat.
#
# The gun's SoC is unmarked (FINDINGS.md section 10), so the boot log is the only
# way to identify it. J3 is four through-holes labelled GND / TX / RX / V3.3.
#
# Wiring — two wires are enough to READ:
#     J3 GND -> adapter GND
#     J3 TX  -> adapter RX        (they cross)
# Leave J3 V3.3 unconnected; the board powers itself from its own USB cable.
# Only add  J3 RX <- adapter TX  when you want to type at the bootloader.
#
# Usage:
#   tools/uart_capture.sh list
#   tools/uart_capture.sh scan                       # try common baud rates
#   tools/uart_capture.sh read 115200 work/boot.log  # capture until Ctrl-C
#
# NOTE ON macOS: termios settings on /dev/cu.* are discarded as soon as the last
# file descriptor closes. Running `stty` and then `cat` as two separate processes
# silently reverts to 9600 baud. Everything below therefore holds the port open on
# fd 3 across both the stty and the read.
#
# A plain CP2102 tops out at 1 Mbaud, so the 1500000 entry below will not work on
# one. If the console turns out to run that fast, use a CP2102N, FT232H or CH343.
set -uo pipefail

BAUDS=(115200 1500000 921600 460800 230400 57600 38400 9600)
SCAN_SECONDS=4

find_ports() {
    ls /dev/cu.usbserial* /dev/cu.usbmodem* /dev/cu.SLAB* /dev/cu.wchusbserial* \
       /dev/ttyUSB* /dev/ttyACM* 2>/dev/null
}

pick_port() {
    local p
    p=$(find_ports | head -1)
    if [ -z "$p" ]; then
        echo "no USB serial adapter found. Plug it in, then: $0 list" >&2
        echo "On macOS use the /dev/cu.* node, never /dev/tty.* (that one blocks on DTR)." >&2
        exit 1
    fi
    echo "$p"
}

# Read from $1 at baud $2 for $3 seconds into file $4, holding the port open so
# the termios settings survive.
grab() {
    local port="$1" baud="$2" secs="$3" out="$4"
    (
        exec 3<>"$port" || exit 1
        stty -f "$port" "$baud" cs8 -cstopb -parenb raw -echo 2>/dev/null || exit 2
        cat <&3 > "$out" &
        local catpid=$!
        sleep "$secs"
        kill "$catpid" 2>/dev/null
        wait "$catpid" 2>/dev/null
    )
}

# Fraction of bytes that look like console text. Garbage => wrong baud.
printable_ratio() {
    python3 -c '
import sys
d = sys.stdin.buffer.read()
if not d:
    print("0.000 0"); raise SystemExit
ok = sum(1 for b in d if 0x20 <= b <= 0x7e or b in (9, 10, 13))
print(f"{ok/len(d):.3f} {len(d)}")'
}

case "${1:-read}" in
list)
    found=$(find_ports)
    if [ -n "$found" ]; then
        echo "$found" | while read -r p; do echo "  $p"; done
    else
        echo "  (none)"
    fi
    ;;

scan)
    PORT="${2:-$(pick_port)}"
    echo "scanning $PORT — power-cycle the gun repeatedly while this runs" >&2
    echo >&2
    best_baud=""; best_ratio=0
    for b in "${BAUDS[@]}"; do
        raw=$(mktemp)
        grab "$PORT" "$b" "$SCAN_SECONDS" "$raw"
        case $? in
          1) echo "  cannot open $PORT" >&2; rm -f "$raw"; exit 1 ;;
          2) printf "  %8s  unsupported by this adapter\n" "$b" >&2; rm -f "$raw"; continue ;;
        esac
        read -r ratio bytes < <(printable_ratio < "$raw")
        note=""
        awk -v r="$ratio" -v n="$bytes" 'BEGIN{exit !(r>0.85 && n>32)}' && note="   <-- looks like text"
        printf "  %8s  %6s bytes  printable %5.1f%%%s\n" \
               "$b" "$bytes" "$(awk -v r="$ratio" 'BEGIN{print r*100}')" "$note" >&2
        if awk -v r="$ratio" -v n="$bytes" -v br="$best_ratio" 'BEGIN{exit !(n>32 && r>br)}'; then
            best_ratio=$ratio; best_baud=$b; cp "$raw" /tmp/uart_best.bin
        fi
        rm -f "$raw"
    done
    echo >&2
    if [ -z "$best_baud" ]; then
        cat >&2 <<'MSG'
nothing received at any baud rate. Check, in this order:
  - J3 TX goes to the adapter's RX (the data lines cross)
  - grounds are common between adapter and gun
  - the gun is actually powered (its own USB cable, not the adapter's V3.3)
  - you are using /dev/cu.* and not /dev/tty.*
MSG
        exit 1
    fi
    echo "best guess: $best_baud. First bytes seen:" >&2
    head -c 400 /tmp/uart_best.bin
    echo >&2
    echo "now:  $0 read $best_baud work/boot.log" >&2
    ;;

read)
    BAUD="${2:-115200}"
    OUT="${3:-}"
    PORT="$(pick_port)"
    [ -n "$OUT" ] && mkdir -p "$(dirname "$OUT")"
    echo "reading $PORT at $BAUD — power-cycle the gun now. Ctrl-C to stop." >&2
    exec 3<>"$PORT" || { echo "cannot open $PORT" >&2; exit 1; }
    stty -f "$PORT" "$BAUD" cs8 -cstopb -parenb raw -echo 2>/dev/null \
        || { echo "adapter will not do $BAUD" >&2; exit 1; }
    if [ -n "$OUT" ]; then cat <&3 | tee "$OUT"; else cat <&3; fi
    ;;

*)
    sed -n '2,24p' "$0" | sed 's/^# \{0,1\}//'
    exit 1
    ;;
esac
