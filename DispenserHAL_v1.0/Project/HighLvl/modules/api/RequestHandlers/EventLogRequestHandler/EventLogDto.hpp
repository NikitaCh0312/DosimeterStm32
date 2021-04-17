#ifndef EVENT_LOG_API_H_
#define EVENT_LOG_API_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/apiObjects/[Interfaces]/DtoObject.h"
#include "modules/Configuration.h"

class EventLogDto: public IDtoObject
{
public:
  EventLogDto(JsonSerializer * serializer,
              char * date,
              int code)
  {
      _code = code;
      strcpy(_date, date);
  }
  
  void Serialize( char * outString )
  {
      char code[5];
      sprinf(code, "%d", _code);
      
      _serializer->WriteStartObject(outString);
      _serializer->WriteProperty(outString, EVENT_CODE_PROPERTY_NAME, _date);
      _serializer->WriteEndProperty(outString);
      _serializer->WriteProperty(outString, DATE_PROPERTY_NAME, code);
      _serializer->WriteEndObject(outString);
  }
private:
  
  JsonSerializer * _serializer;
  
  char * EVENT_CODE_PROPERTY_NAME = "event_code";
  char * DATE_PROPERTY_NAME = "date";
  
  char _date[20];
  
  int _code;
};

#endif