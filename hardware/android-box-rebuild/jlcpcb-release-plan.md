# Plan to reach a JLCPCB prototype release

This is the execution plan for Rev-A. A gate is complete only when its named evidence
exists in the repository or in the JLCPCB order record. Passing the final gate means the
files are safe to upload and quote; it does not mean the unproven board should go
straight to volume production.

## Locked Rev-P1 intent

- Core: pinned Avaota A1 v1.4 T527/A527 + AXP717 + AXP323 + LPDDR4 topology.
- Same reference edge: USB-C PD power, one USB 2.0 host Type-C and horizontal HDMI.
- Input assumption: a dedicated power-only USB-C sink negotiating 9 V / 3 A into the
  existing `DCIN-12V` path, subject to Gate 2 power-budget approval.
- First software target: Avaota-compatible baseline image, followed by a G'AIM'E
  bootloader/device-tree port. Stock G'AIM'E firmware is not a Rev-A acceptance target.
- Construction target: 8 layers, controlled impedance, ENIG, epoxy-filled/capped
  via-in-pad where required by the reference BGA escape.

## Gate 0 - product and mechanical freeze

Work:

1. Measure or import the enclosure interior, opening sizes, board keep-outs, mounting
   holes, heatsink envelope and connector insertion paths.
2. Freeze the relative order and orientation of same-edge J5, J6 and J1. Include plug
   shells and cable bend clearance, not only PCB footprints.
3. Decide board outline, thickness, mounting hardware and maximum component heights on
   both faces.

Evidence / pass criteria:

- Dimensioned DXF plus STEP model with named mechanical datums.
- Verified manufacturer drawings and production footprints for J1, J5 and J6.
- Printed 1:1 fit check or mechanical dummy PCB fits the enclosure and all plugs.
- No unresolved connector, mounting or heatsink dimensions.

## Gate 1 - controlled reference import

Work:

1. Fork the pinned Avaota A1 v1.4 editable source and retain license/notices.
2. Import the SoC, AXP717, AXP323, DRAM, eMMC, clocks, boot straps, debug and HDMI
   source circuitry into one reviewable project.
3. Import the 8-layer LPDDR4 placement/escape template without geometry changes.
4. Generate a reference netlist/BOM and save a machine-readable diff baseline before
   pruning anything.

Evidence / pass criteria:

- Reproducibly editable schematic and PCB source committed in the repository.
- Reference commit, source checksums and CERN-OHL-S-2.0 notices retained.
- Every imported symbol-to-footprint mapping and BGA pin map checks against the source.
- No unreviewed differences inside the core boundary defined in `architecture.md`.

## Gate 2 - schematic adaptation and power proof

Status: the J5 power schematic uses STUSB4500QTR U1001 and TPS259470LRPWR U1002 with
PDO2-qualified enable, approximately 7.19-10.87 V input window, 3.33 A nominal current
limit and programming test pads. The exact J5/U1001/U1002 front end is placed and the
CC/raw-VBUS/protected-VBUS paths are routed into D2/Q1. The control-passive PCB fanout,
NVM image control, power-budget approval and bench evidence are still open.

Work:

1. Remove unused carrier peripherals one block at a time, auditing every disconnected
   rail, strap, clock and shared I/O net.
2. Implement J5 as an autonomous 9 V / 3 A USB-C PD sink with OVP/UVLO, current limiting
   and reverse-current protection feeding the existing `DCIN-12V` entry.
3. Implement J6 as one USB 2.0 source/host port with CC Rp, ESD and a controlled VBUS
   switch. Default its VBUS output off during start-up.
4. Keep HDMI J1 in the reference corridor while retaining DDC, CEC, HPD and protected +5 V.
5. Calculate worst-case input demand: PD/load-path and buck loss, CPU/GPU transient,
   DRAM, eMMC, HDMI, the advertised USB load and cable/connector loss.

Evidence / pass criteria:

