#!/usr/bin/env python3
"""Create the Rev-P1 USB-C PD input sheet and replace the barrel-jack symbol.

Run from the project directory with:

    uv run --with kicad-sch-api python scripts/add_usbc_pd_power.py

The parent migration is idempotent: an existing child-sheet reference is preserved,
while the generated child can be refreshed without duplicating hierarchy objects.
"""

from __future__ import annotations

from pathlib import Path

import kicad_sch_api as ksa


PROJECT_DIR = Path(__file__).resolve().parent.parent
PARENT_PATH = PROJECT_DIR / "12_12VDC.kicad_sch"
CHILD_PATH = PROJECT_DIR / "USB_C_PD_9V.kicad_sch"
KICAD_SYMBOLS = Path(
    "/Applications/KiCad/KiCad.app/Contents/SharedSupport/symbols"
)
ROOT_SCHEMATIC_UUID = "550d58f0-4e41-4062-aec4-b3409407efa1"
POWER_SHEET_UUID = "0077da8f-ce56-4f67-9443-2c8309cd2330"
PD_SHEET_UUID = "dc10ca32-d859-445f-91cb-6e652499906f"
PROJECT_NAME = "avaota-a1-v14"

R_0603 = "Resistor_SMD:R_0603_1608Metric"
C_0603 = "Capacitor_SMD:C_0603_1608Metric"
C_0805 = "Capacitor_SMD:C_0805_2012Metric"
C_1206 = "Capacitor_SMD:C_1206_3216Metric"


def point_tuple(point: object) -> tuple[float, float]:
    return (point.x, point.y)


def add_library_paths() -> None:
    cache = ksa.library.get_symbol_cache()
    cache.add_library_path(str(PROJECT_DIR / "libs" / "power.kicad_sym"))
    for library in ("Device", "Transistor_FET", "Connector"):
        cache.add_library_path(str(KICAD_SYMBOLS / f"{library}.kicad_sym"))


def add_component(
    schematic: ksa.Schematic,
    lib_id: str,
    reference: str,
    value: str,
    position: tuple[float, float],
    footprint: str,
    *,
    rotation: float = 0.0,
    **properties: str,
):
    return schematic.components.add(
        lib_id=lib_id,
        reference=reference,
        value=value,
        position=position,
        footprint=footprint,
        rotation=rotation,
        **properties,
    )


def add_resistor(
    schematic: ksa.Schematic,
    reference: str,
    value: str,
    position: tuple[float, float],
    net_1: str,
    net_2: str,
    *,
    footprint: str = R_0603,
) -> None:
    add_component(
        schematic, "Device:R", reference, value, position, footprint
    )
    label_pin(schematic, reference, "1", net_1)
    label_pin(schematic, reference, "2", net_2)


def add_capacitor(
    schematic: ksa.Schematic,
    reference: str,
    value: str,
    position: tuple[float, float],
    net_1: str,
    net_2: str = "GND",
    *,
    footprint: str = C_0603,
) -> None:
    add_component(
        schematic, "Device:C", reference, value, position, footprint
    )
    label_pin(schematic, reference, "1", net_1)
    label_pin(schematic, reference, "2", net_2)


def label_pin(
    schematic: ksa.Schematic,
    reference: str,
    pin_number: str,
    net_name: str,
    *,
    stub: float = 2.54,
) -> None:
    pin = schematic.get_component_pin_position(reference, pin_number)
    if pin is None:
        raise RuntimeError(f"No pin {pin_number} found on {reference}")
    start = point_tuple(pin)
    end = (pin.x + stub, pin.y)
    schematic.add_wire(start, end)
    schematic.add_label(
        net_name,
        position=end,
        rotation=180.0 if stub < 0 else 0.0,
        size=1.0,
    )


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


