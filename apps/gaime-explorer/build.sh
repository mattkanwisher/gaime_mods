#!/usr/bin/env bash
# Build the GAIME Hello APK with the raw SDK tools (no Gradle).
#
# The app deliberately has no resources beyond AndroidManifest.xml — the UI is
# built in Java — so the whole build is aapt2 link + javac + d8 + apksigner.
set -euo pipefail

HERE="$(cd "$(dirname "$0")" && pwd)"
SDK="${ANDROID_SDK:-$HOME/Library/Android/sdk}"
API="${API:-33}"
BT="$(ls -d "$SDK"/build-tools/* | sort -V | tail -1)"
JAR="$SDK/platforms/android-$API/android.jar"

[ -f "$JAR" ] || { echo "no android.jar for API $API at $JAR" >&2; exit 1; }

OUT="$HERE/out"
rm -rf "$OUT"; mkdir -p "$OUT/classes"

echo "== aapt2 link (manifest only) =="
"$BT/aapt2" link \
    -I "$JAR" \
    --manifest "$HERE/AndroidManifest.xml" \
    --min-sdk-version 28 --target-sdk-version 33 \
    -o "$OUT/base.apk"

echo "== javac =="
javac --release 17 -nowarn \
    -cp "$JAR" \
    -d "$OUT/classes" \
    $(find "$HERE/src" -name '*.java')

echo "== d8 =="
"$BT/d8" --min-api 28 --output "$OUT" \
    $(find "$OUT/classes" -name '*.class')

echo "== package =="
cp "$OUT/base.apk" "$OUT/unsigned.apk"
(cd "$OUT" && zip -q unsigned.apk classes.dex)

echo "== sign =="
# Keystore lives outside out/ so rebuilds keep the same signing identity;
# a fresh key each build makes `adb install -r` fail with
# INSTALL_FAILED_UPDATE_INCOMPATIBLE.
KS="$HERE/debug.keystore"
# Only create the key once; with set -e, keytool failing because the alias
# already exists would abort the whole build.
if [ ! -f "$KS" ]; then
    keytool -genkeypair -keystore "$KS" -storepass android -keypass android \
        -alias gaime -keyalg RSA -keysize 2048 -validity 10000 \
        -dname "CN=GAIME, O=gaime_mods, C=GB" >/dev/null 2>&1
fi

"$BT/zipalign" -f 4 "$OUT/unsigned.apk" "$OUT/aligned.apk"
"$BT/apksigner" sign \
    --ks "$KS" --ks-pass pass:android --key-pass pass:android \
    --min-sdk-version 28 \
    --out "$OUT/gaime-explorer.apk" "$OUT/aligned.apk"

"$BT/apksigner" verify --print-certs "$OUT/gaime-explorer.apk" | head -3
ls -la "$OUT/gaime-explorer.apk"
echo
echo "install with:"
echo "  adb install -r -g $OUT/gaime-explorer.apk"
echo "  adb shell appops set nu.hyperworks.gaimeexplorer SYSTEM_ALERT_WINDOW allow"
echo "  adb shell am start -n nu.hyperworks.gaimeexplorer/.ExplorerActivity"
