#ifndef PINS_H
#define PINS_H

/* J14 button header (carrier spec SP-11324-001, Table 3-4):
     GP0 -> J14.3 UART2_RXD     GP2 SYS_RESET* (J14.8)
     GP1 <- J14.4 UART2_TXD     GP3 FORCE_RECOVERY* (J14.10)
     GP4 -> SLEEP/WAKE* via BC547B (J14.12)
   SYS_RESET* and FORCE_RECOVERY* are open-drain (assert = drive low, release =
   hi-Z); SLEEP/WAKE* is push-pull through the transistor. */

#if defined(ARDUINO_ARCH_RP2040)
#define PIN_SERIAL_TX 0
#define PIN_SERIAL_RX 1
#define PIN_RESET     2
#define PIN_RECOV     3
#define PIN_POWER     4
#elif defined(ARDUINO_NRF52_ADAFRUIT)
/* nRF52840 stand-in, untested on hardware; real pins might differ. */
#define PIN_SERIAL_TX 0
#define PIN_SERIAL_RX 1
#define PIN_RESET     2
#define PIN_RECOV     3
#define PIN_POWER     4
#else
#error "unsupported: add pins for this target"
#endif

#endif /* PINS_H */
