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
    
    virtual WebResponse * Handle(HttpRequest * request) = 0;
  
    void SetWebResponse(WebResponse * response)
    {
        _response = response;
    }
    
private:
  
    WebResponse * _response;
  
};






#endif
