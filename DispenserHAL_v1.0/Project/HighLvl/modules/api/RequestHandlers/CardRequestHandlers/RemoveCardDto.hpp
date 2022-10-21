#ifndef REMOVE_CARD_API_H_
#define REMOVE_CARD_API_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"

class RemoveCardDto: public IDtoObject
{
public:
  RemoveCardDto(JsonSerializer * serializer, bool result )
  {
      _serializer = serializer;
      _result = result;
  }
  
  void Serialize( char * outString)
  {
      _serializer->WriteStartObject(outString);
      
      if (_result)
        _serializer->WriteProperty(outString, RESULT_PROPERTY_NAME, "true");
      else
        _serializer->WriteProperty(outString, RESULT_PROPERTY_NAME, "false");
      
      _serializer->WriteEndObject(outString);
  }
  
private:
  
  JsonSerializer * _serializer;
  
  char * RESULT_PROPERTY_NAME = "Result";
  
  bool _result;
};

#endif