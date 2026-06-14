#ifndef CONF_H
#define CONF_H

/* TRC_ prefix dodges arduino-pico's own USB_VID/PID macros. */

#define TRC_USB_VID       0x1209
#define TRC_USB_PID       0x0001
#define TRC_USB_PRODUCT   "tegra-rcm-console"
#define SERIAL_IFACE_STR  "tegra-rcm serial"
#define JETSON_UART_BAUD  115200
#define CTRL_LINE_MAX     32

#endif /* CONF_H */
