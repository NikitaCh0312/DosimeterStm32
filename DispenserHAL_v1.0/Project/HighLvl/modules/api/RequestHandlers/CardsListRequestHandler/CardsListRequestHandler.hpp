#ifndef CARDS_LIST_REQUEST_HANDLER_H_
#define CARDS_LIST_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/CardsListRequestHandler/CardsListDto.hpp"
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
        int cards[5];
        cards[0] = 908904;
        cards[1] = 908905;
        cards[2] = 908906;
        cards[3] = 908907;
        cards[4] = 908908;
        CardsListDto cardsListDto (JsonSerializer::GetInstance(), cards, 5);
        cardsListDto.Serialize(_content);
        webResponse->AddContent(_content);
        Flush();
        return true;
        
    }
private:
    ICardsManager* _cardsManager;
    char _content[100];
    
    void Flush()
    {
        for (int i = 0; i < sizeof(_content); i++)
          _content[i] = '\0';
    }
};






#endif
