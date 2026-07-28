#!/usr/bin/env python3
"""Place and route the J5 USB-C PD front end.

This pass replaces the staged connector clone with the exact C720629 footprint,
places the STUSB4500 and TPS259470L in the narrow original power corridor, and
routes the connector-critical CC, raw VBUS, protected VBUS, and ground paths.
The small control/passive network remains in the schematic for the next routing pass;
placing it here would overlap inherited FPC1 copper on the back side.

Run with KiCad's bundled Python:

    .../Python.framework/Versions/3.9/bin/python3 \
        scripts/route_usbc_pd_power.py INPUT.kicad_pcb OUTPUT.kicad_pcb
"""

from __future__ import annotations

import sys
from pathlib import Path

import pcbnew


MM = pcbnew.FromMM
PROJECT_DIR = Path(__file__).resolve().parent.parent
POWER_LIBRARY = PROJECT_DIR / "libs" / "power.pretty"
KICAD_FOOTPRINTS = Path(
    "/Applications/KiCad/KiCad.app/Contents/SharedSupport/footprints"
)
FOOTPRINT_READER = pcbnew.PCB_IO_KICAD_SEXPR()

SIGNAL_WIDTH = 0.200
PAD_NECK_WIDTH = 0.250
VBUS_WIDTH = 1.200
VBUS_NECK_WIDTH = 0.450
POWER_VIA_SIZE = 0.600
POWER_VIA_DRILL = 0.300
SIGNAL_VIA_SIZE = 0.450
SIGNAL_VIA_DRILL = 0.200


def point(x: float, y: float) -> pcbnew.VECTOR2I:
    return pcbnew.VECTOR2I_MM(x, y)


def xy(item: pcbnew.BOARD_ITEM) -> tuple[float, float]:
    p = item.GetPosition()
    return pcbnew.ToMM(p.x), pcbnew.ToMM(p.y)


def get_or_create_net(board: pcbnew.BOARD, name: str) -> pcbnew.NETINFO_ITEM:
    net = board.FindNet(name)
    if net is None:
        net = pcbnew.NETINFO_ITEM(board, name)
        board.Add(net)
    return net


def require_footprint(board: pcbnew.BOARD, reference: str) -> pcbnew.FOOTPRINT:
    footprint = board.FindFootprintByReference(reference)
    if footprint is None:
        raise RuntimeError(f"required footprint {reference} was not found")
    return footprint


def require_pad(footprint: pcbnew.FOOTPRINT, number: str) -> pcbnew.PAD:
    pad = footprint.FindPadByNumber(str(number))
    if pad is None:
        raise RuntimeError(f"{footprint.GetReference()} pad {number} was not found")
    return pad


def load_footprint(library: Path, name: str) -> pcbnew.FOOTPRINT:
    # KiCad 10's convenience FootprintLoad() selects the wrong plug-in for the
    # imported EasyEDA-style local files on macOS.  Select the s-expression
    # reader explicitly; it accepts both the legacy ``module`` header and current
    # KiCad library footprints.
    footprint = FOOTPRINT_READER.FootprintLoad(str(library), name, True)
    if footprint is None:
        raise RuntimeError(f"unable to load {library.name}:{name}")
    return footprint


def assign_pad_nets(
    board: pcbnew.BOARD, footprint: pcbnew.FOOTPRINT, pad_nets: dict[str, str]
) -> None:
    for pad in footprint.Pads():
        net_name = pad_nets.get(pad.GetNumber())
        if net_name is None:
            pad.SetNetCode(0)
        else:
            pad.SetNet(get_or_create_net(board, net_name))


def place(
    board: pcbnew.BOARD,
    library: Path,
    name: str,
    reference: str,
    value: str,
    location: tuple[float, float],
    pad_nets: dict[str, str],
    orientation: float = 0.0,
    back: bool = False,
) -> pcbnew.FOOTPRINT:
    footprint = load_footprint(library, name)
    footprint.SetPath(pcbnew.KIID_PATH())
    footprint.SetReference(reference)
    footprint.SetValue(value)
    footprint.SetPosition(point(*location))
    footprint.SetOrientationDegrees(orientation)
    board.Add(footprint)
    if back:
        footprint.Flip(footprint.GetPosition(), False)
    assign_pad_nets(board, footprint, pad_nets)
    # This corridor is too dense for useful reference text on silkscreen.  The
    # references remain on the fabrication layers and in the board metadata.
    footprint.Reference().SetVisible(False)
    footprint.Reference().SetTextSize(point(0.65, 0.65))
    footprint.Reference().SetTextThickness(MM(0.10))
    footprint.Value().SetVisible(False)
    return footprint


