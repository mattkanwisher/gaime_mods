/*
 * cam_grab — pull frames from the gun's camera via libvideo.so, to learn the
 * frame struct and prove the real feed is obtainable (Route 1, milestone 1).
 *
 * Replicates gun's comp_video_start() init sequence (reversed in
 * docs/gun-camera-abi.md), installs our own frame callback, and in it safely
 * dumps the frame struct so we can pin the pixel-data pointer offset — which the
 * decompiler would not hand over (Thumb). Every wild pointer read is guarded by
 * a SIGSEGV/SIGBUS longjmp so a wrong guess prints "unreadable" instead of
 * faulting (a fault here could leave the ISP wedged and reboot the box).
 *
 * The camera is a single exclusive stream, so gun must be stopped first. Run:
 *     kill -TERM $(pidof gun); sleep 1        # clean stop, then
 *     cam_grab /dev/video3 /tmp/frames        # writes struct dumps + raw frames
 *     /app/bin/gun &                          # restart aiming
 *
 * Frames may be dark/empty (lens capped, nothing in view) — that is fine; a
 * valid buffer with sane width/height is the result we want.
 *
 * Built against the toolchain sysroot; resolves libvideo at runtime via dlopen
 * so we do not need the vendor headers or an import library.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <dlfcn.h>
#include <signal.h>
#include <setjmp.h>

/* ---- reversed libvideo.so ABI (see docs/gun-camera-abi.md) ---- */
typedef void *(*vs_create_t)(void);
typedef int   (*vs_p_t)(void *h, void *arg);   /* set_camera_source/res/src_para */
typedef int   (*vs_hi_t)(void *h, int v);      /* set_rotate */
typedef int   (*vs_h_t)(void *h);              /* start/stop_camera */
typedef int   (*vs_ret_t)(void *h, void *fr);  /* return_frame */

static vs_create_t vs_create;
static vs_p_t   vs_set_camera_source, vs_set_res, vs_set_src_para, vs_set_frame_cb;
static vs_hi_t  vs_set_rotate;
static vs_h_t   vs_start_camera, vs_stop_camera;
static vs_ret_t vs_return_frame;

static void  *g_handle;
static char   g_dir[256];
static int    g_count, g_max = 6;

/* ---- SIGSEGV-guarded memory probe ---- */
static sigjmp_buf g_jb;
static volatile int g_faulted;
static void fault(int sig) { (void)sig; g_faulted = 1; siglongjmp(g_jb, 1); }

/* Copy n bytes from src to dst, returning 0 on success, -1 if it would fault. */
static int safe_copy(void *dst, const void *src, size_t n)
{
    g_faulted = 0;
    if (sigsetjmp(g_jb, 1)) return -1;
    memcpy(dst, src, n);
    return 0;
}

static int looks_like_ptr(uint32_t v)
{
    /* userspace heap/mmap on this 32-bit ARM Linux: rough sanity window */
    return v >= 0x1000 && v < 0xF0000000;
}

/* The frame callback. libvideo invokes cbptr(?, frame); we take two args and
 * work out which is the frame by looking for a plausible width at +0x20. */
