#!/usr/bin/env python3
"""Normalize the three retained edge connectors for layout and 3D review.

The imported Avaota design calls the HDMI receptacle ``USB1``.  That reference is
kept electrically so the imported hierarchy continues to match, but it should not
appear as a misleading assembly/silkscreen label.  J6 was originally cloned from an
EasyEDA footprint whose 3D model path is not part of this project; replace it with
the exact local C720629 footprint already used by J5 while preserving every pad net.
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


def replace_j6_from_j5(board: pcbnew.BOARD) -> None:
    template = require_footprint(board, "J5")
    old = require_footprint(board, "J6")
    pad_nets = {pad.GetNumber(): pad.GetNet() for pad in old.Pads()}
    ground = board.FindNet("GND")
    if ground is None:
        raise RuntimeError("required GND net was not found")

    replacement = pcbnew.Cast_to_FOOTPRINT(template.Duplicate(False))
    replacement.SetPath(pcbnew.KIID_PATH())
    replacement.SetReference("J6")
    replacement.SetValue(old.GetValue())
    replacement.SetPosition(old.GetPosition())
    replacement.SetOrientation(old.GetOrientation())
    replacement.Reference().SetVisible(False)
    board.Add(replacement)

    for pad in replacement.Pads():
        # The project-local footprint numbers the four shell stakes 13..16; the
        # imported EasyEDA clone used 12..15. Always ground all four stakes.
        net = ground if pad.GetNumber() in {"13", "14", "15", "16"} else pad_nets.get(pad.GetNumber())
        if net is None:
            pad.SetNetCode(0)
        else:
            pad.SetNet(net)

    board.Remove(old)


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit(
            "usage: finalize_connector_presentation.py INPUT.kicad_pcb OUTPUT.kicad_pcb"
        )

    source = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    board = pcbnew.LoadBoard(str(source))

    # Query board-owned containers before replacing a footprint. KiCad's SWIG layer
    # can invalidate later iterators after a BOARD.Remove() call in the same process.
    labels = {
        item.GetText()
        for item in board.GetDrawings()
        if isinstance(item, pcbnew.PCB_TEXT)
        and item.GetLayer() == pcbnew.F_SilkS
    }
    missing = {"POWER", "HOST", "HDMI"} - labels
    if missing:
        raise RuntimeError(f"missing connector-edge labels: {sorted(missing)}")

    # POWER, HOST and HDMI board text are the user-facing port labels.  Keep the
    # inherited references in the files, but do not print them on the enclosure edge.
    for footprint in (
        require_footprint(board, "J5"),
        require_footprint(board, "USB1"),
    ):
        footprint.Reference().SetVisible(False)
    replace_j6_from_j5(board)

    pcbnew.SaveBoard(str(destination), board)
    print("replaced J6 with the local C720629 footprint/model")
    print("hid inherited connector references; retained POWER/HOST/HDMI labels")


if __name__ == "__main__":
    main()
