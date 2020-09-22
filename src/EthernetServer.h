/*
 UIPServer.h - Arduino implementation of a uIP wrapper class.
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
  */
#ifndef UIPSERVER_H
#define UIPSERVER_H

#include "EthernetClient.h"

class EthernetServer {

public:
  EthernetServer(uint16_t);
  EthernetClient available();
  EthernetClient accept();
  void begin();
  void end();
  operator bool();

protected:
  size_t writeToAllClients(const uint8_t *buf, size_t size);

private:
  uint16_t _port;
  bool listening = false;
};

class EthernetServerPrint : public EthernetServer, public Print {

public:
  EthernetServerPrint(uint16_t port) : EthernetServer(port) {}

  virtual size_t write(uint8_t);
  virtual size_t write(const uint8_t *buf, size_t size);

  using Print::write;

};

#endif