def create_pd_sheet() -> None:
    schematic = ksa.create_schematic(PROJECT_NAME)
    schematic.set_hierarchy_context(ROOT_SCHEMATIC_UUID, PD_SHEET_UUID)
    schematic.set_paper_size("A4")
    schematic.set_title_block(
        title="USB-C PD 9 V input and protected load path",
        rev="Rev-P1",
        company="gun_pcb / Avaota A1 derivative",
        comments={
            1: "PDO2=9 V/3 A; default 5 V is hardware-blocked",
            2: "Prototype and bench-validate before assembly release",
        },
    )

    add_component(
        schematic,
        "power:TYPEC-304-BCP16",
        "J5",
        "TYPEC-304-BCP16",
        (42.0, 72.0),
        "power:USB-C-SMD_TYPEC-304-BCP16",
        Datasheet="https://www.lcsc.com/product-detail/C720629.html",
        Manufacturer="XUNPU",
        **{"Manufacturer Part": "TYPEC-304-BCP16", "Supplier Part": "C720629"},
    )
    add_component(
        schematic,
        "power:STUSB4500QTR",
        "U1001",
        "STUSB4500QTR",
        (111.0, 72.0),
        "power:QFN-24_L4.0-W4.0-P0.50-BL-EP2.8",
        Datasheet="https://www.st.com/resource/en/datasheet/stusb4500.pdf",
        Manufacturer="STMicroelectronics",
        **{"Manufacturer Part": "STUSB4500QTR", "Supplier Part": "C2678061"},
    )
    add_component(
        schematic,
        "power:TPS259470LRPWR",
        "U1002",
        "TPS259470LRPWR",
        (205.0, 72.0),
        "power:VQFN-10_L2.0-W2.0-P0.45-TL",
        Datasheet="https://www.ti.com/lit/ds/symlink/tps25947.pdf",
        Manufacturer="Texas Instruments",
        **{"Manufacturer Part": "TPS259470LRPWR", "Supplier Part": "C3662793"},
    )

    # Power-only receptacle.  Both combined VBUS and GND pad groups are explicit.
    for pin in ("A4B9", "B4A9"):
        label_pin(schematic, "J5", pin, "PD_VBUS_RAW", stub=-2.54)
    label_pin(schematic, "J5", "A5", "PD_CC1", stub=-2.54)
    label_pin(schematic, "J5", "B5", "PD_CC2", stub=-2.54)
    for pin in ("A1B12", "B1A12"):
        label_pin(schematic, "J5", pin, "GND", stub=-2.54)
    for pin in ("13", "14", "15", "16"):
        label_pin(schematic, "J5", pin, "GND")
    for pin in ("A6", "A7", "A8", "B6", "B7", "B8"):
        no_connect(schematic, "J5", pin)

    # STUSB4500 dead-battery CC path and supply/sense connections.
    for pin in ("1", "2"):
        label_pin(schematic, "U1001", pin, "PD_CC1", stub=-2.54)
    for pin in ("4", "5"):
        label_pin(schematic, "U1001", pin, "PD_CC2", stub=-2.54)
    label_pin(schematic, "U1001", "24", "PD_VBUS_RAW")
    label_pin(schematic, "U1001", "18", "VBUS_SENSE")
    label_pin(schematic, "U1001", "9", "VBUS_DISCH")
    label_pin(schematic, "U1001", "20", "PDO2_OK_N")
    label_pin(schematic, "U1001", "21", "VREG_1V2")
    label_pin(schematic, "U1001", "23", "VREG_2V7")
    label_pin(schematic, "U1001", "6", "PD_RESET", stub=-2.54)
    label_pin(schematic, "U1001", "7", "PD_SCL", stub=-2.54)
    label_pin(schematic, "U1001", "8", "PD_SDA", stub=-2.54)
    label_pin(schematic, "U1001", "19", "PD_ALERT_N")
    for pin in ("10", "12", "13", "22", "25"):
        label_pin(schematic, "U1001", pin, "GND")
    for pin in ("3", "11", "14", "15", "16", "17"):
        no_connect(schematic, "U1001", pin)

    # CC protection is intentionally 24 V tolerant; finalize the JLC supplier code
    # during the passive/protection AVL pass.
    for reference, y, net in (
        ("D1001", 112.0, "PD_CC1"),
        ("D1002", 124.0, "PD_CC2"),
    ):
        add_component(
            schematic,
            "Device:D_TVS",
            reference,
            "PESD24VL1BA",
            (52.0, y),
            "Diode_SMD:D_SOD-323",
            Datasheet="https://assets.nexperia.com/documents/data-sheet/PESD24VL1BA.pdf",
            Manufacturer="Nexperia",
            **{"Manufacturer Part": "PESD24VL1BA"},
        )
        label_pin(schematic, reference, "1", net, stub=-2.54)
        label_pin(schematic, reference, "2", "GND")

    add_capacitor(
        schematic, "C1001", "4.7uF 25V", (67.0, 113.0), "PD_VBUS_RAW", footprint=C_1206
    )
    add_capacitor(schematic, "C1002", "100nF 25V", (80.0, 113.0), "PD_VBUS_RAW")
    add_capacitor(schematic, "C1003", "1uF", (142.0, 105.0), "VREG_1V2")
    add_capacitor(schematic, "C1004", "1uF", (155.0, 105.0), "VREG_2V7")
    add_capacitor(schematic, "C1005", "1uF 25V", (168.0, 105.0), "PD_VBUS_RAW")

    add_resistor(schematic, "R1001", "470R", (86.0, 135.0), "PD_VBUS_RAW", "VBUS_SENSE")
    add_resistor(
        schematic, "R1002", "1k", (100.0, 135.0), "PD_9V_PROTECTED", "VBUS_DISCH"
    )
    add_resistor(schematic, "R1003", "100k", (114.0, 135.0), "PD_RESET", "GND")
    add_resistor(schematic, "R1004", "4.7k", (128.0, 135.0), "VREG_2V7", "PD_SCL")
    add_resistor(schematic, "R1005", "4.7k", (142.0, 135.0), "VREG_2V7", "PD_SDA")
    add_resistor(
        schematic, "R1006", "4.7k", (156.0, 135.0), "VREG_2V7", "PD_ALERT_N"
    )
    add_resistor(
        schematic, "R1007", "100k", (170.0, 135.0), "VREG_2V7", "PDO2_OK_N"
    )

    # Hardware-qualified enable: 9 V must be selected as PDO2 and VBUS must exceed
    # about 7.19 V.  This prevents a default 5 V source from reaching DCIN.
    add_resistor(schematic, "R1008", "499k 1%", (184.0, 124.0), "PD_VBUS_RAW", "EFUSE_EN")
    add_resistor(schematic, "R1009", "100k 1%", (184.0, 145.0), "EFUSE_EN", "GND")
    add_component(
        schematic,
        "Transistor_FET:2N7002",
        "Q1001",
        "2N7002",
        (208.0, 139.0),
        "Package_TO_SOT_SMD:SOT-23",
        Datasheet="https://assets.nexperia.com/documents/data-sheet/2N7002.pdf",
    )
    label_pin(schematic, "Q1001", "1", "PDO2_OK_N", stub=-2.54)
    label_pin(schematic, "Q1001", "2", "GND")
    label_pin(schematic, "Q1001", "3", "EFUSE_EN")

    # An independent upper window rejects 12/15/20 V contracts and cable faults.
    add_resistor(schematic, "R1010", "806k 1%", (226.0, 124.0), "PD_VBUS_RAW", "EFUSE_OVLO")
    add_resistor(schematic, "R1011", "100k 1%", (226.0, 145.0), "EFUSE_OVLO", "GND")

    label_pin(schematic, "U1002", "1", "EFUSE_EN", stub=-5.08)
    label_pin(schematic, "U1002", "2", "EFUSE_OVLO", stub=-5.08)
    label_pin(schematic, "U1002", "5", "PD_VBUS_RAW", stub=-5.08)
    label_pin(schematic, "U1002", "7", "EFUSE_DVDT")
    label_pin(schematic, "U1002", "8", "GND")
    label_pin(schematic, "U1002", "9", "EFUSE_ILM")
    label_pin(schematic, "U1002", "10", "EFUSE_ITIMER")
    for pin in ("3", "4"):
        no_connect(schematic, "U1002", pin)

    add_capacitor(schematic, "C1006", "2.2nF", (242.0, 112.0), "EFUSE_DVDT")
    add_capacitor(schematic, "C1007", "2.2nF", (255.0, 112.0), "EFUSE_ITIMER")
    add_resistor(schematic, "R1012", "1.00k 1%", (268.0, 112.0), "EFUSE_ILM", "GND")
    add_capacitor(
        schematic,
        "C1008",
        "10uF 16V",
        (242.0, 137.0),
        "PD_9V_PROTECTED",
        footprint=C_1206,
    )
    add_capacitor(schematic, "C1009", "100nF 16V", (255.0, 137.0), "PD_9V_PROTECTED")

    # Four pads are enough to program and inspect the STUSB4500 NVM without adding
    # a permanent system MCU dependency.
    for reference, x, net in (
        ("TP1001", 91.0, "PD_SCL"),
        ("TP1002", 103.0, "PD_SDA"),
        ("TP1003", 115.0, "VREG_2V7"),
        ("TP1004", 127.0, "GND"),
    ):
        add_component(
            schematic,
            "Connector:TestPoint",
            reference,
            net,
            (x, 157.0),
            "TestPoint:TestPoint_Pad_D1.0mm",
        )
        label_pin(schematic, reference, "1", net)

    out_pin = schematic.get_component_pin_position("U1002", "6")
    if out_pin is None:
        raise RuntimeError("U1002 output pin was not created")
    output_label_position = (271.78, out_pin.y)
    schematic.add_wire(point_tuple(out_pin), output_label_position)
    schematic.add_hierarchical_label(
        "PD_9V_PROTECTED",
        output_label_position,
        shape="output",
        rotation=0.0,
        size=1.0,
    )

    schematic.add_text(
        "PROGRAM U1001 NVM BEFORE BRING-UP: SNK_PDO_NUMB=2; PDO2=9 V / 3 A; POWER_ONLY_ABOVE_5V=1",
        (148.5, 28.0),
        size=1.2,
        bold=True,
    )
    schematic.add_text(
        "U1002 window: UVLO ~= 7.19 V, OVLO ~= 10.87 V; RILM=1.00 kOhm ~= 3.33 A; dV/dt ~= 0.91 V/ms",
        (148.5, 34.0),
        size=1.1,
    )
    schematic.add_text(
        "Power-only Type-C: USB2 and SBU pins are intentionally unconnected. CC1/CC2 TVS must sit at J5.",
        (148.5, 40.0),
        size=1.1,
    )
    # Hierarchy context is required for correct annotation paths, but version
    # 0.5.5 also exposes that path as a visible custom field.  The instances keep
    # their correct paths after this presentation-only field is removed.
    for component in schematic.components:
        component.remove_property("hierarchy_path")
    schematic.save_as(str(CHILD_PATH))
    # kicad-sch-api 0.5.5 currently ignores the requested hierarchical-label
    # shape and serializes every new label as an input.  Correct this generated
    # output label before KiCad validates the hierarchy.
    text = CHILD_PATH.read_text(encoding="utf-8")
    for reference in ("J5", "U1001", "U1002"):
        text = set_instance_property_visibility(
            text, reference, "Reference", hidden=False
        )
        for property_name in (
            "Value",
            "Footprint",
            "Datasheet",
            "Manufacturer",
            "Manufacturer Part",
            "Supplier Part",
        ):
            text = set_instance_property_visibility(
                text, reference, property_name, hidden=True
            )
    marker = '(hierarchical_label "PD_9V_PROTECTED"\n\t\t(shape input)'
    if marker not in text:
        raise RuntimeError("Could not locate the generated PD output label")
    CHILD_PATH.write_text(
        text.replace(marker, marker.replace("shape input", "shape output"), 1),
        encoding="utf-8",
    )


