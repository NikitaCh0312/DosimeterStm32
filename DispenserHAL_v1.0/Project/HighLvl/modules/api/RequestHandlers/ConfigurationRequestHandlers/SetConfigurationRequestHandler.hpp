#ifndef SET_CONFIGURATION_REQUEST_HANDLER_H_
#define SET_CONFIGURATION_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/Configuration.h"

//request for configuration
//http://192.168.36.77:666/set_config?ip=value&mask=value&port=value&date=value&time=value
class SetConfigurationRequestHandler: public IRequestHandler
{
public:
    SetConfigurationRequestHandler()
    {
      _config = ModulesLocator::GetInstance()->configuration;
    }
    
    virtual ~SetConfigurationRequestHandler(){}
  
#warning TO REALIZE
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_POST)
            return false;
        
        //Card card;
//        bool result = ParseQuery(request->GetQueryString(), &card);
//        if (result)
//        {
//            //if (!_cardsManager->AddCard(card))
//                return false;
//            
//        }
        
        //CreateResponse(webResponse, result);
        return true;        
    }
private:
    Configuration * _config;
 //ip=value&mask=value&port=value&date=value&time=value   
    bool ParseQuery(char * query, Card * outCard)
    {
      IpAddr_t ip;
      char* confIp = strtok((char*)query, "="); // ip
      if (strcmp(confIp, "ip"))
        return false;
      char* confIpStr = strtok(NULL, "&"); // byte.byte.byte.byte
      ip.addr_1 = atoi(strtok(NULL, "."));
      ip.addr_2 = atoi(strtok(NULL, "."));
      ip.addr_3 = atoi(strtok(NULL, "."));
      ip.addr_4 = atoi(strtok(NULL, "&"));
      
      Mask_t mask;
      char* confMask = strtok(NULL, "="); // mask
      if (strcmp(confMask, "mask"))
        return false;
      char* confMaskStr = strtok(NULL, "&"); // byte.byte.byte.byte
      mask.mask_1 = atoi(strtok(NULL, "."));
      mask.mask_2 = atoi(strtok(NULL, "."));
      mask.mask_3 = atoi(strtok(NULL, "."));
      mask.mask_4 = atoi(strtok(NULL, "&"));
      
      uint16_t port = 0;
      char* confPort = strtok(NULL, "="); // port
      if (strcmp(confPort, "port"))
        return false;
      char* confPortStr = strtok(NULL, "&"); // uint16_t
      port = atoi(confPortStr);

      //Mask_t mask;
      char* confDate = strtok(NULL, "=");    // date
      if (strcmp(confDate, "date"))
        return false;      
      char* confDateStr = strtok(NULL, "&");    // day:byte-mounth:byte-year:uint16_t
      uint8_t day = atoi(strtok(NULL, "-"));
      uint8_t mounth = atoi(strtok(NULL, "-"));
      uint16_t year = atoi(strtok(NULL, "&"));      

        
        return false;
    }
    
    void CreateResponse(WebResponse * webResponse, bool result)
    {
        //Flush();
        //webResponse->AddHeader(RES_JSONHEAD_OK);
        //AddCardDto dto (JsonSerializer::GetInstance(), result);
        //dto.Serialize(_content);
        //webResponse->AddContent(_content);
        //Flush();
    }
};






#endif
