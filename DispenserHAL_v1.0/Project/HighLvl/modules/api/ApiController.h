#ifndef API_CONTORLLER_H_
#define API_CONTORLLER_H_

#include "stdio.h"
#include "Ethernet/Internet/HttpServer/HttpParser.h"
#include "modules/api/WebResponse.h"
#include "modules/api/RequestHandler.h"

#define MAX_WEB_RESOURCES 20

typedef struct
{
    char ResourceName[10];
    RequestHandler * handler;
}ResourceValue_t;

class ApiController
{
public:
    ApiController()
    {
        _resourcesQuantity = 0;
    }
  
    virtual ~ApiController(){} 
  
    void RegisterHandler(char * resourceName, RequestHandler * handler)
    {
        if (_resourcesQuantity >= MAX_WEB_RESOURCES)
            return;
        strcpy(_resources[_resourcesQuantity].ResourceName, resourceName);
        _resources[_resourcesQuantity].handler = handler;
        _resourcesQuantity++;
    }
    
    uint8_t * GetResponse(uint8_t * receivedBuffer)
    {
        st_http_request request;
        parse_http_request(&request, receivedBuffer);
        if (request.METHOD == METHOD_GET)
        {
            HandleGetMethod(&request);
        }
        else if (request.METHOD == METHOD_POST)
        {
            HandlePostMethod(&request);
        }
        else
            HandleErrorRequest();
        return (uint8_t*)_webResponse.ToString();
    }
    
private:
    
    ResourceValue_t _resources[MAX_WEB_RESOURCES];
    uint32_t _resourcesQuantity;
    
    WebResponse _webResponse;
    
    char * GetResourceName()
    {
      
    }
    
    RequestHandler * FindRequestHandler(char * resource)
    {
        return NULL;
    }
    
    void GetHttpMethodType()
    {
      
    }
    
   
    void HandleGetMethod(st_http_request * request)
    {
        char * uri = strtok((char*)request->URI, "/");
        if (!strcmp(uri, "api"))
        {
            char debugBuffer[100];
            char * resourceName = strtok(strtok(NULL, "/"), "?");
            strcpy(debugBuffer, resourceName);
            char * query = strtok(NULL, "?");
            strcpy(debugBuffer, query);
            RequestHandler * requestHandler = FindRequestHandler(resourceName);
            if (requestHandler == NULL)
            {
                _webResponse.SetFullResponse((char*)ERROR_REQUEST_PAGE);
                return;
            }
            requestHandler->Handle(query);
        }
        
        if (!strcmp(uri, "about"))
        {
            _webResponse.AddHeader(HTML_HEADER);
            _webResponse.AddContent((char*)AboutPageHtml);
            return;
        }
        else if (!strcmp(uri, "contacts"))
        {
            _webResponse.AddHeader(HTML_HEADER);
            _webResponse.AddContent((char*)ContactsPageHtml);
            return;
        }
        else
        {
            _webResponse.AddHeader(HTML_HEADER);
            _webResponse.AddContent((char*)MainPageHtml);
            return;            
        }
    }
    
    void HandlePostMethod(st_http_request * request)
    {
        _webResponse.SetFullResponse((char*)ERROR_REQUEST_PAGE);
    }
    
    void HandleErrorRequest()
    {
        _webResponse.SetFullResponse((char*)ERROR_REQUEST_PAGE);
    }
};





#endif
