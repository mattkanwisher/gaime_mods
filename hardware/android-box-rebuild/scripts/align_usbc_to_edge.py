#!/usr/bin/env python3
"""Align staged J5/J6 USB-C receptacles to the bottom board edge.

The imported USB3 receptacle was 3.9055 mm inboard from the top Edge.Cuts
centerline. Mirroring that insertion depth to the 143.555 mm bottom edge places
J5/J6 at y=139.6495 mm and gives the same ~1.27 mm shell protrusion.

Run with KiCad's bundled Python so the pcbnew module is available:

    .../Python.framework/Versions/Current/bin/python3 \
        scripts/align_usbc_to_edge.py INPUT.kicad_pcb OUTPUT.kicad_pcb
"""

from __future__ import annotations

import math
import sys
from pathlib import Path

import pcbnew


REFERENCE_EDGE_INSET_MM = 3.9055


def point_mm(x: float, y: float) -> pcbnew.VECTOR2I:
    return pcbnew.VECTOR2I(pcbnew.FromMM(x), pcbnew.FromMM(y))


def require_footprint(board: pcbnew.BOARD, reference: str) -> pcbnew.FOOTPRINT:
    footprint = board.FindFootprintByReference(reference)
    if footprint is None:
        raise RuntimeError(f"required footprint {reference} was not found")
    return footprint


def bottom_edge_y_mm(board: pcbnew.BOARD) -> float:
    horizontal_edges: list[float] = []
    for drawing in board.GetDrawings():
        if drawing.GetLayer() != pcbnew.Edge_Cuts or not isinstance(drawing, pcbnew.PCB_SHAPE):
            continue
        if drawing.GetShape() != pcbnew.SHAPE_T_SEGMENT:
            continue
        start, end = drawing.GetStart(), drawing.GetEnd()
        if start.y == end.y:
            horizontal_edges.append(pcbnew.ToMM(start.y))
    if not horizontal_edges:
        raise RuntimeError("no horizontal Edge.Cuts segments found")
    return max(horizontal_edges)


def attached_copper(board: pcbnew.BOARD, footprint: pcbnew.FOOTPRINT) -> list[pcbnew.BOARD_ITEM]:
    pads = list(footprint.Pads())
    return [
        item
        for item in board.GetTracks()
        if any(pad.HitTest(item.GetStart()) or pad.HitTest(item.GetEnd()) for pad in pads)
    ]


def distance_to_segment_mm(
    point: tuple[float, float], start: pcbnew.VECTOR2I, end: pcbnew.VECTOR2I
) -> float:
    px, py = point
    x1, y1 = pcbnew.ToMM(start.x), pcbnew.ToMM(start.y)
    x2, y2 = pcbnew.ToMM(end.x), pcbnew.ToMM(end.y)
    dx, dy = x2 - x1, y2 - y1
    if dx == 0 and dy == 0:
        return math.hypot(px - x1, py - y1)
    t = max(0.0, min(1.0, ((px - x1) * dx + (py - y1) * dy) / (dx * dx + dy * dy)))
    return math.hypot(px - (x1 + t * dx), py - (y1 + t * dy))


def copper_width_mm(item: pcbnew.BOARD_ITEM) -> float:
    if isinstance(item, pcbnew.PCB_VIA):
        return pcbnew.ToMM(item.GetWidth(pcbnew.F_Cu))
    return pcbnew.ToMM(item.GetWidth())


def conflicting_copper(
    tracks: list[pcbnew.BOARD_ITEM], footprints: tuple[pcbnew.FOOTPRINT, ...]
) -> list[pcbnew.BOARD_ITEM]:
    pads = [pad for footprint in footprints for pad in footprint.Pads()]
    conflicts: list[pcbnew.BOARD_ITEM] = []
    for item in tracks:
        half_width = copper_width_mm(item) / 2.0
        for pad in pads:
            if pad.GetNetCode() != 0 and pad.GetNetCode() == item.GetNetCode():
                continue
            size = pad.GetSize()
            pad_radius = max(pcbnew.ToMM(size.x), pcbnew.ToMM(size.y)) / 2.0
            center = (pcbnew.ToMM(pad.GetPosition().x), pcbnew.ToMM(pad.GetPosition().y))
            if distance_to_segment_mm(center, item.GetStart(), item.GetEnd()) <= pad_radius + 0.25 + half_width:
                conflicts.append(item)
                break
    return conflicts


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: align_usbc_to_edge.py INPUT.kicad_pcb OUTPUT.kicad_pcb")

    source = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    board = pcbnew.LoadBoard(str(source))

    j5 = require_footprint(board, "J5")
    j6 = require_footprint(board, "J6")
    for retained in ("USB1", "J7", "H2", "CGQ1"):
        require_footprint(board, retained)

    for connector in (j5, j6):
        copper = attached_copper(board, connector)
        if copper:
            raise RuntimeError(
                f"{connector.GetReference()} has {len(copper)} attached copper items; "
                "reroute them before using this placement-only script"
            )
    tracks = list(board.GetTracks())

    bottom_edge = bottom_edge_y_mm(board)
    target_y = bottom_edge - REFERENCE_EDGE_INSET_MM
    if abs(target_y - 139.6495) > 0.001:
        raise RuntimeError(f"unexpected USB-C edge datum {target_y:.4f} mm")

    for connector in (j5, j6):
        connector.SetPosition(point_mm(pcbnew.ToMM(connector.GetX()), target_y))

    conflicts = conflicting_copper(tracks, (j5, j6))
    conflict_ids = {id(item) for item in conflicts}
    for item in tracks:
        if id(item) in conflict_ids:
            board.Remove(item)

    pcbnew.ZONE_FILLER(board).Fill(board.Zones())
    pcbnew.SaveBoard(str(destination), board)
    print(
        f"moved J5/J6 to y={target_y:.4f} mm; shell front now mirrors the "
        f"original USB3 edge protrusion; removed {len(conflicts)} conflicting local "
        f"track/via items"
    )


if __name__ == "__main__":
    main()
