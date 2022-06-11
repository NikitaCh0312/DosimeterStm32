#ifndef NETWORK_SETTINGS_DTO_H_
#define NETWORK_SETTINGS_DTO_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"
//#include "modules/Configuration.h"

class NetworkSettingsDto: public IDtoObject
{
public:
  NetworkSettingsDto(JsonSerializer * serializer,
                     IpAddr_t ip,
                     uint32_t port,
                     Mask_t mask)
  {
      _serializer = serializer;
      _ip = ip;
      _port = port;
      _mask = mask;
  }
  
  void Serialize( char * outString )
  {
      _serializer->WriteStartObject(outString);
      _serializer->WriteProperty(outString, IP_ADDRESS_PROPERTY_NAME, "192.168.0.55");
      _serializer->WriteEndProperty(outString);
      _serializer->WriteProperty(outString, PORT_PROPERTY_NAME, "666");
      _serializer->WriteEndProperty(outString);
      _serializer->WriteProperty(outString, MASK_PROPERTY_NAME, "255.255.0.0");
      _serializer->WriteEndProperty(outString);
  }
  
private:
  
  char * IP_ADDRESS_PROPERTY_NAME = "IpAddress";
  char * PORT_PROPERTY_NAME = "Port";
  char * MASK_PROPERTY_NAME = "Mask";

  JsonSerializer * _serializer;

  IpAddr_t _ip;
  
  uint32_t _port;
  
  Mask_t _mask;
};

#endif