// G'AIM'E light gun bridge for macOS.
//
// The gun's interface 1 is a HID digitizer reporting absolute X/Y. macOS matches
// that as a system pointing device, so the gun drives the desktop cursor and its
// tracking noise makes the machine unusable. This tool SEIZES the digitizer, which
// stops macOS routing it anywhere, and then optionally re-emits clean mouse events
// only while a chosen application is frontmost.
//
// Report layout (from the HID report descriptor, verified on hardware):
//   byte 0  report ID 1
//   byte 1  bit0 = tip switch (trigger), bit1 = in range (has screen lock)
//   byte 2-3  X, uint16 LE, logical 0..10000
//   byte 4-5  Y, uint16 LE, logical 0..10000
//
// Build:  swiftc -O -swift-version 5 -o work/gun_bridge tools/gun_bridge.swift
// Usage:  work/gun_bridge --log
//         work/gun_bridge --app RetroArch [--latch-ms 60] [--require-in-range]
//         work/gun_bridge --block
//
// Needs Input Monitoring permission for the host process to seize the device.

import Foundation
import IOKit
import IOKit.hid
import CoreGraphics
import AppKit

let kVendorID = 0x2E2C
let kProductID = 0x0631
let kDigitizerUsagePage = 0x0D

// The descriptor declares 0..10000, but the gun clamps to this observed range.
let kLogicalMin = 99.0
let kLogicalMax = 9900.0

// Measured on hardware: the gun reports at ~278 Hz, and with no valid screen lock
// it sweeps the whole coordinate space while still asserting in_range. So in_range
// is NOT a usable validity signal — outliers have to be rejected geometrically.
let kDefaultMedian = 5
let kDefaultMaxJump = 400.0
let kOutlierRunToAccept = 6

// MARK: - options

enum Mode {
    case log
    case block
    case bridge(app: String)
}

struct Options {
    var mode: Mode = .log
    var latchMs: Double = 60
    var median = kDefaultMedian
    var maxJump = kDefaultMaxJump
    var verbose = false
}

func parseArgs() -> Options {
    var o = Options()
    var app: String?
    let args = Array(CommandLine.arguments.dropFirst())
    var i = 0
    while i < args.count {
        switch args[i] {
        case "--log": o.mode = .log
        case "--block": o.mode = .block
        case "--app":
            i += 1
            guard i < args.count else { fail("--app needs an application name") }
            app = args[i]
        case "--latch-ms":
            i += 1
            guard i < args.count, let v = Double(args[i]) else { fail("--latch-ms needs a number") }
            o.latchMs = v
        case "--median":
            i += 1
            guard i < args.count, let v = Int(args[i]), v >= 1 else { fail("--median needs a positive integer") }
            o.median = v
        case "--max-jump":
            i += 1
            guard i < args.count, let v = Double(args[i]), v > 0 else { fail("--max-jump needs a positive number") }
            o.maxJump = v
        case "--verbose", "-v": o.verbose = true
        case "--help", "-h": usage(); exit(0)
        default: fail("unknown argument: \(args[i])")
        }
        i += 1
    }
    if let app { o.mode = .bridge(app: app) }
    return o
}

func usage() {
    print("""
    gun_bridge — seize the G'AIM'E gun's digitizer so it stops driving the macOS cursor

      --log                 seize and print reports (desktop stays quiet while running)
      --block               seize and discard everything, no output
      --app <name>          seize, and re-emit mouse events only while <name> is frontmost
                            (matches bundle id, bundle name, or localized name, case-insensitive)
      --latch-ms <n>        freeze coordinates for n ms around a trigger edge (default 60)
      --median <n>          median-of-n spike filter (default \(kDefaultMedian); 1 disables)
      --max-jump <n>        reject moves larger than n logical counts as outliers
                            (default \(Int(kDefaultMaxJump)); \(kOutlierRunToAccept) in a row are accepted
                            anyway so genuine fast movement still works)
      --verbose             log every report in bridge mode too

    Note: the in-range bit is asserted even when the gun is producing garbage, so it
    is not usable as a validity gate. Outliers are rejected geometrically instead.
    """)
}

func fail(_ msg: String) -> Never {
    FileHandle.standardError.write("gun_bridge: \(msg)\n".data(using: .utf8)!)
    exit(2)
}

// MARK: - state

