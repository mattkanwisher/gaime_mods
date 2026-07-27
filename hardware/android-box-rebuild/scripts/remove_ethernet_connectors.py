#!/usr/bin/env python3
"""Remove both Ethernet jacks and their connector-side track stubs.

The PHYs and their upstream circuitry remain on the board.  Only RJ1/RJ2, the
ETH0/ETH1 edge labels, and track/via items that directly touch a jack pad are
removed.  This keeps pruning local and reversible while the schematic is still
being reduced.

Run with KiCad's bundled Python:

    .../Python.framework/Versions/3.9/bin/python3 \
        scripts/remove_ethernet_connectors.py INPUT.kicad_pcb OUTPUT.kicad_pcb
"""

from __future__ import annotations

import sys
from pathlib import Path

import pcbnew


def require_footprint(board: pcbnew.BOARD, reference: str) -> pcbnew.FOOTPRINT:
    footprint = board.FindFootprintByReference(reference)
    if footprint is None:
        raise RuntimeError(f"required footprint {reference} was not found")
    return footprint


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: remove_ethernet_connectors.py INPUT.kicad_pcb OUTPUT.kicad_pcb")

    source = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    board = pcbnew.LoadBoard(str(source))

    ethernet = [require_footprint(board, "RJ1"), require_footprint(board, "RJ2")]
    ethernet_pads = [pad for footprint in ethernet for pad in footprint.Pads()]

    # Snapshot all iterators before the first BOARD.Remove(); KiCad 10's SWIG
    # collections can be invalidated by deletions made in the same process.
    drawings = list(board.GetDrawings())
    tracks = list(board.GetTracks())

    labels = [
        drawing
        for drawing in drawings
        if isinstance(drawing, pcbnew.PCB_TEXT)
        and drawing.GetLayer() == pcbnew.F_SilkS
        and drawing.GetText() in {"ETH0", "ETH1"}
    ]
    found_labels = {label.GetText() for label in labels}
    if found_labels != {"ETH0", "ETH1"}:
        raise RuntimeError(f"expected ETH0/ETH1 silkscreen labels, found {sorted(found_labels)}")

    direct_fanout = [
        track
        for track in tracks
        if any(
            pad.HitTest(track.GetStart()) or pad.HitTest(track.GetEnd())
            for pad in ethernet_pads
        )
    ]

    for item in labels + direct_fanout + ethernet:
        board.Remove(item)

    note = pcbnew.PCB_TEXT(board)
    note.SetText("RJ1/RJ2 ETHERNET REMOVED - PHY CIRCUITS RETAINED")
    note.SetLayer(pcbnew.Cmts_User)
    note.SetPosition(pcbnew.VECTOR2I(pcbnew.FromMM(174.0), pcbnew.FromMM(133.5)))
    note.SetTextSize(pcbnew.VECTOR2I(pcbnew.FromMM(0.9), pcbnew.FromMM(0.9)))
    note.SetTextThickness(pcbnew.FromMM(0.14))
    board.Add(note)

    pcbnew.ZONE_FILLER(board).Fill(board.Zones())
    pcbnew.SaveBoard(str(destination), board)
    print(f"removed RJ1/RJ2, 2 silkscreen labels and {len(direct_fanout)} direct fanout items")


if __name__ == "__main__":
    main()
