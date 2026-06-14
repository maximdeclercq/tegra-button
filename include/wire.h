#ifndef WIRE_H
#define WIRE_H

/* A command is one token "<line>=<0|1>" where line is recov, reset, or power; 1 asserts (active),
 * 0 releases. Any space or control byte delimits, so a newline ends a command. Each token gets one
 * reply, OK or ERR, terminated by "\r\n". */

#define WIRE_RECOV "recov"
#define WIRE_RESET "reset"
#define WIRE_POWER "power"

#define REP_OK  "OK"
#define REP_ERR "ERR"

#endif /* WIRE_H */
