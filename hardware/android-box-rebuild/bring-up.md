# Bring-up plan

## Before the full board

1. Build and load-test the proposed 9 V USB-C PD sink/protection plus the J6 host VBUS switch.
2. Confirm 9 V negotiation, invalid/default 5 V behavior and cable drop at peak load.
3. Validate UVLO/eFuse start-up, reverse-current blocking, short-circuit response and
   host-port discharge. J6 must not back-power the system.
4. Confirm JLCPCB's fabrication and assembly process for the BGA664, FBGA200, FBGA153,
   via-in-pad and any consigned parts.

## Prototype population stages

### Stage 0 - power and shorts

Inspect by microscope and X-ray. With the SoC unpowered, check every rail-to-ground
resistance against the expected reference range. Current-limit the negotiated 9 V input, verify
no unintended rail rises and confirm FEL/host VBUS switches default off as designed.

### Stage 1 - PMIC sequencing

Enable AXP717/AXP323 without high-risk peripherals where the assembly option permits.
Capture every regulator's ramp, steady voltage, ripple and shutdown sequence. Compare
against the Avaota reference boot rather than the retail AXP2202/AXP1530 board.

### Stage 2 - BootROM and DRAM

Populate SoC, LPDDR4, clocks, UART, FEL and reset. Prove:

- stable current with no rail outside tolerance;
- Allwinner FEL enumeration on the internal recovery pads;
- clean UART at 115200;
- repeatable DRAM training over cold/ambient/hot and input-voltage corners.

Use an Avaota-compatible loader first. The retail G'AIM'E loader is not the initial
hardware acceptance test because its PMIC description must be ported.

### Stage 3 - storage

Populate blank eMMC, test identification and destructive read/write on the prototype,
then program the baseline Avaota-derived system image. Verify HS400 only after lower
speed modes are reliable.

### Stage 4 - video and USB

Bring up HDMI in its preserved corridor, then J6. Test hot plug, ESD, VBUS current
limits, HDMI modes and thermal behavior before attaching the light gun.

### Stage 5 - software port

Port the G'AIM'E bootloader/device tree to AXP717/AXP323 and the new regulator/USB
topology. Only after Android boots reliably should game userspace and the gun be tested.

## Stop conditions

- Any rail or sequence differs from the pinned reference without a reviewed reason.
- Input droop or thermal limiting appears at the validated load.
- DRAM training is intermittent at any tested corner.
- X-ray shows marginal BGA joints or via-in-pad defects.
- eMMC, HDMI or USB signal integrity fails at its target mode.
- J6 advertises or supplies more current than the input budget permits.