static int frame_cb(void *a0, void *a1)
{
    void *frame = NULL;
    uint32_t hdr[24];

    /* Decide which arg is the frame: the one whose +0x20 reads as a small dim. */
    void *cands[2] = { a1, a0 };
    for (int c = 0; c < 2 && !frame; c++) {
        if (!cands[c]) continue;
        if (safe_copy(hdr, cands[c], sizeof(hdr)) == 0) {
            uint32_t w = hdr[8], h = hdr[9];   /* +0x20, +0x24 */
            if (w >= 16 && w <= 8192 && h >= 16 && h <= 8192) { frame = cands[c]; }
        }
    }
    if (!frame) frame = a1 ? a1 : a0;   /* fall back to arg1 */

    if (g_count < g_max) {
        safe_copy(hdr, frame, sizeof(hdr));
        fprintf(stderr, "[frame %d] cb args a0=%p a1=%p -> frame=%p\n",
                g_count, a0, a1, frame);
        for (int i = 0; i < 24; i++)
            fprintf(stderr, "    +0x%02x = 0x%08x %s\n", i * 4, hdr[i],
                    looks_like_ptr(hdr[i]) ? "(ptr?)" : "");
        uint32_t w = hdr[8], h = hdr[9];
        fprintf(stderr, "    width@0x20=%u height@0x24=%u\n", w, h);

        /* Probe every pointer-looking field: how many readable bytes, and does
         * the size match a WxH image at 1/1.5/2/3 bytes-per-pixel? */
        for (int i = 0; i < 24; i++) {
            if (!looks_like_ptr(hdr[i])) continue;
            uint8_t probe[32];
            if (safe_copy(probe, (void *)hdr[i], sizeof(probe)) == 0) {
                fprintf(stderr, "    field +0x%02x -> readable buffer, first bytes:"
                        " %02x %02x %02x %02x %02x %02x %02x %02x\n", i * 4,
                        probe[0], probe[1], probe[2], probe[3],
                        probe[4], probe[5], probe[6], probe[7]);
                /* If a nearby field holds a plausible byte length, dump it. */
                for (int j = 0; j < 24; j++) {
                    uint32_t len = hdr[j];
                    if (w && h && (len == w*h || len == w*h*3/2 ||
                                   len == w*h*2 || len == w*h*3)) {
                        char path[300];
                        snprintf(path, sizeof(path), "%s/frame%d_off0x%02x_%ux%u_%u.bin",
                                 g_dir, g_count, i * 4, w, h, len);
                        FILE *f = fopen(path, "wb");
                        if (f) {
                            uint8_t *buf = malloc(len);
                            if (buf && safe_copy(buf, (void *)hdr[i], len) == 0) {
                                fwrite(buf, 1, len, f);
                                fprintf(stderr, "    SAVED %s (len via +0x%02x)\n", path, j*4);
                            }
                            free(buf);
                            fclose(f);
                        }
                        break;
                    }
                }
            }
        }
    }
    g_count++;
    if (vs_return_frame) vs_return_frame(g_handle, frame);
    return 0;
}

#define SYM(dst, name) do { \
    *(void **)(&dst) = dlsym(lib, name); \
    if (!dst) { fprintf(stderr, "missing symbol %s\n", name); return 3; } \
} while (0)

int main(int argc, char **argv)
{
    const char *src = argc > 1 ? argv[1] : "/dev/video3";
    snprintf(g_dir, sizeof(g_dir), "%s", argc > 2 ? argv[2] : "/tmp");

    signal(SIGSEGV, fault);
    signal(SIGBUS, fault);

    void *lib = dlopen("libvideo.so", RTLD_NOW | RTLD_GLOBAL);
    if (!lib) { fprintf(stderr, "dlopen libvideo.so: %s\n", dlerror()); return 2; }

    SYM(vs_create,             "video_stream_create");
    SYM(vs_set_camera_source,  "video_stream_set_camera_source");
    SYM(vs_set_res,            "video_stream_set_res");
    SYM(vs_set_src_para,       "video_stream_set_src_para");
    SYM(vs_set_rotate,         "video_stream_set_rotate");
    SYM(vs_start_camera,       "video_stream_start_camera");
    SYM(vs_set_frame_cb,       "video_stream_set_frame_cb");
    SYM(vs_return_frame,       "video_stream_return_frame");
    SYM(vs_stop_camera,        "video_stream_stop_camera");

    g_handle = vs_create();
    fprintf(stderr, "create -> %p\n", g_handle);
    if (!g_handle) return 4;

    /* set_camera_source(h, "/dev/videoN") — arg is a pointer to the path bytes */
    char srcbuf[64]; memset(srcbuf, 0, sizeof(srcbuf));
    snprintf(srcbuf, sizeof(srcbuf), "%s", src);
    fprintf(stderr, "set_camera_source(%s) -> %d\n", src,
            vs_set_camera_source(g_handle, srcbuf));

    int res[2] = { 8, 4 };                 /* {fmt/scale enums} from gun */
    fprintf(stderr, "set_res -> %d\n", vs_set_res(g_handle, res));

    int src_para[3] = { 224, 224, 60 };    /* w, h, fps */
    fprintf(stderr, "set_src_para(224x224@60) -> %d\n", vs_set_src_para(g_handle, src_para));

    fprintf(stderr, "set_rotate -> %d\n", vs_set_rotate(g_handle, 0));
    fprintf(stderr, "start_camera -> %d\n", vs_start_camera(g_handle));

    /* frame cb struct: { enable=1, 0, &frame_cb } */
    struct { int en; int pad; void *cb; } cbs = { 1, 0, (void *)frame_cb };
    fprintf(stderr, "set_frame_cb -> %d\n", vs_set_frame_cb(g_handle, &cbs));

    for (int i = 0; i < 40 && g_count < g_max; i++) usleep(100000);  /* up to 4s */

    fprintf(stderr, "got %d frames; stopping\n", g_count);
    vs_stop_camera(g_handle);
    return 0;
}