/// Median-of-N over a sliding window. Cheap, and unlike a mean it rejects spikes
/// outright rather than smearing them across neighbouring samples.
struct MedianWindow {
    private var buf: [Double] = []
    let size: Int
    init(size: Int) { self.size = size }
    mutating func push(_ v: Double) -> Double {
        buf.append(v)
        if buf.count > size { buf.removeFirst() }
        return buf.sorted()[buf.count / 2]
    }
    mutating func reset() { buf.removeAll() }
}

final class Bridge {
    let opts: Options
    private var lastX = 0.0, lastY = 0.0
    private var haveLast = false
    private var lastTip = false
    private var latchUntil = 0.0
    private var latchedX = 0.0, latchedY = 0.0
    private var medX: MedianWindow
    private var medY: MedianWindow
    private var outlierRun = 0
    private var reportCount = 0
    private var suppressedCount = 0
    private var rejectedCount = 0

    init(opts: Options) {
        self.opts = opts
        self.medX = MedianWindow(size: opts.median)
        self.medY = MedianWindow(size: opts.median)
    }

    /// True when the target application currently owns the foreground.
    private func targetIsFrontmost(_ name: String) -> Bool {
        guard let front = NSWorkspace.shared.frontmostApplication else { return false }
        let needle = name.lowercased()
        for candidate in [front.bundleIdentifier, front.localizedName] {
            if let c = candidate?.lowercased(), c == needle || c.contains(needle) { return true }
        }
        return false
    }

    func handle(report: UnsafeMutablePointer<UInt8>, length: CFIndex, reportID: UInt32) {
        // Some macOS paths include the report ID in the buffer, some do not.
        var p = report
        var len = length
        if len >= 6 && p[0] == 1 { p += 1; len -= 1 }
        guard len >= 5 else { return }

        let flags = p[0]
        let tip = flags & 0x01 != 0
        let inRange = flags & 0x02 != 0
        let rawX = Double(UInt16(p[1]) | UInt16(p[2]) << 8)
        let rawY = Double(UInt16(p[3]) | UInt16(p[4]) << 8)
        reportCount += 1

        if case .log = opts.mode {
            let bytes = (0..<len).map { String(format: "%02x", p[$0]) }.joined(separator: " ")
            print(String(format: "[%6d] %@  tip=%d in_range=%d  X=%5.0f Y=%5.0f",
                         reportCount, bytes, tip ? 1 : 0, inRange ? 1 : 0, rawX, rawY))
            fflush(stdout)
            return
        }
        if case .block = opts.mode { return }
        guard case .bridge(let app) = opts.mode else { return }

        _ = inRange  // always asserted; see kDefaultMaxJump comment

        // Median-filter to kill isolated spikes, then gate on how far the smoothed
        // position moved. A sustained run of "outliers" is a real movement, so accept
        // it and re-seed rather than locking the pointer out forever.
        let sx = medX.push(rawX)
        let sy = medY.push(rawY)

        if haveLast {
            let dist = ((sx - lastX) * (sx - lastX) + (sy - lastY) * (sy - lastY)).squareRoot()
            if dist > opts.maxJump {
                outlierRun += 1
                if outlierRun < kOutlierRunToAccept {
                    rejectedCount += 1
                    return
                }
                medX.reset(); medY.reset()
            }
            if dist <= opts.maxJump { outlierRun = 0 }
        }

        let now = CFAbsoluteTimeGetCurrent()

        // A trigger edge perturbs the vision pipeline, so freeze the coordinate
        // across the edge and keep re-using the last pre-edge position.
        if tip != lastTip {
            latchUntil = now + opts.latchMs / 1000.0
            if haveLast { latchedX = lastX; latchedY = lastY }
        }

        var x = sx, y = sy
        if now < latchUntil && haveLast {
            x = latchedX; y = latchedY
        } else {
            lastX = sx; lastY = sy; haveLast = true
        }

        let wasDown = lastTip
        lastTip = tip

        guard targetIsFrontmost(app) else {
            suppressedCount += 1
            return
        }

        emit(x: x, y: y, tip: tip, wasDown: wasDown)

        if opts.verbose {
            print(String(format: "[%6d] X=%5.0f Y=%5.0f tip=%d -> emitted", reportCount, x, y, tip ? 1 : 0))
            fflush(stdout)
        }
    }

