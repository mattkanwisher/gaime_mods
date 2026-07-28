#!/usr/bin/env python3
"""Generate the J6 USB 2.0 Type-C host sheet and add it to the root hierarchy.

The Avaota source already contains the host-power switch U17 (SY6280AAC), its
approximately 1 A current-limit network, VBUS sensing, and D13 USB2 ESD array. This
sheet adds the replacement receptacle, default-current Type-C Rp resistors, and a
zero-ohm net-tie resistor to the preserved switched output.

Run from the project directory with:

    uv run --with kicad-sch-api python scripts/add_usbc_host.py
"""

from __future__ import annotations

from pathlib import Path

import kicad_sch_api as ksa


PROJECT_DIR = Path(__file__).resolve().parent.parent
ROOT_PATH = PROJECT_DIR / "android-box-rebuild.kicad_sch"
SOURCE_SHEET = PROJECT_DIR / "6_PERF1.kicad_sch"
CHILD_PATH = PROJECT_DIR / "USB_C_HOST.kicad_sch"
KICAD_SYMBOLS = Path("/Applications/KiCad/KiCad.app/Contents/SharedSupport/symbols")

PROJECT_NAME = "avaota-a1-v14"
ROOT_SCHEMATIC_UUID = "550d58f0-4e41-4062-aec4-b3409407efa1"
HOST_SHEET_UUID = "4bb8fddd-ad20-4516-9ea1-5a73cdfa092b"
R_0603 = "Resistor_SMD:R_0603_1608Metric"


def point_tuple(point: object) -> tuple[float, float]:
    return (point.x, point.y)


def add_library_paths() -> None:
    cache = ksa.library.get_symbol_cache()
    cache.add_library_path(str(PROJECT_DIR / "libs" / "power.kicad_sym"))
    for library in ("Device", "Connector"):
        cache.add_library_path(str(KICAD_SYMBOLS / f"{library}.kicad_sym"))


def label_pin_global(
    schematic: ksa.Schematic,
    reference: str,
    pin_number: str,
    net_name: str,
    *,
    stub: float = 2.54,
    shape: str = "bidirectional",
) -> None:
    pin = schematic.get_component_pin_position(reference, pin_number)
    if pin is None:
        raise RuntimeError(f"No pin {pin_number} found on {reference}")
    end = (pin.x + stub, pin.y)
    schematic.add_wire(point_tuple(pin), end)
    # kicad-sch-api 0.5.5 records global labels in memory but does not serialize
    # them. Emit local labels here and promote them after save below.
    schematic.add_label(net_name, position=end, size=1.0)


def no_connect(schematic: ksa.Schematic, reference: str, pin_number: str) -> None:
    pin = schematic.get_component_pin_position(reference, pin_number)
    if pin is None:
        raise RuntimeError(f"No pin {pin_number} found on {reference}")
    schematic.no_connects.add(point_tuple(pin))


def set_instance_property_visibility(
    text: str, reference: str, property_name: str, *, hidden: bool
) -> str:
    """Work around property-effect indexing bugs in kicad-sch-api 0.5.5."""

    ref_marker = f'(property "Reference" "{reference}"'
    ref_at = text.index(ref_marker)
    symbol_start = text.rfind("\n\t(symbol\n", 0, ref_at)
    symbol_end = text.find("\n\t(symbol\n", ref_at)
    if symbol_end < 0:
        symbol_end = len(text)
    block = text[symbol_start:symbol_end]
    prop_marker = f'(property "{property_name}"'
    prop_at = block.index(prop_marker)
    next_prop = block.find("\n\t\t(property ", prop_at + 1)
    next_pin = block.find("\n\t\t(pin ", prop_at + 1)
    candidates = [index for index in (next_prop, next_pin) if index >= 0]
    prop_end = min(candidates) if candidates else len(block)
    prop = block[prop_at:prop_end]
    hide_line = "\n\t\t\t\t(hide yes)"
    if hidden and hide_line not in prop:
        prop = prop.replace("\n\t\t\t(effects", "\n\t\t\t(effects" + hide_line, 1)
    if not hidden:
        prop = prop.replace(hide_line, "")
    block = block[:prop_at] + prop + block[prop_end:]
    return text[:symbol_start] + block + text[symbol_end:]


