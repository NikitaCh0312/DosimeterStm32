#ifndef HTTP_REQUEST_H_
#define HTTP_REQUEST_H_

#include "string.h"

typedef enum
{
    HTTP_METHOD_ERR = 0,
    HTTP_METHOD_GET = 1,
    HTTP_METHOD_HEAD = 2,
    HTTP_METHOD_POST = 3,
}HTTP_METHOD_t;

#define HTTP_URI_NAME_LENGTH 20
#define HTTP_QUERY_LENGTH 200
#define HTTP_BODY_LENGTH 500

class HttpRequest
{
public:
    HttpRequest(HTTP_METHOD_t method,
                char * uriName,
                char * query,
                char * body)
    {
        _method = method;
        if (strlen(uriName) < HTTP_URI_NAME_LENGTH)
            strcpy(_uriName, uriName);
        if (strlen(_query) < HTTP_QUERY_LENGTH)
            strcpy(_query, query);
        //if (strlen(_body) < HTTP_BODY_LENGTH)
        //    strcpy(_body, body);        
    }
    virtual ~HttpRequest(){}
    
    HTTP_METHOD_t GetMethod()
    {
        return _method;
    }
    
    char * GetUriName()
    {
        return _uriName;
    }
    
    char * GetQueryString()
    {
        return _query;
    }
    
    char * GetBody()
    {
        return _body;
    }
    
private:
    
    HTTP_METHOD_t _method; 
    char _uriName[HTTP_URI_NAME_LENGTH];
    char _query[HTTP_QUERY_LENGTH];
    char _body[HTTP_BODY_LENGTH];
};

#endif
