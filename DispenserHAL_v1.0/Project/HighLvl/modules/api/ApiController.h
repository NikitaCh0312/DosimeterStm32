#ifndef API_CONTORLLER_H_
#define API_CONTORLLER_H_

#include "stdio.h"
#include "Ethernet/Internet/HttpServer/HttpParser.h"
#include "modules/api/WebResponse.h"
#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/HtmlPage.h"
#include "Extensions/StringDictionary.h"

class ApiController
{
public:
    static ApiController * GetInstance()
    {
        if (_instance == NULL)
            _instance = new ApiController();
        return _instance;
    }
    virtual ~ApiController(){} 
  
    bool RegisterHandler(char * resourceName, IRequestHandler * handler)
    {
        return _resourceHandlers->TryAddValue(resourceName, handler);
    }
    
    uint8_t * GetResponse(uint8_t * receivedBuffer)
    {
        st_http_request request;
        parse_http_request(&request, receivedBuffer);

        HandleRequest(&request);

        if (false)
            HandleErrorRequest();
        return (uint8_t*)_webResponse.ToString();
    }

private:
    ApiController()
    {
        _resourceHandlers = new StringDictionary<IRequestHandler*>();
    }
    static ApiController * _instance;
    
    WebResponse _webResponse;

    void HandleRequest(st_http_request * request)
    {
        char * uri = strtok((char*)request->URI, "/");
        if (!strcmp(uri, "api"))
        {
            char * resourceName = strtok(strtok(NULL, "/"), "?");
            char * query = strtok(NULL, "?");
            #warning REALIZE AND TEST REQUIRED
            char * body = "body";
            
            IRequestHandler * requestHandler = FindRequestHandler(resourceName);
            if (requestHandler == NULL)
            {
                _webResponse.SetFullResponse((char*)ERROR_REQUEST_PAGE);
                return;
            }
            HttpRequest httpRequest = HttpRequest( (HTTP_METHOD_t)request->METHOD, uri, query, body);
            if (!requestHandler->Handle(&httpRequest, &_webResponse))
              _webResponse.SetFullResponse((char*)ERROR_REQUEST_PAGE);
            return;
        }
        
        if (request->METHOD == METHOD_GET)
        {
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
    }
    
        
    IRequestHandler * FindRequestHandler(char * resource)
    {
        IRequestHandler * handler = NULL;
        _resourceHandlers->TryGetValue(resource, &handler);
        return handler;
    }
    
    void HandleErrorRequest()
    {
        _webResponse.SetFullResponse((char*)ERROR_REQUEST_PAGE);
    }
    
    
    StringDictionary<IRequestHandler*> * _resourceHandlers;
};





#endif
