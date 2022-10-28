#ifndef REMOVE_CARD_REQUEST_HANDLER_H_
#define REMOVE_CARD_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/ModulesLocator.h"
#include "RemoveCardDto.hpp"

class RemoveCardRequestHandler: public IRequestHandler
{
public:
    RemoveCardRequestHandler()
    {
      _cardsManager = ModulesLocator::GetInstance()->cardsManager;
    }
    
    virtual ~RemoveCardRequestHandler(){}
  
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;
            
        Flush();
        webResponse->AddHeader((char*)RES_JSONHEAD_OK);
        
        int cardId = ParseCardId(request->GetQueryString());
        _cardsManager->DeleteCard(cardId);
        
        RemoveCardDto removeCardDto (JsonSerializer::GetInstance(), true);
        removeCardDto.Serialize(_content);
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
