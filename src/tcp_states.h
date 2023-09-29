
#ifndef UIP_TCP_STATES_H
#define UIP_TCP_STATES_H

#include <utility/uip.h>

// common constants for client.state() return values
enum uip_tcp_state {
  CLOSED      = UIP_CLOSED,
  SYN_SENT    = UIP_SYN_SENT,
  SYN_RCVD    = UIP_SYN_RCVD,
  ESTABLISHED = UIP_ESTABLISHED,
  FIN_WAIT_1  = UIP_FIN_WAIT_1,
  FIN_WAIT_2  = UIP_FIN_WAIT_2,
  CLOSE_WAIT  = 10, // not used
  CLOSING     = UIP_CLOSING,
  LAST_ACK    = UIP_LAST_ACK,
  TIME_WAIT   = UIP_TIME_WAIT
};

#endif
