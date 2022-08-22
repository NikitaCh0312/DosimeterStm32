#ifndef SET_CONFIGURATION_REQUEST_HANDLER_H_
#define SET_CONFIGURATION_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"

//request for configuration
//http://192.168.36.77:666/set_config?ip=value&mask=value&port=value&date=value&time=value
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
        if (request->GetMethod() != METHOD_POST)
            return false;
        
        ParseQuery();
    }
private:
    void ParseQuery()
    {
      
    }
  
};






#endif