    private func emit(x: Double, y: Double, tip: Bool, wasDown: Bool) {
        let bounds = CGDisplayBounds(CGMainDisplayID())
        let span = kLogicalMax - kLogicalMin
        let fx = min(max((x - kLogicalMin) / span, 0), 1)
        let fy = min(max((y - kLogicalMin) / span, 0), 1)
        let pt = CGPoint(x: bounds.origin.x + bounds.width * fx,
                         y: bounds.origin.y + bounds.height * fy)
        let source = CGEventSource(stateID: .hidSystemState)

        if tip != wasDown {
            let type: CGEventType = tip ? .leftMouseDown : .leftMouseUp
            CGEvent(mouseEventSource: source, mouseType: type,
                    mouseCursorPosition: pt, mouseButton: .left)?.post(tap: .cghidEventTap)
        } else {
            let type: CGEventType = tip ? .leftMouseDragged : .mouseMoved
            CGEvent(mouseEventSource: source, mouseType: type,
                    mouseCursorPosition: pt, mouseButton: .left)?.post(tap: .cghidEventTap)
        }
    }

    func summary() {
        FileHandle.standardError.write("""

            gun_bridge: \(reportCount) reports, \(rejectedCount) rejected as outliers, \
            \(suppressedCount) suppressed (app not frontmost)

            """.data(using: .utf8)!)
    }
}

// MARK: - main

let opts = parseArgs()
let bridge = Bridge(opts: opts)

let manager = IOHIDManagerCreate(kCFAllocatorDefault, IOOptionBits(kIOHIDOptionsTypeNone))
IOHIDManagerSetDeviceMatching(manager, [
    kIOHIDVendorIDKey: kVendorID,
    kIOHIDProductIDKey: kProductID,
    kIOHIDPrimaryUsagePageKey: kDigitizerUsagePage,
] as CFDictionary)

// Seize: take the device away from the system so it stops moving the cursor.
let openResult = IOHIDManagerOpen(manager, IOOptionBits(kIOHIDOptionsTypeSeizeDevice))
if openResult != kIOReturnSuccess {
    fail(String(format: """
        could not seize the digitizer (IOReturn 0x%08x).
        This usually means the host process lacks Input Monitoring permission
        (System Settings > Privacy & Security > Input Monitoring).
        """, openResult))
}

// Keep report buffers alive for the lifetime of the process.
final class BufferStore { var buffers: [UnsafeMutablePointer<UInt8>] = [] }
let store = BufferStore()

func attach(_ device: IOHIDDevice) {
    let size = (IOHIDDeviceGetProperty(device, kIOHIDMaxInputReportSizeKey as CFString) as? Int) ?? 64
    let buf = UnsafeMutablePointer<UInt8>.allocate(capacity: size)
    store.buffers.append(buf)
    IOHIDDeviceRegisterInputReportCallback(
        device, buf, size,
        { context, _, _, _, reportID, report, length in
            guard let context else { return }
            Unmanaged<Bridge>.fromOpaque(context).takeUnretainedValue()
                .handle(report: report, length: length, reportID: reportID)
        },
        Unmanaged.passUnretained(bridge).toOpaque())
    FileHandle.standardError.write("gun_bridge: attached and seized a digitizer interface\n"
        .data(using: .utf8)!)
}

// Attach to anything already present, and to anything that appears later, so the
// tool can be started before the gun is plugged in.
IOHIDManagerRegisterDeviceMatchingCallback(manager, { _, _, _, device in
    attach(device)
}, nil)

let present = (IOHIDManagerCopyDevices(manager) as? Set<IOHIDDevice>) ?? []
if present.isEmpty {
    FileHandle.standardError.write("gun_bridge: waiting for the gun to be plugged in…\n"
        .data(using: .utf8)!)
}

IOHIDManagerScheduleWithRunLoop(manager, CFRunLoopGetCurrent(), CFRunLoopMode.defaultMode.rawValue)

switch opts.mode {
case .log:
    FileHandle.standardError.write("gun_bridge: logging. Cursor stays free while this runs. "
        .appending("Ctrl-C to release.\n").data(using: .utf8)!)
case .block:
    FileHandle.standardError.write("gun_bridge: seized and blocking. Ctrl-C to release.\n"
        .data(using: .utf8)!)
case .bridge(let app):
    FileHandle.standardError.write("gun_bridge: seized; forwarding only while \"\(app)\" is frontmost. "
        .appending("Ctrl-C to release.\n").data(using: .utf8)!)
}

for sig in [SIGINT, SIGTERM] {
    signal(sig) { _ in
        bridge.summary()
        exit(0)
    }
}

CFRunLoopRun()
