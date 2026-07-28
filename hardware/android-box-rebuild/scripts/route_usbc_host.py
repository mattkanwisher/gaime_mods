#!/usr/bin/env python3
"""Place and route the J6 USB 2.0 Type-C host interface.

The already-routed Avaota U17 SY6280AAC switch, its enable/current-limit network,
and D13 USB2 ESD array are retained in place. This pass adds the two 56 kOhm Rp
resistors and zero-ohm output link, carries switched 5 V to J6 on In6.Cu, and
reconnects the reversible Type-C USB2 pins through D13.
"""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path

import pcbnew


MM = pcbnew.FromMM
SIGNAL_WIDTH = 0.15
USB_WIDTH = 0.15
POWER_WIDTH = 0.80
POWER_NECK_WIDTH = 0.25
POWER_VIA_SIZE = 0.65
POWER_VIA_DRILL = 0.30
SIGNAL_VIA_SIZE = 0.40
SIGNAL_VIA_DRILL = 0.20


def point(x: float, y: float) -> pcbnew.VECTOR2I:
    return pcbnew.VECTOR2I_MM(x, y)


def xy(item: pcbnew.BOARD_ITEM) -> tuple[float, float]:
    p = item.GetPosition()
    return pcbnew.ToMM(p.x), pcbnew.ToMM(p.y)


def require_footprint(board: pcbnew.BOARD, reference: str) -> pcbnew.FOOTPRINT:
    footprint = board.FindFootprintByReference(reference)
    if footprint is None:
        raise RuntimeError(f"required footprint {reference} was not found")
    return footprint


def require_pad(footprint: pcbnew.FOOTPRINT, number: str) -> pcbnew.PAD:
    pad = footprint.FindPadByNumber(number)
    if pad is None:
        raise RuntimeError(f"{footprint.GetReference()} pad {number} was not found")
    return pad


def get_or_create_net(board: pcbnew.BOARD, name: str) -> pcbnew.NETINFO_ITEM:
    net = board.FindNet(name)
    if net is None:
        net = pcbnew.NETINFO_ITEM(board, name)
        board.Add(net)
    return net


def pad_xy(footprint: pcbnew.FOOTPRINT, number: str) -> tuple[float, float]:
    return xy(require_pad(footprint, number))


def add_track(
    board: pcbnew.BOARD,
    net: pcbnew.NETINFO_ITEM,
    start: tuple[float, float],
    end: tuple[float, float],
    width: float,
    layer: int,
) -> None:
    if start == end:
        return
    track = pcbnew.PCB_TRACK(board)
    track.SetStart(point(*start))
    track.SetEnd(point(*end))
    track.SetWidth(MM(width))
    track.SetLayer(layer)
    track.SetNet(net)
    board.Add(track)


def add_polyline(
    board: pcbnew.BOARD,
    net: pcbnew.NETINFO_ITEM,
    vertices: list[tuple[float, float]],
    width: float,
    layer: int,
) -> None:
    for start, end in zip(vertices, vertices[1:]):
        add_track(board, net, start, end, width, layer)


def add_via(
    board: pcbnew.BOARD,
    net: pcbnew.NETINFO_ITEM,
    location: tuple[float, float],
    *,
    power: bool = False,
) -> None:
    via = pcbnew.PCB_VIA(board)
    via.SetPosition(point(*location))
    via.SetWidth(MM(POWER_VIA_SIZE if power else SIGNAL_VIA_SIZE))
    via.SetDrill(MM(POWER_VIA_DRILL if power else SIGNAL_VIA_DRILL))
    via.SetLayerPair(pcbnew.F_Cu, pcbnew.B_Cu)
    via.SetNet(net)
    board.Add(via)


def in_box(location: pcbnew.VECTOR2I, box: tuple[float, float, float, float]) -> bool:
    x, y = pcbnew.ToMM(location.x), pcbnew.ToMM(location.y)
    x1, y1, x2, y2 = box
    return x1 <= x <= x2 and y1 <= y <= y2


