# Allwinner FEL / FES protocol — as implemented by this device

Working notes for dumping the G'AIM'E console's flash without writing to it.

Two independent sources agree, which is why these values are trustworthy:

1. The **vendor's own U-Boot** (`u-boot.fex` out of the firmware image) contains the
   handler strings — `FEX_CMD_fes_trans`, `fes_up`, `fes_down`, `fes_verify_status`,
   `fes_query_storage`, `fes_flash_set_on/off`, `fes_force_erase`, `fes_memset`,
   `fes_unseqmem_read/write`, `fes_tool_mode`, `fes_query_secure`, plus the
   `SUNXI_EFEX_*_TAG` constants.
2. [FELix](https://github.com/jankowskib/FELix), an open-source Allwinner flash tool,
   defines the numeric codes. **Every name in FELix's enum appears in this device's
   U-Boot**, so the enum is this firmware's command set.

Deriving the codes rather than recalling them matters: `fes_up` (read) and `fes_down`
(write) are adjacent opcodes, and `force_erase` sits in the same table.

## Why FEL alone is not enough

FEL is the boot ROM. It gives arbitrary memory read/write and code execution but has
**no storage driver** — it cannot touch NAND/eMMC. Reading partitions requires bringing
up DRAM and a storage stack first, which is what the FES path does:

```
FEL  →  load fes1.fex to SRAM, run it      (initialises DRAM)
     →  load u-boot.fex to DRAM, run it    (enters "efex" mode)
FES  →  partition read/write commands
```

The factory boot log confirms this is exactly what the vendor tool does — it ends with
`sunxi work mode=0x10` / `run usb efex`.

## Transport

Every transaction is framed. Host sends a 32-byte request, then payload, then reads a
13-byte status.

```
AWUSBRequest (32 bytes, little-endian)
  0x00  char[4]  magic = "AWUC"
  0x04  u32      tag
  0x08  u32      len
  0x0C  u16      reserved = 0
  0x0E  u8       reserved = 0
  0x0F  u8       cmd_len = 0x0C
  0x10  u8       cmd          0x11 = read (device→host), 0x12 = write (host→device)
  0x11  u8       reserved = 0
  0x12  u32      len2 = len
  0x16  u8[10]   reserved = 0

AWUSBResponse (13 bytes)
  0x00  char[4]  magic = "AWUS"
  0x04  u32      tag
  0x08  u32      residue
  0x0C  u8       csw_status     non-zero = failure

AWFELStatusResponse (8 bytes)
  0x00  u16  mark = 0xFFFF
  0x02  u16  tag
  0x04  u8   state
  0x05  u8[3] reserved
```

## FEL commands (16-byte `AWFELMessage`)

```
  0x00  u16  cmd
  0x02  u16  tag
  0x04  u32  address
  0x08  u32  len
  0x0C  u32  flags
```

| Code | Name | Direction |
|---|---|---|
| `0x001` | verify_device | read, returns `AWUSBFEX` banner |
| `0x003` | is_ready | read 8 |
| `0x004` | get_cmd_set_ver | read 16 |
| `0x010` | disconnect | — |
| `0x101` | download | **write to device** |
| `0x102` | run | execute |
| `0x103` | upload | read from device |

`verify_device` response is 32 bytes: `"AWUSBFEX"`, board id, fw, mode, data_flag,
data_length, data_start_address. Our unit reports board `0x00001890` (A523).

## FES commands

| Code | Name | Notes |
|---|---|---|
| `0x201` | transmit | read or write depending on flags — see below |
| `0x202` | run | |
| `0x203` | info | has FES_RUN finished (32 bytes) |
| `0x204` | get_msg | result of last run |
| `0x205` | unreg_fed | unmount NAND/MMC |
| `0x206` | **download** | **WRITE — do not send** |
| `0x207` | **upload** | **READ — this is the dump path** |
| `0x208` | verify | |
| `0x209` | query_storage | which medium we booted from |
| `0x20A` | flash_set_on | `sunxi_sprite_init(0)` — needed before partition I/O |
| `0x20B` | flash_set_off | `sunxi_sprite_exit(1)` |
| `0x20C` | verify_value | CRC of a memory block |
| `0x20D` | verify_status | read 12 |
| `0x20E` | flash_size_probe | read 4 |
| `0x20F` | tool_mode | can reboot the device |
| `0x210` | memset | |
| `0x211` | pmu | voltage settings |
| `0x212` / `0x213` | unseqmem read / write | |
| `0x214` | reset_cpu | |
| `0x220` | **force_erase** | **DESTRUCTIVE — never send** |
| `0x221` | **force_erase_key** | **DESTRUCTIVE — never send** |
| `0x230` | query_secure | |

### FES_TRANSMITE request (16 bytes)

```
  0x00  u16  cmd = 0x201
  0x02  u16  tag
  0x04  u32  address        sector number for non-DRAM media, byte address for DRAM
  0x08  u32  len            bytes
  0x0C  u8   media_index
  0x0D  u8   flags
  0x0E  u8[2] reserved
```

`flags`: `0x10` write · `0x20` read · `0x40` start · `0x80` finish
`media_index`: `0x00` dram · `0x01` physical · `0x02` nand/logical · `0x03` card/spinor

For non-DRAM media the address advances by `len / 512` **sectors** per chunk, not bytes.

### Tags for FES_DOWN (write path — listed only so they are recognisable and avoided)

`0x7F00` dram · `0x7F01` mbr (**performs an erase**) · `0x7F02` uboot/boot1 ·
`0x7F03` boot0 · `0x7F04` erase · `0x8000` flash · `0x10000` finish · `0x20000` start

## Boot-to-FES sequence

FELix's modern path, for reference:

```ruby
write(0x2000,     fes1)          # eGON SPL into SRAM
run(0x2000)
write(0x4a000000, uboot)         # U-Boot into DRAM
write(0x4a0000e0, work_mode)     # 0x10 = usb_product (FES mode)
run(0x4a000000)
```

**These addresses are SoC-specific and are the open question for sun55iw3.** They are
not present in the shipped `Context.cfg`. Known constraints for this SoC:

- `sunxi-fel` places the A523 SPL at **`0x44000`** (`soc_info.c`), with scratch at
  `0x45000` and 96 KB of SRAM — so `sunxi-fel spl fes1.fex` is the natural first attempt,
  since `fes1.fex` carries a valid `eGON.BT0` header.
- A523 DRAM starts at `0x40000000`, so FELix's `0x4a000000` is plausible but unconfirmed.
- This device also ships `boot_package.fex` (1.5 MB), the modern container holding
  BL31 + U-Boot. Newer Allwinner parts boot that rather than a bare `u-boot.fex`, so the
  FES stage may expect it instead.

A wrong address wedges FEL — recoverable by replugging (nothing is written), but each
attempt costs a physical replug cycle.

## Device facts captured so far

```
FEL mode      VID 0x1f3a  PID 0xefe8      (BROM FEL, not the vendor FES layer)
SoC           0x1890 = A523 (sun55iw3)
SID           0300ff10:90204824:75779908:287d1ed4
FEL version   ver=0001, scratchpad 0x00061500
```

Arbitrary memory read/write verified: wrote `0xDEADBEEF` to `0x45800`, read it back,
restored the original value.

**Caution learned the hard way:** reading an unmapped address (tried `0x100000`) hangs
the FEL endpoint. The device stays enumerated but every bulk transfer times out; only a
replug clears it. Stay within SRAM (`0x40000`–`0x58000`) and the SID block at
`0x03006200` until DRAM is up.

## What a flash would actually overwrite

From `sys_partition.fex` — only partitions with a `downloadfile` are written:

*Written:* `bootloader_a`, `env_a`, `boot_a`, `vendor_boot_a`, `init_boot_a`, `super`,
`misc`, `vbmeta_a`, `vbmeta_system_a`, `vbmeta_vendor_a`, `dtbo_a`.

*Not written:* every `_b` slot, `frp` (`keydata = 0x8000`, explicitly preserved across
re-production), `private` (16 MB), `media_data`, `metadata`, `treadahead`, `UDISK`.

So the update's write set is exactly the set we already hold bit-reproducible stock
copies of. The irreplaceable per-device material — including whatever holds the keybox
the U-Boot env lists (`widevine, ec_key, ec_cert1-3, rsa_key, rsa_cert1-3, hdcpkey`) —
sits outside it. Keep `erase_all=0` in `PhoenixPro.cfg`; that is the one setting that
would wipe the preserved partitions.
