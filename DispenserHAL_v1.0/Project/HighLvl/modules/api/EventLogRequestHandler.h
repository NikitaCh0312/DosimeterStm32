#ifndef EVENT_LOG_API_HANDLER_H_
#defien EVENT_LOG_API_HANDLER_H_

#include "modules/api/WebResponse.h"
#include "modules/api/RequestHandler.h"

class EventLogRequestHandler: public RequestHandler
{
public:
    EventLogRequestHandler()
    {
      
    }
    
    virtual ~EventLogRequestHandler(){}
  
    WebResponse Handle(char * uri)
    {
      
    }
private:
};






#endif
