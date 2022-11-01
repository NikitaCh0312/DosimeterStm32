#ifndef SET_EXTENDED_CARDS_REQUEST_HANDLER_H_
#define SET_EXTENDED_CARDS_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/ModulesLocator.h"
#include "SetExtendedCardsDto.hpp"

class SetExtendedCardsRequestHandler: public IRequestHandler
{
public:
    SetExtendedCardsRequestHandler()
    {
      _cardsManager = ModulesLocator::GetInstance()->cardsManager;
    }
    
    virtual ~SetExtendedCardsRequestHandler(){}
  
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;
            
        Flush();
        webResponse->AddHeader((char*)RES_JSONHEAD_OK);
        
        uint32_t extendedCards[10];
        ParseExtendedCardIds(request->GetQueryString(), extendedCards);
        _cardsManager->SetExtendedAccessCards(extendedCards, 10);
        
        SetExtendedCardsDto dto (JsonSerializer::GetInstance(), true);
        dto.Serialize(_content);
        webResponse->AddContent(_content);
        Flush();
        
        return true;
    }
private:
    ICardsManager* _cardsManager;
    
    void ParseExtendedCardIds(char * query, uint32_t * buffer)
    {
      
    }
};






#endif
