#ifndef IREQUEST_HANDLER_FACTORY_H_
#define IREQUEST_HANDLER_FACTORY_H_


#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/DescriptionRequestHandler/DescriptionRequestHandler.hpp"
#include "modules/api/RequestHandlers/EventLogRequestHandler/EventLogRequestHandler.hpp"
#include "modules/api/RequestHandlers/NetworkRequestHandler/NetworkRequestHandler.hpp"
#include "modules/api/RequestHandlers/CardsListRequestHandler/CardsListRequestHandler.hpp"
#include "modules/api/RequestHandlers/AddCardRequestHandler/AddCardRequestHandler.hpp"


class IRequestHandlerFactory
{
public:
    IRequestHandlerFactory()
    {
      
    }
    
    virtual ~IRequestHandlerFactory(){}
  
    virtual IRequestHandler * CreateDescriptionRequestHandler() = 0;
      
    virtual IRequestHandler * CreateEventLogRequestHandler() = 0;
      
    virtual IRequestHandler * CreateNetworkRequestHandler() = 0;
    
    virtual IRequestHandler * CreateCardsListRequestHandler() = 0;

    virtual IRequestHandler * CreateAddCardRequestHandler() = 0;

private:
};






#endif