def clear_rebuilt_copper(board: pcbnew.BOARD) -> int:
    pair_box = (123.5, 126.45, 131.5, 137.8)
    added_box = (130.0, 122.5, 137.5, 130.0)
    rebuilt = {
        "USB1-DP",
        "USB1-DM",
        "USB1_CC1",
        "USB1_CC2",
        "USB1_VBUS_SW",
    }
    removed = 0
    for item in list(board.GetTracks()):
        if item.GetNetname() == "PD_VBUS_RAW":
            endpoints = (item.GetStart(), item.GetEnd())
            if any(in_box(p, (123.9, 129.5, 124.9, 136.8)) for p in endpoints):
                board.Remove(item)
                removed += 1
                continue
        if item.GetNetname() not in rebuilt:
            continue
        endpoints = (item.GetStart(), item.GetEnd())
        if any(in_box(p, pair_box) or in_box(p, added_box) for p in endpoints):
            board.Remove(item)
            removed += 1
    # Remove generated passives in this throwaway child process.  Removing a
    # footprint can invalidate unrelated SWIG handles in the same process.
    for reference in ("R1101", "R1102", "R1103"):
        footprint = board.FindFootprintByReference(reference)
        if footprint is not None:
            board.Remove(footprint)
    return removed


def place_on_back(
    footprint: pcbnew.FOOTPRINT,
    location: tuple[float, float],
    orientation: float,
) -> None:
    if footprint.GetLayer() == pcbnew.B_Cu:
        footprint.Flip(footprint.GetPosition(), False)
    footprint.SetPosition(point(*location))
    footprint.SetOrientationDegrees(orientation)
    footprint.Flip(footprint.GetPosition(), False)
    footprint.Reference().SetVisible(False)
    footprint.Value().SetVisible(False)


def add_resistor(
    board: pcbnew.BOARD,
    template: pcbnew.FOOTPRINT,
    reference: str,
    value: str,
    location: tuple[float, float],
    orientation: float,
    net_1: str,
    net_2: str,
) -> pcbnew.FOOTPRINT:
    existing = board.FindFootprintByReference(reference)
    if existing is not None:
        board.Remove(existing)
    footprint = pcbnew.Cast_to_FOOTPRINT(template.Duplicate(False))
    footprint.SetPath(pcbnew.KIID_PATH())
    footprint.SetReference(reference)
    footprint.SetValue(value)
    board.Add(footprint)
    place_on_back(footprint, location, orientation)
    require_pad(footprint, "1").SetNet(get_or_create_net(board, net_1))
    require_pad(footprint, "2").SetNet(get_or_create_net(board, net_2))
    return footprint


def route_typec_fanout(
    board: pcbnew.BOARD,
    j6: pcbnew.FOOTPRINT,
    net: pcbnew.NETINFO_ITEM,
    pins: tuple[str, str],
    vias: tuple[tuple[float, float], tuple[float, float]],
    join_layer: int,
) -> None:
    for pin, via in zip(pins, vias):
        pad = pad_xy(j6, pin)
        # Leave the 0.5 mm pitch row perpendicular to the connector before
        # spreading toward the dogbone vias.  A direct diagonal clips the
        # adjacent interleaved Type-C pad even at a 0.15 mm trace width.
        add_polyline(board, net, [pad, (pad[0], 136.00), via], SIGNAL_WIDTH, pcbnew.F_Cu)
        add_via(board, net, via)
    add_track(board, net, vias[0], vias[1], SIGNAL_WIDTH, join_layer)


def route_usb2(board: pcbnew.BOARD, j6: pcbnew.FOOTPRINT, d13: pcbnew.FOOTPRINT) -> None:
    dp = get_or_create_net(board, "USB1-DP")
    dm = get_or_create_net(board, "USB1-DM")

    # Reconnect D13's SoC side to the preserved upstream pair junctions.
    add_track(board, dp, (129.111, 126.410), pad_xy(d13, "5"), USB_WIDTH, pcbnew.F_Cu)
    add_track(board, dm, (129.619, 126.410), pad_xy(d13, "4"), USB_WIDTH, pcbnew.F_Cu)

    # Stagger the four dogbones to maintain manufacturable via clearance at the
    # 0.5 mm interleaved Type-C pin row.
    dp_vias = ((125.864, 135.00), (126.864, 135.00))
    dm_vias = ((125.364, 135.80), (126.364, 135.80))
    route_typec_fanout(board, j6, dp, ("A6", "B6"), dp_vias, pcbnew.In2_Cu)
    route_typec_fanout(board, j6, dm, ("B7", "A7"), dm_vias, pcbnew.In3_Cu)

    # Cross the pin order locally, then run D+/D- as a parallel pair on In1.Cu.
    dp_pair = (124.20, 134.00)
    dm_pair = (125.364, 134.00)
    add_polyline(board, dp, [dp_vias[0], (125.10, 134.50), dp_pair], USB_WIDTH, pcbnew.In2_Cu)
    add_via(board, dp, dp_pair)
    add_polyline(
        board,
        dm,
        [dm_vias[0], (dm_vias[0][0], dm_pair[1]), dm_pair],
        USB_WIDTH,
        pcbnew.In3_Cu,
    )
    add_via(board, dm, dm_pair)

    dp_esd = (128.90, 129.00)
    dm_esd = (129.70, 129.00)
    add_polyline(
        board,
        dp,
        [dp_pair, (125.20, 133.00), (125.20, 130.00), dp_esd],
        USB_WIDTH,
        pcbnew.In1_Cu,
    )
    add_polyline(
        board,
        dm,
        [
            dm_pair,
            (126.20, 133.00),
            # The detour stays above the existing eFuse-enable via and also
            # compensates the D+/D- crossover length.
            (126.85, 132.50),
            (126.20, 132.00),
            (126.85, 131.50),
            (126.20, 131.00),
            (128.20, 131.00),
            (129.70, 129.50),
            dm_esd,
        ],
        USB_WIDTH,
        pcbnew.In1_Cu,
    )
    add_via(board, dp, dp_esd)
    add_via(board, dm, dm_esd)
    add_track(board, dp, dp_esd, pad_xy(d13, "6"), USB_WIDTH, pcbnew.F_Cu)
    add_track(board, dm, dm_esd, pad_xy(d13, "7"), USB_WIDTH, pcbnew.F_Cu)


