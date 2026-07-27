# Electrical architecture

## Functional chain

```text
same-edge USB-C PD power (9 V / 3 A negotiated; no data)
        |
        +--> TVS / eFuse / reverse-current protection --> existing 12 V-to-5 V buck
        |                                                +--> system, DRAM and I/O rails
        |                                                +--> eMMC / HDMI support rails
        |
        +-----------------------------------------------> AXP323
                                                         +--> CPU-B / DNR rails

24 MHz + 32.768 kHz --> T527/A527 --> LPDDR4 (2 GB baseline)
                              |  --> eMMC 32/64 GB (SDC2, 8-bit HS400)
                              |  --> same-edge horizontal HDMI Type-A
                              |  --> USB0 FEL on internal test pads
                              |  --> USB1 host switch --> same-edge USB-C x1
                              |  --> UART0 / JTAG
                              +  --> FEL, reset and power controls
```

## Baseline rule

The SoC, AXP717, AXP323, LPDDR4, clocks, boot straps and eMMC form one imported
Avaota A1 core. Do not redraw these blocks from screenshots or rename rails while
pruning peripherals. Any change within that core requires a schematic diff against the
pinned reference and an explicit power/boot review.

## Fixed interface contracts

| Function | Required connection |
|---|---|
| PMIC control | Avaota A1 S-TWI connections and addresses, unchanged from the pinned source |
| Debug UART | UART0 TX `PB09`, RX `PB10`, 115200 8N1 |
| eMMC | SDC2: `PC5` CLK, `PC6` CMD, `PC10/13/15/8/9/11/14/16` D0-D7, `PC1` reset, `PC0` data strobe, 1.8 V I/O |
| JTAG | `PF0` TMS, `PF5` TCK, `PF3` TDO, `PF1` TDI |
| USB0 | FEL/device retained on internal prototype pads; not an external production connector |
| USB1 | One USB 2.0 host on the same-edge USB-C receptacle |
| USB2 | Not externally populated in Rev-P1 |
| HDMI | Native HDMI block and CEC; no external bridge; keep the reference connector corridor |

## Input-power decision

Rev-P1 keeps the Avaota carrier's TPS54531 input buck. The barrel jack is replaced by a
dedicated USB-C PD sink which requests 9 V / 3 A and feeds the existing
reverse-protected `DCIN-12V` node. The rail name is inherited; its Rev-P1 operating
voltage is 9 V. This minimizes power-plane and PMIC changes. A non-PD 5 V source must
not be allowed to brown out the board; the PD controller/load path needs undervoltage
gating so the input is enabled only after a valid 9 V contract.

The power connector has no USB data role. USB0 FEL/device is retained on internal
prototype pads so recovery remains possible without complicating the external power
port.

## Same-edge USB-C host

- J6 is a USB 2.0 Type-C source/host port replacing the reference dual USB-A connector.
- It uses `USB1-DP/DM`, Rp on both CC pins, a low-capacitance D+/D- ESD array and a
  current-limited, discharge-capable 5 V load switch.
- The selected Rp advertisement must not exceed the programmed VBUS current limit.
- Route D+/D- as 90-ohm differential pairs over an uninterrupted reference plane.

## HDMI

- Keep the horizontal right-angle HDMI Type-A connector in the reference edge corridor.
- Preserve the existing 100-ohm TMDS routing, source termination, DDC pull-ups, CEC,
  HPD, +5 V current limiting and connector-side ESD placement.

## Clocking and controls

- Preserve the reference 24 MHz and 32.768 kHz circuits, placement and grounding.
- Retain accessible FEL, reset and power controls on prototype boards.
- Validate eMMC-first boot straps against the Avaota bootloader configuration before
  releasing the schematic.
