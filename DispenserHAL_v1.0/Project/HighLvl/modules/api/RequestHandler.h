#ifndef API_HANDLER_H_
#define API_HANDLER_H_


#include "modules/api/WebResponse.h"

class RequestHandler
{
public:
    RequestHandler()
    {
      
    }
    virtual ~RequestHandler(){}
    
    virtual WebResponse Handle(char * uri) = 0;
  
private:
  
  
};






#endif
