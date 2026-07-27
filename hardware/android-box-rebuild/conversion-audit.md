# Avaota-to-KiCad conversion audit

## Source and tool

- Source: Avaota A1 repository commit `bbd81c54c9a971e8fd9397fec958a9d9afebdffe`.
- Input: v1.4 EasyEDA Pro project, SHA-256
  `a08d6b190b034455ce3941dad1c47cae812a917def3b7929a2ad29e24e98dac2`.
- Converter/editor: KiCad 10.0.4 built-in EasyEDA Pro importer on macOS.
- Imported combination: `Avaota Pi A / PCB1 / Avaota Pi A`. The other archive
  combinations are DRAM-only templates and were not used as the project root.

## Generated project baseline

The project now contains the real Avaota hierarchy rather than placeholder blocks:

- `android-box-rebuild.kicad_sch` plus 13 child sheets;
- `android-box-rebuild.kicad_pcb`, an eight-copper-layer routed PCB;
- embedded imported symbols, footprints, nets, tracks, vias and zones.

The reference core that must remain geometrically controlled is:

| Function | Reference | Imported footprint/value |
|---|---:|---|
| T527/A527 SoC | U14 | `T527-BGA664` |
| Main PMIC | U4 | AXP717, QFN-52 6 x 6 mm, 0.4 mm pitch |
| CPU PMIC | U5 | AXP323, QFN-20 3 x 3 mm, 0.4 mm pitch |
| HDMI | USB1 | `HDMI-001C`, imported LCSC identity C2836126 |
| USB-A host | USB2 | `USB-303WSD-BRY` |
| USB-C | USB3 | `TYPEC-304-BCP16` |
| 12 V input | DC1 | `DC-044A-A200` |

The original designators are preserved even where names are odd (`USB1` is HDMI).
Renumber only after the customized schematic and PCB are synchronized.

## Imported mechanical reference

- Main outline: 100 x 75 mm with 3 mm corner radii.
- HDMI USB1 origin: `(140.124, 132.247) mm`, rotation `-90 deg`.
- USB-C USB3 origin: `(182.7305, 72.4605) mm`, rotation `180 deg`.
- USB-A USB2 origin: `(126.114, 134.970) mm`, rotation `0 deg`.
- DC barrel DC1 origin: `(109.6545, 136.8555) mm`, rotation `90 deg`.

These coordinates document the imported baseline. Rev-P1 reuses the DC1, USB2 and
USB1 edge corridors respectively for USB-C PD power, one USB-C host and horizontal
HDMI, minimizing high-speed rerouting.

## Import repairs performed

Two copper keepout zones were assigned to `Edge.Cuts` by the importer. They were moved
to `F.Cu` so they remain rule areas rather than corrupting the outline layer.

The imported `FAN2510` footprint contained two 3 mm mounting-hole pads placed through
existing routed copper. The pads accounted for all 89 initial short reports. They were
removed while retaining the fan body/placement graphics; fan mounting holes must be
reintroduced only after the thermal solution and hole locations are frozen and copper
keepouts are routed around them.

Four audio-jack body segments were imported on `Edge.Cuts`, creating two open outline
fragments. They were moved to `F.Fab`. The actual 100 x 75 mm board outline was not
changed.

## Validation snapshot

| Check | Result | Interpretation |
|---|---:|---|
| Schematic parse/ERC execution | Pass | All 14 sheets parse in KiCad 10 |
| ERC findings | 4,226 | Mostly imported EasyEDA pin electrical types and missing KiCad power-driver semantics; must be audited, not blanket-excluded |
| PCB parse/position export | Pass | Component positions export successfully |
| PCB 3D render | Pass | Board, copper and components load successfully |
| PCB DRC execution | Pass | DRC completes when allowed macOS GUI-state access |
| PCB DRC findings after import repair | 2,674; zero unconnected items | Imported rule defaults do not match the source process and many footprint/courtyard objects need normalization |
| Reported shorts | 0 | Reduced from 89 after removing the two impossible fan-hole pads |
| Outline validity | Pass | Reduced from two malformed-outline findings after moving audio-jack body graphics to `F.Fab` |

Largest remaining DRC groups are 499 clearance, 205 hole-clearance, 203
starved-thermal, and capped groups of 199 each for via diameter, track width, drill
range, annular width, courtyard overlap, hole-to-hole, forbidden items and imported
footprint issues. Treat this count as the conversion backlog, not as a release waiver.
The next reduction must start by importing/reconstructing the source fabrication rules;
blanket exclusions would hide real defects.

## Next controlled changes

1. Save an immutable import tag/hash before editing the electrical core.
2. Reconcile the imported net classes and via rules with the Avaota fabrication files
   and the intended JLCPCB eight-layer stack-up.
3. Preserve the zero-short/valid-outline baseline while changing edge connectors.
4. Prune GMAC0/1, camera, display and other unused carrier blocks one subsystem at a
   time, with schematic/PCB parity checks after each deletion.
5. Replace the barrel connector with a reviewed 9 V USB-C PD sink feeding the existing
   protected `DCIN-12V` path.
6. Replace the dual USB-A with one USB 2.0 Type-C host and keep HDMI in its reference
   routing corridor after the mechanical outline and selected connector drawings are verified.
