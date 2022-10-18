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
        webResponse->AddHeader((char*)RES_JSONHEAD_OK);
        int cardId = ParseCardId(request->GetQueryString());
        Card card;
        card.TasksQuantity = 5;
        GetCardDto networkDto (JsonSerializer::GetInstance(), card);
        networkDto.Serialize(_content);
        webResponse->AddContent(_content);
        Flush();
        return true;
        
    }
private:

    char _content[500];
    
    void Flush()
    {
        for (int i = 0; i < sizeof(_content); i++)
          _content[i] = '\0';
    }
    
    int ParseCardId(char * query)
    {
        char* card_id = strtok((char*)query, "&=");
        if (strcmp(card_id, "card_id"))
          return false;
        char* cardIdValue = strtok(NULL, "&=");
        int cardIdInt = atoi(cardIdValue);
        return cardIdInt;
    }
};


#endif