/*
 * frame_tap — an LD_PRELOAD shim that taps the frames gun already receives.
 *
 * The standalone approach fails at video_stream_start_camera (the camera
 * subsystem needs init only gun does — see docs/gun-camera-abi.md). So instead
 * of bringing the camera up ourselves, we ride along inside gun's process: we
 * intercept video_stream_set_frame_cb, swap gun's frame callback for our own
 * wrapper, and forward to gun's original after copying the frame. gun has
 * already done all the sensor/ISP bring-up, so the frames are real.
 *
 *   kill -9 $(pidof gun)                       # stop the running gun (once)
 *   LD_PRELOAD=/app/frame_tap.so /app/bin/gun &  # restart it with the tap
 *   # -> writes /app/tap.log and a few /app/tapframe_*.bin
 *
 * Frame struct (from gun.c): width @ +0x20, height @ +0x24. The pixel-data
 * pointer offset is unknown, so the wrapper dumps the struct and probes every
 * pointer-looking field for a buffer whose size matches WxH at common
 * bytes-per-pixel, saving the first match. Every wild read is SIGSEGV-guarded.
 *
 * Build: arm-...-gcc -shared -fPIC -o frame_tap.so frame_tap.c -ldl
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <dlfcn.h>
#include <signal.h>
#include <setjmp.h>
#include <pthread.h>
#include <stdarg.h>

#define LOG_PATH   "/app/tap.log"
#define OUT_DIR    "/app"
#define MAX_SAVE   5

static int (*real_set_frame_cb)(void *, void *);
static int (*orig_cb)(void *, void *);
static void  *g_handle;
static int    g_count;
static FILE  *g_log;
static pthread_mutex_t g_lk = PTHREAD_MUTEX_INITIALIZER;

/* per-thread SIGSEGV guard for probing unknown pointers */
static __thread sigjmp_buf t_jb;
static __thread volatile int t_fault;
static void on_fault(int s) { (void)s; t_fault = 1; siglongjmp(t_jb, 1); }

static int safe_copy(void *dst, const void *src, size_t n)
{
    t_fault = 0;
    if (sigsetjmp(t_jb, 1)) return -1;
    memcpy(dst, src, n);
    return 0;
}

static int is_ptr(uint32_t v) { return v >= 0x1000 && v < 0xF0000000; }

static void logf_(const char *fmt, ...)
{
    if (!g_log) return;
    va_list ap; va_start(ap, fmt);
    vfprintf(g_log, fmt, ap);
    va_end(ap);
    fflush(g_log);
}

/* Our stand-in callback: tap, then hand off to gun's real one. */
static int cb_wrapper(void *a0, void *a1)
{
    /* gun's callback is (ctx, frame); frame is arg1. Sanity-check via width. */
    void *frame = a1;
    uint32_t hdr[24];

    pthread_mutex_lock(&g_lk);
    if (g_count < MAX_SAVE && safe_copy(hdr, frame, sizeof(hdr)) == 0) {
        uint32_t w = hdr[8], h = hdr[9];     /* +0x20, +0x24 */
        logf_("[frame %d] frame=%p width@0x20=%u height@0x24=%u\n",
              g_count, frame, w, h);
        for (int i = 0; i < 24; i++)
            logf_("    +0x%02x = 0x%08x%s\n", i * 4, hdr[i],
                  is_ptr(hdr[i]) ? "  (ptr?)" : "");

        if (w >= 16 && w <= 8192 && h >= 16 && h <= 8192) {
            /* find a pointer field backing a WxH image at 1 / 1.5 / 2 / 3 bpp */
            size_t cands[4] = { (size_t)w*h, (size_t)w*h*3/2,
                                (size_t)w*h*2, (size_t)w*h*3 };
            for (int i = 0; i < 24 && g_count < MAX_SAVE; i++) {
                if (!is_ptr(hdr[i])) continue;
                for (int c = 0; c < 4; c++) {
                    uint8_t *buf = malloc(cands[c]);
                    if (!buf) continue;
                    if (safe_copy(buf, (void *)hdr[i], cands[c]) == 0) {
                        char path[256];
                        const char *tag = c==0?"gray":c==1?"nv12":c==2?"yuyv":"rgb";
                        snprintf(path, sizeof(path),
                                 OUT_DIR "/tapframe%d_off0x%02x_%ux%u_%s.bin",
                                 g_count, i * 4, w, h, tag);
                        FILE *f = fopen(path, "wb");
                        if (f) { fwrite(buf, 1, cands[c], f); fclose(f);
                                 logf_("    SAVED %s (data @+0x%02x)\n", path, i*4); }
                        free(buf);
                        break;   /* first readable size for this field */
                    }
                    free(buf);
                }
            }
            g_count++;
        }
    }
    pthread_mutex_unlock(&g_lk);

    return orig_cb ? orig_cb(a0, a1) : 0;
}

/* The intercept. gun passes cbstruct = { int enable; int pad; void *cb; }. */
int video_stream_set_frame_cb(void *handle, void *cbstruct)
{
    if (!real_set_frame_cb)
        real_set_frame_cb = dlsym(RTLD_NEXT, "video_stream_set_frame_cb");
    if (!g_log) {
        g_log = fopen(LOG_PATH, "w");
        signal(SIGSEGV, on_fault);
        signal(SIGBUS, on_fault);
        logf_("frame_tap loaded; intercepting set_frame_cb(handle=%p)\n", handle);
    }
    g_handle = handle;

    /* swap gun's callback (at struct +8) for ours, keep the original */
    void **slot = (void **)((char *)cbstruct + 8);
    orig_cb = (int (*)(void *, void *)) *slot;
    *slot = (void *) cb_wrapper;
    logf_("hooked: gun cb=%p -> wrapper=%p\n", (void *)orig_cb, (void *)cb_wrapper);

    return real_set_frame_cb ? real_set_frame_cb(handle, cbstruct) : -1;
}
