# M.2 NVMe implementation audit — 2026-07-29

## Result

**Mechanical/net-assignment staging passes; the electrical implementation fails.**

J7 is not currently a working NVMe port. It is a correctly oriented M-key connector
with a plausible M.2 2230 datum and the intended PCIe x1 pad names, but it has no
matching schematic sheet, no 3.3 V supply and no routed clock/control/PCIe connection
to the connector.

## Which side is it on?

J7 is on `F.Cu` at `(184.5, 122.0) mm`, rotated 90 degrees. H2 is also on `F.Cu`
at `(154.5, 122.0) mm`, exactly 30.0 mm from the connector datum. The module extends
left from J7 over the 30 x 22 mm `Dwgs.User` envelope.

That is the **top/component side—the same visible side as the ON/RESET/FEL buttons**
in `renders/pcb-top.png`. So if “button side” meant the face carrying those buttons,
the placement is already on that side. It is not bottom-mounted.

## Pin-assignment verification

The staged pin mapping is appropriate for a PCIe x1 M-key socket:

| Path | SoC/board side | J7 pins | Audit |
|---|---|---:|---|
| Host receive | combo-PHY RX `USB2-RXN/RXP` | PERn/p 41/43 | Pass assignment; unrouted to J7 |
| Host transmit | post-C219/C220 combo-PHY TX nets | PETn/p 47/49 | Pass assignment and AC-cap direction; unrouted to J7 |
| 100 MHz clock | `PCIE_REFCLK_N/P` | 53/55 | Correct pins; zero copper items |
| Reset | `PCIE_PERST_N` | 50 | Correct pin; zero copper items |
| Clock request | `PCIE_CLKREQ_N` | 52 | Correct pin; zero copper items |
| Wake | `PCIE_WAKE_N` | 54 | Correct pin; zero copper items |
| SSD power | `NVME_3V3_SW` | 2/4/12/14/16/18/70/72/74 | Correct pins; zero copper items and no regulator |
| Ground/shell | GND pins and shell | 1/3/9/15/21/27/33/39/45/51/57/71/73/75/76 | Assigned, but DRC reports unconnected J7 ground pads |

The direction is important: the host's receive pair goes to the module's PER pair,
and the host's transmit pair goes to PET. The existing TX coupling capacitors are
therefore on the correct logical path, although their PCIe bandwidth/package/layout
still require review.

## Electrical blockers

1. No schematic contains an M.2 connector reference or the new PCIe/NVMe net names;
   J7 exists only in the PCB file.
2. The source Avaota USB3 configuration ties the T527 PCIe reference-clock balls
   B21/C21 to ground. Those connections must be removed in a reviewed PCIe schematic.
3. `PCIE_REFCLK_P/N`, `PCIE_PERST_N`, `PCIE_CLKREQ_N`, `PCIE_WAKE_N` and
   `NVME_3V3_SW` each have zero PCB copper items.
4. No legal T527 mux/GPIO selections, pull-ups or clock/reset/power sequencing have
   been implemented.
5. There is no current-limited, discharge-controlled, sequenced 3.3 V SSD supply or
   local bulk/ceramic decoupling.
6. The combo-PHY lane is still named/routed as USB3-era copper, is not connected to
   J7 and has not been validated at PCIe Gen2 85-ohm differential impedance.
7. Complete-board DRC is failing, including unconnected J7 pads, so layout
   connectivity has not passed.

## Repeatable staging check

Run:

```sh
/Applications/KiCad/KiCad.app/Contents/Frameworks/Python.framework/Versions/3.9/bin/python3.9 \
  hardware/android-box-rebuild/scripts/check_nvme_staging.py
```

This validates the side, position, 30 mm 2230 datum and staged pad-net mapping. It
does not certify the missing electrical design.

## How to verify the completed port

### Before fabrication

1. Author and peer-review the PCIe/M.2 schematic against the T527 pin/mux data and
   the Radxa A527/T527-family reference implementation.
2. Synchronize schematic to PCB, then run ERC plus a netlist comparison proving that
   every J7 power, ground, lane, clock and control pin is accounted for.
3. Verify 3.3 V regulator current limit, inrush, discharge and sequencing with the
   chosen SSD's worst-case values; simulate or calculate rail droop and thermal loss.
4. Route the x1 lane and clock with the released 85-ohm stack geometry, continuous
   ground reference, return vias at transitions, TX capacitors in the reviewed
   location and explicit length/skew constraints.
5. Run complete-board DRC to zero unexplained errors and perform a PCIe Gen2 SI review.
6. Confirm the UMAX connector courtyard, insertion direction, SSD component height,
   standoff/screw access and enclosure volume from the manufacturer drawing and a
   physical 2230 sample.

### On first hardware

1. Populate no SSD initially; verify 3.3 V-off leakage, then enable timing, voltage,
   current limit, discharge and ripple with an oscilloscope/electronic load.
2. Insert a known-good, low-power 2230 NVMe device and train the link at PCIe Gen1.
   Confirm PERST#, REFCLK and CLKREQ# timing with probes suitable for the signals.
3. Check the Linux PCIe root port and endpoint enumeration (`lspci -vv`), AER counters,
   negotiated width/speed and repeated cold/warm reset behavior.
4. Enable Gen2, repeat error-counter/reset testing, then run sustained read/write,
   random I/O, power-cycle and thermal-soak tests while monitoring the 3.3 V rail.

Primary design references remain the [Allwinner T527 product page](https://www.allwinnertech.com/index.php?a=index&c=product&id=110),
the [Radxa Cubie A5E v1.2 schematic](https://dl.radxa.com/cubie/a5e/docs/hw/v1.2/radxa_cubie_a5e_schematic_v1.2_20250113.pdf)
and the [UMAX/JLCPCB C601195 connector listing](https://jlcpcb.com/partdetail/UMAX-91302_42067RDM/C601195).

## Release decision

Keep the current top-side location if it fits the enclosure; there is no electrical
reason to move it to the bottom. Do not order the board with J7 populated until all
electrical blockers above are closed.
