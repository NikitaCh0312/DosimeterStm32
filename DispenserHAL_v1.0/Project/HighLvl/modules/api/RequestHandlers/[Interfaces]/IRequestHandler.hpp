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
    
    char _content[500];
    
    void Flush()
    {
        for (int i = 0; i < sizeof(_content); i++)
          _content[i] = '\0';
    }
};






#endif
