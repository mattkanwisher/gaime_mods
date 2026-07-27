#!/usr/bin/env python3
"""Create the Rev-P1 same-edge connector placement from the imported board.

This is intentionally a placement/electrical-staging transformation, not a finished
router.  It preserves HDMI USB1, removes DC1/USB2/USB3, and places two duplicates of
the imported TYPEC-304-BCP16 footprint in the old barrel and dual-USB corridors.
New PD, CC, and switched-VBUS nets remain unrouted until the schematic is implemented.

Run with KiCad's bundled Python so the pcbnew module is available:

    .../Python.framework/Versions/3.9/bin/python3 \
        scripts/stage_same_edge_connectors.py INPUT.kicad_pcb OUTPUT.kicad_pcb
"""

from __future__ import annotations

import sys
from pathlib import Path

import pcbnew


MM = pcbnew.FromMM


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


def point_in_box(point: pcbnew.VECTOR2I, box: tuple[float, float, float, float]) -> bool:
    x = pcbnew.ToMM(point.x)
    y = pcbnew.ToMM(point.y)
    x1, y1, x2, y2 = box
    return x1 <= x <= x2 and y1 <= y <= y2


def mirrored_reference_edge_y(
    board: pcbnew.BOARD, top_edge_template: pcbnew.FOOTPRINT
) -> float:
    """Mirror the original top-edge USB-C insertion depth to the bottom edge."""

    edge_box = board.GetBoardEdgesBoundingBox()
    top_edge = pcbnew.ToMM(edge_box.GetTop())
    bottom_edge = pcbnew.ToMM(edge_box.GetBottom())
    template_y = pcbnew.ToMM(top_edge_template.GetY())
    return bottom_edge - (template_y - top_edge)


def clear_connector_fanout(
    board: pcbnew.BOARD, boxes: list[tuple[float, float, float, float]]
) -> int:
    """Remove track/via items touching the vacated connector courtyards.

    Only the first local fanout items are removed.  Upstream routing remains so it can
    be reconnected to the new footprints without disturbing the core escape.
    """

    removed = 0
    for item in list(board.GetTracks()):
        endpoints = (item.GetStart(), item.GetEnd())
        if any(point_in_box(point, box) for box in boxes for point in endpoints):
            board.Remove(item)
            removed += 1
    return removed


def duplicate_typec(
    board: pcbnew.BOARD,
    template: pcbnew.FOOTPRINT,
    reference: str,
    x: float,
    y: float,
    pad_nets: dict[str, str],
) -> pcbnew.FOOTPRINT:
    clone = pcbnew.Cast_to_FOOTPRINT(template.Duplicate(False))
    clone.SetPath(pcbnew.KIID_PATH())
    clone.SetReference(reference)
    clone.SetValue("TYPEC-304-BCP16")
    clone.SetPosition(point_mm(x, y))
    clone.SetOrientationDegrees(0)
    board.Add(clone)

    for pad in clone.Pads():
        net_name = pad_nets.get(pad.GetNumber())
        if net_name is None:
            pad.SetNetCode(0)
        else:
            pad.SetNet(get_or_create_net(board, net_name))

    reference_text = clone.Reference()
    reference_text.SetVisible(True)
    reference_text.SetLayer(pcbnew.F_SilkS)
    reference_text.SetTextSize(point_mm(1.0, 1.0))
    reference_text.SetTextThickness(MM(0.15))
    reference_text.SetPosition(point_mm(x, y - 5.0))
    return clone


def add_board_note(board: pcbnew.BOARD, text: str, x: float, y: float) -> None:
    note = pcbnew.PCB_TEXT(board)
    note.SetText(text)
    note.SetLayer(pcbnew.Cmts_User)
    note.SetPosition(point_mm(x, y))
    note.SetTextSize(point_mm(0.9, 0.9))
    note.SetTextThickness(MM(0.14))
    board.Add(note)


