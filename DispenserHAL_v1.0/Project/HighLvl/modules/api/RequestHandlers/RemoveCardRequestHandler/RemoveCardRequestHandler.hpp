#ifndef REMOVE_CARD_REQUEST_HANDLER_H_
#define REMOVE_CARD_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"

class RemoveCardRequestHandler: public IRequestHandler
{
public:
    RemoveCardRequestHandler()
    {
      
    }
    
    virtual ~RemoveCardRequestHandler(){}
  
#warning TO REALIZE
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
      
    }
private:
};






#endif
