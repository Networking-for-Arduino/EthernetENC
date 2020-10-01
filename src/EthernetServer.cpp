/*
 UIPServer.cpp - Arduino implementation of a uIP wrapper class.
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
#include "Ethernet.h"
#include "EthernetServer.h"
extern "C" {
  #include "utility/uip-conf.h"
}

#define UIPServer EthernetServer // to not pollute source code history with the rename
#define UIPClient EthernetClient

UIPServer::UIPServer(uint16_t port) : _port(htons(port))
{
}

UIPClient UIPServer::available()
{
  UIPEthernetClass::tick();
  for ( uip_userdata_t* data = &UIPClient::all_data[0]; data < &UIPClient::all_data[UIP_CONNS]; data++ )
    {
      if (data->packets_in[0] != NOBLOCK
          && (((data->state & UIP_CLIENT_CONNECTED) && uip_conns[data->conn_index].lport ==_port)
              || ((data->state & UIP_CLIENT_REMOTECLOSED) && ((uip_userdata_closed_t *)data)->lport == _port)))
        return UIPClient(data);
    }
  return UIPClient();
}

UIPClient UIPServer::accept()
{
  UIPEthernetClass::tick();
  for ( uip_userdata_t* data = &UIPClient::all_data[0]; data < &UIPClient::all_data[UIP_CONNS]; data++ )
    {
      if (!(data->state & UIP_CLIENT_ACCEPTED)
          && (((data->state & UIP_CLIENT_CONNECTED) && uip_conns[data->conn_index].lport ==_port)
              || ((data->state & UIP_CLIENT_REMOTECLOSED) && ((uip_userdata_closed_t *)data)->lport == _port))) {
        data->state |= UIP_CLIENT_ACCEPTED;
        return UIPClient(data);
      }
    }
  return UIPClient();
}

void UIPServer::begin()
{
  uip_listen(_port);
  UIPEthernetClass::tick();
  listening = true;
}

void UIPServer::end() {
  uip_unlisten(_port);
  listening = false;
  for ( uip_userdata_t* data = &UIPClient::all_data[0]; data < &UIPClient::all_data[UIP_CONNS]; data++ )
    {
      if ((data->state & UIP_CLIENT_CONNECTED) && uip_conns[data->conn_index].lport ==_port)
        {
          UIPClient client(data);
          client.stop();
        }
    }
}

UIPServer::operator bool() {
  return listening;
}

size_t UIPServer::writeToAllClients(const uint8_t *buf, size_t size)
{
  size_t ret = 0;
  for ( uip_userdata_t* data = &UIPClient::all_data[0]; data < &UIPClient::all_data[UIP_CONNS]; data++ )
    {
      if ((data->state & UIP_CLIENT_CONNECTED) && uip_conns[data->conn_index].lport ==_port)
        {
          EthernetClient client(data);
          ret = client.write(buf, size);
        }
    }
  return ret;
}

size_t EthernetServerPrint::write(uint8_t c)
{
  return write(&c,1);
}

size_t EthernetServerPrint::write(const uint8_t *buf, size_t size)
{
  return EthernetServer::writeToAllClients(buf, size);
}
