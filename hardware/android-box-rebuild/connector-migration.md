# Same-edge connector migration work package

Rev-P1 keeps the three required external ports on the Avaota reference connector edge
to avoid rerouting the SoC-side HDMI and crossing the LPDDR/core region.

## Target row and reuse strategy

| Target ref | Target function | Reference corridor reused | Electrical action |
|---|---|---|---|
| `J5` | USB-C PD power input | Barrel `DC1`, origin `(109.6545, 136.8555) mm` | Negotiate 9 V / 3 A and feed the existing protected `DCIN-12V` input |
| `J6` | One USB 2.0 Type-C host | Dual USB-A `USB2`, origin `(126.114, 134.970) mm` | Reuse `USB1-DP/DM`; add CC Rp, ESD and a controlled 5 V VBUS switch |
| `J1` | Horizontal right-angle HDMI Type-A | HDMI `USB1`, origin `(140.124, 132.247) mm`, rotation `-90 deg` | Keep connector corridor and existing HDMI routing |

The intended left-to-right row in the current board view is power USB-C, host USB-C,
then HDMI. The coordinates are imported footprint origins, not final shell centerlines.

The original `USB3` USB-C on the opposite edge will be removed from the production
variant. USB0 FEL/device recovery remains available on internal test pads. The second
USB 2.0 host and the USB SuperSpeed lanes are not externally populated.

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
- `STUSB4500QTR` (JLCPCB/LCSC `C2678061`) is the current Rev-P1 PD-controller
  candidate because it supports standalone sink negotiation and configurable sink
  PDOs. Program the Rev-P1 candidate for 9 V / 3 A. Its NVM configuration and external
  power-path implementation still require a reviewed schematic and startup test.
- The imported reverse-polarity MOSFET is only rated 15 V, so a 15 V contract is not
  acceptable without replacing that stage. Nine volts preserves useful margin and the
  existing TPS54531 can regulate the system 5 V rail from it.
- Select the exact protection device and USB-C receptacle only after checking their
  voltage/current ratings, startup state and JLCPCB assembly status.

## USB-C host conversion

- Replace the dual USB-A footprint with one USB 2.0-only Type-C receptacle.
- Use `USB1-DP/DM`, which already routes into this connector corridor.
- Tie A6/B6 together to D+ and A7/B7 together to D- at the receptacle.
- Add independent Rp resistors on CC1/CC2, connector-side low-capacitance ESD and a
  current-limited, discharge-capable 5 V VBUS switch.
- Do not fit SuperSpeed pins or an orientation mux in Rev-P1; this avoids unnecessary
  high-speed rerouting.

## HDMI

Keep the existing full-size right-angle Type-A HDMI position and orientation. Validate
the selected connector against the footprint, but preserve the existing TMDS, DDC,
CEC, HPD, +5 V and ESD routing unless the connector pinout forces a local change.

## Implementation order

1. Freeze the three shell centerlines and panel openings from the enclosure drawing.
2. Validate the selected XUNPU `TYPEC-304-BCP16` USB-C and `HDMI-001C` HDMI drawings
   against the imported footprints and measured enclosure.
3. Replace DC1 with the PD sink/protection block and connect it locally to the existing
   `DCIN-12V` entry.
4. Replace USB2 with J6 and reconnect only `USB1-DP/DM` plus its local VBUS circuitry.
5. Remove USB3 and unused edge connectors/peripherals one subsystem at a time.
6. Refill zones and compare ERC/DRC against the zero-short, valid-outline import
   baseline after every subsystem change.

## Blockers before footprint replacement

- Verified manufacturer drawings and enclosure fit for the selected connectors.
- Enclosure shell centerlines, panel openings, wall thickness and plug keepouts.
- Exact 9 V USB PD sink/protection implementation and power-budget proof.
- JLCPCB eight-layer stack-up and manufacturing rule normalization.
