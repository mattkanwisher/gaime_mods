/*
 * v4l2_probe — query-only inspection of the gun's V4L2 nodes.
 *
 * No streaming, no buffers: just QUERYCAP + ENUM_FMT + G_FMT on each node given
 * on the command line. This is safe to run while `gun` is using the camera via
 * its own /dev/lb_util path — it only reads capability/format, it does not touch
 * the pipeline. It tells us whether /dev/video1/3/4 are real capture devices and
 * what pixel format / resolution they carry, which decides whether a
 * V4L2 -> UVC bridge is worth building.
 *
 * Cross-compiled for the N7V5 (ARMv7 / glibc 2.25). Uses only <linux/videodev2.h>
 * uapi, which the toolchain sysroot provides.
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

static void fourcc(char *out, unsigned f)
{
    out[0] = f & 0xff; out[1] = (f >> 8) & 0xff;
    out[2] = (f >> 16) & 0xff; out[3] = (f >> 24) & 0xff; out[4] = 0;
}

static void probe(const char *path)
{
    printf("== %s ==\n", path);
    int fd = open(path, O_RDWR | O_NONBLOCK);
    if (fd < 0) { printf("  open: %s\n", strerror(errno)); return; }

    struct v4l2_capability cap;
    memset(&cap, 0, sizeof(cap));
    if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == 0) {
        printf("  driver=%s card=%s bus=%s caps=0x%08x devcaps=0x%08x\n",
               cap.driver, cap.card, cap.bus_info,
               cap.capabilities, cap.device_caps);
    } else {
        printf("  QUERYCAP: %s\n", strerror(errno));
    }

    /* Enumerate the capture formats this node offers. */
    for (unsigned t = 0; t < 2; t++) {
        unsigned type = t ? V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE
                          : V4L2_BUF_TYPE_VIDEO_CAPTURE;
        for (unsigned i = 0; ; i++) {
            struct v4l2_fmtdesc fd_;
            memset(&fd_, 0, sizeof(fd_));
            fd_.index = i; fd_.type = type;
            if (ioctl(fd, VIDIOC_ENUM_FMT, &fd_) != 0) break;
            char cc[5]; fourcc(cc, fd_.pixelformat);
            printf("  fmt[%s %u]: %s  '%s'\n",
                   t ? "mplane" : "single", i, cc, fd_.description);
        }
    }

    /* Current format on the single-plane capture type, then the mplane type. */
    struct v4l2_format f;
    memset(&f, 0, sizeof(f));
    f.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (ioctl(fd, VIDIOC_G_FMT, &f) == 0) {
        char cc[5]; fourcc(cc, f.fmt.pix.pixelformat);
        printf("  G_FMT single: %ux%u %s field=%u bytesperline=%u size=%u\n",
               f.fmt.pix.width, f.fmt.pix.height, cc, f.fmt.pix.field,
               f.fmt.pix.bytesperline, f.fmt.pix.sizeimage);
    } else {
        memset(&f, 0, sizeof(f));
        f.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
        if (ioctl(fd, VIDIOC_G_FMT, &f) == 0) {
            char cc[5]; fourcc(cc, f.fmt.pix_mp.pixelformat);
            printf("  G_FMT mplane: %ux%u %s planes=%u\n",
                   f.fmt.pix_mp.width, f.fmt.pix_mp.height, cc,
                   f.fmt.pix_mp.num_planes);
        } else {
            printf("  G_FMT: %s\n", strerror(errno));
        }
    }
    close(fd);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("usage: %s /dev/videoN [...]\n", argv[0]);
        return 2;
    }
    for (int i = 1; i < argc; i++) probe(argv[i]);
    return 0;
}
