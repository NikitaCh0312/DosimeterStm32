#ifndef GET_EVENT_LOG_API_H_
#define GET_EVENT_LOG_API_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"

class GetEventLogDto: public IDtoObject
{
public:
    GetEventLogDto(JsonSerializer * serializer,
                    EventJournalItem_t item)
    {
        _serializer = serializer;
        _item = item;
    }
  
    void Serialize( char * outString )
    {
        char value[10];
      
        _serializer->WriteStartObject(outString);
        
        sprintf(value, "%d", _item.Id);
        _serializer->WriteProperty(outString, NUMBER_PROPERTY_NAME, (char*)value);
        _serializer->WriteEndProperty(outString);
        
        sprintf(value, "%d", _item.EventId);
        _serializer->WriteProperty(outString, EVENT_ID_PROPERTY_NAME, (char*)value);
        _serializer->WriteEndProperty(outString);
        
        //format YYYY-MM-DDThh:mm:ss
        char datetime[20];
        //add year
        sprintf(datetime, "%d", _item.Year);
        
        strcat(datetime, "-");
        
        //add month
        sprintf(value, "%d", _item.Month);
        strcat(datetime, value);
        
        strcat(datetime, "-");
        
        //add day
        sprintf(value, "%d", _item.Day);
        strcat(datetime, value);
        
        strcat(datetime, "T");
        
        //add Hours
        sprintf(value, "%d", _item.Hours);
        strcat(datetime, value);
        
        strcat(datetime, ":");
        
        //add Minutes
        sprintf(value, "%d", _item.Minutes);
        strcat(datetime, value);
        
        strcat(datetime, ":");
        
        //add Seconds
        sprintf(value, "%d", _item.Seconds);
        strcat(datetime, value);
        
        _serializer->WriteProperty(outString, DATETIME_PROPERTY_NAME, (char*)datetime);
        _serializer->WriteEndProperty(outString);
        
        sprintf(value, "%d", _item.ExtraInfo);
        _serializer->WriteProperty(outString, EXTRAINFO_PROPERTY_NAME, (char*)value);
        
        _serializer->WriteEndObject(outString);
    }
private:
  
    JsonSerializer * _serializer;
  
    char * NUMBER_PROPERTY_NAME = (char*)"num";
    char * EVENT_ID_PROPERTY_NAME = (char*)"id";
    char * DATETIME_PROPERTY_NAME = (char*)"dt";
    char * EXTRAINFO_PROPERTY_NAME = (char*)"ex";

    EventJournalItem_t _item;
};

#endif