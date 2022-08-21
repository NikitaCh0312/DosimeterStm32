#ifndef REMOVE_CARD_API_H_
#define REMOVE_CARD_API_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"

class RemoveCardDto: public IDtoObject
{
public:
  RemoveCardDto(JsonSerializer * serializer)
  {
      _serializer = serializer;
  }
  
  void Serialize( char * outString )
  {
      
  }
  
private:
  
  JsonSerializer * _serializer;
};

#endif