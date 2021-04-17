#ifndef NETWORK_SETTINGS_API_H_
#define NETWORK_SETTINGS_API_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/apiObjects/[Interfaces]/DtoObject.h"
#include "modules/Configuration.h"

class NetworkSettingsDto: public IDtoObject
{
public:
  NetworkSettingsDto(JsonSerializer * serializer,
                     IP_ADDR ip,
                     uint32_t port)
  {
      _ip = ip;
      _port = port;
  }
  
  void Serialize( char * outString )
  {
      
  }
  
private:
  
  JsonSerializer * _serializer;
  
  uint32_t _mask;
  
  IP_ADDR _ip;
  
  uint32_t _port;
  
  uint32_t _mac;
};

#endif