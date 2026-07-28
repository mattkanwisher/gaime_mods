# Complete-board DRC status — 2026-07-29

## Result

**FAIL — this revision is not safe to fabricate or assemble.**

KiCad 10.0.4 checked the complete PCB, including all copper layers, zones,
footprints and the current board constraints. The run completed and reported:

- 2,783 design-rule violations
- 121 unconnected-item violations
- 42 explicit shorts between different nets
- 0 footprint-consistency errors

The machine-readable source for this summary is the adjacent
`android-box-rebuild-full-drc.rpt`. KiCad limits several displayed categories to
199 entries, so those category counts are lower bounds rather than the complete
population.

## Command

```sh
/Applications/KiCad/KiCad.app/Contents/MacOS/kicad-cli pcb drc \
  --exit-code-violations --units mm \
  --output hardware/android-box-rebuild/validation/android-box-rebuild-full-drc.rpt \
  hardware/android-box-rebuild/android-box-rebuild.kicad_pcb
```

## Violation totals by category

| Count | KiCad category |
|---:|---|
| 499 | Clearance |
| 199 | Via diameter |
| 199 | Track width |
| 199 | Library footprint issues |
| 199 | Items not allowed |
| 199 | Hole-to-hole |
| 199 | Hole clearance |
| 199 | Drill out of range |
| 199 | Courtyard overlap |
| 199 | Annular width |
| 167 | Dangling tracks |
| 121 | Unconnected items |
| 104 | Starved thermals |
| 56 | Silkscreen over copper |
| 42 | Shorting items |
| 27 | Copper slivers |
| 21 | Dangling vias |
| 19 | Silkscreen-to-edge clearance |
| 12 | Solder-mask bridges |
| 12 | Isolated copper |
| 7 | Tracks crossing |
| 7 | Silkscreen overlap |
| 6 | Padstack errors |
| 5 | Intersecting zones |
| 4 | Copper-to-edge clearance |
| 3 | Co-located holes |
| 1 | Text thickness |

## Immediate blockers found in the new work

The earlier J5/J6 scripts only checked their local connector neighborhoods. The
complete-board run found that several long inner-layer routes cross legacy
through-vias and copper elsewhere on the board. These are real electrical shorts,
not cosmetic warnings:

- `EFUSE_EN` intersects USB2 TX/RX and D+/D- through-vias.
- `EFUSE_OVLO` intersects GND, `CTP-SDA`, `CTP-SCK` and `CLDO3`.
- `PD_VBUS_RAW` intersects GND, `CLDO3` and combo-PHY USB2 lane copper.
- `USB1_VBUS_SW` intersects GND and several legacy power/control nets along its
  long L7 route.
- The R1103/SIM1 placement and bottom-layer fanout create `VBUS-USB`/GND and
  `USB1_VBUS_SW`/GND conflicts.
- A new `VBUS` segment near `(132.8, 122.65) mm` intersects a GND via.

## Required closure sequence

1. Remove or reroute every new J5/J6 short using complete-board clearance checks,
   not bounding-box-only checks.
2. Remove the orphaned GMAC copper left after both Ethernet populations were
   deleted; it accounts for many dangling and unconnected items.
3. Normalize the imported Avaota footprint drills, annular rings, padstacks and
   courtyards to the selected fabricator capabilities.
4. Refill all zones and resolve plane-to-plane intersections and thermal failures.
5. Re-run DRC without category truncation during cleanup and reach zero unexplained
   errors before generating Gerbers.

No violation in this report is waived by this document.
