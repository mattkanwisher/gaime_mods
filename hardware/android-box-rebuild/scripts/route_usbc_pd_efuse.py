#!/usr/bin/env python3
"""Place and route the local TPS259470L analogue-programming parts.

This incremental PD milestone adds the eFuse slew-rate capacitor, fault-timer
capacitor, and current-limit resistor.  The voltage-window dividers and
PDO2-qualified enable gate remain for the next committed routing step.

Run with KiCad's bundled Python:

    .../Python.framework/Versions/Current/bin/python3 \
        scripts/route_usbc_pd_efuse.py INPUT.kicad_pcb OUTPUT.kicad_pcb
"""

from __future__ import annotations

import sys
from pathlib import Path

import pcbnew

from route_usbc_pd_power import (
    KICAD_FOOTPRINTS,
    SIGNAL_WIDTH,
    add_polyline,
    add_track,
    add_via,
    get_or_create_net,
    pad_xy,
    place,
    require_footprint,
)


def place_local_programming_parts(
    board: pcbnew.BOARD,
) -> dict[str, pcbnew.FOOTPRINT]:
    if board.FindFootprintByReference("C1006") is not None:
        raise RuntimeError("eFuse local programming parts are already present")

    capacitor_library = KICAD_FOOTPRINTS / "Capacitor_SMD.pretty"
    resistor_library = KICAD_FOOTPRINTS / "Resistor_SMD.pretty"
    return {
        "C1006": place(
            board, capacitor_library, "C_0603_1608Metric", "C1006", "2.2nF",
            (119.5, 136.5), {"1": "EFUSE_DVDT", "2": "GND"}, 270.0,
        ),
        "C1007": place(
            board, capacitor_library, "C_0603_1608Metric", "C1007", "2.2nF",
            (120.5, 131.5), {"1": "EFUSE_ITIMER", "2": "GND"}, 90.0,
        ),
        "R1012": place(
            board, resistor_library, "R_0603_1608Metric", "R1012", "1.00k 1%",
            (123.0, 132.0), {"1": "EFUSE_ILM", "2": "GND"}, 90.0,
        ),
    }


def ground_pad(
    board: pcbnew.BOARD,
    footprint: pcbnew.FOOTPRINT,
    via_location: tuple[float, float],
) -> None:
    ground = get_or_create_net(board, "GND")
    add_track(board, ground, pad_xy(footprint, "2"), via_location, 0.25)
    add_via(board, ground, via_location)


def route_local_programming_parts(
    board: pcbnew.BOARD, fp: dict[str, pcbnew.FOOTPRINT]
) -> None:
    u2 = require_footprint(board, "U1002")

    # DVDT exits upward toward the connector edge, clear of the pre-existing
    # ground via at 118.5/134.525 and the raw-VBUS neck to its left.
    dvdt = get_or_create_net(board, "EFUSE_DVDT")
    add_polyline(
        board, dvdt,
        [pad_xy(u2, "7"), (117.35, 135.25), (118.00, 135.50), pad_xy(fp["C1006"], "1")],
        SIGNAL_WIDTH,
    )

    # ITIMER uses the short top-layer corridor directly below U1002.
    timer = get_or_create_net(board, "EFUSE_ITIMER")
    add_polyline(
        board, timer,
        [pad_xy(u2, "10"), (118.00, 132.60), (118.50, 132.275), pad_xy(fp["C1007"], "1")],
        SIGNAL_WIDTH,
    )

    # ILM crosses under the timer on In2.Cu, then returns to the top beside R1012.
    ilm = get_or_create_net(board, "EFUSE_ILM")
    source_via = (119.20, 133.10)
    target_via = (123.00, 134.00)
    add_polyline(
        board, ilm,
        [pad_xy(u2, "9"), (117.75, 133.27), (118.00, 133.10), source_via],
        0.15,
    )
    add_via(board, ilm, source_via)
    add_polyline(
        board, ilm,
        [source_via, (120.00, 134.20), (123.00, 134.20), target_via],
        SIGNAL_WIDTH, pcbnew.In2_Cu,
    )
    add_via(board, ilm, target_via)
    add_track(board, ilm, target_via, pad_xy(fp["R1012"], "1"), SIGNAL_WIDTH)

    ground_pad(board, fp["C1006"], (120.20, 138.30))
    ground_pad(board, fp["C1007"], (120.50, 129.90))
    ground_pad(board, fp["R1012"], (123.00, 130.40))


def update_note(board: pcbnew.BOARD) -> None:
    for drawing in board.GetDrawings():
        if isinstance(drawing, pcbnew.PCB_TEXT) and drawing.GetText().startswith(
            "J5 USB-C PD"
        ):
            drawing.SetText("J5 USB-C PD: POWER + EFUSE TIMING/ILM ROUTED")
            return


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: route_usbc_pd_efuse.py INPUT.kicad_pcb OUTPUT.kicad_pcb")
    source = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    board = pcbnew.LoadBoard(str(source))
    footprints = place_local_programming_parts(board)
    route_local_programming_parts(board, footprints)
    update_note(board)
    board.BuildConnectivity()
    pcbnew.ZONE_FILLER(board).Fill(board.Zones())
    pcbnew.SaveBoard(str(destination), board)
    print("placed and routed C1006, C1007, and R1012 beside U1002")
    print("completed eFuse dV/dt, timer, and nominal 3.33 A current-limit programming")
    print("left the EN/OVLO dividers and PDO2_OK gate for the next committed step")


if __name__ == "__main__":
    main()
