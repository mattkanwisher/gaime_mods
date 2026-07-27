#!/usr/bin/env python3
"""Replace the imported side-oriented HDMI footprint with a horizontal edge part.

The source PCB used HDMI-001C rotated -90 degrees and was first staged with a generic
19APL2 mechanical placeholder. This pass substitutes the verified HCTL HDMI-01 / JLCPCB
C2906135 right-angle Type-A footprint, preserves pad nets and schematic association,
and clears the exact production footprint's local reroute corridor.
"""

from __future__ import annotations

import sys
from pathlib import Path

import pcbnew


SOURCE_REF = "USB1"
FOOTPRINT_LIBRARY = "hdmi.pretty"
FOOTPRINT_NAME = "USB-SMD_HDMI-01"
TARGET_X_MM = 140.124
SHELL_FRONT_OFFSET_MM = 8.10
LOCAL_COPPER_CLEARANCE_MM = 0.2
OBSOLETE_OVERLAPPED_REFS = {"C294"}


def bottom_edge_y(board: pcbnew.BOARD) -> float:
    candidates: list[tuple[float, float]] = []
    for drawing in board.GetDrawings():
        if drawing.GetLayer() != pcbnew.Edge_Cuts or drawing.GetShape() != pcbnew.SHAPE_T_SEGMENT:
            continue
        start = drawing.GetStart()
        end = drawing.GetEnd()
        dx = abs(pcbnew.ToMM(end.x - start.x))
        dy = abs(pcbnew.ToMM(end.y - start.y))
        if dy < 0.01 and dx > 20.0:
            candidates.append(((pcbnew.ToMM(start.y) + pcbnew.ToMM(end.y)) / 2.0, dx))
    if not candidates:
        raise RuntimeError("could not derive the lower horizontal Edge.Cuts datum")
    return max(candidates, key=lambda item: item[0])[0]


def direct_fanout(board: pcbnew.BOARD, footprint: pcbnew.FOOTPRINT) -> list[pcbnew.BOARD_ITEM]:
    connected: list[pcbnew.BOARD_ITEM] = []
    for item in board.Tracks():
        if any(
            item.GetNetCode() == pad.GetNetCode()
            and (pad.HitTest(item.GetStart()) or pad.HitTest(item.GetEnd()))
            for pad in footprint.Pads()
        ):
            connected.append(item)
    return connected


def boxes_overlap(
    first: pcbnew.BOX2I, second: pcbnew.BOX2I, margin: int = 0
) -> bool:
    return not (
        first.GetRight() + margin < second.GetX()
        or second.GetRight() < first.GetX() - margin
        or first.GetBottom() + margin < second.GetY()
        or second.GetBottom() < first.GetY() - margin
    )


def conflicting_copper(
    board: pcbnew.BOARD, footprint: pcbnew.FOOTPRINT
) -> list[pcbnew.BOARD_ITEM]:
    """Return old track/via items whose copper overlaps a differently-netted new pad."""
    conflicts: list[pcbnew.BOARD_ITEM] = []
    clearance = pcbnew.FromMM(LOCAL_COPPER_CLEARANCE_MM)
    for item in board.Tracks():
        for pad in footprint.Pads():
            if (
                pad.IsOnLayer(item.GetLayer())
                and pad.GetNetCode() != item.GetNetCode()
                and boxes_overlap(pad.GetBoundingBox(), item.GetBoundingBox(), clearance)
            ):
                conflicts.append(item)
                break
    return conflicts


def replace(input_path: Path, output_path: Path) -> None:
    board = pcbnew.LoadBoard(str(input_path))
    old = next((fp for fp in board.GetFootprints() if fp.GetReference() == SOURCE_REF), None)
    if old is None:
        raise RuntimeError(f"{SOURCE_REF} not found")
    if str(old.GetFPID().GetLibItemName()) == FOOTPRINT_NAME:
        raise RuntimeError(f"{SOURCE_REF} already uses the production HDMI footprint")

    nets_by_pad: dict[str, pcbnew.NETINFO_ITEM] = {}
    for pad in old.Pads():
        if pad.GetNetCode() and pad.GetNumber() not in nets_by_pad:
            nets_by_pad[pad.GetNumber()] = pad.GetNet()
    if not all(str(number) in nets_by_pad for number in range(1, 20)):
        raise RuntimeError("the imported HDMI signal pad/net map is incomplete")
    shield_net = nets_by_pad.get("20") or nets_by_pad.get("SH")
    if shield_net is None:
        raise RuntimeError("the imported HDMI shield/GND net is missing")

    local_library = input_path.parent / "libs" / FOOTPRINT_LIBRARY
    replacement = pcbnew.FootprintLoad(str(local_library), FOOTPRINT_NAME)
    if replacement is None:
        raise RuntimeError(f"could not load {local_library / (FOOTPRINT_NAME + '.kicad_mod')}")

    stale_fanout = direct_fanout(board, old)
    old_path = old.GetPath()
    old_sheetname = old.GetSheetname()
    old_sheetfile = old.GetSheetfile()
    board.Remove(old)
    for item in stale_fanout:
        board.Remove(item)

    replacement.SetReference(SOURCE_REF)
    replacement.SetValue(FOOTPRINT_NAME)
    replacement.SetPath(old_path)
    replacement.SetSheetname(old_sheetname)
    replacement.SetSheetfile(old_sheetfile)
    replacement.SetOrientationDegrees(0.0)
    target_y = bottom_edge_y(board) - SHELL_FRONT_OFFSET_MM
    replacement.SetPosition(pcbnew.VECTOR2I_MM(TARGET_X_MM, target_y))
    board.Add(replacement)

    for pad in replacement.Pads():
        if pad.GetNumber() in {"20", "21", "22", "23"}:
            pad.SetNet(shield_net)
        elif pad.GetNumber() in nets_by_pad:
            pad.SetNet(nets_by_pad[pad.GetNumber()])
        if pad.GetNumber() in {"2", "5", "8", "11", "17", "20", "21", "22", "23"}:
            pad.SetLocalZoneConnection(pcbnew.ZONE_CONNECTION_FULL)

    obsolete_parts = [
        fp for fp in board.GetFootprints() if fp.GetReference() in OBSOLETE_OVERLAPPED_REFS
    ]
    obsolete_fanout: list[pcbnew.BOARD_ITEM] = []
    for footprint in obsolete_parts:
        obsolete_fanout.extend(direct_fanout(board, footprint))
        board.Remove(footprint)

    local_conflicts = conflicting_copper(board, replacement)
    copper_to_remove: list[pcbnew.BOARD_ITEM] = []
    for item in [*obsolete_fanout, *local_conflicts]:
        if item not in copper_to_remove:
            copper_to_remove.append(item)
    for item in copper_to_remove:
        board.Remove(item)

    filler = pcbnew.ZONE_FILLER(board)
    filler.Fill(board.Zones())
    pcbnew.SaveBoard(str(output_path), board)
    print(
        f"replaced {SOURCE_REF} with {FOOTPRINT_NAME} at "
        f"x={TARGET_X_MM:.3f}, y={target_y:.3f}, rotation=0 deg; "
        f"removed {len(stale_fanout)} old direct fanout items, "
        f"{len(copper_to_remove)} conflicting local copper items and "
        f"{len(obsolete_parts)} obsolete overlapped support part(s)"
    )


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit(f"usage: {Path(sys.argv[0]).name} INPUT.kicad_pcb OUTPUT.kicad_pcb")
    replace(Path(sys.argv[1]).resolve(), Path(sys.argv[2]).resolve())


if __name__ == "__main__":
    main()
