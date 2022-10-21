#ifndef CLEAR_EVENT_LOG_API_HANDLER_H_
#define CLEAR_EVENT_LOG_API_HANDLER_H_

#include "modules/api/WebResponse.h"
#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/HttpRequest.h"

class ClearEventLogRequestHandler: public IRequestHandler
{
public:
    ClearEventLogRequestHandler()
    {
      
    }
    
    virtual ~ClearEventLogRequestHandler(){}
  
#warning TO REALIZE
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
      
    }
private:
};






#endif