def add_track(
    board: pcbnew.BOARD,
    net: pcbnew.NETINFO_ITEM,
    start: tuple[float, float],
    end: tuple[float, float],
    width: float = SIGNAL_WIDTH,
    layer: int = pcbnew.F_Cu,
) -> pcbnew.PCB_TRACK:
    track = pcbnew.PCB_TRACK(board)
    track.SetStart(point(*start))
    track.SetEnd(point(*end))
    track.SetWidth(MM(width))
    track.SetLayer(layer)
    track.SetNet(net)
    board.Add(track)
    return track


def add_polyline(
    board: pcbnew.BOARD,
    net: pcbnew.NETINFO_ITEM,
    points: list[tuple[float, float]],
    width: float = SIGNAL_WIDTH,
    layer: int = pcbnew.F_Cu,
) -> list[pcbnew.PCB_TRACK]:
    return [
        add_track(board, net, start, end, width, layer)
        for start, end in zip(points, points[1:])
        if start != end
    ]


def add_via(
    board: pcbnew.BOARD,
    net: pcbnew.NETINFO_ITEM,
    location: tuple[float, float],
    power: bool = False,
) -> pcbnew.PCB_VIA:
    via = pcbnew.PCB_VIA(board)
    via.SetPosition(point(*location))
    via.SetWidth(MM(POWER_VIA_SIZE if power else SIGNAL_VIA_SIZE))
    via.SetDrill(MM(POWER_VIA_DRILL if power else SIGNAL_VIA_DRILL))
    via.SetLayerPair(pcbnew.F_Cu, pcbnew.B_Cu)
    via.SetNet(net)
    board.Add(via)
    return via


def pad_xy(footprint: pcbnew.FOOTPRINT, number: str) -> tuple[float, float]:
    return xy(require_pad(footprint, number))


def route_pad_to_pad(
    board: pcbnew.BOARD,
    first: tuple[pcbnew.FOOTPRINT, str],
    second: tuple[pcbnew.FOOTPRINT, str],
    width: float = SIGNAL_WIDTH,
    layer: int = pcbnew.F_Cu,
    middle: list[tuple[float, float]] | None = None,
) -> None:
    first_pad = require_pad(*first)
    second_pad = require_pad(*second)
    if first_pad.GetNetCode() != second_pad.GetNetCode():
        raise RuntimeError(
            f"cannot route unlike nets: {first[0].GetReference()}:{first[1]} to "
            f"{second[0].GetReference()}:{second[1]}"
        )
    add_polyline(
        board,
        first_pad.GetNet(),
        [xy(first_pad), *(middle or []), xy(second_pad)],
        width,
        layer,
    )


def ground_stitch(
    board: pcbnew.BOARD,
    footprint: pcbnew.FOOTPRINT,
    pad_number: str,
    via_location: tuple[float, float],
    layer: int,
) -> None:
    pad = require_pad(footprint, pad_number)
    net = get_or_create_net(board, "GND")
    add_track(board, net, xy(pad), via_location, SIGNAL_WIDTH, layer)
    add_via(board, net, via_location)


def replace_j5(board: pcbnew.BOARD) -> pcbnew.FOOTPRINT:
    old = require_footprint(board, "J5")
    position = xy(old)
    orientation = old.GetOrientationDegrees()
    board.Remove(old)
    ground = {"A1B12", "B1A12", "13", "14", "15", "16"}
    pad_nets = {number: "GND" for number in ground}
    pad_nets.update(
        {
            "A4B9": "PD_VBUS_RAW",
            "B4A9": "PD_VBUS_RAW",
            "A5": "PD_CC1",
            "B5": "PD_CC2",
        }
    )
    return place(
        board,
        POWER_LIBRARY,
        "USB-C-SMD_TYPEC-304-BCP16",
        "J5",
        "TYPEC-304-BCP16",
        position,
        pad_nets,
        orientation,
    )