def route_cc_and_power(
    board: pcbnew.BOARD,
    j6: pcbnew.FOOTPRINT,
    u17: pcbnew.FOOTPRINT,
    parts: dict[str, pcbnew.FOOTPRINT],
) -> None:
    vbus = get_or_create_net(board, "VBUS")
    source = get_or_create_net(board, "VBUS-USB")
    output = get_or_create_net(board, "USB1_VBUS_SW")
    cc1 = get_or_create_net(board, "USB1_CC1")
    cc2 = get_or_create_net(board, "USB1_CC2")

    # Use the retained VBUS via beside C221/C222 for both Rp resistors.
    vbus_anchor = (135.244, 126.805)
    add_polyline(
        board,
        vbus,
        [pad_xy(parts["R1101"], "1"), (132.80, 122.65), (136.20, 122.65), vbus_anchor],
        SIGNAL_WIDTH,
        pcbnew.B_Cu,
    )
    add_track(board, vbus, pad_xy(parts["R1102"], "1"), vbus_anchor, SIGNAL_WIDTH, pcbnew.B_Cu)

    # Staggered CC vias avoid both the USB2 fanout and the existing J5 divider vias.
    cc1_via = (124.864, 135.00)
    cc2_via = (127.864, 135.80)
    cc1_pad = pad_xy(j6, "A5")
    cc2_pad = pad_xy(j6, "B5")
    add_polyline(board, cc1, [cc1_pad, (cc1_pad[0], 136.00), cc1_via], SIGNAL_WIDTH, pcbnew.F_Cu)
    add_polyline(board, cc2, [cc2_pad, (cc2_pad[0], 136.00), cc2_via], SIGNAL_WIDTH, pcbnew.F_Cu)
    add_via(board, cc1, cc1_via)
    add_via(board, cc2, cc2_via)
    cc1_target = (130.80, 124.80)
    cc2_target = (133.70, 126.00)
    add_via(board, cc1, cc1_target)
    add_via(board, cc2, cc2_target)
    add_polyline(
        board,
        cc1,
        [
            cc1_via,
            (124.864, 132.80),
            (127.00, 132.00),
            (131.50, 131.50),
            (131.50, 126.00),
            cc1_target,
        ],
        SIGNAL_WIDTH,
        pcbnew.In4_Cu,
    )
    add_polyline(
        board,
        cc2,
        [cc2_via, (134.50, 135.80), (134.50, 126.80), cc2_target],
        SIGNAL_WIDTH,
        pcbnew.In5_Cu,
    )
    add_track(board, cc1, cc1_target, pad_xy(parts["R1101"], "2"), SIGNAL_WIDTH, pcbnew.B_Cu)
    add_track(board, cc2, cc2_target, pad_xy(parts["R1102"], "2"), SIGNAL_WIDTH, pcbnew.B_Cu)

    # Carry U17's protected output across the board on In6.Cu. U17 itself and all
    # of its enable/current-limit routing stay untouched.
    source_via = (188.20, 76.70)
    add_track(board, source, pad_xy(u17, "1"), source_via, POWER_WIDTH, pcbnew.F_Cu)
    add_via(board, source, source_via, power=True)
    add_track(board, source, source_via, pad_xy(parts["R1103"], "1"), POWER_WIDTH, pcbnew.B_Cu)

    link_output_via = (183.40, 82.20)
    add_track(board, output, pad_xy(parts["R1103"], "2"), link_output_via, POWER_WIDTH, pcbnew.B_Cu)
    add_via(board, output, link_output_via, power=True)
    left_via = (122.45, 135.00)
    right_via = (129.75, 135.00)
    branch = (130.50, 131.50)
    add_polyline(
        board,
        output,
        [
            link_output_via,
            (178.0, 87.6),
            (178.0, 116.0),
            (166.0, 124.0),
            (140.0, 124.0),
            (132.0, 124.0),
        ],
        POWER_WIDTH,
        pcbnew.In6_Cu,
    )
    # A short 0.5 mm neck passes between the retained HDMI shield pad and a
    # ground via; the wider trunk resumes once it reaches the branch point.
    add_polyline(
        board,
        output,
        [(132.0, 124.0), (131.60, 123.60), (131.60, 130.40), branch],
        0.50,
        pcbnew.In6_Cu,
    )
    add_polyline(
        board,
        output,
        [branch, (120.80, 131.50), (120.80, 135.00), left_via],
        POWER_WIDTH,
        pcbnew.In6_Cu,
    )
    add_polyline(board, output, [branch, (130.50, 133.20), right_via], POWER_WIDTH, pcbnew.In6_Cu)
    for pin, via in (("A4B9", left_via), ("B4A9", right_via)):
        add_via(board, output, via, power=True)
        pad = pad_xy(j6, pin)
        add_polyline(
            board,
            output,
            [pad, (pad[0], 135.90), via],
            POWER_NECK_WIDTH,
            pcbnew.F_Cu,
        )


