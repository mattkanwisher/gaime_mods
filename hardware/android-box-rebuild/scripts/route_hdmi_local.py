#!/usr/bin/env python3
"""Route the local fanout for the staged HCTL HDMI-01 / C2906135 connector.

This pass joins the exact production footprint to the preserved Avaota HDMI corridor.
It keeps the imported 0.102 mm TMDS trace width, converges each connector pair to the
existing 0.5 mm center spacing, compensates the shorter P trace in each fanout, and
escapes CEC/DDC/HPD on B.Cu. Final impedance still depends on the released stack-up.
"""

from __future__ import annotations

import os
import sys
from pathlib import Path

import pcbnew


HDMI_REF = "USB1"
HDMI_FOOTPRINT = "USB-SMD_HDMI-01"
TMDS_WIDTH_MM = 0.102
CONTROL_WIDTH_MM = 0.102
POWER_WIDTH_MM = 0.508
CUT_Y_MM = 123.507
ESCAPE_Y_MM = 130.800
VIA_ESCAPE_Y_MM = 130.550
VIA_SIZE_MM = 0.400
VIA_DRILL_MM = 0.200

TMDS_TARGETS = {
    "HTX2P": (145.5290, CUT_Y_MM),
    "HTX2N": (145.0290, CUT_Y_MM),
    "HTX1P": (144.0285, CUT_Y_MM),
    "HTX1N": (143.5290, CUT_Y_MM),
    "HTX0P": (142.6585, CUT_Y_MM),
    "HTX0N": (142.1590, CUT_Y_MM),
    "HTXCP": (141.1580, CUT_Y_MM),
    "HTXCN": (140.6585, CUT_Y_MM),
}

CONTROL_TARGETS = {
    "13": (141.9125, 126.7655, False),  # CEC, existing B.Cu endpoint
    "15": (141.6080, 126.9435, False),  # DDC SCL, existing B.Cu endpoint
    "16": (140.2110, 127.5785, True),   # DDC SDA, existing F.Cu endpoint
    "19": (139.7885, 126.3165, True),   # HPD, existing F.Cu endpoint
}

# Pad 19's preserved F.Cu endpoint is too close to the adjacent DDC data track for a
# 0.4 mm via.  Land the via clear of that corridor, then use a short F.Cu link.
CONTROL_VIA_LOCATIONS = {
    "19": (140.1000, 126.3165),
}


def point(x_mm: float, y_mm: float) -> pcbnew.VECTOR2I:
    return pcbnew.VECTOR2I_MM(x_mm, y_mm)


def add_track(
    board: pcbnew.BOARD,
    net: pcbnew.NETINFO_ITEM,
    start: tuple[float, float],
    end: tuple[float, float],
    width_mm: float,
    layer: int,
) -> pcbnew.PCB_TRACK:
    track = pcbnew.PCB_TRACK(board)
    track.SetStart(point(*start))
    track.SetEnd(point(*end))
    track.SetWidth(pcbnew.FromMM(width_mm))
    track.SetLayer(layer)
    track.SetNet(net)
    board.Add(track)
    return track


def add_polyline(
    board: pcbnew.BOARD,
    net: pcbnew.NETINFO_ITEM,
    points: list[tuple[float, float]],
    width_mm: float,
    layer: int,
) -> list[pcbnew.PCB_TRACK]:
    return [
        add_track(board, net, start, end, width_mm, layer)
        for start, end in zip(points, points[1:])
        if start != end
    ]


def add_via(
    board: pcbnew.BOARD, net: pcbnew.NETINFO_ITEM, location: tuple[float, float]
) -> pcbnew.PCB_VIA:
    via = pcbnew.PCB_VIA(board)
    via.SetPosition(point(*location))
    via.SetWidth(pcbnew.FromMM(VIA_SIZE_MM))
    via.SetDrill(pcbnew.FromMM(VIA_DRILL_MM))
    via.SetLayerPair(pcbnew.F_Cu, pcbnew.B_Cu)
    via.SetNet(net)
    board.Add(via)
    return via


def prune_old_tmds_fanout(board: pcbnew.BOARD) -> int:
    removed = []
    for item in board.Tracks():
        if item.GetNetname() not in TMDS_TARGETS:
            continue
        sx, sy, ex, ey = map(
            pcbnew.ToMM,
            (item.GetStart().x, item.GetStart().y, item.GetEnd().x, item.GetEnd().y),
        )
        if min(sx, ex) > 138.0 and max(sy, ey) > CUT_Y_MM + 0.0001:
            removed.append(item)
    for item in removed:
        board.Remove(item)
    return len(removed)


