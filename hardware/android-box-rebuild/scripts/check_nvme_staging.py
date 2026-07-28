#!/usr/bin/env python3
"""Verify the mechanical datum and staged M.2 NVMe pad assignments.

Run with KiCad's bundled Python so the pcbnew module is available. This checker
deliberately verifies only the PCB staging contract; it does not certify that the
PCIe interface is electrically complete.
"""

from __future__ import annotations

import argparse
import collections
import math
from pathlib import Path

import pcbnew


PROJECT_DIR = Path(__file__).resolve().parents[1]
DEFAULT_BOARD = PROJECT_DIR / "android-box-rebuild.kicad_pcb"

EXPECTED_NETS = {
    "1": "GND",
    "2": "NVME_3V3_SW",
    "3": "GND",
    "4": "NVME_3V3_SW",
    "9": "GND",
    "10": "NVME_DAS_DSS_N",
    "12": "NVME_3V3_SW",
    "14": "NVME_3V3_SW",
    "15": "GND",
    "16": "NVME_3V3_SW",
    "18": "NVME_3V3_SW",
    "21": "GND",
    "27": "GND",
    "33": "GND",
    "39": "GND",
    "41": "USB2-RXN",
    "43": "USB2-RXP",
    "45": "GND",
    "47": "$6N19249",
    "49": "$6N19248",
    "50": "PCIE_PERST_N",
    "51": "GND",
    "52": "PCIE_CLKREQ_N",
    "53": "PCIE_REFCLK_N",
    "54": "PCIE_WAKE_N",
    "55": "PCIE_REFCLK_P",
    "57": "GND",
    "70": "NVME_3V3_SW",
    "71": "GND",
    "72": "NVME_3V3_SW",
    "73": "GND",
    "74": "NVME_3V3_SW",
    "75": "GND",
    "76": "GND",
}

REQUIRED_ELECTRICAL_NETS = (
    "PCIE_REFCLK_N",
    "PCIE_REFCLK_P",
    "PCIE_PERST_N",
    "PCIE_CLKREQ_N",
    "PCIE_WAKE_N",
    "NVME_3V3_SW",
)


def mm(value: int) -> float:
    return pcbnew.ToMM(value)


def require(condition: bool, message: str) -> None:
    if not condition:
        raise RuntimeError(message)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("board", nargs="?", type=Path, default=DEFAULT_BOARD)
    args = parser.parse_args()

    board = pcbnew.LoadBoard(str(args.board.resolve()))
    j7 = board.FindFootprintByReference("J7")
    h2 = board.FindFootprintByReference("H2")
    require(j7 is not None, "J7 is missing")
    require(h2 is not None, "H2 is missing")

    require(j7.GetLayer() == pcbnew.F_Cu, "J7 must remain on F.Cu")
    require(h2.GetLayer() == pcbnew.F_Cu, "H2 must remain on F.Cu")
    require(math.isclose(mm(j7.GetX()), 184.5, abs_tol=0.001), "J7 X datum changed")
    require(math.isclose(mm(j7.GetY()), 122.0, abs_tol=0.001), "J7 Y datum changed")
    require(math.isclose(j7.GetOrientationDegrees(), 90.0, abs_tol=0.01), "J7 rotation changed")
    require(math.isclose(mm(h2.GetX()), 154.5, abs_tol=0.001), "H2 X datum changed")
    require(math.isclose(mm(h2.GetY()), 122.0, abs_tol=0.001), "H2 Y datum changed")
    require(math.isclose(math.hypot(mm(j7.GetX() - h2.GetX()), mm(j7.GetY() - h2.GetY())), 30.0, abs_tol=0.001),
            "J7-to-H2 2230 datum is not 30.0 mm")

    pad_nets: dict[str, set[str]] = collections.defaultdict(set)
    for pad in j7.Pads():
        if pad.GetNumber():
            pad_nets[pad.GetNumber()].add(pad.GetNetname())
    for number, expected in EXPECTED_NETS.items():
        require(expected in pad_nets[number], f"J7 pad {number}: expected {expected}, found {sorted(pad_nets[number])}")

    copper_counts = collections.Counter(item.GetNetname() for item in board.GetTracks())
    print(f"PASS: J7 is on {board.GetLayerName(j7.GetLayer())} at (184.500, 122.000) mm / 90 deg")
    print("PASS: H2 is on the same side at a 30.000 mm M.2 2230 datum")
    print("PASS: staged M-key PCIe x1/refclock/control/power pad assignments match the design table")
    print("Copper items on unfinished electrical nets:")
    for net in REQUIRED_ELECTRICAL_NETS:
        print(f"  {net}: {copper_counts[net]}")
    print("STAGING ONLY: schematic, 3.3 V supply, refclock/control and PCIe routing still require release checks")


if __name__ == "__main__":
    main()
