# T527 M.2 2230 NVMe migration

## Decision

Use an M-key M.2 2230 **NVMe** module, not M.2 SATA. Allwinner specifies the T527
with a PCIe 2.1/USB 3.1 combo interface, and Radxa demonstrates an A527/T527-family
implementation with an M-key 2230 NVMe socket. The interface is a combo PHY, so the
same high-speed pins cannot provide USB 3 and PCIe simultaneously. This board only
needs a USB 2.0 Type-C host, so dedicating the combo PHY to PCIe is compatible with
the requested external I/O.

Primary references:

- [Allwinner T527 product page](https://www.allwinnertech.com/index.php?a=index&c=product&id=110)
- [Radxa Cubie A5E product brief](https://dl.radxa.com/cubie/a5e/radxa_cubie_a5e_product_brief.pdf)
- [Radxa Cubie A5E v1.2 schematic](https://dl.radxa.com/cubie/a5e/docs/hw/v1.2/radxa_cubie_a5e_schematic_v1.2_20250113.pdf), M.2/USB3 implementation on page 14
- [JLCPCB/LCSC C601195](https://jlcpcb.com/partdetail/UMAX-91302_42067RDM/C601195), UMAX `91302-42-067RDM`

## PCB checkpoint implemented

- J7: UMAX `91302-42-067RDM`, M-key 67-pin, 4.2 mm height, placed at
  `(184.5, 122.0) mm`, rotation `90 deg`.
- H2: 2.8 mm NPTH mounting datum at `(154.5, 122.0) mm` for a 2230 module.
- Module envelope: 30 x 22 mm, extending left from J7, drawn on `Dwgs.User`.
- Both imported GMAC PHY/support populations are removed from the PCB. The schematic
  sheets are intentionally retained until the replacement PCIe sheet is authored.
- The adjacent IR receiver and its route are retained.
- Project-local KiCad symbol, footprint and 3D model live under `libs/` and are
  registered by `sym-lib-table` and `fp-lib-table`.

## J7 pad assignment

| M.2 pin(s) | Function | Staged PCB net | Status |
|---|---|---|---|
| 41 / 43 | PERn0 / PERp0 | `USB2-RXN` / `USB2-RXP` | Assigned, unrouted to J7 |
| 47 / 49 | PETn0 / PETp0 | `$6N19249` / `$6N19248` | Assigned after existing C219/C220 AC coupling, unrouted to J7 |
| 53 / 55 | REFCLKn / REFCLKp | `PCIE_REFCLK_N` / `PCIE_REFCLK_P` | New nets, unrouted |
| 50 | PERST# | `PCIE_PERST_N` | New net, unrouted |
| 52 | CLKREQ# | `PCIE_CLKREQ_N` | New net, unrouted |
| 54 | WAKE# | `PCIE_WAKE_N` | New net, unrouted |
| 10 | DAS/DSS# | `NVME_DAS_DSS_N` | Optional new net, unrouted |
| 2, 4, 12, 14, 16, 18, 70, 72, 74 | 3.3 V | `NVME_3V3_SW` | New net, no regulator yet |
| 1, 3, 9, 15, 21, 27, 33, 39, 45, 51, 57, 71, 73, 75, 76 | Ground/shell | `GND` | Assigned |

All other M.2 pins are intentionally unconnected in this PCIe x1-only staging pass.
The imported `$6N...` names must be replaced with readable schematic net names when
the PCIe sheet is synchronized.

## Electrical work still required

1. Replace the two GMAC schematic sheets with a reviewed PCIe/M.2 sheet and synchronize
   it with the PCB. Until that happens, J7 exists only on the PCB.
2. Reconfigure the T527 combo PHY from USB3 to PCIe. In the Avaota USB3 baseline the
   PCIe reference-clock balls B21/C21 are tied to ground; disconnect those ties and
   route the actual differential reference clock to J7 pins 55/53.
3. Select legal T527 GPIO/mux assignments for PERST#, CLKREQ# and WAKE#. Verify reset,
   power-good and clock timing against both the SoC documentation and selected SSD.
4. Add a dedicated, sequenced `NVME_3V3_SW` supply with current limit, controlled
   discharge, local bulk/ceramic decoupling and enough inrush/peak-current margin for
   the approved SSD. Do not reuse `DCDC4` without a full rail-load audit.
5. Review D15 and all remaining combo-lane protection/coupling parts for PCIe Gen2
   bandwidth and capacitance. Keep the host-TX AC capacitors in the correct location.
6. Route the x1 lane and 100 MHz reference clock as controlled-impedance differential
   pairs using the released JLCPCB eight-layer stack-up. Set the actual 85 ohm geometry,
   length/skew limits, return-path stitching and layer transitions before routing.
7. Add the PCIe controller/PHY, regulator and GPIO descriptions to the bootloader and
   device tree, then validate link training at Gen1 before enabling Gen2.
8. Confirm connector insertion direction, SSD top/bottom component height, standoff
   hardware, screw access and enclosure clearance from manufacturer drawings and a
   physical 2230 module.

## Release gate

Do not order this revision for assembly merely because J7 is visible in KiCad. It is
ready for mechanical review and schematic capture only. Fabrication requires a
synchronized schematic, powered/routed J7, stack-up-specific PCIe constraints, ERC,
DRC with no unexplained errors, and a reviewed JLCPCB fabrication/assembly package.