def relabel_connector_silkscreen(board: pcbnew.BOARD) -> None:
    replacements = {"12VDC": "POWER", "USB": "HOST"}
    found: set[str] = set()
    for drawing in board.GetDrawings():
        if not isinstance(drawing, pcbnew.PCB_TEXT):
            continue
        old_text = drawing.GetText()
        if old_text in replacements:
            drawing.SetText(replacements[old_text])
            found.add(old_text)
    missing = replacements.keys() - found
    if missing:
        raise RuntimeError(f"connector silkscreen labels not found: {sorted(missing)}")


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: stage_same_edge_connectors.py INPUT.kicad_pcb OUTPUT.kicad_pcb")

    source = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    board = pcbnew.LoadBoard(str(source))

    hdmi = require_footprint(board, "USB1")
    hdmi_position_xy = (hdmi.GetX(), hdmi.GetY())
    hdmi_orientation = hdmi.GetOrientationDegrees()
    typec_template = require_footprint(board, "USB3")
    typec_edge_y = mirrored_reference_edge_y(board, typec_template)

    old_footprints = [
        require_footprint(board, "DC1"),
        require_footprint(board, "USB2"),
        typec_template,
    ]
    # Touch board-level text before deletions; KiCad 10's SWIG iterator can be
    # invalidated by later BOARD.Remove() calls in the same process.
    relabel_connector_silkscreen(board)

    ground_pads = {"12", "13", "14", "15", "A1B12", "B1A12"}
    power_nets = {pad: "GND" for pad in ground_pads}
    power_nets.update(
        {
            "A4B9": "PD_VBUS_RAW",
            "B4A9": "PD_VBUS_RAW",
            "A5": "PD_CC1",
            "B5": "PD_CC2",
        }
    )
    host_nets = {pad: "GND" for pad in ground_pads}
    host_nets.update(
        {
            "A4B9": "USB1_VBUS_SW",
            "B4A9": "USB1_VBUS_SW",
            "A5": "USB1_CC1",
            "B5": "USB1_CC2",
            "A6": "USB1-DP",
            "B6": "USB1-DP",
            "A7": "USB1-DM",
            "B7": "USB1-DM",
        }
    )

    duplicate_typec(board, typec_template, "J5", 109.6545, typec_edge_y, power_nets)
    duplicate_typec(board, typec_template, "J6", 126.1140, typec_edge_y, host_nets)

    removed_tracks = clear_connector_fanout(
        board,
        [
            (103.2, 129.5, 116.2, 141.2),  # DC1 local copper
            (117.0, 129.0, 135.0, 139.2),  # USB2 local copper
            (177.0, 66.5, 188.2, 76.2),  # old opposite-edge USB3 copper
        ],
    )

    for footprint in old_footprints:
        board.Remove(footprint)

    add_board_note(board, "J5 USB-C PD POWER - PD/UVLO UNROUTED", 109.6545, 126.9)
    add_board_note(board, "J6 USB-C HOST - CC/VBUS/USB2 UNROUTED", 126.1140, 126.9)

    if ((hdmi.GetX(), hdmi.GetY()) != hdmi_position_xy
            or hdmi.GetOrientationDegrees() != hdmi_orientation):
        raise RuntimeError("HDMI moved unexpectedly")

    pcbnew.ZONE_FILLER(board).Fill(board.Zones())
    pcbnew.SaveBoard(str(destination), board)
    print(f"staged J5/J6; removed {removed_tracks} local track/via items")
    print(f"aligned J5/J6 to reference USB-C edge datum at y={typec_edge_y:.4f} mm")
    print(f"preserved HDMI at {pcbnew.ToMM(hdmi_position_xy[0]):.3f}, "
          f"{pcbnew.ToMM(hdmi_position_xy[1]):.3f} mm / {hdmi_orientation:.1f} deg")


if __name__ == "__main__":
    main()
