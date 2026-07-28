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

- `android-box-rebuild.kicad_sch` plus 14 child sheets, including the new USB-C PD input;
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
| ERC findings | 4,265 | 607 errors and 3,658 warnings overall; the new PD sheet contributes 37 unspecified-pin compatibility warnings and no errors, while the inherited EasyEDA electrical-type backlog remains open |
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

## Rev-P1 connector placement snapshot

The first connector-only PCB transformation has now been applied. It places J5 power
USB-C at `(109.6545, 139.6495) mm` and J6 USB-C host at
`(126.114, 139.6495) mm`, removes DC1/USB2/USB3, and replaces HDMI USB1 with the
horizontal HCTL `HDMI-01` / JLCPCB `C2906135` footprint at `(140.124, 135.455) mm`,
rotation `0 deg`. A top-side 3D render and position export both complete successfully.
The corrected USB-C datum is 3.9055 mm inboard of the
bottom board edge and gives a modeled shell-front overhang of 1.267 mm, matching the
original USB3 receptacle. Moving the two footprints outward by 6.2995 mm exposed one
abandoned local VBUS track beneath J6; the alignment pass removed it.

The exact HDMI replacement preserves all 19 signal nets and the grounded shell
assignment. Its four TMDS pairs are rejoined to the preserved corridor with a maximum
added positive/negative pair mismatch of 0.0001 mm; CEC, DDC, HPD and +5 V are also
connected. Ground signal pins and the four shell stakes use solid zone connections.
Current full-board DRC completes with 2,709 inherited/staging violations, 127
unconnected items, zero shorts and zero invalid-outline findings. There are no
unconnected items in the HDMI area. Eight J5/J6 copper-edge flags and seven clipped
J5/J6/HDMI silkscreen-edge flags are caused by the intentional connector-edge
engagement and still require review against the selected receptacle drawings and
fabricator rules. The unconnected count is expected
at this stage: the new PD VBUS/CC nets, host VBUS/CC/USB2 nets, and other previously
pruned subsystems must be reconciled with their matching schematic circuitry.

## J5 connector-critical routing pass

The staged J5 clone has been replaced by the exact XUNPU C720629 footprint without
changing its edge datum. U1001 and U1002 fit between J5 and the retained D2/Q1 input
stage; the two CC TVS parts and five connector/power capacitors are on B.Cu. CC1/CC2,
both raw VBUS fingers, the 1.2 mm raw/protected inner-layer trunks, output capacitors,
and the D2/Q1 handoff are connected. C1006, C1007 and R1012 are now placed beside
U1002 and route its dV/dt, fault-timer and nominal 3.33 A current-limit programming.
R1008-R1011 now route the approximately 7.19 V UVLO and 10.87 V OVLO window. The
Q1001 PDO2-qualified gate, U1001 support network and programming pads remain
schematic-only.

`scripts/check_j5_local.py` confirms the four connector/power groups plus the three
eFuse analogue-programming and voltage-window groups and finds
no different-net copper pair below 0.20 mm in the J5 corridor on F.Cu, In2.Cu,
In4.Cu, In5.Cu or B.Cu. Position export and top/bottom 3D renders pass; board
connectivity currently reports 125 inherited/staging unconnected edges. Full-board
top/bottom renders are stored under `renders/`, and `power-path.svg` tracks the current
logical completion state. The KiCad CLI full-board DRC aborts in the current headless
macOS process, so a GUI DRC run and
comparison against the previous 2,783-finding import backlog remain mandatory.

## Ethernet connector prune

RJ1 and RJ2, their ETH0/ETH1 edge labels, and 53 track/via items directly touching
their pads have been removed. The neighboring IR receiver and unrelated routing were
not included. The GMAC PHYs, magnetics-side support components and upstream nets remain
on the PCB until their matching schematic sheets can be pruned in a controlled pass.

After this change, position export and 3D render still pass. DRC reports 2,679 findings
and 52 unconnected items, with zero shorts and zero invalid-outline findings. The
parked Ethernet-side nets account for part of the intentional dangling/unconnected
backlog and are not a fabrication waiver.

## M.2 2230 NVMe staging pass

The complete PCB component populations from imported sheets `10_GMAC0` and
`11_GMAC1` have been removed: 64 PHY/support footprints and 341 directly attached
track/via items. J7, a UMAX `91302-42-067RDM` M-key connector (JLCPCB/LCSC
`C601195`), is placed at `(184.5, 122.0) mm`, rotation `90 deg`. H2 is a 2.8 mm
NPTH 2230 mounting datum at `(154.5, 122.0) mm`. The 30 x 22 mm module envelope is
drawn on `Dwgs.User`.

The staged lane mapping reuses the imported T527 combo-PHY receive nets and the
post-AC-coupling transmit nets at C219/C220. J7 clock, control and 3.3 V nets are
named but remain unrouted. Pre-existing copper was cleared from the connector pads
and mounting hole; the neighboring IR receiver was preserved, including a small
inner-layer jog around J7's upper mechanical anchor.

After this pass, position export and 3D render pass. DRC reports 2,848 inherited and
staging findings plus 130 unconnected items, with zero shorts and zero invalid-outline
findings. The added unconnected items are expected from the removed GMAC circuits and
unrouted M.2 nets. This is a placement/net-assignment checkpoint, not a fabrication
waiver. See `nvme-migration.md` for the electrical blockers.

## External eDP/DisplayPort prune

The board label `DP` identified U15, the 24-pin internal eDP panel connector; it was
not the retained HDMI port. U15 and its 20 connector-side support footprints were
removed: D10-D12, C190-C199, C223/C224, and R56/R57/R60-R62. The pass also removed
518 track/via items on dedicated eDP lane, AUX and HPD nets, 14 local GND/DCDC4
fanout items, and the `DP` silkscreen label. HDMI USB1 and its existing route remain
unchanged.

The SoC's internal eDP-domain rail decoupling is deliberately retained until the
power-domain schematic is audited; unused-domain power state must be resolved in the
schematic and firmware rather than by deleting core capacitors from placement alone.
The imported `6_PERF1` schematic still contains the eDP connector circuit and must be
synchronized before release.

After the eDP PCB prune, position export and 3D render pass. DRC reports 2,783
inherited/staging findings and 127 unconnected items, with zero shorts and zero
invalid-outline findings.

## Next controlled changes

1. Save an immutable import tag/hash before editing the electrical core.
2. Reconcile the imported net classes and via rules with the Avaota fabrication files
   and the intended JLCPCB eight-layer stack-up.
3. Preserve the zero-short/valid-outline baseline while changing edge connectors.
4. Remove the GMAC0/1 schematic sheets and the eDP section of `6_PERF1` to match the
   completed PCB prunes, then remove camera and other unused carrier blocks one
   subsystem at a time.
5. Place and route the remaining J5 PD/eFuse control-passive network, review the
   staged 9 V trunk against the released stack-up/current target, program and read back
   the STUSB4500 NVM, then prove startup and fault behavior on the bench.
6. Replace the dual USB-A with one USB 2.0 Type-C host and keep HDMI in its reference
   routing corridor after the mechanical outline and selected connector drawings are verified.
7. Complete the staged M.2 design: disconnect/reassign the combo-PHY reference-clock
   balls, add PCIe control GPIOs and a sequenced 3.3 V supply, then route and simulate
   the PCIe Gen2 lane against the released stack-up.
