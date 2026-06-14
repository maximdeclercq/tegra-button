# Control protocol

The board exposes two USB CDC interfaces: a button channel (below, on the lower
interface) and a serial bridge to the Jetson UART2. The host pairs them by
interface order; udev also exposes `/dev/tegra-button` and `/dev/tegra-serial`.

## Button channel

A command is one line-state token, `<line>=<0|1>`, where `1` asserts the line and
`0` releases it. Any space or control byte delimits tokens, so a newline ends a
command. Each token gets one reply, `OK` or `ERR`, ended by `\r\n`.

| line  | `1` (assert)                        | `0` (release) |
| ----- | ----------------------------------- | ------------- |
| recov | FORCE_RECOVERY* low                 | hi-Z          |
| reset | SYS_RESET* low                      | hi-Z          |
| power | SLEEP/WAKE* driven (button pressed) | released      |

The firmware only sets the pin and acks; it holds no timing or state. The host
composes the recovery and power sequences (`board.py`), holding the button port
open and timing the holds, so the MCU never blocks and the sequences retune
without reflashing. A line left asserted by a host crash is cleared on the next
command, and a USB unplug releases everything in hardware.

## Serial channel

Transparent byte bridge to the Jetson UART2 (J14 pins 3/4), exposed by the host
`serial` command.
