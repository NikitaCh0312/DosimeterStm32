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
        handler->SetWebResponse(&_webResponse);
        return _resourceHandlers->TryAddValue(resourceName, handler);
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
    ApiController()
    {
        _resourceHandlers = new StringDictionary<IRequestHandler*>();
    }
    static ApiController * _instance;
    
    WebResponse _webResponse;

#warning REALIZE AND TEST REQUIRED
    void HandleGetMethod(st_http_request * request)
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
            requestHandler->Handle(&httpRequest);
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
    
    IRequestHandler * FindRequestHandler(char * resource)
    {
        IRequestHandler * handler = NULL;
        _resourceHandlers->TryGetValue(resource, &handler);
        return handler;
    }
    
#warning REALIZE AND TEST REQUIRED
    void HandlePostMethod(st_http_request * request)
    {
        _webResponse.SetFullResponse((char*)ERROR_REQUEST_PAGE);
    }
    
    void HandleErrorRequest()
    {
        _webResponse.SetFullResponse((char*)ERROR_REQUEST_PAGE);
    }
    
    
    StringDictionary<IRequestHandler*> * _resourceHandlers;
};





#endif
