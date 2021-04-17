#ifndef DESCRIPTION_REQUEST_HANDLER_H_
#define DESCRIPTION_REQUEST_HANDLER_H_

#include "modules/api/WebResponse.h"
#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/HttpRequest.h"

class DescriptionRequestHandler: public IRequestHandler
{
public:
    DescriptionRequestHandler()
    {
      
    }
    
    virtual ~DescriptionRequestHandler(){}
    
#warning TO REALIZE
    WebResponse * Handle(HttpRequest * request)
    {
      
    }
  
private:
};






#endif
