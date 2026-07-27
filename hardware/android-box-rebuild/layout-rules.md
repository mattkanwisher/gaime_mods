# Layout and fabrication rules

## Stack-up

Start with the pinned Avaota A1 8-layer LPDDR4 template. Before routing, select a
specific JLCPCB 8-layer controlled-impedance stack-up and record its material,
dielectrics and finished copper values. Generate rather than guess the 50-ohm
single-ended and 90/100-ohm differential geometries.

Provisional functional stack:

1. L1 - components and short high-speed fanout
2. L2 - solid ground
3. L3 - high-speed signals / LPDDR byte lanes
4. L4 - power planes
5. L5 - power planes / low-speed signals
6. L6 - high-speed signals / LPDDR address-command
7. L7 - solid ground
8. L8 - components and low-speed fanout

## Placement order

1. Fix outline, mounting holes and measured connector datums for the same-edge row:
   USB-C PD power in the barrel corridor, one USB-C host in the dual USB-A corridor,
   and horizontal HDMI in its reference corridor.
2. Preserve the Avaota SoC/LPDDR placement, orientation, escape and layer assignment.
3. Preserve eMMC, AXP717, AXP323, crystal and critical-decoupling relationships.
4. Place the PD sink/protection near J5 and the host load switch near J6.
5. Place ESD at the connector side of each protected interface.
6. Keep all PMIC switch nodes outside the LPDDR, HDMI, USB and clock corridors.

## Routing priority

1. LPDDR4 data/strobe byte lanes and address/command/clock, copied from the template.
2. eMMC HS400 clock/strobe/data.
3. Preserve the existing HDMI TMDS plus DDC/CEC/HPD routing.
4. The single external USB 2.0 differential pair.
5. Crystals and analog reference rails.
6. PMIC feedback, switch nodes and high-current input/host power.
7. Remaining control and GPIO.

## Hard constraints

- No split reference plane under LPDDR4, eMMC, HDMI, USB or clocks.
- HDMI is 100 ohms differential; USB 2.0 is 90 ohms differential. Values must be
  solved for the ordered stack-up and included in the fab notes.
- Do not alter DRAM topology, lane grouping, termination or match targets without an
  Allwinner/Avaota design-rule source and an SI review.
- Via-in-pad beneath BGA/FBGA parts must be epoxy-filled and copper-capped; upload a
  via-fill drawing and select production-file confirmation.
- Put a ground return via beside every high-speed signal layer transition.
- Connector bodies may intentionally meet/overhang the edge; obtain written JLCPCB
  assembly approval for those exceptions before the order.
- Decoupling placement and via count are circuit requirements.
- The Rev-P1 KiCad project contains the converted Avaota routed board. Imported
  footprints and constraints are reference data only until their dimensions, drill
  classes, courtyards and assembly availability have been normalized.

## Review gates

- Independent schematic review before layout.
- JLCPCB fabrication and assembly capability review before fanout/stack-up lock.
- SI review of LPDDR4, eMMC, HDMI and USB before release.
- Power-integrity review with peak/transient current and voltage-drop estimates.
- ERC, DRC, netlist-to-layout, BOM-to-footprint, polarity and pin-1 checks with no
  unresolved boot-critical waivers.