def reroute_pd_raw_corridor(board: pcbnew.BOARD) -> None:
    """Shift the existing J5 raw-power trace left of the J6 signal vias."""
    raw = get_or_create_net(board, "PD_VBUS_RAW")
    r1008 = require_footprint(board, "R1008")
    corridor_via = (123.60, 130.00)
    add_polyline(
        board,
        raw,
        [(118.0, 136.5), (123.60, 136.5), corridor_via, (126.0, 128.4)],
        0.20,
        pcbnew.In4_Cu,
    )
    add_via(board, raw, corridor_via)
    add_track(board, raw, corridor_via, pad_xy(r1008, "1"), 0.20, pcbnew.F_Cu)


def main() -> None:
    if len(sys.argv) == 4 and sys.argv[1] == "--clear-only":
        board = pcbnew.LoadBoard(str(Path(sys.argv[2]).resolve()))
        removed = clear_rebuilt_copper(board)
        pcbnew.SaveBoard(str(Path(sys.argv[3]).resolve()), board)
        print(f"REMOVED={removed}")
        return
    if len(sys.argv) != 3:
        raise SystemExit("usage: route_usbc_host.py INPUT.kicad_pcb OUTPUT.kicad_pcb")

    source_path = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    cleaned = subprocess.run(
        [sys.executable, __file__, "--clear-only", str(source_path), str(destination)],
        check=True,
        capture_output=True,
        text=True,
    )
    removed_line = next(line for line in cleaned.stdout.splitlines() if line.startswith("REMOVED="))
    removed = int(removed_line.split("=", 1)[1])
    board = pcbnew.LoadBoard(str(destination))

    template = require_footprint(board, "R1008")
    parts = {
        "R1101": add_resistor(board, template, "R1101", "56k 1%", (132.0, 123.8), 0.0, "VBUS", "USB1_CC1"),
        "R1102": add_resistor(board, template, "R1102", "56k 1%", (135.2, 124.8), 0.0, "VBUS", "USB1_CC2"),
        "R1103": add_resistor(board, template, "R1103", "0R", (185.0, 81.0), 0.0, "VBUS-USB", "USB1_VBUS_SW"),
    }
    j6 = require_footprint(board, "J6")
    u17 = require_footprint(board, "U17")
    d13 = require_footprint(board, "D13")

    route_cc_and_power(board, j6, u17, parts)
    route_usb2(board, j6, d13)
    reroute_pd_raw_corridor(board)
    pcbnew.ZONE_FILLER(board).Fill(board.Zones())
    pcbnew.SaveBoard(str(destination), board)
    print(f"retained routed U17/D13 circuits and removed {removed} obsolete local copper items")
    print("routed J6 switched VBUS, CC1/CC2 Rp and reversible USB2 D+/D-")


if __name__ == "__main__":
    main()
