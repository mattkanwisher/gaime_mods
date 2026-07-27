# Avaota A1-derived Android box PCB

This directory is the Rev-P1 engineering baseline for a compact T527/A527 Android
board derived from the open-hardware Avaota A1. The requested external arrangement is
now fixed at the concept level and deliberately follows the reference connector edge:

- original DC barrel location: USB-C PD power input;
- original dual USB-A location: one USB 2.0 USB-C host port;
- original HDMI location and route corridor: horizontal right-angle HDMI Type-A;
- all other external connectors are removed from the production baseline.

This is **not fabrication-ready**, but it is now a real editable KiCad project. The
pinned Avaota v1.4 EasyEDA source has been converted into a 14-sheet schematic and a
routed eight-layer PCB. The imported reference has not yet been pruned or mechanically
adapted, and its conversion findings must be cleared before release. See
[`conversion-audit.md`](conversion-audit.md) and
[`jlcpcb-release-plan.md`](jlcpcb-release-plan.md).

## Rev-P1 baseline

| Item | Baseline | Release decision |
|---|---|---|
| SoC | Allwinner T527/A527, BGA664 | Preserve the Avaota A1 symbol, escape, clocks, straps and decoupling |
| RAM | 2 GB LPDDR4 baseline | Select an exact reference-supported MPN before schematic freeze; 4 GB is an assembly option only after boot validation |
| Storage | 32 or 64 GB eMMC 5.1, 8-bit HS400 | Select exact MPN and bootloader timing profile before release |
| Main PMIC | AXP717 | Reuse the Avaota A1 core power sheet and sequencing |
| CPU PMIC | AXP323 | Reuse the Avaota A1 core power sheet and sequencing |
| Video | Horizontal right-angle HDMI 2.0 Type-A in the reference location | Preserve native HDMI connector corridor and existing TMDS routing |
| Power | Dedicated USB-C PD sink replacing the barrel jack | Negotiate 9 V / 3 A into the existing protected `DCIN-12V` path; no data on this connector |
| Accessory port | One USB 2.0 host USB-C replacing the dual USB-A | Reuse one existing host pair; add Rp, ESD and a current-limited VBUS switch |
| Debug | UART, JTAG, FEL and reset | Retain accessible pads or headers on prototypes |
| Excluded | Ethernet, Wi-Fi, SD, camera, audio, PCIe and panel display | Prune only after the unmodified Avaota core sheets are imported |

## Important software consequence

The retail G'AIM'E image expects AXP2202/AXP1530. This board instead keeps the
Avaota A1's AXP717/AXP323 topology, so the stock image is **not expected to boot
unchanged**. The practical sequence is to boot an Avaota-supported Android/Linux image
first, then port the G'AIM'E bootloader/device-tree power configuration and Android
userspace. This is lower hardware risk than redesigning undocumented PMIC circuits.

## Files

- [`android-box-rebuild.kicad_pro`](android-box-rebuild.kicad_pro) - open this file in KiCad to load the Rev-P1 project.
- [`android-box-rebuild.kicad_sch`](android-box-rebuild.kicad_sch) - imported full Avaota schematic hierarchy.
- [`android-box-rebuild.kicad_pcb`](android-box-rebuild.kicad_pcb) - imported routed eight-layer Avaota PCB baseline; not the final Rev-P1 layout.
- [`conversion-audit.md`](conversion-audit.md) - source provenance, import repairs, validation counts and conversion backlog.
- [`connector-migration.md`](connector-migration.md) - current connector/net mapping and the controlled same-edge conversion sequence.
- [`mechanical-datums.csv`](mechanical-datums.csv) - enclosure measurements required before connector placement is locked.
- [`jlcpcb-release-plan.md`](jlcpcb-release-plan.md) - gated plan from source import to the JLCPCB upload package.
- [`architecture.md`](architecture.md) - block-level electrical design and net contracts.
- [`power-tree.csv`](power-tree.csv) - Avaota-derived regulator map that must be checked against the editable source.
- [`interfaces.csv`](interfaces.csv) - connector and SoC interface contract.
- [`bom-seed.csv`](bom-seed.csv) - critical parts and sourcing gates.
- [`layout-rules.md`](layout-rules.md) - stack-up, placement and routing constraints.
- [`bring-up.md`](bring-up.md) - staged prototype validation.
- [`reference-design.md`](reference-design.md) - pinned Avaota A1 source and license notes.
- [`floorplan.svg`](floorplan.svg) - Rev-P1 connector and major-component placement.

## Recommended implementation path

1. Clear the import-audit items that can hide real shorts, outline defects or incorrect
   manufacturing constraints; keep a frozen hash of the original conversion.
2. Freeze measured enclosure datums for the same-edge USB-C power, USB-C host and HDMI row.
3. Remove unused external peripherals without changing core nets or power sequencing.
4. Add the 9 V USB-C PD sink and adapt the single USB host protection, then prove the
   power and load-switch limits on the schematic.
5. Select exact SoC, DRAM, eMMC and PMIC MPNs, verify the selected connector drawings,
   and agree with JLCPCB how the fine-pitch BGAs and any consigned parts will be handled.
6. Preserve the reference DRAM placement/escape and route the changed edge I/O around it.
7. Complete every release gate in `jlcpcb-release-plan.md`, build a small prototype lot,
   and use the staged bring-up plan before attempting a firmware port.
