#ifndef EVENT_LOG_INFO_API_HANDLER_H_
#define EVENT_LOG_INFO_API_HANDLER_H_

#include "modules/api/WebResponse.h"
#include "modules/api/HttpRequest.h"
#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/EventLogRequestHandlers/EventLogInfoDto.hpp"
#include "modules/ModulesLocator.h"

class EventLogInfoRequestHandler: public IRequestHandler
{
public:
    EventLogInfoRequestHandler()
    {
        _eventJournal = ModulesLocator::GetInstance()->eventJournal;
    }
    
    virtual ~EventLogInfoRequestHandler(){}
  
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;
            
        Flush();
        webResponse->AddHeader((char*)RES_JSONHEAD_OK);
        
        EventJournalInfo_t info = _eventJournal->GetEventJournalInfo();
        
        EventLogInfoDto dto (JsonSerializer::GetInstance(), info);
        dto.Serialize(_content);
        
        webResponse->AddContent(_content);
        Flush();
        return true;
    }
private:
    EventJournal* _eventJournal;
};






#endif