def place_front_end(board: pcbnew.BOARD) -> dict[str, pcbnew.FOOTPRINT]:
    if board.FindFootprintByReference("U1001") is not None:
        raise RuntimeError("J5 PD front end is already present; refusing to duplicate it")

    footprints: dict[str, pcbnew.FOOTPRINT] = {}
    footprints["J5"] = replace_j5(board)
    footprints["U1001"] = place(
        board,
        POWER_LIBRARY,
        "QFN-24_L4.0-W4.0-P0.50-BL-EP2.8",
        "U1001",
        "STUSB4500QTR",
        (109.6545, 133.5000),
        {
            "1": "PD_CC1", "2": "PD_CC1", "4": "PD_CC2", "5": "PD_CC2",
            "6": "PD_RESET", "7": "PD_SCL", "8": "PD_SDA", "9": "VBUS_DISCH",
            "10": "GND", "12": "GND", "13": "GND", "18": "VBUS_SENSE",
            "19": "PD_ALERT_N", "20": "PDO2_OK_N", "21": "VREG_1V2",
            "22": "GND", "23": "VREG_2V7", "24": "PD_VBUS_RAW", "25": "GND",
        },
    )
    footprints["U1002"] = place(
        board,
        POWER_LIBRARY,
        "VQFN-10_L2.0-W2.0-P0.45-TL",
        "U1002",
        "TPS259470LRPWR",
        (116.5000, 133.5000),
        {
            "1": "EFUSE_EN", "2": "EFUSE_OVLO", "5": "PD_VBUS_RAW",
            "6": "PD_9V_PROTECTED", "7": "EFUSE_DVDT", "8": "GND",
            "9": "EFUSE_ILM", "10": "EFUSE_ITIMER",
        },
    )
    diode_library = KICAD_FOOTPRINTS / "Diode_SMD.pretty"
    footprints["D1001"] = place(
        board, diode_library, "D_SOD-323", "D1001", "PESD24VL1BA",
        (105.5000, 135.0000), {"1": "PD_CC1", "2": "GND"}, 0.0, True,
    )
    footprints["D1002"] = place(
        board, diode_library, "D_SOD-323", "D1002", "PESD24VL1BA",
        (113.4000, 135.0000), {"1": "PD_CC2", "2": "GND"}, 0.0, True,
    )

    # Only the connector-critical capacitors are placed in this pass.  The
    # controller/eFuse control network remains in the schematic until a clean
    # second-side fanout is routed around the inherited FPC1 copper.
    capacitor_library = KICAD_FOOTPRINTS / "Capacitor_SMD.pretty"
    back_parts = {
        "C1001": ("C_1206_3216Metric", "4.7uF 25V", (105.5, 130.7), 0.0, {"1": "PD_VBUS_RAW", "2": "GND"}),
        "C1002": ("C_0603_1608Metric", "100nF 25V", (102.0, 136.0), 90.0, {"1": "PD_VBUS_RAW", "2": "GND"}),
        "C1005": ("C_0603_1608Metric", "1uF 25V", (118.5, 136.0), 90.0, {"1": "PD_VBUS_RAW", "2": "GND"}),
        "C1008": ("C_1206_3216Metric", "10uF 16V", (115.5, 128.7), 90.0, {"1": "PD_9V_PROTECTED", "2": "GND"}),
        "C1009": ("C_0603_1608Metric", "100nF 16V", (118.2, 129.0), 90.0, {"1": "PD_9V_PROTECTED", "2": "GND"}),
    }
    for reference, (name, value, location, orientation, nets) in back_parts.items():
        footprints[reference] = place(
            board, capacitor_library, name, reference, value, location, nets,
            orientation, True,
        )
    return footprints