def update_parent_sheet() -> None:
    text = PARENT_PATH.read_text(encoding="utf-8")
    if 'hierarchical_label "PD_9V_PROTECTED"' in text:
        print("12 V sheet already accepts PD_9V_PROTECTED; left unchanged")
        return

    block_start = text.index(
        '\t(symbol\n\t\t(lib_id "avaota-a1--easyedapro:DC-044A-A200")'
    )
    block_end = text.index("\n\t(symbol\n", block_start + 1)
    barrel = text[block_start:block_end]
    barrel = barrel.replace("\t\t(in_bom yes)", "\t\t(in_bom no)", 1)
    barrel = barrel.replace("\t\t(on_board yes)", "\t\t(on_board no)", 1)
    barrel = barrel.replace("\t\t(in_pos_files yes)", "\t\t(in_pos_files no)", 1)
    barrel = barrel.replace("\t\t(dnp no)", "\t\t(dnp yes)", 1)
    barrel = barrel.replace(
        '(property "Value" "DC-044A-A200"',
        '(property "Value" "DNP - USB-C PD REPLACES BARREL"',
        1,
    )
    text = text[:block_start] + barrel + text[block_end:]

    first_instance = '\t(symbol\n\t\t(lib_id "avaota-a1--easyedapro:CapAcitance")'
    handoff = '''\t(hierarchical_label "PD_9V_PROTECTED"
\t\t(shape input)
\t\t(at 59.69 57.15 180)
\t\t(effects
\t\t\t(font
\t\t\t\t(size 1 1)
\t\t\t)
\t\t\t(justify right)
\t\t)
\t\t(uuid "20b118ec-02e1-4da0-a4a6-de27cdc4e898")
\t)
\t(text "DC1 IS DNP: J5 USB-C PD feeds this node through the protected 9 V sheet"
\t\t(exclude_from_sim no)
\t\t(at 43.18 45.72 0)
\t\t(effects
\t\t\t(font
\t\t\t\t(size 1 1)
\t\t\t\t(bold yes)
\t\t\t)
\t\t\t(justify left)
\t\t)
\t\t(uuid "dfafb519-69e0-48af-a145-3b450fc17c7f")
\t)
'''
    if first_instance not in text:
        raise RuntimeError("Could not locate the first 12 V sheet symbol instance")
    PARENT_PATH.write_text(
        text.replace(first_instance, handoff + first_instance, 1), encoding="utf-8"
    )


