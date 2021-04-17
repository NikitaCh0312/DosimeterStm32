#ifndef WEB_RESPONSE_H_
#define WEB_RESPONSE_H_

#include "string.h"

#warning TODO
class WebResponse
{
public:
    
    void AddHeader(char * header)
    {
        strcpy(_response, header);
    }
  
    void AddContent(char * content)
    {
        strcpy(_response, content);
    }
    
    void SetFullResponse(char * response)
    {
        strcpy(_response, response);
    }
  
    char * ToString()
    {
       return _response;
    }
private:
    char _response[1000];
};

#endif