- ERC-clean schematic with every no-connect intentional and documented.
- Reviewed power tree and regulator sequencing table.
- Power budget has at least the agreed engineering margin at minimum input voltage.
- Bench coupon passes 5 V-to-9 V PD negotiation, input start-up, rated load, invalid
  source, short circuit, reverse-current and host-switch tests.
- Independent schematic review closes every boot/power/high-speed finding.

## Gate 3 - exact parts and assembly route

Work:

1. Replace every family/TBD entry with manufacturer, exact MPN, package, lifecycle,
   moisture sensitivity, source and approved alternates.
2. Assign a JLC/LCSC part number where available. For unavailable SoC, PMIC, DRAM,
   eMMC or connectors, choose Pre-Order, Global Sourcing or consignment and wait until
   inventory appears in the account before placing the PCBA order.
3. Send JLCPCB the proposed stack-up/fanout and ask for written confirmation covering:
   BGA664 0.5 mm pitch, FBGA200, FBGA153, via-in-pad fill/cap, board thickness,
   controlled impedance, connector edge placement, X-ray inspection and acceptable
   paste/assembly class.
4. Buy enough critical parts for prototypes plus rework/process attrition from one lot.

Evidence / pass criteria:

- BOM has exact MPN and JLC/LCSC or consignment route for every fitted item.
- No generic automatic substitution for SoC, PMIC, DRAM, eMMC, crystals or connectors.
- All non-library parts are received into the JLCPCB parts inventory before ordering.
- Written DFM/assembly response confirms the proposed fine-pitch process, or the board
  is revised to the process they approve.

## Gate 4 - stack-up and constraint lock

Work:

1. Select one current JLCPCB 8-layer stack-up in their impedance calculator.
2. Record material, finished thickness, copper weight, dielectric thickness, soldermask
   assumptions and calculated geometries for 50-ohm single-ended, 90-ohm USB and
   100-ohm HDMI traces.
3. Port the reference DRAM and eMMC constraints into named net classes. Record each
   target, tolerance, reference plane and permitted via structure.
4. Define filled/capped via drill diameter(s) and create a via-fill map.

Evidence / pass criteria:

- Approved stack-up drawing and impedance table are part of the fab notes.
- CAD net classes cover every DRAM, eMMC, HDMI, USB and clock net.
- JLCPCB confirms the selected via structure before the BGA escape is frozen.

## Gate 5 - production layout

Work order:

1. Fix outline, holes, connector datums and keep-outs from Gate 0.
2. Place/import SoC, LPDDR4, eMMC, AXP717/AXP323, crystals and critical decoupling.
3. Route DRAM from the reference template, then eMMC.
4. Preserve the existing HDMI corridor; route the single external USB host pair,
   clocks and sensitive analog nets.
5. Route the local USB-C PD-to-`DCIN-12V` path, PMIC switch nodes and high-current 5 V
   paths; finish planes and low-speed I/O.
6. Add test access for input current, every major rail, PMIC bus, reset, UART and FEL
   without stubbing high-speed nets.
7. Complete silkscreen polarity/pin-1 marks, assembly fiducials and serial/revision ID.

Evidence / pass criteria:

- DRC has zero errors and no undocumented waivers.
- Reference-core PCB diff explains every changed object.
- SI review passes DRAM, eMMC, HDMI and USB; PI review passes planes and transient paths.
- 3D collision review passes connectors, heatsink, enclosure and both plug types.
- Thermal estimate defines heatsink/interface material and test limits.

## Gate 6 - release review and manufacturing outputs

Run four independent checklists:

1. **Electrical:** schematic-to-PCB netlist, power pin types, straps, PMIC sequence,
   pull-ups, connector pin numbers, ESD orientation and all differential-pair polarity.
2. **PCB:** stack-up, impedance classes, return paths, via-fill map, soldermask dams,
   paste apertures, fiducials, tooling assumptions and copper-to-edge.
3. **BOM/assembly:** value/MPN/footprint match, unique designators, fitted/DNP status,
   polarity, pin 1, rotations and top/bottom side.
4. **Mechanical:** outline and slots, mounting hole plating, connector shell/overhang,
   heights and heatsink contact pressure.

Release package:

- Gerber X2 or JLC-compatible Gerbers for every copper, mask, paste, silk and outline
  layer; Excellon plated/non-plated drill files and drill map.
- Fabrication drawing/notes with revision, dimensions, stack-up, impedance table,
  surface finish, copper weights, finished thickness, tolerances and via-fill callout.
- JLC-formatted BOM and CPL/centroid with exactly matching, case-consistent designators.
- Assembly drawings for both sides, paste layers, polarity/pin-1 document and DNP list.
- STEP model, dimensioned mechanical drawing and via-fill highlight drawing.
- Source archive, schematic PDF, netlist, ERC/DRC reports, review sign-off and bring-up
  test plan.
- Firmware package for initial FEL/UART/DRAM testing plus programming instructions for
  blank eMMC; do not ship licensed retail game data to the assembler.

Evidence / pass criteria:

- A fresh checkout can regenerate all outputs with matching hashes.
- Gerber/drill viewer shows correct outline, holes, layers, apertures and no stray data.
- BOM and CPL upload with no missing, repeated or mismatched fitted designators.
- Two people complete the release checklists from the generated files, not the editor.

## Gate 7 - JLCPCB upload preflight and prototype order

1. Upload as a **Standard PCBA** quote and select the exact approved stack-up, impedance,
   ENIG and filled/capped via options.
2. Manually verify every automatically matched part against MPN, package and footprint.
3. Inspect online PCB/assembly previews, rotations and pin-1 markers for every IC,
   connector, diode and polarized capacitor.
4. Attach the via-fill drawing and order notes. Select **Confirm production files** so
   the CAM output can be checked before manufacture.
5. Resolve every engineering question in writing and archive the final production files.
6. Order a small engineering lot: five bare PCBs and two or three assembled boards is a
   sensible first pass; retain unassembled boards for sectioning/rework if needed.

Release is complete only after JLCPCB accepts the files, critical parts are allocated,
the final CAM files match the release package and the order is explicitly approved.

## Gate 8 - first article, not production

- Photograph and microscope-inspect both sides before power.
- Obtain X-ray images for the three BGAs and review voiding/opens/bridges.
- Execute `bring-up.md` in order with a current-limited supply.
- Record rework, schematic/layout corrections and test evidence in a Rev-B issue list.
- Do not order volume until all prototypes pass power, DRAM, storage, HDMI, simultaneous
  USB load, thermal and software-port soak tests.

## Current blockers

- Exact orderable T527/A527, LPDDR4 and eMMC MPNs are not selected.
- The 9 V / 3 A USB-C PD contract, power margin and invalid-source behavior are not yet
  calculated or bench-proven.
- Selected connector footprints still need manufacturer-drawing and enclosure-datum verification.
- JLCPCB has not reviewed the BGA/via-in-pad/edge-connector process for this design.
- The imported Avaota source still needs rule normalization and subsystem pruning.

## JLCPCB source notes

The manufacturing gates above follow the current official guidance:

- [JLCPCB impedance calculator](https://jlcpcb.com/help/article/user-guide-to-the-jlcpcb-impedance-calculator) supports controlled calculations for current 4- to 8-layer stack-ups and requires the selected material/stack-up to match the calculation.
- [Via covering guidance](https://jlcpcb.com/help/article/pcb-via-covering) identifies epoxy-filled and capped vias as suitable for via-in-pad/BGA use and recommends a fill drawing plus production-file confirmation.
- [BOM/CPL preparation guidance](https://jlcpcb.com/help/article/advice-for-bom-and-cpl-files-preparation) requires exact, case-consistent reference matching and accurate selected parts.
- [Component sourcing guidance](https://jlcpcb.com/help/article/how-to-use-my-own-parts-for-pcb-assembly-order) covers pre-ordered, globally sourced and consigned parts held in the customer's parts library.
- [Assembly terms](https://jlcpcb.com/help/article/terms-and-conditions-of-jlcpcb-assembly-service) require manual verification of automatically matched parts and document normal footprint/placement constraints; the intentional edge connectors therefore need explicit approval.
