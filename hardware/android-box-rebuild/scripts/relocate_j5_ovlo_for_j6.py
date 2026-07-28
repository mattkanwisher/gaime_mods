#!/usr/bin/env python3
"""Move the J5 OVLO divider out of the J6 Type-C fanout corridor."""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path

import pcbnew

from route_usbc_pd_power import add_polyline, add_track, add_via, pad_xy, require_footprint


SIGNAL_WIDTH = 0.20


def point_in_box(point: pcbnew.VECTOR2I, box: tuple[float, float, float, float]) -> bool:
    x, y = pcbnew.ToMM(point.x), pcbnew.ToMM(point.y)
    x1, y1, x2, y2 = box
    return x1 <= x <= x2 and y1 <= y <= y2


def clear_old_ovlo_copper(board: pcbnew.BOARD) -> int:
    box = (113.0, 133.5, 131.2, 137.0)
    removed = 0
    for item in list(board.GetTracks()):
        if item.GetNetname() not in {"PD_VBUS_RAW", "EFUSE_OVLO", "GND"}:
            continue
        endpoints = (item.GetStart(), item.GetEnd())
        if any(point_in_box(endpoint, box) for endpoint in endpoints):
            # Preserve unrelated ground and raw-power items outside the old
            # R1010/R1011 branch by requiring at least one endpoint at x >= 123 mm.
            if max(pcbnew.ToMM(endpoint.x) for endpoint in endpoints) < 123.0:
                continue
            board.Remove(item)
            removed += 1
    return removed


def main() -> None:
    if len(sys.argv) == 4 and sys.argv[1] == "--clear-only":
        board = pcbnew.LoadBoard(str(Path(sys.argv[2]).resolve()))
        removed = clear_old_ovlo_copper(board)
        pcbnew.SaveBoard(str(Path(sys.argv[3]).resolve()), board)
        print(f"REMOVED={removed}")
        return
    if len(sys.argv) != 3:
        raise SystemExit("usage: relocate_j5_ovlo_for_j6.py INPUT.kicad_pcb OUTPUT.kicad_pcb")

    source = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    cleaned = subprocess.run(
        [sys.executable, __file__, "--clear-only", str(source), str(destination)],
        check=True,
        capture_output=True,
        text=True,
    )
    removed_line = next(line for line in cleaned.stdout.splitlines() if line.startswith("REMOVED="))
    removed = int(removed_line.split("=", 1)[1])
    board = pcbnew.LoadBoard(str(destination))

    r1010 = require_footprint(board, "R1010")
    r1011 = require_footprint(board, "R1011")
    r1010.SetPosition(pcbnew.VECTOR2I_MM(132.0, 123.5))
    r1010.SetOrientationDegrees(90.0)
    r1011.SetPosition(pcbnew.VECTOR2I_MM(133.8, 123.5))
    r1011.SetOrientationDegrees(-90.0)

    raw = board.FindNet("PD_VBUS_RAW")
    ovlo = board.FindNet("EFUSE_OVLO")
    ground = board.FindNet("GND")
    if None in (raw, ovlo, ground):
        raise RuntimeError("required J5 OVLO nets are missing")

    raw_target = (131.2, 122.0)
    add_via(board, raw, raw_target)
    add_polyline(
        board,
        raw,
        [(116.7, 135.6), (118.0, 136.5), (123.6, 136.5), (123.6, 130.0)],
        SIGNAL_WIDTH,
        pcbnew.In4_Cu,
    )
    add_polyline(
        board,
        raw,
        [(123.6, 130.0), (126.0, 128.4), (126.0, 123.0), raw_target],
        SIGNAL_WIDTH,
        pcbnew.In4_Cu,
    )
    add_track(board, raw, raw_target, pad_xy(r1010, "1"), SIGNAL_WIDTH, pcbnew.F_Cu)

    add_track(board, ovlo, pad_xy(r1010, "2"), pad_xy(r1011, "1"), SIGNAL_WIDTH, pcbnew.F_Cu)
    ovlo_target = (132.9, 125.2)
    add_track(board, ovlo, pad_xy(r1011, "1"), ovlo_target, SIGNAL_WIDTH, pcbnew.F_Cu)
    add_via(board, ovlo, ovlo_target)
    add_polyline(
        board,
        ovlo,
        [(114.0, 134.0), (110.0, 130.0), (110.0, 121.0), (129.0, 121.0), ovlo_target],
        SIGNAL_WIDTH,
        pcbnew.In3_Cu,
    )

    ground_target = (134.8, 122.5)
    add_track(board, ground, pad_xy(r1011, "2"), ground_target, 0.25, pcbnew.F_Cu)
    add_via(board, ground, ground_target)

    pcbnew.ZONE_FILLER(board).Fill(board.Zones())
    pcbnew.SaveBoard(str(destination), board)
    print(f"relocated R1010/R1011; removed {removed} old OVLO branch items")
    print("freed the J6 reversible USB2 fanout corridor without changing divider values")


if __name__ == "__main__":
    main()
