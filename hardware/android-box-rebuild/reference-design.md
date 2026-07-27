# Reference design provenance

The design baseline is the open-hardware Avaota A1 T527/A527 board:

- Repository: <https://github.com/AvaotaSBC/Avaota-A1>
- Pinned commit: `bbd81c54c9a971e8fd9397fec958a9d9afebdffe`
- License: CERN Open Hardware Licence Version 2 - Strongly Reciprocal
- Main schematic: `hardware/v1.4/01_SCH/SCH_Avaota Pi A_2024-05-20.pdf`
- Editable EasyEDA project: `hardware/v1.4/08_JLCEDA/ProPrj_Avaota A1 ... .epro`
- 8-layer LPDDR4 template: `resource/dram_8l/`

Checksums at the pinned commit:

```text
1955ff93111b169c9e8cae42a94ed14e35e8c4aa4ef8a7ce886a90bf8dcc9a55  main schematic PDF
a08d6b190b034455ce3941dad1c47cae812a917def3b7929a2ad29e24e98dac2  editable EasyEDA project
5027924ea3e9e4da00d81e0b5d9654f01a3de9b3ddfba7d6da210061d229b90d  8-layer LPDDR4 EasyEDA template
```

## Reuse unchanged as one core

- T527/A527 BGA664 symbol, ball map, straps and decoupling.
- AXP717/AXP323 circuits, sequence, rail names and PMIC control bus.
- LPDDR4 schematic, placement, escape, layer assignment and length constraints.
- eMMC, crystals, reset and debug circuitry.
- Native HDMI source circuitry and connector routing corridor.

## Planned changes outside the core

- Replace the barrel jack with a reviewed 9 V USB-C PD sink feeding the existing
  protected `DCIN-12V` input.
- Keep horizontal HDMI Type-A in its reference connector corridor.
- Replace the dual USB-A with one USB 2.0 host Type-C receptacle in the same corridor.
- Remove Ethernet, wireless, SD, camera, audio, panel-display and other unused carrier
  interfaces only after a full net-consumer audit.

The source is strongly reciprocal hardware. Preserve notices, modification records and
the CERN-OHL-S-2.0 license when distributing manufacturing source or modified designs.
