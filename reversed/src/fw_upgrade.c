/*
 * fw_upgrade — reconstructed from /usr/bin/fw_upgrade (12716-byte ARM ELF).
 *
 * Clean-room C rebuilt from decompiled/fw_upgrade.c. Functionally identical;
 * not a byte-for-byte reproduction.
 *
 * This is the "ask the bootloader to do an update" tool. It does NOT flash
 * anything itself. It writes a 64-byte control block to the `misc` partition —
 * a header the bootloader reads on the next boot to decide whether to enter an
 * update path — then reboots. This is the standard Android BCB (Bootloader
 * Control Block) idiom, here with a Lombo-specific header.
 *
 * Header layout (16 x uint32, 64 bytes), from the field stores in the original:
 *     [0]  magic     'U''P''T'' '  = 0x20545055 (little-endian "UPT ")
 *     [1]  version   1
 *     [2]  checksum  32-bit sum of words [3..15] of the block just built
 *     [3..15]  command / argument words, preserved from the existing block
 *
 * Two device paths, tried in order:
 *     /dev/char/misc     the MTD character device (preferred)
 *     /dev/block/misc    the NFTL block device (fallback)
 *
 * On the character device it issues MEMUNLOCK/MEMERASE-style ioctls
 * (0x80204d01 = MEMGETINFO, 0x40084d02 = MEMERASE) before writing; on the
 * block device it just rewrites in place. Both then `reboot`.
 *
 * IMPORTANT: this ships in the rootfs but nothing invokes it (see FINDINGS
 * section 20). It is included here for completeness and study. Running it writes
 * to `misc` and reboots — do not run it on hardware without understanding what
 * bootloader command you are staging, or you can leave the device trying to
 * apply an update that does not exist.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdint.h>

#define MISC_CHAR   "/dev/char/misc"
#define MISC_BLOCK  "/dev/block/misc"
#define HDR_WORDS   16
#define HDR_BYTES   (HDR_WORDS * 4)

/* MTD ioctls, from the raw numbers in the original. */
#define MEMGETINFO  0x80204d01u   /* struct mtd_info_user */
#define MEMERASE    0x40084d02u   /* struct erase_info_user */

#define MAGIC_UPT   0x20545055u   /* "UPT " */

/* 32-bit word-sum over a byte length (rounded down to whole words). The
 * original's checksum: sum of the uint32s from index 0 up to (len>>2). */
static int32_t check_sum(const int32_t *p, unsigned len_bytes)
{
    if (!p) {
        printf("Err: %s %d", "check_sum", 0x5a);
        return 0;
    }
    int32_t sum = 0;
    for (unsigned i = 0; i < (len_bytes >> 2); i++)
        sum += p[i];
    return sum;
}

/* One quirk faithfully reproduced: fields read back as -1 (0xFFFFFFFF, i.e.
 * erased flash) are normalised to 0 before the block is re-stamped, so a fresh
 * or wiped `misc` doesn't carry erased words into the new checksum. */
static void normalise_erased(uint32_t *hdr)
{
    for (int i = 3; i < HDR_WORDS; i++)
        if (hdr[i] == 0xFFFFFFFFu)
            hdr[i] = 0;
}

static int upgrade_char(int fd)
{
    struct { uint32_t sz, es; } info;   /* only the erasesize field is used */
    if (ioctl(fd, MEMGETINFO, &info) != 0) {
        printf("%s:%d ioctl failed! ret %d\n", __func__, 0x82, -1);
        return 0x82;
    }

    uint32_t hdr[HDR_WORDS] = {0};
    if (read(fd, hdr, HDR_BYTES) < 0) {
        printf("read err ret:%d\n", -1);
        return 0xbd;
    }
    normalise_erased(hdr);
    hdr[0] = MAGIC_UPT;
    hdr[1] = 1;
    hdr[2] = (uint32_t)check_sum((int32_t *)hdr, HDR_BYTES);

    /* Erase the block the header lives in, then rewrite. The original sizes the
     * write buffer to a whole number of erase blocks; a single-block header
     * fits the first erase block. */
    struct { uint32_t start, length; } er = { 0, info.es ? info.es : HDR_BYTES };
    lseek(fd, 0, SEEK_SET);
    if (ioctl(fd, MEMERASE, &er) != 0) {
        printf("%s:%d erase flash failed! ret %d\n", __func__, 0xc9, -1);
        return 0xca;
    }
    lseek(fd, 0, SEEK_SET);
    if (write(fd, hdr, HDR_BYTES) < 0) {
        printf("write err ret:%d\n", -1);
        return 0xd5;
    }
    return 0;
}

static int upgrade_block(int fd)
{
    uint32_t hdr[HDR_WORDS] = {0};
    read(fd, hdr, HDR_BYTES);
    normalise_erased(hdr);
    hdr[0] = MAGIC_UPT;
    hdr[1] = 1;
    hdr[2] = (uint32_t)check_sum((int32_t *)hdr, HDR_BYTES);
    lseek(fd, 0, SEEK_SET);
    write(fd, hdr, HDR_BYTES);
    return 0;
}

int main(void)
{
    int fd = open(MISC_CHAR, O_RDWR | O_SYNC | O_CLOEXEC);
    int rc;

    if (fd >= 0) {
        rc = upgrade_char(fd);
        close(fd);
    } else {
        puts("open /dev/char/misc failed! try to open /dev/block/misc");
        fd = open(MISC_BLOCK, O_RDWR);
        if (fd < 0) {
            puts("open /dev/block/misc failed! exit");
            return 0xe4;
        }
        rc = upgrade_block(fd);
        close(fd);
    }

    if (rc == 0)
        system("reboot");
    return rc;
}
