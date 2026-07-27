# Gun camera stack — reverse-engineered ABI (Route 1 groundwork)

Goal: route the real camera image the CV uses to the host over UVC. This documents
the vendor camera stack, reversed from `decompiled/gun.c` and the shared libraries
in `backup/gun/rootfs/usr/lib/`. It is the groundwork for a custom
camera→UVC bridge; the bridge itself is not built (see "What's left" below).

## The libraries

| Library | Role |
|---|---|
| `libvideo.so` (38 KB) | the `video_stream_*` API — a wrapper over the Lombo ISP |
| `liblb_extra_vchn.so` | `lb_vchn_*` — an in-process producer/consumer frame queue |
| `libuvcg.so` (68 KB) | UVC gadget lib; **also exports a full V4L2→UVC bridge API** |
| `libcampan.so` | higher-level camera-pan/analytics (not the stream API) |

The `video_stream_*` symbols live in **`libvideo.so`**, not libcampan.

## The camera init sequence

Reversed from `comp_video_start()` in `gun.c`. This is exactly what a bridge must
replicate:

```c
handle = video_stream_create();
video_stream_set_camera_source(handle, "/dev/video3");   // ISP output path0
video_stream_set_res(handle,       &res);                // {8, 4} (fmt/scale enums)
video_stream_set_src_para(handle,  &src);                // {0xE0, 0xE0, 0x3C} = 224x224 @ 60
video_stream_set_rotate(handle,    0);
video_stream_start_camera(handle);
video_stream_set_frame_cb(handle,  &cb);                 // cb = {enable=1, 0, &callback}
// callback(ctx, frame) is invoked per frame; return the buffer with
// video_stream_return_frame(handle, frame) when done.
```

Two findings that matter:

- **The source is `/dev/video3`** — the ISP's `viss-isp0.path0`. Opened cold it
  returns ENODEV (`tools/v4l2_probe.c` confirmed this); it only works *through*
  libvideo, which brings up the ISP media pipeline first. So the earlier "ISP V4L2
  nodes are dead" conclusion is refined: they are dead to a naive opener but live
  under libvideo's setup.
- **The CV resolution is 224×224 @ 60fps** — the NN input crop. That is literally
  "the feed the CV uses"; it is small and square, not a 1080p picture.

## The frame path

```
libvideo frame_cb(ctx, frame)          gun: FUN_00016090
   -> comp_gaime_push_frame(frame)
        -> lb_vchn_sendp_push(chan, frame)     when DAT_00031770 (vchn enabled)
        -> else video_stream_return_frame(frame)

detection thread (prctl name "gaime_det", FUN_00015d34):
   frame = lb_vchn_recvp_request(chan)
   width  = *(int*)(frame + 0x20)
   height = *(int*)(frame + 0x24)
   nna_gaime_process(nn_handle, &params, &result, imu_roll)   // params carries w/h
   lb_vchn_recvp_return(chan, frame)
```

- `lb_vchn` is gun's **internal** queue between the camera-callback thread
  (producer, `sendp`) and the NN thread (consumer, `recvp`). It is created by
  `lb_vchn_init` inside gun, so tapping it from another process is not a given.
- **Frame struct**: `width @ +0x20`, `height @ +0x24` are confirmed. The pixel
  **data pointer offset was not cleanly recovered** — the NN reads it via the
  `params` block, and Ghidra could not disassemble libvideo/libuvcg (Thumb) to
  pin the exact layout. This is the main missing piece for a working callback.

## Constraints found on hardware

- **Single exclusive camera stream.** `/dev/video1` (raw CSI) is EBUSY while gun
  runs; a second `video_stream` from another process almost certainly cannot open
  the sensor concurrently. So simultaneous aim + host-view is not available; a
  bridge means a *view mode* that stops gun.
- **Stopping gun abruptly reboots the box.** `kill gun` -> reboot ~15 s later
  (`sensor h63p_mipi power state is already 0!`), from an unclean ISP teardown
  (gun holds no `/dev/watchdog`, so it is not a userspace watchdog). A bridge must
  stop gun *cleanly* (via its own shutdown path) or accept the reboot risk.

## What's left to build a working bridge

1. Pin the frame **pixel-data pointer + pixel format** in the libvideo frame
   struct (needs a Thumb-correct disassembly of `libvideo.so`, or on-device
   experimentation dumping frame bytes).
2. A **camera-grab tool**: `dlopen("libvideo.so")`, run the init sequence above,
   in the callback copy the frame's pixels to a file. First milestone — proves the
   real image is obtainable. Must run with gun stopped.
3. The **UVC push**: reverse the `libuvcg_*` V4L2→UVC API (or drive the UVC
   functionfs directly) and feed the grabbed frames to it, with UVC re-enabled in
   the gadget (`CFG_UVC_ENABLE=1`).
4. Package as a **view mode**: stop gun cleanly → grab+stream → on exit, restart
   gun. Aiming and host-view remain mutually exclusive.

