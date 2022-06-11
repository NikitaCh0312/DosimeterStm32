#ifndef EVENT_LOG_API_HANDLER_H_
#define EVENT_LOG_API_HANDLER_H_

#include "modules/api/WebResponse.h"
#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/HttpRequest.h"

class EventLogRequestHandler: public IRequestHandler
{
public:
    EventLogRequestHandler()
    {
      
    }
    
    virtual ~EventLogRequestHandler(){}
  
#warning TO REALIZE
    void Handle(HttpRequest * request, WebResponse * WebResponse)
    {
      
    }
private:
};






#endif
