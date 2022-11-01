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
      
    IRequestHandler * CreateGetEventLogRequestHandler()
    {
        return new GetEventLogRequestHandler();
    }
    
    IRequestHandler * CreateClearEventLogRequestHandler()
    {
        return new ClearEventLogRequestHandler();
    }
    
    IRequestHandler * CreateEventLogInfoRequestHandler()
    {
        return new EventLogInfoRequestHandler();
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

    IRequestHandler * CreateGetCardRequestHandler()
    {
        return new GetCardRequestHandler();
    }
    
    IRequestHandler * CreateRemoveCardRequestHandler()
    {
        return new RemoveCardRequestHandler();
    }
    
    IRequestHandler * CreateGetConfigurationRequestHandler()
    {
        return new GetConfiguratuionRequestHandler();
    }
    
    IRequestHandler * CreateSetConfigurationRequestHandler()
    {
        return new SetConfigurationRequestHandler();
    }
    
    IRequestHandler * CreateGetExtendedCardsRequestHandler()
    {
        return new GetExtendedCardsRequestHandler();
    }
    
    IRequestHandler * CreateSetExtendedCardsRequestHandler()
    {
        return new SetExtendedCardsRequestHandler();
    }
    
private:
};






#endif
