#ifndef SET_CONFIGURATION_REQUEST_HANDLER_H_
#define SET_CONFIGURATION_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/Configuration.h"
#include "RTC/RTC_drv.h"


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
        bool result = ParseQuery(request->GetQueryString());
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
    bool ParseQuery(char * query)
    {
      // first part
      IpAddr_t ip;
      char* confIp = strtok((char*)query, "="); // ip
      if (strcmp(confIp, "ip"))
        return false;
      char* confIpStr = strtok(NULL, "&"); // byte.byte.byte.byte
      
      Mask_t mask;
      char* confMask = strtok(NULL, "="); // mask
      if (strcmp(confMask, "mask"))
        return false;
      char* confMaskStr = strtok(NULL, "&"); // byte.byte.byte.byte
      
      uint16_t port = 0;
      char* confPort = strtok(NULL, "="); // port
      if (strcmp(confPort, "port"))
        return false;      
      char* confPortStr = strtok(NULL, "&"); // uint16_t
      
      //Mask_t mask;
      char* confDate = strtok(NULL, "=");    // date
      if (strcmp(confDate, "date"))
        return false;   
      char* confDateStr = strtok(NULL, "&");    // day:byte-mounth:byte-year:uint16_t
      
      char* confTime = strtok(NULL, "=");    // time
      if (strcmp(confTime, "time"))
        return false;     
      char* confTimeStr = strtok(NULL, "\0");    // hours:byte-minute:byte
      
      // second part
      ip.addr_1 = atoi(strtok(confIpStr, "."));
      ip.addr_2 = atoi(strtok(NULL, "."));
      ip.addr_3 = atoi(strtok(NULL, "."));
      ip.addr_4 = atoi(strtok(NULL, "\0"));

      mask.mask_1 = atoi(strtok(confMaskStr, "."));
      mask.mask_2 = atoi(strtok(NULL, "."));
      mask.mask_3 = atoi(strtok(NULL, "."));
      mask.mask_4 = atoi(strtok(NULL, "\0"));
      
      port = atoi(confPortStr);

      uint8_t day = atoi(strtok(confDateStr, "-"));
      uint8_t mounth = atoi(strtok(NULL, "-"));
      uint16_t year = atoi(strtok(NULL, "\0"));      

      uint8_t hours = atoi(strtok(confTimeStr, "-"));
      uint8_t minute = atoi(strtok(NULL, "\0"));
      
      
      // hueta
      
      RtcDateTime_t dateTime;
      dateTime.Day = day;
      dateTime.Month = mounth;
      dateTime.Year = year % 100;
      dateTime.Hours = hours;
      dateTime.Minutes = minute;
      dateTime.Seconds = 0;
      RtcSetDateTime(&dateTime);
            
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