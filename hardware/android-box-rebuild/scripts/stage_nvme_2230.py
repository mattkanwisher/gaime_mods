#!/usr/bin/env python3
"""Stage an M-key M.2 2230 NVMe connector in the vacated Ethernet area.

This is a mechanical and net-assignment pass, not a finished PCIe design.  It
removes both complete GMAC0/GMAC1 component groups, places J7 and its 2230
mounting hole, and assigns the PCIe lane/control/power pads.  Reference clock,
control, 3.3 V power and all high-speed routing intentionally remain unfinished.

Run with KiCad's bundled Python so the pcbnew module is available:

    .../Python.framework/Versions/Current/bin/python3 \
        scripts/stage_nvme_2230.py INPUT.kicad_pcb OUTPUT.kicad_pcb
"""

from __future__ import annotations

import math
import sys
from pathlib import Path

import pcbnew


MM = pcbnew.FromMM
PROJECT_DIR = Path(__file__).resolve().parent.parent
FOOTPRINT_LIBRARY = PROJECT_DIR / "libs" / "nvme.pretty"
FOOTPRINT_NAME = "CONN-SMD_91302-42-067RDM"

# These references come directly from the two imported GMAC schematic sheets.
# RJ1/RJ2 were removed in the preceding connector-prune pass.
GMAC0_REFS = {
    "C248", "C249", "C250", "C251", "C252", "C253", "C254", "C262",
    "C263", "C264", "C265", "C266", "C267", "C268", "L9", "R79",
    "R80", "R82", "R83", "R85", "R86", "R88", "R89", "R90", "R91",
    "R92", "R93", "R94", "R95", "R96", "U12", "X3",
}
GMAC1_REFS = {
    "C255", "C256", "C257", "C258", "C259", "C260", "C261", "C269",
    "C270", "C271", "C272", "C273", "C274", "C275", "L10", "R97",
    "R98", "R100", "R101", "R103", "R104", "R106", "R107", "R108",
    "R109", "R110", "R111", "R112", "R113", "R114", "U13", "X4",
}


def point_mm(x: float, y: float) -> pcbnew.VECTOR2I:
    return pcbnew.VECTOR2I(MM(x), MM(y))


def require_footprint(board: pcbnew.BOARD, reference: str) -> pcbnew.FOOTPRINT:
    footprint = board.FindFootprintByReference(reference)
    if footprint is None:
        raise RuntimeError(f"required footprint {reference} was not found")
    return footprint


def get_or_create_net(board: pcbnew.BOARD, name: str) -> pcbnew.NETINFO_ITEM:
    net = board.FindNet(name)
    if net is None:
        net = pcbnew.NETINFO_ITEM(board, name)
        board.Add(net)
    return net


def direct_fanout_items(
    tracks: list[pcbnew.BOARD_ITEM], pads: list[pcbnew.PAD]
) -> list[pcbnew.BOARD_ITEM]:
    return [
        track
        for track in tracks
        if any(pad.HitTest(track.GetStart()) or pad.HitTest(track.GetEnd()) for pad in pads)
    ]


def distance_to_segment_mm(
    point: tuple[float, float], start: pcbnew.VECTOR2I, end: pcbnew.VECTOR2I
) -> float:
    px, py = point
    x1, y1 = pcbnew.ToMM(start.x), pcbnew.ToMM(start.y)
    x2, y2 = pcbnew.ToMM(end.x), pcbnew.ToMM(end.y)
    dx, dy = x2 - x1, y2 - y1
    if dx == 0 and dy == 0:
        return math.hypot(px - x1, py - y1)
    t = max(0.0, min(1.0, ((px - x1) * dx + (py - y1) * dy) / (dx * dx + dy * dy)))
    return math.hypot(px - (x1 + t * dx), py - (y1 + t * dy))


