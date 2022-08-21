#ifndef GET_CONFIGURATION_DTO_H_
#define GET_CONFIGURATION_DTO_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"

class GetConfigurationDto: public IDtoObject
{
public:
  GetConfigurationDto(JsonSerializer * serializer,
                     char * ip,
                     char * port,
                     char * mask,
                     char * date,
                     char * time)
  {
      _serializer = serializer;
      strcpy(_ip, ip);
      strcpy(_port, port);
      strcpy(_mask, mask);
      strcpy(_date, date);
      strcpy(_time, time);
  }
  
  void Serialize( char * outString )
  {
      _serializer->WriteStartObject(outString);
      _serializer->WriteProperty(outString, IP_ADDRESS_PROPERTY_NAME, _ip);
      _serializer->WriteEndProperty(outString);
      _serializer->WriteProperty(outString, PORT_PROPERTY_NAME, _port);
      _serializer->WriteEndProperty(outString);
      _serializer->WriteProperty(outString, MASK_PROPERTY_NAME, _mask);
      _serializer->WriteEndProperty(outString);
      _serializer->WriteProperty(outString, DATE_PROPERTY_NAME, _date);
      _serializer->WriteEndProperty(outString);
      _serializer->WriteProperty(outString, TIME_PROPERTY_NAME, _time);
      _serializer->WriteEndObject(outString);
  }
  
private:

  char * IP_ADDRESS_PROPERTY_NAME = "IpAddress";
  char * PORT_PROPERTY_NAME = "Port";
  char * MASK_PROPERTY_NAME = "Mask";
  char * DATE_PROPERTY_NAME = "Date";
  char * TIME_PROPERTY_NAME = "Time";

  JsonSerializer * _serializer;

  char _ip[20];
  
  char _port[10];
  
  char _mask[20];
  
  char _date [15];
  
  char _time [15];
};

#endif