def route_tmds(
    board: pcbnew.BOARD,
    pads_by_net: dict[str, tuple[pcbnew.NETINFO_ITEM, tuple[float, float]]],
) -> tuple[list[pcbnew.BOARD_ITEM], dict[str, float]]:
    added: list[pcbnew.BOARD_ITEM] = []
    lengths: dict[str, float] = {}
    compensation_dx = 0.306
    compensation_half_height = 0.400

    for net_name, target in TMDS_TARGETS.items():
        net, start = pads_by_net[net_name]
        shift = target[0] - start[0]
        if shift <= 0:
            raise RuntimeError(f"unexpected {net_name} fanout direction")
        diagonal_end = (target[0], ESCAPE_Y_MM - shift)
        path = [start, (start[0], ESCAPE_Y_MM), diagonal_end]

        if net_name.endswith("P"):
            bump_center_y = 127.100
            path.extend(
                [
                    (target[0], bump_center_y + compensation_half_height),
                    (target[0] + compensation_dx, bump_center_y),
                    (target[0], bump_center_y - compensation_half_height),
                ]
            )
        path.append(target)
        tracks = add_polyline(board, net, path, TMDS_WIDTH_MM, pcbnew.F_Cu)
        added.extend(tracks)
        lengths[net_name] = sum(pcbnew.ToMM(track.GetLength()) for track in tracks)

    return added, lengths


def route_controls(
    board: pcbnew.BOARD,
    pads_by_number: dict[str, tuple[pcbnew.NETINFO_ITEM, tuple[float, float]]],
) -> list[pcbnew.BOARD_ITEM]:
    added: list[pcbnew.BOARD_ITEM] = []
    for pad_number, (target_x, target_y, target_needs_via) in CONTROL_TARGETS.items():
        net, (pad_x, pad_y) = pads_by_number[pad_number]
        escape = (pad_x, VIA_ESCAPE_Y_MM)
        added.extend(
            add_polyline(
                board,
                net,
                [(pad_x, pad_y), escape],
                CONTROL_WIDTH_MM,
                pcbnew.F_Cu,
            )
        )
        added.append(add_via(board, net, escape))
        target = (target_x, target_y)
        if target_needs_via:
            via_location = CONTROL_VIA_LOCATIONS.get(pad_number, target)
            added.extend(
                add_polyline(
                    board,
                    net,
                    [escape, via_location],
                    CONTROL_WIDTH_MM,
                    pcbnew.B_Cu,
                )
            )
            added.append(add_via(board, net, via_location))
            added.extend(
                add_polyline(
                    board,
                    net,
                    [via_location, target],
                    CONTROL_WIDTH_MM,
                    pcbnew.F_Cu,
                )
            )
        else:
            added.extend(
                add_polyline(
                    board,
                    net,
                    [escape, target],
                    CONTROL_WIDTH_MM,
                    pcbnew.B_Cu,
                )
            )

    power_net, power_start = pads_by_number["18"]
    power_path = [
        power_start,
        (power_start[0], 129.050),
        (137.4930, 127.6810),
        (137.4930, 127.4005),
    ]
    # Keep the pad escape narrower than the 0.5 mm connector pitch, then widen once
    # below the signal row.  A full-width escape violates pad 17's clearance.
    added.append(
        add_track(
            board,
            power_net,
            power_path[0],
            power_path[1],
            0.254,
            pcbnew.F_Cu,
        )
    )
    added.extend(
        add_polyline(board, power_net, power_path[1:], POWER_WIDTH_MM, pcbnew.F_Cu)
    )
    return added


def route(input_path: Path, output_path: Path) -> None:
    board = pcbnew.LoadBoard(str(input_path))
    hdmi = next((fp for fp in board.GetFootprints() if fp.GetReference() == HDMI_REF), None)
    if hdmi is None or str(hdmi.GetFPID().GetLibItemName()) != HDMI_FOOTPRINT:
        raise RuntimeError("the exact C2906135 HDMI footprint is not staged")

    pads = list(hdmi.Pads())
    pads_by_number = {
        pad.GetNumber(): (
            pad.GetNet(),
            (pcbnew.ToMM(pad.GetPosition().x), pcbnew.ToMM(pad.GetPosition().y)),
        )
        for pad in pads
    }
    pads_by_net = {
        pad.GetNetname(): (
            pad.GetNet(),
            (pcbnew.ToMM(pad.GetPosition().x), pcbnew.ToMM(pad.GetPosition().y)),
        )
        for pad in pads
        if pad.GetNetname() in TMDS_TARGETS
    }
    if set(pads_by_net) != set(TMDS_TARGETS):
        raise RuntimeError("HDMI TMDS pad/net map is incomplete")

    removed = prune_old_tmds_fanout(board)
    tmds_items, lengths = route_tmds(board, pads_by_net)
    control_items = route_controls(board, pads_by_number)
    pcbnew.SaveBoard(str(output_path), board)

    pair_skews = []
    for positive, negative in (
        ("HTX2P", "HTX2N"),
        ("HTX1P", "HTX1N"),
        ("HTX0P", "HTX0N"),
        ("HTXCP", "HTXCN"),
    ):
        pair_skews.append(abs(lengths[positive] - lengths[negative]))
    print(
        f"removed {removed} old TMDS fanout items; added {len(tmds_items)} TMDS "
        f"and {len(control_items)} control/power items; maximum added pair skew "
        f"{max(pair_skews):.4f} mm",
        flush=True,
    )
    # KiCad 9's macOS SWIG bindings can crash while destroying removed board items
    # after a successful save.  The output is complete at this point, so avoid the
    # faulty interpreter-shutdown destructor path.
    os._exit(0)


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit(f"usage: {Path(sys.argv[0]).name} INPUT.kicad_pcb OUTPUT.kicad_pcb")
    route(Path(sys.argv[1]).resolve(), Path(sys.argv[2]).resolve())


if __name__ == "__main__":
    main()
