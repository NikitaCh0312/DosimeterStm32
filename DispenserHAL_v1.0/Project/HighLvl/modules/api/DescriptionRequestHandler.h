#ifndef DESCRIPTION_REQUEST_HANDLER_H_
#define DESCRIPTION_REQUEST_HANDLER_H_


#include "modules/api/WebResponse.h"
#include "modules/api/RequestHandler.h"
#include "modules/api/HttpRequest.h"

class DescriptionRequestHandler: public RequestHandler
{
public:
  
    DescriptionRequestHandler()
    {
      
    }
    
    virtual ~DescriptionRequestHandler(){}
    
    WebResponse Handle(HttpRequest * request)
    {
      
    }
  
private:
};






#endif
