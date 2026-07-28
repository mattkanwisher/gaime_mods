# Stack-up and controlled-impedance validation — 2026-07-29

## Result

**FAIL — no final stack-up or impedance geometry is encoded in the board.**

The PCB declares eight copper layers and a nominal finished thickness of 1.6 mm,
but its KiCad `setup` contains no physical stack-up: there are no dielectric
thicknesses, material names, dielectric constants, loss tangents or finished copper
thicknesses. All eight copper layers are also declared as `signal`; the GND/VCC
roles currently exist only in layer display names and documentation.

Consequently, none of the existing HDMI, USB or future PCIe routes can be certified
as 100/90/85-ohm differential pairs from this file.

## Current layer declaration

| KiCad layer | Display name | Intended function | Validation issue |
|---|---|---|---|
| F.Cu / L1 | Top Layer | Components / high-speed fanout | No dielectric or impedance model |
| In1.Cu / L2 | GND1 | Solid ground | Declared signal; USB1 routes also use it |
| In2.Cu / L3 | 内层2 | High-speed signal | No upper/lower reference definition |
| In3.Cu / L4 | VCC | Power | Declared signal; new control routes use it |
| In4.Cu / L5 | 内层4 | Power / low speed | HDMI routes use it without a defined reference |
| In5.Cu / L6 | Inner5 | High-speed signal | No upper/lower reference definition |
| In6.Cu / L7 | GND2 | Solid ground | Declared signal; host VBUS routing uses it |
| B.Cu / L8 | Bottom Layer | Components / low speed | No dielectric or impedance model |

The L2 and L7 observations are release blockers: a layer intended to be a continuous
reference plane cannot also carry ordinary signal or power traces through the
high-speed return-current corridor.

## Existing high-speed width audit

This is only a width inventory; without dielectric heights and pair spacing it is
not an impedance calculation.

| Interface | Nets | Observed widths / layers | Status |
|---|---|---|---|
| HDMI TMDS | `HTX0/1/2/CP/CN` | 0.076, 0.1015 and 0.102 mm on L1; 0.1015 mm on L5 | Not validated; 0.076 mm is below JLCPCB's published 0.09 mm standard minimum for 4+ layer 0.5/1 oz boards |
| J6 USB 2 | `USB1-DP/DM` | 0.1015–0.15 mm across L1, L2, L3/L4 and L8 | Not validated; too many reference/layer transitions and use of intended GND layer |
| Combo PHY / staged PCIe lane | `USB2-RX/TX*` and anonymous TX nets | 0.076–0.127 mm on L1/L8 | Not PCIe-routed to J7 and not validated |
| PCIe reference clock | `PCIE_REFCLK_P/N` | No tracks | Missing |

## Fabricator basis checked

The candidate fabrication family is JLCPCB's 8-layer, 1.6 mm controlled-impedance
process. JLCPCB's current documentation says:

- its calculator supports 4–8 layer construction using Nan Ya NP-155F material;
- finished 1 oz outer copper is modeled as 1.6 mil and 0.5 oz inner copper as
  0.6 mil;
- the selected reference layer must actually contain a ground plane;
- differential width is calculated from the selected production stack and entered
  conductor spacing; and
- the standard published minimum trace/space for 4+ layer 0.5/1 oz construction is
  0.09 mm (3.5 mil), with 0.076 mm (3 mil) treated as an extra-cost capability.

Primary references:

- [JLCPCB impedance-calculator guide](https://jlcpcb.com/help/article/user-guide-to-the-jlcpcb-impedance-calculator)
- [JLCPCB multilayer laminated structures](https://jlcpcb.com/help/article/multi-layer-pcb-standard-laminated-structures)
- [JLCPCB copper-weight and minimum trace/space guide](https://jlcpcb.com/help/article/jlcpcb-copper-weight)
- [JLCPCB controlled-impedance calculator](https://jlcpcb.com/pcb-impedance-calculator)

JLCPCB describes `JLC08161H-3313` as a standard 8-layer, 1.6 mm functional stack,
but the exact order-time laminate construction and calculator result still need to
be captured before it is placed into KiCad. A family name alone is not enough to
approve trace geometry.

## Required closure sequence

1. Confirm the exact orderable 8-layer, 1.6 mm JLCPCB stack with the fabricator,
   including every dielectric thickness/Dk, copper thickness and finished tolerance.
2. Enter that physical construction into KiCad and make L2/L7 continuous GND planes.
   Reassign L4/L5 power-versus-signal functions to a symmetric, reviewed buildup.
3. Calculate and record at least 50-ohm single-ended plus 90-ohm USB, 100-ohm HDMI
   and 85-ohm PCIe differential geometries for each routing layer actually used.
4. Create KiCad net classes/custom rules for the resulting width, gap, clearance,
   via and skew limits.
5. Reroute HDMI, USB and PCIe so every segment has a continuous reference return,
   then perform field-solver/SI review and request controlled-impedance coupons in
   the fabrication notes.

No impedance target is approved by this audit.