def route_connector_front_end(
    board: pcbnew.BOARD, fp: dict[str, pcbnew.FOOTPRINT]
) -> None:
    j5, u1, u2 = fp["J5"], fp["U1001"], fp["U1002"]
    raw = get_or_create_net(board, "PD_VBUS_RAW")
    protected = get_or_create_net(board, "PD_9V_PROTECTED")
    ground = get_or_create_net(board, "GND")

    # CC pins land almost directly on the STUSB4500 dead-battery inputs.  The
    # B5 jog keeps the trace clear of adjacent U1001 pin 6.
    route_pad_to_pad(board, (j5, "A5"), (u1, "1"), SIGNAL_WIDTH)
    route_pad_to_pad(board, (u1, "1"), (u1, "2"), SIGNAL_WIDTH)
    route_pad_to_pad(
        board, (j5, "B5"), (u1, "5"), SIGNAL_WIDTH,
        middle=[(111.4045, 136.25), (110.4045, 136.25)],
    )
    route_pad_to_pad(board, (u1, "5"), (u1, "4"), SIGNAL_WIDTH)

    # Put the TVS parts on B.Cu.  This avoids crossing VBUS at U1001 pin 24 and
    # keeps both protection branches within about 3 mm of the receptacle pins.
    cc1 = get_or_create_net(board, "PD_CC1")
    cc2 = get_or_create_net(board, "PD_CC2")
    cc1_via, cc2_via = (108.4045, 136.15), (111.4045, 136.15)
    add_via(board, cc1, cc1_via)
    add_via(board, cc2, cc2_via)
    d1001_signal = pad_xy(fp["D1001"], "1")
    d1002_signal = pad_xy(fp["D1002"], "1")
    add_polyline(
        board, cc1,
        [cc1_via, (d1001_signal[0], 136.30), d1001_signal],
        SIGNAL_WIDTH, pcbnew.B_Cu,
    )
    add_polyline(
        board, cc2,
        [cc2_via, (d1002_signal[0], 136.30), d1002_signal],
        SIGNAL_WIDTH, pcbnew.B_Cu,
    )
    ground_stitch(board, fp["D1001"], "2", (103.60, 135.00), pcbnew.B_Cu)
    ground_stitch(board, fp["D1002"], "2", (113.20, 133.50), pcbnew.B_Cu)

    # Tie the receptacle ground fingers into its grounded shell anchors.
    route_pad_to_pad(board, (j5, "A1B12"), (j5, "13"), PAD_NECK_WIDTH)
    route_pad_to_pad(board, (j5, "B1A12"), (j5, "14"), PAD_NECK_WIDTH)

    # Both receptacle VBUS fingers feed a wide In5.Cu trunk.  Narrow segments at
    # U1001/U1002 respect the 0.5/0.45 mm pitches before the route widens.
    add_polyline(
        board, raw,
        [pad_xy(j5, "A4B9"), (107.2045, 135.60), (107.6545, 135.25)],
        VBUS_NECK_WIDTH, pcbnew.F_Cu,
    )
    add_track(board, raw, (107.6545, 135.25), pad_xy(u1, "24"), SIGNAL_WIDTH)

    left_raw_vias = [(106.00, 132.40), (106.70, 132.40)]
    right_raw_vias = [(116.00, 135.60), (116.70, 135.60)]
    for location in left_raw_vias + right_raw_vias:
        add_via(board, raw, location, power=True)
    add_polyline(
        board, raw,
        [left_raw_vias[0], left_raw_vias[1], (106.70, 131.00),
         (112.00, 131.00), (112.00, 134.80), right_raw_vias[0], right_raw_vias[1]],
        VBUS_WIDTH, pcbnew.In4_Cu,
    )
    add_polyline(
        board, raw,
        [pad_xy(u1, "24"), (106.80, 134.75), (106.70, 132.40), left_raw_vias[0]],
        SIGNAL_WIDTH, pcbnew.F_Cu,
    )
    add_polyline(
        board, raw,
        [pad_xy(j5, "B4A9"), (112.1045, 135.60), right_raw_vias[0]],
        VBUS_NECK_WIDTH, pcbnew.F_Cu,
    )
    add_polyline(
        board, raw,
        [pad_xy(j5, "B4A9"), (112.1045, 135.60), (116.2700, 135.60), (116.2700, 135.15)],
        VBUS_NECK_WIDTH, pcbnew.F_Cu,
    )
    add_track(board, raw, (116.2700, 135.15), pad_xy(u2, "5"), SIGNAL_WIDTH)

    output_vias = [(116.35, 131.40), (117.05, 131.40)]
    handoff_vias = [(113.15, 129.25), (113.85, 129.25)]
    for location in output_vias + handoff_vias:
        add_via(board, protected, location, power=True)
    add_polyline(
        board, protected,
        [pad_xy(u2, "6"), (116.76, 131.85), output_vias[0], output_vias[1]],
        SIGNAL_WIDTH, pcbnew.F_Cu,
    )
    add_polyline(
        board, protected,
        [output_vias[0], (115.40, 130.30), (113.85, 129.25), handoff_vias[0]],
        VBUS_WIDTH, pcbnew.In2_Cu,
    )

    # The old barrel-input node is now the eFuse output handoff.
    d2 = require_footprint(board, "D2")
    q1 = require_footprint(board, "Q1")
    require_pad(d2, "2").SetNet(protected)
    require_pad(q1, "3").SetNet(protected)
    add_polyline(
        board, protected,
        [handoff_vias[0], pad_xy(d2, "2")], VBUS_NECK_WIDTH, pcbnew.F_Cu,
    )
    route_pad_to_pad(
        board, (d2, "2"), (q1, "3"), 0.800, pcbnew.F_Cu,
        middle=[(114.25, 127.00)],
    )

    # Give every second-side capacitor its own short via pair.  The raw and
    # protected trunks stay on In5.Cu, leaving B.Cu free for the control pass.
    for reference, net, bus_anchor in (
        ("C1001", raw, left_raw_vias[0]),
        ("C1002", raw, left_raw_vias[0]),
        ("C1005", raw, right_raw_vias[1]),
        ("C1008", protected, output_vias[0]),
        ("C1009", protected, output_vias[1]),
    ):
        capacitor = fp[reference]
        center_x, center_y = xy(capacitor)
        power_pad = require_pad(capacitor, "1")
        px, py = xy(power_pad)
        dx, dy = px - center_x, py - center_y
        length = max((dx * dx + dy * dy) ** 0.5, 0.001)
        if reference == "C1001":
            power_via = (103.40, 132.30)
        else:
            power_via = (px + 0.70 * dx / length, py + 0.70 * dy / length)
        if reference == "C1001":
            add_polyline(
                board, net, [(px, py), (px, 132.30), power_via],
                PAD_NECK_WIDTH, pcbnew.B_Cu,
            )
        else:
            add_track(board, net, (px, py), power_via, PAD_NECK_WIDTH, pcbnew.B_Cu)
        add_via(board, net, power_via, power=True)
        power_layer = pcbnew.In4_Cu if net.GetNetname() == "PD_VBUS_RAW" else pcbnew.In5_Cu
        if reference == "C1002":
            add_polyline(
                board, net, [power_via, (102.00, 133.80), bus_anchor],
                VBUS_WIDTH, power_layer,
            )
        else:
            add_track(board, net, power_via, bus_anchor, VBUS_WIDTH, power_layer)

        ground_pad = require_pad(capacitor, "2")
        gx, gy = xy(ground_pad)
        dx, dy = gx - center_x, gy - center_y
        length = max((dx * dx + dy * dy) ** 0.5, 0.001)
        if reference == "C1001":
            ground_via = (103.35, 130.70)
        elif reference == "C1002":
            ground_via = (100.90, gy)
        elif reference == "C1008":
            ground_via = (116.50, 126.40)
        elif reference == "C1009":
            ground_via = (119.00, 128.30)
        else:
            ground_via = (gx + 0.70 * dx / length, gy + 0.70 * dy / length)
        add_track(board, ground, (gx, gy), ground_via, PAD_NECK_WIDTH, pcbnew.B_Cu)
        add_via(board, ground, ground_via)

    # Ground the IC thermal pad and the local power capacitors with short stitches.
    for location in ((109.10, 132.95), (110.20, 132.95), (109.10, 134.05), (110.20, 134.05)):
        add_via(board, ground, location)
    for pin in ("10", "12", "13", "22"):
        add_track(board, ground, pad_xy(u1, pin), (109.6545, 133.5000), SIGNAL_WIDTH)
    ground_stitch(board, u2, "8", (118.40, 133.73), pcbnew.F_Cu)


