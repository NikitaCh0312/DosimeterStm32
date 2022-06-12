#ifndef NETWORK_REQUEST_HANDLER_H_
#define NETWORK_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/NetworkRequestHandler/NetworkSettingsDto.hpp"

class NetworkRequestHandler: public IRequestHandler
{
public:
    NetworkRequestHandler()
    {
      
    }
    
    virtual ~NetworkRequestHandler(){}
  
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;
            
        Flush();
        webResponse->AddHeader(RES_JSONHEAD_OK);
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
        NetworkSettingsDto networkDto (JsonSerializer::GetInstance(), ipAddr, port, mask);
        networkDto.Serialize(_content);
        webResponse->AddContent(_content);
        Flush();
        return true;
        
    }
private:

    char _content[100];
    
    void Flush()
    {
        for (int i = 0; i < sizeof(_content); i++)
          _content[i] = '\0';
    }
};


#endif