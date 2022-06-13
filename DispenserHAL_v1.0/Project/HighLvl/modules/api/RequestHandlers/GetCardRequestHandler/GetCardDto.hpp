#ifndef GET_CARD_DTO_H_
#define GET_CARD_DTO_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"
#include "modules/Card.h"

class GetCardDto: public IDtoObject
{
public:
  GetCardDto(JsonSerializer * serializer,
             Card card)
  {
      _serializer = serializer;
      _card = card;
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

  Card _card;
};

#endif