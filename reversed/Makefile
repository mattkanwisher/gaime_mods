# Rebuild the reconstructed gun binaries for the LomboTech N7V5.
#
# Target: ARMv7 Cortex-A7, Linux, glibc 2.25, little-endian, hard-float.
# That matches what the gun runs (uname: Linux 4.19.73; libc-2.25.so).
#
#   make            cross-compile every target in reversed/src (needs CROSS)
#   make check      compile the portable logic with the host cc (no toolchain
#                   needed) — proves the source is correct C, not a build of
#                   the ARM binary
#   make deploy     push a built binary to the gun over the serial console
#   make clean
#
# CROSS is the cross-compiler prefix. The install that works on macOS is:
#     brew trust messense/macos-cross-toolchains        # you must approve this
#     brew install arm-unknown-linux-gnueabihf
# giving CROSS=arm-unknown-linux-gnueabihf-. On Linux, the distro package
# gcc-arm-linux-gnueabihf gives CROSS=arm-linux-gnueabihf-. Override on the
# command line: make CROSS=arm-linux-gnueabihf-

CROSS   ?= arm-unknown-linux-gnueabihf-
CC       = $(CROSS)gcc

# -march=armv7-a matches the A7; static libgcc avoids depending on the exact
# libgcc SONAME on the device. Everything else links against the device's own
# glibc 2.25 at runtime, which is ABI-compatible with what we build here.
CFLAGS   = -O2 -Wall -march=armv7-a -mfpu=neon -mfloat-abi=hard \
           -static-libgcc -D_GNU_SOURCE

SRC      = $(wildcard src/*.c)
BIN      = $(patsubst src/%.c,out/%,$(SRC))

all: $(BIN)

out/%: src/%.c | out
	$(CC) $(CFLAGS) -o $@ $<
	@file $@

out:
	@mkdir -p out

# Host verification: the same sources compiled with the native compiler. This
# does NOT produce a device binary — it proves the reconstructed C is valid and
# self-consistent. Hardware-specific ioctls still compile on Linux; on macOS the
# MTD paths won't (no <mtd/>), so `check` targets usb_monitor, which is portable.
check: | out
	@echo "== host compile (correctness check) =="
	$(CC_HOST) -O2 -Wall -D_GNU_SOURCE -c src/usb_monitor.c -o out/usb_monitor.host.o
	@echo "OK: usb_monitor.c compiles cleanly on the host"

CC_HOST ?= cc

# Push a built binary to the gun's /app over the J3 serial console (no adb on
# the gun; this is the only wired path). Usage: make deploy T=usb_monitor
deploy:
	@test -n "$(T)" || { echo "usage: make deploy T=<name>"; exit 1; }
	python3 ../tools/uart_push.py out/$(T) /app/bin/$(T).new
	@echo "pushed to /app/bin/$(T).new — inspect over serial before replacing the original"

clean:
	rm -rf out

.PHONY: all check deploy clean
