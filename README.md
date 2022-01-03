
EthernetENC is the Ethernet library for ENC28J60. It is a modern version of [the UIPEthernet library](https://github.com/jandrassy/EthernetENC/wiki/UIPEthernet).

The modernization includes:
* Ethernet 2.0.0 Arduino library functions
* compatible include file names EthernetClient.h, EthernetServer.h and EthernetUdp.h 
* support of many Arduino architectures by using the SPI library
* SPI transactions to share the SPI bus with devices with different communication settings
* SPI communication at 20 MHz if the MCU supports it, else on the maximum supported by the MCU
* client.flush() to send the packet immediately
* calls yield() in blocking functions 
* has UDP backlog to receive more than one message at time
* Arduino 1.5 library format built with dot_a_linkage option  for optimal build result

<details>
  <summary>Notes for ESP (click to expand)</summary>
  
* *For esp8266 Arduino there is a much better option for enc28j60 than using this library. Use the lwIP_enc28j60 library bundled with esp8266 Arduino boards support package 3. (There is also a lwIP_w5500 and lwIP_w5100 library.)* 
* *For ESP32 it is better than using a MAC layer module like the enc28j60 to use a PHY layer LAN module like LAN8720 supported by the ESP32 MAC peripheral and the Arduino boards support package.* 
</details>

[The documentation of Arduino Ethernet library](https://www.arduino.cc/en/Reference/Ethernet) applies for classes and functions descriptions.

Limitations:
* UDP.beginMulticast is not supported, because the uIP stack doesn't support multicast
* UDP broadcasts receiving is turned off on ENC to lower the processing load on the library

This library doesn't have examples, because examples of the Arduino Ethernet library apply. You can find them in the Arduino IDE Examples menu Ethernet section. Only change `#include <Ethernet.h>` to `#include <EthernetENC.h>`. Some examples require [a little change](https://github.com/jandrassy/EthernetENC/wiki/Examples).

This library is based on the Norbert Truchsess's arduino-uip original source code repository and uses experience from the development of the multi-architecture support by Cassy. Applicable fixes and enhancements from development of EthernetENC were transfered to Cassy's UIPEthernet.

**You can find more information in project's [Wiki](https://github.com/jandrassy/EthernetENC/wiki).**

## Original notes by Norbert Truchsess

UIPEthernet is written as a wrapper around the mature uIP Stack by Adam Dunkels, which provides the low-level implementation for all supported protocols. To overcome the memory-constrains (a 'regular' uIP-application does all processing in RAM) the ENC28J60 internal memory is used for all stream buffers (in and out). Only 400-600 Bytes of Arduinos RAM are used (depending on the number of concurrently open connections). As of Flash-memory a ATmega368-based Arduino is the minimum requirenment.

uIP was written by Adam Dunkels of the Networked Embedded Systems group at the Swedish Institute of Computer Science.

This library was inspired by the SerialIP implementation by Adam Nielsen <malvineous@shikadi.net>, actually I took this code as a starting point, but in the latest versions there are very few lines left.

 
## Licenses
```
UIPEthernet.h
UIPEthernet.cpp
UIPServer.h
UIPServer.cpp
UIPClient.h
UIPClient.cpp
UIPUdp.h
UIPUdp.cpp
utility/mempool.h
utility/mempool.cpp

Copyright (c) 2013 Norbert Truchsess <norbert.truchsess@t-online.de>
All rights reserved.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

--------------

utility/enc28j60.h

Author        : Pascal Stang (c)2005
Modified by Norbert Truchsess
Copyright: GPL V2

--------------

utility/Enc28J60Network.h
utility/Enc28J60Network.cpp

Copyright (c) 2013 Norbert Truchsess <norbert.truchsess@t-online.de>
All rights reserved.

inspired and based on enc28j60.c file from the AVRlib library by Pascal Stang.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

--------------

utility/uip.c
utility/uip_arp.h
utility/uip_arp.c
utility/uip_arch.h
utility/uip.h
utility/uipopt.h

Copyright (c) 2001-2003, Adam Dunkels <adam@sics.se>, <adam@dunkels.com>.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. Neither the name of the Institute nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.

--------------

Dhcp.h
Dhcp.cpp

DHCP Library v0.3 - April 25, 2009
Author: Jordan Terrell - blog.jordanterrell.com
- as included in Arduinos stock Ethernet-library, no special licence mentioned here

--------------

Dns.h
Dns.cpp

(c) Copyright 2009-2010 MCQN Ltd.
Released under Apache License, version 2.0

```