def copper_width_mm(item: pcbnew.BOARD_ITEM) -> float:
    if isinstance(item, pcbnew.PCB_VIA):
        return pcbnew.ToMM(item.GetWidth(pcbnew.F_Cu))
    return pcbnew.ToMM(item.GetWidth())


def mounting_hole_copper_items(
    tracks: list[pcbnew.BOARD_ITEM], center: tuple[float, float], radius_mm: float
) -> list[pcbnew.BOARD_ITEM]:
    """Return track/via copper from every layer that conflicts with the NPTH hole."""

    conflicts: list[pcbnew.BOARD_ITEM] = []
    for item in tracks:
        half_width = copper_width_mm(item) / 2.0
        if distance_to_segment_mm(center, item.GetStart(), item.GetEnd()) <= radius_mm + half_width:
            conflicts.append(item)
    return conflicts


def connector_pad_conflict_items(
    tracks: list[pcbnew.BOARD_ITEM], pads: list[pcbnew.PAD], clearance_mm: float = 0.25
) -> list[pcbnew.BOARD_ITEM]:
    """Return old copper that crosses a J7 pad assigned to another (or no) net."""

    conflicts: list[pcbnew.BOARD_ITEM] = []
    for item in tracks:
        # The IR receiver is immediately to the right of J7.  Its inner-layer
        # route is proven to clear the actual connector geometry and must not
        # be pruned by the deliberately conservative circular pad test.
        if item.GetNetname() in {"IR-RX", "$13N5258"}:
            continue
        item_net = item.GetNetCode()
        half_width = copper_width_mm(item) / 2.0
        for pad in pads:
            pad_net = pad.GetNetCode()
            if pad_net != 0 and pad_net == item_net:
                continue
            pad_size = pad.GetSize()
            pad_radius = max(pcbnew.ToMM(pad_size.x), pcbnew.ToMM(pad_size.y)) / 2.0
            center = (pcbnew.ToMM(pad.GetPosition().x), pcbnew.ToMM(pad.GetPosition().y))
            if distance_to_segment_mm(center, item.GetStart(), item.GetEnd()) <= pad_radius + clearance_mm + half_width:
                conflicts.append(item)
                break
    return conflicts


def reroute_ir_around_j7(board: pcbnew.BOARD, tracks: list[pcbnew.BOARD_ITEM]) -> None:
    """Jog the inner-layer IR trace around J7's upper mechanical anchor."""

    original_start = point_mm(184.7115, 110.23)
    original_end = point_mm(191.7730, 117.2915)
    jog_left = point_mm(188.0, 110.23)
    jog_right = point_mm(191.7730, 110.23)
    matches = [
        item
        for item in tracks
        if isinstance(item, pcbnew.PCB_TRACK)
        and not isinstance(item, pcbnew.PCB_VIA)
        and item.GetNetname() == "IR-RX"
        and (
            (item.GetStart() == original_start and item.GetEnd() == original_end)
            or (item.GetStart() == original_end and item.GetEnd() == original_start)
        )
    ]
    if len(matches) != 1:
        raise RuntimeError(f"expected one IR-RX segment at the J7 anchor, found {len(matches)}")

    original = matches[0]
    original.SetStart(original_start)
    original.SetEnd(jog_left)
    for start, end in ((jog_left, jog_right), (jog_right, original_end)):
        continuation = pcbnew.PCB_TRACK(board)
        continuation.SetStart(start)
        continuation.SetEnd(end)
        continuation.SetLayer(original.GetLayer())
        continuation.SetWidth(original.GetWidth())
        continuation.SetNet(original.GetNet())
        board.Add(continuation)


def add_line(
    board: pcbnew.BOARD,
    start: tuple[float, float],
    end: tuple[float, float],
    layer: int = pcbnew.Dwgs_User,
    width_mm: float = 0.15,
) -> None:
    line = pcbnew.PCB_SHAPE(board)
    line.SetShape(pcbnew.SHAPE_T_SEGMENT)
    line.SetLayer(layer)
    line.SetStart(point_mm(*start))
    line.SetEnd(point_mm(*end))
    line.SetWidth(MM(width_mm))
    board.Add(line)


