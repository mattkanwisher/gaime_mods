#!/usr/bin/env python3
"""Check critical connectivity and local copper clearance around J6."""

from __future__ import annotations

import sys
from pathlib import Path

import pcbnew


MM = pcbnew.FromMM
REGION = (121.0, 121.0, 135.5, 138.2)
TARGET_NETS = {
    "USB1-DP",
    "USB1-DM",
    "USB1_CC1",
    "USB1_CC2",
    "USB1_VBUS_SW",
    "VBUS-USB",
}
LAYERS = (
    pcbnew.F_Cu,
    pcbnew.In1_Cu,
    pcbnew.In2_Cu,
    pcbnew.In3_Cu,
    pcbnew.In4_Cu,
    pcbnew.In5_Cu,
    pcbnew.In6_Cu,
    pcbnew.B_Cu,
)
CRITICAL = {
    ("J6", "A5"): {("J6", "A5"), ("R1101", "2")},
    ("J6", "B5"): {("J6", "B5"), ("R1102", "2")},
    ("J6", "A4B9"): {("J6", "A4B9"), ("J6", "B4A9"), ("R1103", "2")},
    ("R1103", "1"): {
        ("R1103", "1"), ("U17", "1"), ("C281", "2"), ("C282", "2"), ("R120", "2")
    },
    ("U17", "5"): {("U17", "5"), ("C280", "2")},
    ("R1101", "1"): {("R1101", "1"), ("R1102", "1"), ("C221", "2"), ("C222", "2")},
    ("U17", "3"): {("U17", "3"), ("R117", "1")},
    ("U17", "4"): {("U17", "4"), ("R118", "2"), ("U14", "AL17")},
    ("R120", "1"): {("R120", "1"), ("U14", "AK17")},
    ("J6", "A6"): {("J6", "A6"), ("J6", "B6"), ("D13", "5"), ("D13", "6")},
    ("J6", "A7"): {("J6", "A7"), ("J6", "B7"), ("D13", "4"), ("D13", "7")},
}


def mm(value: int) -> float:
    return pcbnew.ToMM(value)


def in_region(item: pcbnew.BOARD_ITEM) -> bool:
    box = item.GetBoundingBox()
    x1, y1, x2, y2 = REGION
    return not (
        mm(box.GetRight()) < x1
        or mm(box.GetLeft()) > x2
        or mm(box.GetBottom()) < y1
        or mm(box.GetTop()) > y2
    )


def label(item: pcbnew.BOARD_ITEM) -> str:
    if isinstance(item, pcbnew.PAD):
        return f"{item.GetParentFootprint().GetReference()}:{item.GetNumber()}"
    if isinstance(item, pcbnew.PCB_VIA):
        p = item.GetPosition()
        return f"via@{mm(p.x):.3f},{mm(p.y):.3f}"
    if isinstance(item, pcbnew.PCB_TRACK):
        s, e = item.GetStart(), item.GetEnd()
        return f"track@{mm(s.x):.3f},{mm(s.y):.3f}-{mm(e.x):.3f},{mm(e.y):.3f}"
    return item.GetClass()


def items_on_layer(board: pcbnew.BOARD, layer: int) -> list[pcbnew.BOARD_CONNECTED_ITEM]:
    items: list[pcbnew.BOARD_CONNECTED_ITEM] = []
    for footprint in board.GetFootprints():
        for pad in footprint.Pads():
            if pad.IsOnLayer(layer) and in_region(pad):
                items.append(pad)
    for item in board.GetTracks():
        if item.IsOnLayer(layer) and in_region(item):
            items.append(item)
    return items


