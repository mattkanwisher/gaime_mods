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
let kLogicalMax = 10000.0

// MARK: - options

enum Mode {
    case log
    case block
    case bridge(app: String)
}

struct Options {
    var mode: Mode = .log
    var latchMs: Double = 60
    var requireInRange = false
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
        case "--require-in-range": o.requireInRange = true
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
      --require-in-range    ignore reports whose in-range bit is clear
      --verbose             log every report in bridge mode too
    """)
}

func fail(_ msg: String) -> Never {
    FileHandle.standardError.write("gun_bridge: \(msg)\n".data(using: .utf8)!)
    exit(2)
}

// MARK: - state

final class Bridge {
    let opts: Options
    private var lastX = 0.0, lastY = 0.0
    private var haveLast = false
    private var lastTip = false
    private var latchUntil = 0.0
    private var latchedX = 0.0, latchedY = 0.0
    private var reportCount = 0
    private var suppressedCount = 0

    init(opts: Options) { self.opts = opts }

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

        if opts.requireInRange && !inRange {
            suppressedCount += 1
            return
        }

        let now = CFAbsoluteTimeGetCurrent()

        // A trigger edge perturbs the vision pipeline, so freeze the coordinate
        // across the edge and keep re-using the last pre-edge position.
        if tip != lastTip {
            latchUntil = now + opts.latchMs / 1000.0
            if haveLast { latchedX = lastX; latchedY = lastY }
        }

        var x = rawX, y = rawY
        if now < latchUntil && haveLast {
            x = latchedX; y = latchedY
        } else {
            lastX = rawX; lastY = rawY; haveLast = true
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
        let pt = CGPoint(x: bounds.origin.x + bounds.width * min(max(x / kLogicalMax, 0), 1),
                         y: bounds.origin.y + bounds.height * min(max(y / kLogicalMax, 0), 1))
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
        FileHandle.standardError.write(
            "\ngun_bridge: \(reportCount) reports, \(suppressedCount) suppressed\n".data(using: .utf8)!)
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

signal(SIGINT) { _ in
    bridge.summary()
    exit(0)
}

CFRunLoopRun()
