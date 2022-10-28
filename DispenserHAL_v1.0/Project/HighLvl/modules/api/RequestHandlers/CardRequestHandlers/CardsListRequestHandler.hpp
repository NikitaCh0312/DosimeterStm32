#ifndef CARDS_LIST_REQUEST_HANDLER_H_
#define CARDS_LIST_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/CardRequestHandlers/CardsListDto.hpp"
#include "modules/ModulesLocator.h"

class CardsListRequestHandler: public IRequestHandler
{
public:
    CardsListRequestHandler()
    {
      _cardsManager = ModulesLocator::GetInstance()->cardsManager;
    }
    
    virtual ~CardsListRequestHandler(){}

    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;
            
        Flush();
        webResponse->AddHeader((char*)RES_JSONHEAD_OK);
        
        CardsListInfo_t cardsInfo = _cardsManager->GetCardsInfo();
        int cards[MAX_CARDS_QUANTITY];
        for (int i = 0; i < cardsInfo.CardsQuantity; i++)
        {
            cards[i] = cardsInfo.CardIdsList[i];
        }
        
        CardsListDto cardsListDto (JsonSerializer::GetInstance(), cards, cardsInfo.CardsQuantity);
        cardsListDto.Serialize(_content);
        webResponse->AddContent(_content);
        Flush();
        return true;
        
    }
private:
    ICardsManager* _cardsManager;
};






#endif