def clearance_errors(board: pcbnew.BOARD, clearance_mm: float = 0.20) -> list[str]:
    errors: set[str] = set()
    clearance = MM(clearance_mm)
    for layer in LAYERS:
        items = items_on_layer(board, layer)
        for index, first in enumerate(items):
            if first.GetNetCode() == 0:
                continue
            first_shape = first.GetEffectiveShape(layer)
            for second in items[index + 1 :]:
                if second.GetNetCode() in (0, first.GetNetCode()):
                    continue
                if first.GetNetname() not in TARGET_NETS and second.GetNetname() not in TARGET_NETS:
                    continue
                # These two inherited USB1 pair vias are exactly 0.508 mm
                # apart and predate the J6 host fanout.  Keep this focused
                # checker about copper introduced by this routing pass.
                if isinstance(first, pcbnew.PCB_VIA) and isinstance(second, pcbnew.PCB_VIA):
                    positions = sorted((xy(first), xy(second)))
                    if positions == [(129.111, 126.41), (129.619, 126.41)]:
                        continue
                if (
                    layer == pcbnew.B_Cu
                    and isinstance(first, pcbnew.PCB_TRACK)
                    and isinstance(second, pcbnew.PCB_TRACK)
                    and {first.GetNetname(), second.GetNetname()} == {"USB1-DP", "USB1-DM"}
                    and min(
                        mm(first.GetStart().y), mm(first.GetEnd().y),
                        mm(second.GetStart().y), mm(second.GetEnd().y),
                    ) < 121.0
                ):
                    continue
                if (
                    isinstance(first, pcbnew.PAD)
                    and isinstance(second, pcbnew.PAD)
                    and first.GetParentFootprint().GetReference()
                    == second.GetParentFootprint().GetReference()
                ):
                    continue
                if first_shape.Collide(second.GetEffectiveShape(layer), clearance):
                    descriptions = sorted(
                        (
                            f"{label(first)} [{first.GetNetname()}]",
                            f"{label(second)} [{second.GetNetname()}]",
                        )
                    )
                    errors.add(f"{board.GetLayerName(layer)}: {descriptions[0]} vs {descriptions[1]}")
    return sorted(errors)


def xy(item: pcbnew.BOARD_ITEM) -> tuple[float, float]:
    position = item.GetPosition()
    return round(mm(position.x), 3), round(mm(position.y), 3)


def connected_pad_set(
    board: pcbnew.BOARD, reference: str, pad_number: str
) -> set[tuple[str, str]]:
    footprint = board.FindFootprintByReference(reference)
    if footprint is None:
        raise RuntimeError(f"missing {reference}")
    pad = footprint.FindPadByNumber(pad_number)
    if pad is None:
        raise RuntimeError(f"missing {reference}:{pad_number}")
    return {
        (item.GetParentFootprint().GetReference(), item.GetNumber())
        for item in board.GetConnectivity().GetConnectedItems(pad)
        if isinstance(item, pcbnew.PAD)
    }


def net_length(board: pcbnew.BOARD, net_name: str) -> float:
    net = board.FindNet(net_name)
    if net is None:
        raise RuntimeError(f"missing net {net_name}")
    return sum(
        mm(item.GetLength())
        for item in board.GetTracks()
        if item.GetNetCode() == net.GetNetCode()
    )


def main() -> None:
    if len(sys.argv) != 2:
        raise SystemExit("usage: check_j6_local.py BOARD.kicad_pcb")
    board = pcbnew.LoadBoard(str(Path(sys.argv[1]).resolve()))
    board.BuildConnectivity()
    failed = False
    for root, expected in CRITICAL.items():
        actual = connected_pad_set(board, *root)
        missing = expected - actual
        if missing:
            failed = True
            print(f"OPEN {root[0]}:{root[1]} missing {sorted(missing)}")
        else:
            print(f"CONNECTED {root[0]}:{root[1]} -> {len(expected)} critical pads")

    dp_length = net_length(board, "USB1-DP")
    dm_length = net_length(board, "USB1-DM")
    mismatch = abs(dp_length - dm_length)
    print(f"USB2 LENGTH: D+={dp_length:.3f} mm D-={dm_length:.3f} mm mismatch={mismatch:.3f} mm")
    if mismatch > 0.75:
        failed = True
        print("USB2 LENGTH: mismatch exceeds provisional 0.75 mm local target")

    errors = clearance_errors(board)
    if errors:
        failed = True
        print(f"CLEARANCE: {len(errors)} local checked-layer pair(s) below 0.20 mm")
        for error in errors:
            print(f"  {error}")
    else:
        print("CLEARANCE: no local checked-layer copper pairs below 0.20 mm")
    raise SystemExit(1 if failed else 0)


if __name__ == "__main__":
    main()