Assessment: the ABI is reversed and the path is clear, but a working bridge is a
multi-session effort — three undocumented library ABIs, a frame layout the
decompiler won't hand over cleanly, and a camera pipeline that reboots on error.

## Milestone 1 result: the video_stream ABI is correct, but not sufficient

`tools/cam_grab.c` — a `dlopen("libvideo.so")` tool that runs the reversed init
sequence and installs a SIGSEGV-guarded frame callback to dump the frame struct —
was cross-compiled and run on the device (with `gun` stopped so the camera was
free). Output:

```
create -> 0x16618
set_camera_source(/dev/video3) -> 0
set_res -> 0
set_src_para(224x224@60) -> 0
set_rotate -> 0
start_camera -> -2147479552          # 0x80001000, error
set_frame_cb -> 0
got 0 frames
```

So **the ABI is right** — `create`, `set_camera_source("/dev/video3")`, `set_res`,
`set_src_para`, `set_rotate` all succeed. But **`start_camera` fails with
`0x80001000`**, and the console prints `sensor h63p_mipi power state is already
0!` — the sensor never powers on.

This reproduces on a **clean boot with `gun` moved aside** (so a dirty ISP from
gun's earlier SIGKILL is ruled out), so it is not a stale-state problem.
`gun` itself restarts and streams fine, so the camera hardware works — which
means the bring-up needs **more than the `video_stream` API**: the sensor
power/i2c sequencing and ISP/omx/axvu subsystem init that `gun`'s `main` performs
through `libcampan` / `libomx*` / `/dev/axvu_dev` before it ever calls
`video_stream_start_camera`. `gun.c` shows no extra `video_stream_*` calls, so the
missing init is in those other libraries, not the video_stream layer.

### Reboot behaviour, clarified

Killing `gun` with SIGKILL and **not** restarting it does **not** reboot the box
(uptime kept climbing). The earlier reboot was caused by starting a *second* `gun`
while the first was dying (two openers of the exclusive camera). `gun` ignores
SIGTERM. So the safe pattern is: `kill -9 gun` once, run the experiment, then
`/app/bin/gun &` exactly once — or disable autostart (`mv /app/bin/gun aside`) and
reboot for a truly clean ISP.

### Verdict on Route 1

The `video_stream` ABI is fully reversed and replicable, but a standalone camera
bring-up is blocked at `start_camera` by subsystem init that lives in the vendor's
higher-level libraries (`libcampan` + `libomx*` + `axvu`). Reproducing that is a
substantially larger reverse-engineering effort than the video_stream layer, and
the realistic shortcut is the other direction entirely: **inject into `gun`'s own
process** (LD_PRELOAD a shim, or patch it) to tap the frames it already has,
rather than bringing the camera up ourselves. Left here as a documented result.

## Milestone 2: the LD_PRELOAD frame tap — built, correct, blocked on hardware

Since standalone bring-up fails, `tools/frame_tap.c` rides inside gun instead: an
LD_PRELOAD shim that intercepts `video_stream_set_frame_cb`, swaps gun's frame
callback for a wrapper that copies the frame (SIGSEGV-guarded struct dump + saves
the pixel buffer at the detected offset), then forwards to gun's original. No
sensor bring-up needed — gun already did it.

Deployed via a launch wrapper (`/app/bin/gun` -> `env LD_PRELOAD=/app/frame_tap.so
/app/bin/gun.real`). **Verified: frame_tap.so loads into gun's process**
(`frame_tap` present in `/proc/$(pidof gun.real)/maps`), and gun imports
`video_stream_set_frame_cb` as an undefined symbol with `libvideo.so` in its
`DT_NEEDED`, so the interposition is sound.

But the tap never fires, and the reason is **hardware**: the camera sensor is not
responding. During gun's bring-up the console shows

```
[I2C] i2c-3 ... device addr: 0x40 ... no ask for the 7bit address   (NAK)
[h63p_mipi] sensor_detect:196 err: id_hi =0
viss_pipeline_s_power:230 err: pipeline sd [0] h63p_mipi s_power on failed
```

i2c-3 addresses `0x40` (the h63p sensor) and `0x57` (its EEPROM) both NAK
continuously — i.e. **the barrel camera module (FPC) is disconnected** from the
bare mainboard. With no sensor, `video_stream_start_camera` fails (`0x80001000`)
for gun exactly as it did for `cam_grab`, gun never calls `set_frame_cb`, and the
tap has nothing to hook.

**So the frame-grab software is complete and correct; it is gated on the camera
being physically connected.** Reconnect the barrel camera module and the tap will
capture frames to `/app/tapframe_*.bin` (and log to `/app/tap.log`). `frame_tap.so`
is staged on `/app`. To run it once the camera is back:

```
kill -9 $(pidof gun); sleep 1
LD_PRELOAD=/app/frame_tap.so /app/bin/gun &        # taps as gun brings the camera up
sleep 5; cat /app/tap.log; ls -la /app/tapframe*.bin
```

If a kill-then-restart leaves the ISP dirty (start_camera fails), use the launch
wrapper + a clean reboot instead so gun brings the camera up fresh under the tap.
