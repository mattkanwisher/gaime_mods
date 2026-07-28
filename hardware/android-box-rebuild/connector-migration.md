# Same-edge connector migration work package

Rev-P1 keeps the three required external ports on the Avaota reference connector edge
to avoid rerouting the SoC-side HDMI and crossing the LPDDR/core region.

## Target row and reuse strategy

| Target ref | Target function | Reference corridor reused | Electrical action |
|---|---|---|---|
| `J5` | USB-C PD power input | Barrel `DC1`, origin `(109.6545, 136.8555) mm` | Negotiate 9 V / 3 A and feed the existing protected `DCIN-12V` input |
| `J6` | One USB 2.0 Type-C host | Dual USB-A `USB2`, origin `(126.114, 134.970) mm` | Reuse `USB1-DP/DM`; add CC Rp, ESD and a controlled 5 V VBUS switch |
| `USB1` | Horizontal right-angle HDMI Type-A | Imported HDMI origin `(140.124, 132.247) mm`, rotation `-90 deg` | Replace with horizontal edge footprint and reroute HDMI locally |

The left-to-right row in the current board view is now staged as power USB-C, host
USB-C, then HDMI. J5 is at `(109.6545, 139.6495) mm`, J6 is at
`(126.114, 139.6495) mm`, and horizontal HDMI `USB1` is at
`(140.124, 135.455) mm`, rotation `0 deg`. These are footprint origins, not shell
centerlines. The USB-C origins are
3.9055 mm inboard of the bottom Edge.Cuts centerline and the modeled shell fronts
extend 1.267 mm beyond it, mirroring the original USB3 connector's edge engagement.

The original `USB3` USB-C on the opposite edge has been removed from this placement
variant. USB0 FEL/device recovery remains available on internal test pads. The second
USB 2.0 host and the USB SuperSpeed lanes are not externally populated. U15, the
separate internal eDP/DisplayPort panel connector marked `DP`, and its connector-side
lane/AUX/HPD circuit have also been removed; this does not affect HDMI USB1.

## Power conversion: barrel to USB-C

The imported barrel path is:

```text
DC1 -> reverse/protection stage Q1/D2 -> DCIN-12V -> TPS54531 buck -> system 5 V
```

The lowest-reroute conversion is therefore:

```text
USB-C VBUS + CC1/CC2 -> autonomous PD sink requesting 9 V / 3 A
                     -> OVP/UVLO/eFuse or protected load switch
                     -> existing Q1/D2 and DCIN-12V copper
```

- The power connector is power-only; D+/D- and SBU are absent or left unconnected.
- Do not connect raw default 5 V directly to `DCIN-12V` and hope the board starts.
  Enable the load path only after a valid 9 V contract.
- Retain the existing TPS54531, inductor, output capacitors and downstream 5 V planes.
- `STUSB4500QTR` U1001 (JLCPCB/LCSC `C2678061`) is the selected standalone sink.
  Program `SNK_PDO_NUMB=2`, PDO2 for 9 V / 3 A, and `POWER_ONLY_ABOVE_5V=1` before
  bring-up. SCL, SDA, 2.7 V and GND programming pads are included.
- `TPS259470LRPWR` U1002 (JLCPCB/LCSC `C3662793`) is the selected protected load
  path. A 499 k/100 k UVLO divider enables near 7.19 V, an 806 k/100 k OVLO divider
  trips near 10.87 V, and 1.00 k on ILM sets about 3.33 A nominal current limit.
- `POWER_OK2` and Q1001 form a second enable condition: U1002 remains disabled until
  the programmed PDO2 contract is active. Thus default 5 V is rejected by both the
  PDO gate and UVLO, while 12/15/20 V are rejected by the PDO gate and OVLO.
- The imported reverse-polarity MOSFET is only rated 15 V, so a 15 V contract is not
  acceptable without replacing that stage. Nine volts preserves useful margin and the
  existing TPS54531 can regulate the system 5 V rail from it.
- J5 is the selected XUNPU `TYPEC-304-BCP16` / JLCPCB `C720629`. The CC TVS MPN is
  provisionally `PESD24VL1BA`; assign its JLC/LCSC AVL entry before BOM freeze.

## USB-C host conversion

