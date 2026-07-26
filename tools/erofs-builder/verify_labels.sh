#!/bin/bash
# Verify a rebuilt system EROFS carries the same SELinux labels as the original.
#
# Two things this gets right that a naive attempt does not:
#
#  * the image is system-as-root — its root IS /, containing /system, /acct,
#    /apex — so --mount-point must be / (the default). Passing /system would
#    prefix every path twice and every label would come out wrong.
#  * Docker's overlayfs silently drops security.* xattrs, so extraction has to
#    land on ext4 or the comparison is meaningless (both sides read as MISSING
#    and it looks like a pass).
set -euo pipefail

IMG=/work/in/system_a.img
OUT=/work/out
mkdir -p "$OUT"

# scratch ext4 so security.* xattrs survive extraction
mkdir -p /mnt/scratch
fallocate -l 6G /scratch.img
mkfs.ext4 -q -F /scratch.img
mount -o loop /scratch.img /mnt/scratch
A=/mnt/scratch/a
B=/mnt/scratch/b

echo "== extract original to ext4 =="
fsck.erofs --extract="$A" "$IMG" >/dev/null
FC="$A/system/etc/selinux/plat_file_contexts"
echo "   $(find "$A" | wc -l) paths, file_contexts has $(wc -l < "$FC") rules"

probe=$(getfattr -n security.selinux --only-values "$A/system/bin/sh" 2>/dev/null || true)
if [ -z "$probe" ]; then
    echo "   fsck.erofs does not extract security.selinux — cannot compare this way" >&2
    exit 2
fi
echo "   extraction preserves labels, e.g. /system/bin/sh = $probe"

echo "== rebuild with --mount-point=/ =="
mkfs.erofs -zlz4hc --mount-point=/ --file-contexts="$FC" \
    "$OUT/system_rebuilt.img" "$A" >/dev/null
ls -la "$OUT/system_rebuilt.img"

echo "== extract rebuild =="
fsck.erofs --extract="$B" "$OUT/system_rebuilt.img" >/dev/null

echo "== compare every label =="
( cd "$A" && find . | sort | while read -r p; do
    printf '%s\t%s\n' "$p" "$(getfattr -n security.selinux --only-values "$p" 2>/dev/null || echo NONE)"
  done ) > /tmp/la.txt
( cd "$B" && find . | sort | while read -r p; do
    printf '%s\t%s\n' "$p" "$(getfattr -n security.selinux --only-values "$p" 2>/dev/null || echo NONE)"
  done ) > /tmp/lb.txt

if diff -q /tmp/la.txt /tmp/lb.txt >/dev/null; then
    echo "   ALL $(wc -l < /tmp/la.txt) paths: labels IDENTICAL"
else
    echo "   $(diff /tmp/la.txt /tmp/lb.txt | grep -c '^<') differing paths, first 15:"
    diff /tmp/la.txt /tmp/lb.txt | head -15
fi

echo "== metadata =="
m() { ( cd "$1" && find . -printf '%p\t%y\t%m\t%U:%G\t%s\n' | sort ); }
m "$A" > /tmp/ma.txt; m "$B" > /tmp/mb.txt
diff -q /tmp/ma.txt /tmp/mb.txt >/dev/null \
    && echo "   type/mode/uid:gid/size IDENTICAL" \
    || { echo "   metadata differs:"; diff /tmp/ma.txt /tmp/mb.txt | head -10; }

umount /mnt/scratch