def update_root_sheet() -> None:
    root_path = PROJECT_DIR / "android-box-rebuild.kicad_sch"
    text = root_path.read_text(encoding="utf-8")
    if CHILD_PATH.name in text:
        print("Root sheet already references the USB-C PD child; left unchanged")
        return

    root_wire = '''\t(wire
\t\t(pts
\t\t\t(xy 17.78 104.775) (xy 45 104.775)
\t\t)
\t\t(stroke
\t\t\t(width 0)
\t\t\t(type default)
\t\t)
\t\t(uuid "bfa86062-09fc-457c-968b-d36041d5faa0")
\t)
'''
    text = text.replace("\t(lib_symbols)\n", "\t(lib_symbols)\n" + root_wire, 1)

    power_uuid = f'\t\t(uuid "{POWER_SHEET_UUID}")'
    power_at = text.index(power_uuid)
    power_end = text.index("\n\t(sheet\n", power_at)
    power_block = text[power_at:power_end]
    input_pin = '''\t\t(pin "PD_9V_PROTECTED" input
\t\t\t(at 17.78 104.775 0)
\t\t\t(uuid "cf4db600-0b3c-4cf9-8f8b-2df17763d250")
\t\t\t(effects
\t\t\t\t(font
\t\t\t\t\t(size 1.27 1.27)
\t\t\t\t)
\t\t\t\t(justify right)
\t\t\t)
\t\t)
'''
    power_block = power_block.replace("\t\t(instances\n", input_pin + "\t\t(instances\n", 1)
    text = text[:power_at] + power_block + text[power_end:]

    pd_sheet = '''\t(sheet
\t\t(at 45 102.87)
\t\t(size 35.56 3.81)
\t\t(exclude_from_sim no)
\t\t(in_bom yes)
\t\t(on_board yes)
\t\t(dnp no)
\t\t(fields_autoplaced yes)
\t\t(stroke
\t\t\t(width 0.1524)
\t\t\t(type solid)
\t\t)
\t\t(fill
\t\t\t(color 0 0 0 0)
\t\t)
\t\t(uuid "dc10ca32-d859-445f-91cb-6e652499906f")
\t\t(property "Sheetname" "USB-C PD 9V INPUT"
\t\t\t(at 45 102.1584 0)
\t\t\t(show_name no)
\t\t\t(do_not_autoplace no)
\t\t\t(effects
\t\t\t\t(font
\t\t\t\t\t(size 1.27 1.27)
\t\t\t\t)
\t\t\t\t(justify left bottom)
\t\t\t)
\t\t)
\t\t(property "Sheetfile" "USB_C_PD_9V.kicad_sch"
\t\t\t(at 45 107.2646 0)
\t\t\t(show_name no)
\t\t\t(do_not_autoplace no)
\t\t\t(effects
\t\t\t\t(font
\t\t\t\t\t(size 1.27 1.27)
\t\t\t\t)
\t\t\t\t(justify left top)
\t\t\t)
\t\t)
\t\t(pin "PD_9V_PROTECTED" output
\t\t\t(at 45 104.775 180)
\t\t\t(uuid "0b44e09c-6a75-4e7b-bd6c-f96dc6d8de76")
\t\t\t(effects
\t\t\t\t(font
\t\t\t\t\t(size 1.27 1.27)
\t\t\t\t)
\t\t\t\t(justify left)
\t\t\t)
\t\t)
\t\t(instances
\t\t\t(project "avaota-a1-v14"
\t\t\t\t(path "/550d58f0-4e41-4062-aec4-b3409407efa1"
\t\t\t\t\t(page "15")
\t\t\t\t)
\t\t\t)
\t\t)
\t)
'''
    if "\t(embedded_fonts no)" not in text:
        raise RuntimeError("Could not locate root schematic footer")
    root_path.write_text(
        text.replace("\t(embedded_fonts no)", pd_sheet + "\t(embedded_fonts no)", 1),
        encoding="utf-8",
    )


def main() -> None:
    add_library_paths()
    create_pd_sheet()
    update_parent_sheet()
    update_root_sheet()
    print(f"Generated {CHILD_PATH}")
    print(f"Verified hierarchy handoff through {PARENT_PATH}")


if __name__ == "__main__":
    main()