def add_text(
    board: pcbnew.BOARD,
    text: str,
    x: float,
    y: float,
    layer: int = pcbnew.Cmts_User,
    size_mm: float = 0.9,
) -> None:
    note = pcbnew.PCB_TEXT(board)
    note.SetText(text)
    note.SetLayer(layer)
    note.SetPosition(point_mm(x, y))
    note.SetTextSize(point_mm(size_mm, size_mm))
    note.SetTextThickness(MM(0.14))
    board.Add(note)


def add_standoff(board: pcbnew.BOARD, x: float, y: float) -> pcbnew.FOOTPRINT:
    footprint = pcbnew.FOOTPRINT(board)
    footprint.SetReference("H2")
    footprint.SetValue("M2_STANDOFF_2230")
    footprint.SetPosition(point_mm(x, y))
    board.Add(footprint)

    pad = pcbnew.PAD(footprint)
    pad.SetNumber("")
    pad.SetAttribute(pcbnew.PAD_ATTRIB_NPTH)
    pad.SetShape(pcbnew.PAD_SHAPE_CIRCLE)
    pad.SetSize(point_mm(2.8, 2.8))
    pad.SetDrillSize(point_mm(2.8, 2.8))
    pad.SetLayerSet(pad.PTHMask())
    pad.SetPosition(point_mm(x, y))
    footprint.Add(pad)

    reference = footprint.Reference()
    reference.SetVisible(True)
    reference.SetLayer(pcbnew.F_SilkS)
    reference.SetTextSize(point_mm(0.9, 0.9))
    reference.SetTextThickness(MM(0.14))
    reference.SetPosition(point_mm(x, y - 2.5))
    footprint.Value().SetVisible(False)
    return footprint


def place_connector(board: pcbnew.BOARD) -> pcbnew.FOOTPRINT:
    connector = pcbnew.FootprintLoad(str(FOOTPRINT_LIBRARY), FOOTPRINT_NAME)
    if connector is None:
        raise RuntimeError(f"unable to load {FOOTPRINT_LIBRARY.name}:{FOOTPRINT_NAME}")
    connector.SetPath(pcbnew.KIID_PATH())
    connector.SetReference("J7")
    connector.SetValue("91302-42-067RDM")
    connector.SetPosition(point_mm(184.5, 122.0))
    connector.SetOrientationDegrees(90.0)
    board.Add(connector)

    ground = {"1", "3", "9", "15", "21", "27", "33", "39", "45", "51", "57", "71", "73", "75", "76"}
    power = {"2", "4", "12", "14", "16", "18", "70", "72", "74"}
    pad_nets = {number: "GND" for number in ground}
    pad_nets.update({number: "NVME_3V3_SW" for number in power})
    pad_nets.update(
        {
            "10": "NVME_DAS_DSS_N",
            "41": "USB2-RXN",       # PERn0: endpoint TX -> host RX
            "43": "USB2-RXP",       # PERp0: endpoint TX -> host RX
            "47": "$6N19249",       # PETn0: host TX after C219
            "49": "$6N19248",       # PETp0: host TX after C220
            "50": "PCIE_PERST_N",
            "52": "PCIE_CLKREQ_N",
            "53": "PCIE_REFCLK_N",
            "54": "PCIE_WAKE_N",
            "55": "PCIE_REFCLK_P",
        }
    )
    for pad in connector.Pads():
        net_name = pad_nets.get(pad.GetNumber())
        if net_name is None:
            pad.SetNetCode(0)
        else:
            pad.SetNet(get_or_create_net(board, net_name))

    reference = connector.Reference()
    reference.SetVisible(True)
    reference.SetLayer(pcbnew.F_SilkS)
    reference.SetTextSize(point_mm(0.9, 0.9))
    reference.SetTextThickness(MM(0.14))
    reference.SetPosition(point_mm(184.5, 109.7))
    connector.Value().SetVisible(False)
    return connector


