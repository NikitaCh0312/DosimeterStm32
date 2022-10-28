#ifndef GET_CONFIGURATION_REQUEST_HANDLER_H_
#define GET_CONFIGURATION_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "GetConfigurationDto.hpp"

class GetConfiguratuionRequestHandler: public IRequestHandler
{
public:
    GetConfiguratuionRequestHandler()
    {
      
    }
    
    virtual ~GetConfiguratuionRequestHandler(){}
  
#warning TO REALIZE
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;
            
        Flush();
        webResponse->AddHeader((char*)RES_JSONHEAD_OK);
        
        IpAddr_t ipAddr;
        ipAddr.addr_1 = 192;
        ipAddr.addr_2 = 168;
        ipAddr.addr_3 = 0;
        ipAddr.addr_4 = 55;
        Mask_t mask;
        mask.mask_1 = 255;
        mask.mask_2 = 255;
        mask.mask_3 = 0;
        mask.mask_4 = 0;
        uint32_t port = 666;
        GetConfigurationDto dto = GetConfigurationDto(JsonSerializer::GetInstance(),
                                                      (char*)"192.168.36.77",
                                                      (char*)"666",
                                                      (char*)"255.255.255.0",
                                                      (char*)"08/22/2022",
                                                      (char*)"12:45");
        dto.Serialize(_content);
      
        webResponse->AddContent(_content);
        Flush();
        return true;
    }
private:
};






#endif
