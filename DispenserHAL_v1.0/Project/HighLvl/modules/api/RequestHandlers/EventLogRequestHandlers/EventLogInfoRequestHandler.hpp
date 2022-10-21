#ifndef EVENT_LOG_INFO_API_HANDLER_H_
#define EVENT_LOG_INFO_API_HANDLER_H_

#include "modules/api/WebResponse.h"
#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/HttpRequest.h"

class EventLogInfoRequestHandler: public IRequestHandler
{
public:
    EventLogInfoRequestHandler()
    {
      
    }
    
    virtual ~EventLogInfoRequestHandler(){}
  
#warning TO REALIZE
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
      
    }
private:
};






#endif
