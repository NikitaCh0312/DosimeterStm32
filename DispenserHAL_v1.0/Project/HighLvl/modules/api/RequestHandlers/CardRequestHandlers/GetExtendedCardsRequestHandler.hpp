#ifndef GET_EXTENDED_CARDS_REQUEST_HANDLER_H_
#define GET_EXTENDED_CARDS_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/ModulesLocator.h"
#include "GetExtendedCardsDto.hpp"

class GetExtendedCardsRequestHandler: public IRequestHandler
{
public:
    GetExtendedCardsRequestHandler()
    {
      _cardsManager = ModulesLocator::GetInstance()->cardsManager;
    }
    
    virtual ~GetExtendedCardsRequestHandler(){}
  
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;
            
        Flush();
        webResponse->AddHeader((char*)RES_JSONHEAD_OK);

        uint32_t * extendedCards = _cardsManager->GetExtendedAccessCards();
        
        GetExtendedCardsDto dto (JsonSerializer::GetInstance(), true);
        dto.Serialize(_content);
        webResponse->AddContent(_content);
        Flush();
        
        return true;
    }
private:
    ICardsManager* _cardsManager;
};






#endif
