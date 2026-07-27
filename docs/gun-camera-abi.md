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
