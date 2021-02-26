#ifndef API_HANDLER_H_
#define API_HANDLER_H_


#include "modules/api/WebResponse.h"
#include "modules/api/HttpRequest.h"

class RequestHandler
{
public:
    RequestHandler()
    {
      
    }
    virtual ~RequestHandler(){}
    
    virtual WebResponse Handle(HttpRequest * request) = 0;
  
private:
  
  
};






#endif
