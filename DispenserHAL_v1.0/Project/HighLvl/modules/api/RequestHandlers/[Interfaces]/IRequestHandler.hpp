#ifndef API_HANDLER_H_
#define API_HANDLER_H_


#include "modules/api/WebResponse.h"
#include "modules/api/HttpRequest.h"

class IRequestHandler
{
public:
    IRequestHandler()
    {
      
    }
    virtual ~IRequestHandler(){}
    
    virtual bool Handle(HttpRequest * request, WebResponse * webResponse) = 0;
};






#endif
