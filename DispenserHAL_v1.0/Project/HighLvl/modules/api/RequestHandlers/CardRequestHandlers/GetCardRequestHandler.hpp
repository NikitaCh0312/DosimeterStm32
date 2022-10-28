#ifndef GET_CARD_REQUEST_HANDLER_H_
#define GET_CARD_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/CardRequestHandlers/GetCardDto.hpp"
#include "Ethernet/Internet/httpServer/httpParser.h"
#include "modules/ModulesLocator.h"

class GetCardRequestHandler: public IRequestHandler
{
public:
    GetCardRequestHandler()
    {
      _cardsManager = ModulesLocator::GetInstance()->cardsManager;
    }
    
    virtual ~GetCardRequestHandler(){}
  
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;
            
        Flush();
        webResponse->AddHeader((char*)RES_JSONHEAD_OK);
        
        int cardId = ParseCardId(request->GetQueryString());
        Card card = _cardsManager->GetCard(cardId);
        
        GetCardDto networkDto (JsonSerializer::GetInstance(), card);
        networkDto.Serialize(_content);
        webResponse->AddContent(_content);
        Flush();
        return true;
        
    }
private:
    ICardsManager* _cardsManager;
    
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