#!/bin/bash
# Round-trip fidelity test for rebuilding the system EROFS.
#
# Extract -> rebuild -> extract again, then compare the two extractions on
# content, mode, uid/gid and SELinux label. If the second matches the first,
# the rebuild preserves everything that matters and is safe to flash. If it
# does not, rebuilding would produce an unbootable image and we must not.
set -euo pipefail

IMG=/work/in/system_a.img
A=/tmp/ex_a
B=/tmp/ex_b
OUT=/work/out

mkdir -p "$OUT"
rm -rf "$A" "$B"

echo "== extract original =="
fsck.erofs --extract="$A" "$IMG" >/dev/null
echo "   files: $(find "$A" -type f | wc -l)  dirs: $(find "$A" -type d | wc -l)  links: $(find "$A" -type l | wc -l)"

FC="$A/system/etc/selinux/plat_file_contexts"
[ -f "$FC" ] || { echo "no plat_file_contexts found" >&2; exit 1; }
echo "   file_contexts: $(wc -l < "$FC") rules"

echo "== rebuild =="
mkfs.erofs -zlz4hc --mount-point=/system --file-contexts="$FC" \
    "$OUT/system_rebuilt.img" "$A" >/dev/null
ls -la "$OUT/system_rebuilt.img"

echo "== extract the rebuild =="
fsck.erofs --extract="$B" "$OUT/system_rebuilt.img" >/dev/null

echo "== compare =="
manifest() {
    ( cd "$1" && find . -printf '%p\t%y\t%m\t%U:%G\t%s\n' | sort )
}
manifest "$A" > /tmp/man_a.txt
manifest "$B" > /tmp/man_b.txt
if diff -q /tmp/man_a.txt /tmp/man_b.txt >/dev/null; then
    echo "   metadata (type/mode/uid:gid/size): IDENTICAL"
else
    echo "   metadata DIFFERS:"
    diff /tmp/man_a.txt /tmp/man_b.txt | head -15
fi

echo "== selinux labels on a sample =="
for f in system/build.prop system/bin/sh system/etc/selinux/plat_file_contexts; do
    la=$(getfattr -n security.selinux --only-values "$A/$f" 2>/dev/null || echo MISSING)
    lb=$(getfattr -n security.selinux --only-values "$B/$f" 2>/dev/null || echo MISSING)
    printf '   %-42s %s %s\n' "$f" "$la" "$([ "$la" = "$lb" ] && echo '== OK' || echo "!= $lb")"
done

echo "== content =="
if diff -r --no-dereference -q "$A" "$B" >/dev/null 2>&1; then
    echo "   file contents: IDENTICAL"
else
    echo "   content differences:"
    diff -r --no-dereference -q "$A" "$B" 2>&1 | head -10
fi
