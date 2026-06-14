# tegra-rcm-console

Drive a Jetson Orin Nano Devkit's J14 button header and serial console over USB:
recovery, power on/off/cycle, a console bridge, and `initrd-flash`, as one
scriptable command for unattended Yocto/oeqa bring-up. An MCU (e.g. RP2040) runs
the firmware; a host CLI drives it. The Devkit carrier also takes Orin
NX modules, so the same harness works for both.

## Required Hardware

An RP2040 board, a BC547B NPN transistor with 1k and 10k resistors (for the 5 V
SLEEP/WAKE* line), and five signal wires to J14 are required. See [docs/WIRING.md](docs/WIRING.md).

## Firmware Flashing

    pio run -e pico

Hold BOOTSEL while plugging in the RP2040, then copy
`.pio/build/pico/firmware.uf2` to the mass-storage device that appears.
