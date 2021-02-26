#ifndef EVENT_LOG_API_HANDLER_H_
#define EVENT_LOG_API_HANDLER_H_

#include "modules/api/WebResponse.h"
#include "modules/api/RequestHandler.h"
#include "modules/api/HttpRequest.h"

class EventLogRequestHandler: public RequestHandler
{
public:
    EventLogRequestHandler()
    {
      
    }
    
    virtual ~EventLogRequestHandler(){}
  
    WebResponse Handle(HttpRequest * request)
    {
      
    }
private:
};






#endif
