#ifndef NETWORK_REQUEST_HANDLER_H_
#define NETWORK_REQUEST_HANDLER_H_

#include "modules/api/WebResponse.h"
#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/HttpRequest.h"

class NetworkRequestHandler: public IRequestHandler
{
public:
    NetworkRequestHandler()
    {
      
    }
    
    virtual ~NetworkRequestHandler(){}
  
#warning TO REALIZE
    WebResponse * Handle(HttpRequest * request)
    {
      
    }
private:
};






#endif
