#ifndef EVENT_LOG_INFO_API_H_
#define EVENT_LOG_INFO_API_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"

class EventLogInfoDto: public IDtoObject
{
public:
    EventLogInfoDto(JsonSerializer * serializer,
                  EventJournalInfo_t info)
    {
        _serializer = serializer;
        _info = info;
    }
  
    void Serialize( char * outString )
    {
        _serializer->WriteStartObject(outString);
        
        char value[10];
        sprintf(value, "%d", _info.EventsQuantity);
        _serializer->WriteProperty(outString, EVENTS_NUMBER_PROPERTY_NAME, (char*)value);
        _serializer->WriteEndProperty(outString);
        sprintf(value, "%d", _info.MaxEventQuantity);
        _serializer->WriteProperty(outString, MAX_EVENTS_NUMBER_PROPERTY_NAME, (char*)value);
        
        _serializer->WriteEndObject(outString);
    }
private:
  
    JsonSerializer * _serializer;
  
    EventJournalInfo_t _info;
  
    char * EVENTS_NUMBER_PROPERTY_NAME = (char*)"events_number";
    char * MAX_EVENTS_NUMBER_PROPERTY_NAME = (char*)"max_events_number";
};

#endif