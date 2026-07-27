#!/usr/bin/env python3
"""Remove the external eDP/DisplayPort connector circuit from the staged PCB.

This pass removes U15, the connector-side eDP lane/AUX coupling and protection
parts, its local configuration/power capacitors, the DP silkscreen label, all
dedicated eDP tracks, and GND/DCDC4 fanout directly touching those parts.  It
does not remove the T527's internal eDP-domain decoupling or alter HDMI.

Run with KiCad's bundled Python so the pcbnew module is available:

    .../Python.framework/Versions/Current/bin/python3 \
        scripts/remove_edp_interface.py INPUT.kicad_pcb OUTPUT.kicad_pcb
"""

from __future__ import annotations

import sys
from pathlib import Path

import pcbnew


EDP_REFS = {
    "U15",
    "D10", "D11", "D12",
    "C190", "C191", "C192", "C193", "C194", "C195", "C196", "C197",
    "C198", "C199", "C223", "C224",
    "R56", "R57", "R60", "R61", "R62",
}
SHARED_NETS = {"", "GND", "DCDC4"}


def point_mm(x: float, y: float) -> pcbnew.VECTOR2I:
    return pcbnew.VECTOR2I(pcbnew.FromMM(x), pcbnew.FromMM(y))


def require_footprint(board: pcbnew.BOARD, reference: str) -> pcbnew.FOOTPRINT:
    footprint = board.FindFootprintByReference(reference)
    if footprint is None:
        raise RuntimeError(f"required footprint {reference} was not found")
    return footprint


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: remove_edp_interface.py INPUT.kicad_pcb OUTPUT.kicad_pcb")

    source = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    board = pcbnew.LoadBoard(str(source))

    for retained in ("U14", "USB1", "J5", "J6", "J7", "H2", "CGQ1"):
        require_footprint(board, retained)

    footprints = [require_footprint(board, ref) for ref in sorted(EDP_REFS)]
    pads = [pad for footprint in footprints for pad in footprint.Pads()]
    dedicated_nets = {pad.GetNetname() for pad in pads} - SHARED_NETS

    # Snapshot collections before BOARD.Remove(); KiCad 10's SWIG iterators are
    # invalidated by deletions made earlier in the same process.
    tracks = list(board.GetTracks())
    drawings = list(board.GetDrawings())

    dedicated_copper = [track for track in tracks if track.GetNetname() in dedicated_nets]
    shared_fanout = [
        track
        for track in tracks
        if track.GetNetname() in {"GND", "DCDC4"}
        and any(pad.HitTest(track.GetStart()) or pad.HitTest(track.GetEnd()) for pad in pads)
    ]
    remove_track_ids = {id(track) for track in dedicated_copper + shared_fanout}
    for track in tracks:
        if id(track) in remove_track_ids:
            board.Remove(track)

    for footprint in footprints:
        board.Remove(footprint)

    labels = [
        drawing
        for drawing in drawings
        if isinstance(drawing, pcbnew.PCB_TEXT)
        and drawing.GetLayer() == pcbnew.F_SilkS
        and drawing.GetText() == "DP"
    ]
    if len(labels) != 1:
        raise RuntimeError(f"expected one DP silkscreen label, found {len(labels)}")
    board.Remove(labels[0])

    note = pcbnew.PCB_TEXT(board)
    note.SetText("U15 EXTERNAL EDP/DISPLAYPORT CIRCUIT REMOVED - HDMI RETAINED")
    note.SetLayer(pcbnew.Cmts_User)
    note.SetPosition(point_mm(149.5, 137.0))
    note.SetTextSize(point_mm(0.85, 0.85))
    note.SetTextThickness(pcbnew.FromMM(0.14))
    board.Add(note)

    pcbnew.ZONE_FILLER(board).Fill(board.Zones())
    pcbnew.SaveBoard(str(destination), board)
    print(
        f"removed {len(footprints)} eDP footprints, {len(dedicated_copper)} dedicated "
        f"track/via items, {len(shared_fanout)} shared-rail fanout items and the DP label"
    )


if __name__ == "__main__":
    main()
