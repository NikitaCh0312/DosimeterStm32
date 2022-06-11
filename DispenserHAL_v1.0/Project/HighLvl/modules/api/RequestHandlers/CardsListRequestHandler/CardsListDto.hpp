#ifndef CARDS_LIST_API_H_
#define CARDS_LIST_API_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"

class CardsListDto: public IDtoObject
{
public:
  CardsListDto(JsonSerializer * serializer)
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