def add_resistor(
    schematic: ksa.Schematic,
    reference: str,
    value: str,
    position: tuple[float, float],
    net_1: str,
    net_2: str,
) -> None:
    schematic.components.add(
        lib_id="Device:R",
        reference=reference,
        value=value,
        position=position,
        footprint=R_0603,
    )
    label_pin_global(schematic, reference, "1", net_1, stub=-2.54)
    label_pin_global(schematic, reference, "2", net_2)


def create_host_sheet() -> None:
    schematic = ksa.create_schematic(PROJECT_NAME)
    schematic.set_hierarchy_context(ROOT_SCHEMATIC_UUID, HOST_SHEET_UUID)
    schematic.set_paper_size("A4")
    schematic.set_title_block(
        title="J6 USB 2.0 Type-C host port",
        rev="Rev-P1",
        company="gun_pcb / Avaota A1 derivative",
        comments={
            1: "Reuses U17 SY6280AAC switched VBUS and D13 RClamp0524 USB2 ESD",
            2: "56 kOhm Rp advertises USB default current; U17 limit remains about 1 A",
        },
    )

    schematic.components.add(
        lib_id="power:TYPEC-304-BCP16",
        reference="J6",
        value="TYPEC-304-BCP16",
        position=(74.0, 78.0),
        footprint="power:USB-C-SMD_TYPEC-304-BCP16",
        Datasheet="https://www.lcsc.com/product-detail/C720629.html",
        Manufacturer="XUNPU",
        **{"Manufacturer Part": "TYPEC-304-BCP16", "Supplier Part": "C720629"},
    )

    for pin in ("A4B9", "B4A9"):
        label_pin_global(schematic, "J6", pin, "USB1_VBUS_SW", stub=-2.54)
    label_pin_global(schematic, "J6", "A5", "USB1_CC1", stub=-2.54)
    label_pin_global(schematic, "J6", "B5", "USB1_CC2", stub=-2.54)
    for pin in ("A6", "B6"):
        label_pin_global(schematic, "J6", pin, "USB1-DP", stub=-2.54)
    for pin in ("A7", "B7"):
        label_pin_global(schematic, "J6", pin, "USB1-DM", stub=-2.54)
    for pin in ("A1B12", "B1A12", "13", "14", "15", "16"):
        label_pin_global(schematic, "J6", pin, "GND")
    for pin in ("A8", "B8"):
        no_connect(schematic, "J6", pin)

    add_resistor(schematic, "R1101", "56k 1%", (128.0, 66.0), "VBUS", "USB1_CC1")
    add_resistor(schematic, "R1102", "56k 1%", (128.0, 78.0), "VBUS", "USB1_CC2")
    add_resistor(schematic, "R1103", "0R", (128.0, 96.0), "VBUS-USB", "USB1_VBUS_SW")

    schematic.add_text(
        "U17 / R117 / R118 / R120 / C280-C282 remain on 6_PERF1 and are relocated beside J6 on the PCB.",
        (148.5, 116.0),
        size=1.1,
    )
    schematic.add_text(
        "D13 remains on 6_PERF1; route J6 D+/D- through D13 to the preserved USB1 host pair.",
        (148.5, 123.0),
        size=1.1,
    )
    schematic.add_text(
        "USB-C source only: no PD controller and no 1.5 A / 3 A Rp advertisement.",
        (148.5, 130.0),
        size=1.1,
        bold=True,
    )

    for component in schematic.components:
        component.remove_property("hierarchy_path")
    schematic.save_as(str(CHILD_PATH))

    text = CHILD_PATH.read_text(encoding="utf-8")
    text = text.replace("\n\t(label ", "\n\t(global_label ")
    text = text.replace(
        "\n\t(global_label ",
        "\n\t(global_label ",
    )
    # Every generated label in this dedicated sheet is an inter-sheet net. Insert
    # the required global-label electrical shape before its position.
    blocks = text.split("\n\t(global_label ")
    text = blocks[0] + "".join(
        "\n\t(global_label " + block.replace("\n\t\t(at ", "\n\t\t(shape bidirectional)\n\t\t(at ", 1)
        for block in blocks[1:]
    )
    for reference in ("J6", "R1101", "R1102", "R1103"):
        text = set_instance_property_visibility(text, reference, "Reference", hidden=False)
        for property_name in ("Value", "Footprint", "Datasheet"):
            ref_at = text.index(f'(property "Reference" "{reference}"')
            symbol_start = text.rfind("\n\t(symbol\n", 0, ref_at)
            symbol_end = text.find("\n\t(symbol\n", ref_at)
            block = text[symbol_start : symbol_end if symbol_end >= 0 else len(text)]
            if f'(property "{property_name}"' in block:
                text = set_instance_property_visibility(
                    text, reference, property_name, hidden=True
                )
    CHILD_PATH.write_text(text, encoding="utf-8")


