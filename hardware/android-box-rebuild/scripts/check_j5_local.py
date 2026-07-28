#!/usr/bin/env python3
"""Check copper clearance and critical connectivity in the local J5 corridor."""

from __future__ import annotations

import sys
from pathlib import Path

import pcbnew


MM = pcbnew.FromMM
REGION = (100.0, 124.0, 120.5, 140.0)
LAYERS = (pcbnew.F_Cu, pcbnew.In2_Cu, pcbnew.In4_Cu, pcbnew.In5_Cu, pcbnew.B_Cu)
CRITICAL = {
    ("J5", "A5"): {("J5", "A5"), ("U1001", "1"), ("U1001", "2"), ("D1001", "1")},
    ("J5", "B5"): {("J5", "B5"), ("U1001", "4"), ("U1001", "5"), ("D1002", "1")},
    ("J5", "A4B9"): {
        ("J5", "A4B9"), ("J5", "B4A9"), ("C1001", "1"), ("C1002", "1"),
        ("C1005", "1"), ("U1001", "24"), ("U1002", "5"),
    },
    ("U1002", "6"): {
        ("U1002", "6"), ("C1008", "1"), ("C1009", "1"), ("D2", "2"), ("Q1", "3"),
    },
}


def mm(value: int) -> float:
    return pcbnew.ToMM(value)


def in_region(item: pcbnew.BOARD_ITEM) -> bool:
    box = item.GetBoundingBox()
    x1, y1, x2, y2 = REGION
    return not (
        mm(box.GetRight()) < x1 or mm(box.GetLeft()) > x2
        or mm(box.GetBottom()) < y1 or mm(box.GetTop()) > y2
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
            for second in items[index + 1:]:
                if second.GetNetCode() in (0, first.GetNetCode()):
                    continue
                if (
                    isinstance(first, pcbnew.PAD)
                    and isinstance(second, pcbnew.PAD)
                    and first.GetParentFootprint().GetReference()
                    == second.GetParentFootprint().GetReference()
                ):
                    # Production land patterns can locally override the board's
                    # default clearance at fine-pitch package pads.
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


def connected_pad_set(
    board: pcbnew.BOARD, reference: str, pad_number: str
) -> set[tuple[str, str]]:
    footprint = board.FindFootprintByReference(reference)
    if footprint is None:
        raise RuntimeError(f"missing {reference}")
    pad = footprint.FindPadByNumber(pad_number)
    if pad is None:
        raise RuntimeError(f"missing {reference}:{pad_number}")
    result: set[tuple[str, str]] = set()
    for item in board.GetConnectivity().GetConnectedItems(pad):
        if isinstance(item, pcbnew.PAD):
            result.add((item.GetParentFootprint().GetReference(), item.GetNumber()))
    return result


def main() -> None:
    if len(sys.argv) != 2:
        raise SystemExit("usage: check_j5_local.py BOARD.kicad_pcb")
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
