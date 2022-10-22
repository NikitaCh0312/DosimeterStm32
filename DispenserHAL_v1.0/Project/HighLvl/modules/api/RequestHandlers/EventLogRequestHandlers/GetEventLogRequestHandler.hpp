#ifndef GET_EVENT_LOG_API_HANDLER_H_
#define GET_EVENT_LOG_API_HANDLER_H_

#include "stdlib.h"

#include "modules/api/WebResponse.h"
#include "modules/api/HttpRequest.h"
#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/EventLogRequestHandlers/GetEventLogDto.hpp"
#include "modules/ModulesLocator.h"

class GetEventLogRequestHandler: public IRequestHandler
{
public:
    GetEventLogRequestHandler()
    {
        _eventJournal = ModulesLocator::GetInstance()->eventJournal;
    }
    
    virtual ~GetEventLogRequestHandler(){}
  
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;
            
        Flush();
        webResponse->AddHeader((char*)RES_JSONHEAD_OK);
        
        int eventNumber = ParseEventNumber(request->GetQueryString());
        EventJournalItem_t event = _eventJournal->GetEvent(eventNumber);
        
        GetEventLogDto dto(JsonSerializer::GetInstance(), event);
        dto.Serialize(_content);
        
        webResponse->AddContent(_content);
        Flush();
        return true;
    }
private:
    char _content[100];
    
    void Flush()
    {
        for (int i = 0; i < sizeof(_content); i++)
          _content[i] = '\0';
    }
    
    EventJournal* _eventJournal;
    
    int ParseEventNumber(char * query)
    {
        char* eventNumber = strtok((char*)query, "&=");
        if (strcmp(eventNumber, "event_number"))
          return false;
        char* eventNumberValue = strtok(NULL, "&=");
        int eventNumberInt = atoi(eventNumberValue);
        return eventNumberInt;
    }
};






#endif
