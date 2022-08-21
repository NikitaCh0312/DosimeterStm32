#ifndef SET_CONFIGURATION_REQUEST_HANDLER_H_
#define SET_CONFIGURATION_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"

class SetConfigurationRequestHandler: public IRequestHandler
{
public:
    SetConfigurationRequestHandler()
    {
      
    }
    
    virtual ~SetConfigurationRequestHandler(){}
  
#warning TO REALIZE
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
      
    }
private:
};






#endif
