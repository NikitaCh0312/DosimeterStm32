#ifndef CARDS_LIST_REQUEST_HANDLER_H_
#define CARDS_LIST_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"

#include "modules/ModulesLocator.h"

class CardsListRequestHandler: public IRequestHandler
{
public:
    CardsListRequestHandler()
    {
      _cardsManager = ModulesLocator::GetInstance()->cardsManager;
    }
    
    virtual ~CardsListRequestHandler(){}
  
#warning TO REALIZE
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
      
    }
private:
    ICardsManager* _cardsManager;
};






#endif
