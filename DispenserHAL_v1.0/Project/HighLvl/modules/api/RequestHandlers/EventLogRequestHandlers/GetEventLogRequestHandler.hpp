#ifndef GET_EVENT_LOG_API_HANDLER_H_
#define GET_EVENT_LOG_API_HANDLER_H_

#include "modules/api/WebResponse.h"
#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/HttpRequest.h"

class GetEventLogRequestHandler: public IRequestHandler
{
public:
    GetEventLogRequestHandler()
    {
      
    }
    
    virtual ~GetEventLogRequestHandler(){}
  
#warning TO REALIZE
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
      
    }
private:
};






#endif
