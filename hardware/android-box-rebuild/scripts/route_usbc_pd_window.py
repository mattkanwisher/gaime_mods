#!/usr/bin/env python3
"""Place and route the TPS259470L UVLO/OVLO voltage-window dividers.

This PD milestone adds R1008-R1011.  The divider values admit the intended 9 V
contract while rejecting default 5 V and contracts above approximately 10.87 V.
The separate PDO2_OK_N/Q1001 enable qualification remains for the next step.
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


def place_window_dividers(board: pcbnew.BOARD) -> dict[str, pcbnew.FOOTPRINT]:
    if board.FindFootprintByReference("R1008") is not None:
        raise RuntimeError("eFuse voltage-window dividers are already present")
    library = KICAD_FOOTPRINTS / "Resistor_SMD.pretty"
    parts = {
        "R1008": ("499k 1%", (126.0, 130.0), {"1": "PD_VBUS_RAW", "2": "EFUSE_EN"}),
        "R1009": ("100k 1%", (129.0, 130.0), {"1": "EFUSE_EN", "2": "GND"}),
        "R1010": ("806k 1%", (126.0, 135.0), {"1": "PD_VBUS_RAW", "2": "EFUSE_OVLO"}),
        "R1011": ("100k 1%", (129.0, 135.0), {"1": "EFUSE_OVLO", "2": "GND"}),
    }
    return {
        reference: place(
            board, library, "R_0603_1608Metric", reference, value, location, nets
        )
        for reference, (value, location, nets) in parts.items()
    }


def route_window_dividers(
    board: pcbnew.BOARD, fp: dict[str, pcbnew.FOOTPRINT]
) -> None:
    u2 = require_footprint(board, "U1002")
    raw = get_or_create_net(board, "PD_VBUS_RAW")
    en = get_or_create_net(board, "EFUSE_EN")
    ovlo = get_or_create_net(board, "EFUSE_OVLO")
    ground = get_or_create_net(board, "GND")

    # Raw VBUS reaches the two upper divider pads through a shared In4.Cu branch.
    raw_low_via = (124.40, 130.00)
    raw_high_via = (124.40, 135.00)
    for location in (raw_low_via, raw_high_via):
        add_via(board, raw, location)
    add_polyline(
        board, raw,
        [(116.70, 135.60), (118.00, 136.50), (124.40, 136.50), raw_low_via],
        SIGNAL_WIDTH, pcbnew.In4_Cu,
    )
    add_track(board, raw, raw_low_via, pad_xy(fp["R1008"], "1"), SIGNAL_WIDTH)
    add_track(board, raw, raw_high_via, pad_xy(fp["R1010"], "1"), SIGNAL_WIDTH)

    # EN exits U1002 below the package and runs on In5.Cu to the lower divider.
    en_source_via = (114.30, 131.80)
    en_target_via = (127.50, 130.00)
    add_track(board, en, pad_xy(u2, "1"), en_source_via, 0.15)
    add_via(board, en, en_source_via)
    add_polyline(
        board, en,
        [en_source_via, (112.50, 131.80), (112.50, 125.50), (127.50, 125.50), en_target_via],
        SIGNAL_WIDTH, pcbnew.In5_Cu,
    )
    add_via(board, en, en_target_via)
    add_track(board, en, pad_xy(fp["R1008"], "2"), pad_xy(fp["R1009"], "1"), SIGNAL_WIDTH)

    # OVLO exits upward and crosses the raw power corridor on In2.Cu.
    ovlo_source_via = (114.00, 134.00)
    ovlo_target_via = (127.50, 135.00)
    add_track(board, ovlo, pad_xy(u2, "2"), ovlo_source_via, 0.15)
    add_via(board, ovlo, ovlo_source_via)
    add_polyline(
        board, ovlo,
        [ovlo_source_via, (113.50, 136.60), (127.50, 136.60), ovlo_target_via],
        SIGNAL_WIDTH, pcbnew.In2_Cu,
    )
    add_via(board, ovlo, ovlo_target_via)
    add_track(board, ovlo, pad_xy(fp["R1010"], "2"), pad_xy(fp["R1011"], "1"), SIGNAL_WIDTH)

    # Each lower divider resistor gets an independent ground stitch.
    for reference, via_location in (("R1009", (130.70, 130.00)), ("R1011", (130.70, 135.00))):
        add_track(board, ground, pad_xy(fp[reference], "2"), via_location, 0.25)
        add_via(board, ground, via_location)


def update_note(board: pcbnew.BOARD) -> None:
    for drawing in board.GetDrawings():
        if isinstance(drawing, pcbnew.PCB_TEXT) and drawing.GetText().startswith(
            "J5 USB-C PD"
        ):
            drawing.SetText("J5 USB-C PD: POWER + EFUSE ANALOG CTRL ROUTED")
            return


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: route_usbc_pd_window.py INPUT.kicad_pcb OUTPUT.kicad_pcb")
    source = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    board = pcbnew.LoadBoard(str(source))
    footprints = place_window_dividers(board)
    route_window_dividers(board, footprints)
    update_note(board)
    board.BuildConnectivity()
    pcbnew.ZONE_FILLER(board).Fill(board.Zones())
    pcbnew.SaveBoard(str(destination), board)
    print("placed and routed R1008-R1011")
    print("completed the approximately 7.19 V UVLO and 10.87 V OVLO divider window")
    print("left PDO2_OK_N/Q1001 enable qualification for the next step")


if __name__ == "__main__":
    main()
