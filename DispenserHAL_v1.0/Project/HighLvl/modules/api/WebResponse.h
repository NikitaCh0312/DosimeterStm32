#ifndef WEB_RESPONSE_H_
#define WEB_RESPONSE_H_

#include "string.h"

class WebResponse
{
public:
    
    void AddHeader(char * header)
    {
        strcpy(_response, header);
    }
  
    void AddContent(char * content)
    {
        int contentLength = strlen(content);
        contentLength = strlen(content);
        char contLength[10];
        sprintf(contLength, "%d", contentLength);
        strcat(_response, contLength);
        strcat(_response, "\r\n\r\n");
        strcat(_response, content);
        strcat(_response, "\r\n\0");
    }
    
    void SetFullResponse(char * response)
    {
        Flush();
        strcpy(_response, response);
    }
  
    char * ToString()
    {
       return _response;
    }
private:
    char _response[1000];
    
    void Flush()
    {
        for (int i = 0; i < sizeof(_response); i++)
          _response[i] = '\0';
    }
};

#endif
