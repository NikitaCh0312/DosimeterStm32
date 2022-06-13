#ifndef GET_CARD_REQUEST_HANDLER_H_
#define GET_CARD_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/GetCardRequestHandler/GetCardDto.hpp"
#include "Ethernet/Internet/httpServer/httpParser.h"

class GetCardRequestHandler: public IRequestHandler
{
public:
    GetCardRequestHandler()
    {
      
    }
    
    virtual ~GetCardRequestHandler(){}
  
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;
            
        Flush();
        webResponse->AddHeader(RES_JSONHEAD_OK);
        Card card;
        GetCardDto networkDto (JsonSerializer::GetInstance(), card);
        networkDto.Serialize(_content);
        webResponse->AddContent(_content);
        Flush();
        return true;
        
    }
private:

    char _content[100];
    
    void Flush()
    {
        for (int i = 0; i < sizeof(_content); i++)
          _content[i] = '\0';
    }
};


#endif