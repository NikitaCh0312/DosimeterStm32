#ifndef CARDS_LIST_REQUEST_HANDLER_H_
#define CARDS_LIST_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"

class CardsListRequestHandler: public IRequestHandler
{
public:
    CardsListRequestHandler()
    {
      
    }
    
    virtual ~CardsListRequestHandler(){}
  
#warning TO REALIZE
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
      
    }
private:
};






#endif