def add_note(board: pcbnew.BOARD) -> None:
    for drawing in board.GetDrawings():
        if isinstance(drawing, pcbnew.PCB_TEXT) and drawing.GetText().startswith(
            "J5 USB-C PD POWER"
        ):
            drawing.SetText("J5 USB-C PD: CC + 9V POWER PATH ROUTED; CTRL FANOUT NEXT")
            return
    note = pcbnew.PCB_TEXT(board)
    note.SetText("J5 USB-C PD: CC + 9V POWER PATH ROUTED; CTRL FANOUT NEXT")
    note.SetLayer(pcbnew.Cmts_User)
    note.SetPosition(point(109.65, 126.9))
    note.SetTextSize(point(0.8, 0.8))
    note.SetTextThickness(MM(0.12))
    board.Add(note)


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: route_usbc_pd_power.py INPUT.kicad_pcb OUTPUT.kicad_pcb")
    source = Path(sys.argv[1]).resolve()
    destination = Path(sys.argv[2]).resolve()
    board = pcbnew.LoadBoard(str(source))
    footprints = place_front_end(board)
    route_connector_front_end(board, footprints)
    add_note(board)
    board.BuildConnectivity()
    pcbnew.ZONE_FILLER(board).Fill(board.Zones())
    pcbnew.SaveBoard(str(destination), board)
    print("placed the 10 connector-critical J5 PD/eFuse parts and exact C720629 footprint")
    print("routed CC1/CC2 protection, raw VBUS, protected VBUS, and the existing D2/Q1 handoff")
    print("left the control/passive fanout in the schematic for the next routing pass")


if __name__ == "__main__":
    main()
