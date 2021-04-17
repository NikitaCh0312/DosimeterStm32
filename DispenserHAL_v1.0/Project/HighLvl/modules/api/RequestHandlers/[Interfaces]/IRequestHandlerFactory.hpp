#ifndef IREQUEST_HANDLER_FACTORY_H_
#define IREQUEST_HANDLER_FACTORY_H_


#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/DescriptionRequestHandler/DescriptionRequestHandler.hpp"
#include "modules/api/RequestHandlers/EventLogRequestHandler/EventLogRequestHandler.hpp"
#include "modules/api/RequestHandlers/NetworkRequestHandler/NetworkRequestHandler.hpp"


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
    
private:
};






#endif
