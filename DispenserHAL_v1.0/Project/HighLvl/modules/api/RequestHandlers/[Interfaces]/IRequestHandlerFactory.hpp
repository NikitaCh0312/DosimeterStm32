#ifndef IREQUEST_HANDLER_FACTORY_H_
#define IREQUEST_HANDLER_FACTORY_H_


#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"

#include "modules/api/RequestHandlers/DescriptionRequestHandler/DescriptionRequestHandler.hpp"

#include "modules/api/RequestHandlers/EventLogRequestHandlers/GetEventLogRequestHandler.hpp"
#include "modules/api/RequestHandlers/EventLogRequestHandlers/ClearEventLogRequestHandler.hpp"
#include "modules/api/RequestHandlers/EventLogRequestHandlers/EventLogInfoRequestHandler.hpp"

#include "modules/api/RequestHandlers/NetworkRequestHandler/NetworkRequestHandler.hpp"

#include "modules/api/RequestHandlers/CardRequestHandlers/CardsListRequestHandler.hpp"
#include "modules/api/RequestHandlers/CardRequestHandlers/AddCardRequestHandler.hpp"
#include "modules/api/RequestHandlers/CardRequestHandlers/GetCardRequestHandler.hpp"
#include "modules/api/RequestHandlers/CardRequestHandlers/RemoveCardRequestHandler.hpp"
#include "modules/api/RequestHandlers/CardRequestHandlers/GetExtendedCardsRequestHandler.hpp"
#include "modules/api/RequestHandlers/CardRequestHandlers/SetExtendedCardsRequestHandler.hpp"

#include "modules/api/RequestHandlers/ConfigurationRequestHandlers/GetConfigurationRequestHandler.hpp"
#include "modules/api/RequestHandlers/ConfigurationRequestHandlers/SetConfigurationRequestHandler.hpp"

class IRequestHandlerFactory
{
public:
    IRequestHandlerFactory()
    {
      
    }
    
    virtual ~IRequestHandlerFactory(){}
  
    virtual IRequestHandler * CreateDescriptionRequestHandler() = 0;
      
    virtual IRequestHandler * CreateGetEventLogRequestHandler() = 0;
    
    virtual IRequestHandler * CreateClearEventLogRequestHandler() = 0;
     
    virtual IRequestHandler * CreateEventLogInfoRequestHandler() = 0;
    
    virtual IRequestHandler * CreateNetworkRequestHandler() = 0;
    
    virtual IRequestHandler * CreateCardsListRequestHandler() = 0;

    virtual IRequestHandler * CreateAddCardRequestHandler() = 0;
    
    virtual IRequestHandler * CreateGetCardRequestHandler() = 0;
    
    virtual IRequestHandler * CreateRemoveCardRequestHandler() = 0;
    
    virtual IRequestHandler * CreateGetConfigurationRequestHandler() = 0;

    virtual IRequestHandler * CreateSetConfigurationRequestHandler() = 0;
    
    virtual IRequestHandler * CreateGetExtendedCardsRequestHandler() = 0;

    virtual IRequestHandler * CreateSetExtendedCardsRequestHandler() = 0;
    
private:
};






#endif