- Replace the dual USB-A footprint with one USB 2.0-only Type-C receptacle.
- Use `USB1-DP/DM`, which already routes into this connector corridor.
- Tie A6/B6 together to D+ and A7/B7 together to D- at the receptacle.
- Add independent Rp resistors on CC1/CC2, connector-side low-capacitance ESD and a
  current-limited, discharge-capable 5 V VBUS switch.
- Do not fit SuperSpeed pins or an orientation mux in Rev-P1; this avoids unnecessary
  high-speed rerouting.

## HDMI

The imported `HDMI-001C` footprint had its 19-pin row vertical in board view. It is now
replaced by the selected HCTL `HDMI-01` / JLCPCB `C2906135` horizontal right-angle
Type-A receptacle at `(140.124, 135.455) mm`, rotation `0 deg`. The shell face is flush
with the bottom Edge.Cuts datum and the footprint courtyard has 1.415 mm clearance to
J6. Pads 1-19 retain the imported HDMI nets; shell stakes 20-23 and HDMI ground pins
use solid ground-plane connections.

The four TMDS pairs are locally rejoined to the preserved Avaota routing corridor.
The added positive and negative paths are matched to within 0.0001 mm by geometry;
CEC, DDC clock/data, HPD and +5 V are also connected. KiCad DRC reports no short and
no unconnected item in the HDMI area. The 0.102 mm signal width remains provisional:
the completed route must be recalculated for 100-ohm differential impedance once the
JLCPCB eight-layer stack-up is selected.

## Implementation order

1. Freeze the three shell centerlines and panel openings from the enclosure drawing.
2. Validate the selected XUNPU `TYPEC-304-BCP16` USB-C and HCTL `HDMI-01` drawings
   against their footprints and the measured enclosure.
3. Complete the remaining U1001/U1002 control-passive fanout behind J5. The exact J5,
   U1001/U1002, CC TVS and connector-critical `PD_VBUS_RAW`/`PD_9V_PROTECTED` routes
   into the existing protected input corridor are already placed and connected.
4. Add the CC, ESD and switched-VBUS circuitry behind staged J6, then reconnect
   `USB1-DP/DM` locally.
5. Remove other unused edge connectors/peripherals one subsystem at a time. The
   external eDP interface has completed this PCB prune step.
6. Refill zones and compare ERC/DRC against the zero-short, valid-outline import
   baseline after every subsystem change.

## Placement-pass status and blockers

The PCB placement pass is implemented reproducibly by
`scripts/stage_same_edge_connectors.py`. It removed DC1, USB2 and USB3 plus 155 local
fanout track/via items, duplicated the imported TYPEC-304-BCP16 footprint as J5/J6,
renamed the edge silkscreen to POWER/HOST and refilled zones. The script now derives
the J5/J6 Y datum by mirroring the original USB3 edge inset; the standalone
`scripts/align_usbc_to_edge.py` applies the same correction to an already-staged board.
The separate `scripts/add_usbc_pd_power.py` supplies the matching schematic hierarchy.
`scripts/route_usbc_pd_power.py` replaces J5 with the exact C720629 footprint, places
U1001/U1002 and the connector-critical capacitors/TVS parts, and routes both CC nets,
the raw VBUS trunk, protected output and existing D2/Q1 handoff. The focused
`scripts/check_j5_local.py` check confirms the expected critical pad connectivity and
no copper pair below 0.20 mm on the five local layers it inspects. The control
resistors, small regulator capacitors, Q1001 and programming pads remain to be placed
and routed around inherited FPC1 copper.

`scripts/replace_hdmi_horizontal.py` replaces the imported side-oriented HDMI with the
exact HCTL `HDMI-01` footprint, preserves its net assignments, removes conflicting
local copper and sets the ground pins to solid zone connections. The companion
`scripts/route_hdmi_local.py` reconnects TMDS, CEC, DDC, HPD and +5 V to the preserved
corridor. The production part is selected; enclosure fit and stack-up impedance remain
release gates.

- Verified manufacturer drawings and enclosure fit for the selected connectors.
- Enclosure shell centerlines, panel openings, wall thickness and plug keepouts.
- PCB placement/routing for the remaining PD/eFuse control-passive fanout and a
  stack-up/current-density review of the routed 9 V trunks.
- Frozen STUSB4500 NVM image, production programming method and read-back record.
- CC TVS JLC/LCSC selection, power-budget proof and bench validation.
- JLCPCB eight-layer stack-up and manufacturing rule normalization.
