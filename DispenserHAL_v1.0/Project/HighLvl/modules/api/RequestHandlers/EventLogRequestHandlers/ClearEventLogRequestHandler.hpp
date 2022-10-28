#ifndef CLEAR_EVENT_LOG_API_HANDLER_H_
#define CLEAR_EVENT_LOG_API_HANDLER_H_

#include "modules/api/WebResponse.h"
#include "modules/api/HttpRequest.h"
#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/EventLogRequestHandlers/ClearEventLogDto.hpp"
#include "modules/ModulesLocator.h"

class ClearEventLogRequestHandler: public IRequestHandler
{
public:
    ClearEventLogRequestHandler()
    {
        _eventJournal = ModulesLocator::GetInstance()->eventJournal;
    }
    
    virtual ~ClearEventLogRequestHandler(){}
  
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;
            
        Flush();
        webResponse->AddHeader((char*)RES_JSONHEAD_OK);
        
        _eventJournal->ClearJournal();
        
        ClearEventLogDto dto (JsonSerializer::GetInstance(), true);
        dto.Serialize(_content);
        webResponse->AddContent(_content);
        Flush();
        return true;
    }
private:
    EventJournal* _eventJournal;
};






#endif
