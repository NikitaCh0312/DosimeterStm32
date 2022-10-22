#ifndef CLEAT_EVENT_LOG_DTO_H_
#define CLEAT_EVENT_LOG_DTO_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"

class ClearEventLogDto: public IDtoObject
{
public:
  ClearEventLogDto(JsonSerializer * serializer,
                    bool result)
  {
      _serializer = serializer;
      _result = result;
  }
  
  void Serialize( char * outString )
  {
      _serializer->WriteStartObject(outString);
      if (_result)
        _serializer->WriteProperty(outString, COMMAND_RESULT_PROPERTY_NAME, (char*)"OK");
      else
        _serializer->WriteProperty(outString, COMMAND_RESULT_PROPERTY_NAME, (char*)"ERROR");
      _serializer->WriteEndProperty(outString);
      _serializer->WriteEndObject(outString);
  }
private:
  
  char * COMMAND_RESULT_PROPERTY_NAME = (char*)"result";
  
  JsonSerializer * _serializer;
  
  bool _result;
};

#endif