def add_module_envelope(board: pcbnew.BOARD) -> None:
    # The connector is at the module edge and the 2230 card extends 30 mm left.
    x1, y1, x2, y2 = 154.5, 111.0, 184.5, 133.0
    add_line(board, (x1, y1), (x2, y1))
    add_line(board, (x2, y1), (x2, y2))
    add_line(board, (x2, y2), (x1, y2))
    add_line(board, (x1, y2), (x1, y1))
    add_text(board, "M.2 2230 NVME MODULE ENVELOPE", 169.5, 120.8)
    add_text(board, "J7 REFCLK / CONTROL / 3V3 / PCIE ROUTING UNFINISHED", 169.5, 123.0)


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: stage_nvme_2230.py INPUT.kicad_pcb OUTPUT.kicad_pcb")

    source = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    board = pcbnew.LoadBoard(str(source))

    for required in ("U14", "D15", "C219", "C220", "J5", "J6", "USB1", "CGQ1"):
        require_footprint(board, required)
    if board.FindFootprintByReference("J7") is not None:
        raise RuntimeError("J7 already exists; use the pre-NVMe staging board as input")
    connector = place_connector(board)

    remove_refs = GMAC0_REFS | GMAC1_REFS
    ethernet = [require_footprint(board, ref) for ref in sorted(remove_refs)]
    ethernet_pads = [pad for footprint in ethernet for pad in footprint.Pads()]
    # Snapshot collections before BOARD.Remove(); KiCad 10's SWIG collections
    # are invalidated by deletions made earlier in the same process.
    drawings = list(board.GetDrawings())
    tracks = list(board.GetTracks())
    fanout_items = direct_fanout_items(tracks, ethernet_pads)
    hole_items = mounting_hole_copper_items(tracks, (154.5, 122.0), 2.5)
    connector_items = connector_pad_conflict_items(tracks, list(connector.Pads()))
    remove_item_ids = {id(item) for item in fanout_items + hole_items + connector_items}
    for item in tracks:
        if id(item) in remove_item_ids:
            board.Remove(item)

    for footprint in ethernet:
        board.Remove(footprint)

    for drawing in drawings:
        if (
            isinstance(drawing, pcbnew.PCB_TEXT)
            and drawing.GetText() == "RJ1/RJ2 ETHERNET REMOVED - PHY CIRCUITS RETAINED"
        ):
            board.Remove(drawing)

    reroute_ir_around_j7(board, tracks)
    standoff = add_standoff(board, 154.5, 122.0)
    add_module_envelope(board)
    add_text(board, "GMAC0/1 PCB CIRCUITS REMOVED FOR NVME 2230", 169.5, 134.2)

    # Guard the requested edge connectors and neighboring IR receiver.
    for retained in ("J5", "J6", "USB1", "CGQ1"):
        require_footprint(board, retained)
    if connector.GetOrientationDegrees() != 90.0:
        raise RuntimeError("J7 orientation changed unexpectedly")
    if standoff.GetPosition() != point_mm(154.5, 122.0):
        raise RuntimeError("M.2 2230 standoff moved unexpectedly")

    pcbnew.ZONE_FILLER(board).Fill(board.Zones())
    pcbnew.SaveBoard(str(destination), board)
    print(f"removed {len(ethernet)} GMAC footprints and {len(fanout_items)} direct fanout items")
    print(f"cleared {len(hole_items)} track/via items around the 2230 mounting hole")
    print(f"cleared {len(connector_items)} pre-existing copper items from J7 pads")
    print("staged J7 at 184.500, 122.000 mm / 90 deg and H2 at 154.500, 122.000 mm")


if __name__ == "__main__":
    main()
