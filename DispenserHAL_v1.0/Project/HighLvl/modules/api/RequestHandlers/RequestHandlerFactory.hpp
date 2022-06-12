#ifndef REQUEST_HANDLER_FACTORY_H_
#define REQUEST_HANDLER_FACTORY_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandlerFactory.hpp"

class RequestHandlerFactory: public IRequestHandlerFactory
{
public:
    RequestHandlerFactory()
    {
      
    }
    
    virtual ~RequestHandlerFactory(){}
  
    IRequestHandler * CreateDescriptionRequestHandler()
    {
        return new DescriptionRequestHandler();
    }
      
    IRequestHandler * CreateEventLogRequestHandler()
    {
        return new EventLogRequestHandler();
    }
    
      
    IRequestHandler * CreateNetworkRequestHandler()
    {
        return new NetworkRequestHandler();
    }

    IRequestHandler * CreateCardsListRequestHandler()
    {
        return new CardsListRequestHandler();
    }

    IRequestHandler * CreateAddCardRequestHandler()
    {
        return new AddCardRequestHandler();
    }

private:
};






#endif