def mark_legacy_connectors_dnp() -> None:
    text = SOURCE_SHEET.read_text(encoding="utf-8")
    for reference in ("USB2", "USB3"):
        ref_marker = f'(property "Reference" "{reference}"'
        ref_at = text.index(ref_marker)
        symbol_start = text.rfind("\n\t(symbol\n", 0, ref_at)
        symbol_end = text.find("\n\t(symbol\n", ref_at)
        if symbol_end < 0:
            symbol_end = len(text)
        block = text[symbol_start:symbol_end]
        block = block.replace("\t\t(in_bom yes)", "\t\t(in_bom no)", 1)
        block = block.replace("\t\t(on_board yes)", "\t\t(on_board no)", 1)
        block = block.replace("\t\t(in_pos_files yes)", "\t\t(in_pos_files no)", 1)
        block = block.replace("\t\t(dnp no)", "\t\t(dnp yes)", 1)
        text = text[:symbol_start] + block + text[symbol_end:]
    SOURCE_SHEET.write_text(text, encoding="utf-8")


def update_root_sheet() -> None:
    text = ROOT_PATH.read_text(encoding="utf-8")
    if CHILD_PATH.name in text:
        print("Root sheet already references the USB-C host child; left unchanged")
        return

    sheet = '''\t(sheet
\t\t(at 45 110.49)
\t\t(size 35.56 3.81)
\t\t(exclude_from_sim no)
\t\t(in_bom yes)
\t\t(on_board yes)
\t\t(dnp no)
\t\t(fields_autoplaced yes)
\t\t(stroke (width 0.1524) (type solid))
\t\t(fill (color 0 0 0 0))
\t\t(uuid "4bb8fddd-ad20-4516-9ea1-5a73cdfa092b")
\t\t(property "Sheetname" "USB-C HOST J6"
\t\t\t(at 45 109.7784 0)
\t\t\t(show_name no)
\t\t\t(do_not_autoplace no)
\t\t\t(effects (font (size 1.27 1.27)) (justify left bottom))
\t\t)
\t\t(property "Sheetfile" "USB_C_HOST.kicad_sch"
\t\t\t(at 45 114.8846 0)
\t\t\t(show_name no)
\t\t\t(do_not_autoplace no)
\t\t\t(effects (font (size 1.27 1.27)) (justify left top))
\t\t)
\t\t(instances
\t\t\t(project "avaota-a1-v14"
\t\t\t\t(path "/550d58f0-4e41-4062-aec4-b3409407efa1" (page "16"))
\t\t\t)
\t\t)
\t)
'''
    footer = "\t(embedded_fonts no)"
    if footer not in text:
        raise RuntimeError("Could not locate root schematic footer")
    ROOT_PATH.write_text(text.replace(footer, sheet + footer, 1), encoding="utf-8")


def main() -> None:
    add_library_paths()
    create_host_sheet()
    mark_legacy_connectors_dnp()
    update_root_sheet()
    print(f"Generated {CHILD_PATH}")
    print("Marked legacy USB2/USB3 connectors DNP; retained U17 and D13")


if __name__ == "__main__":
    main()
