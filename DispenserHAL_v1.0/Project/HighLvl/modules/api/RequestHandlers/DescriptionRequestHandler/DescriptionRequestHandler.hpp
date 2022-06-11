#ifndef DESCRIPTION_REQUEST_HANDLER_H_
#define DESCRIPTION_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/DescriptionRequestHandler/DescriptionDto.hpp"

class DescriptionRequestHandler: public IRequestHandler
{
public:
    DescriptionRequestHandler()
    {
      
    }
    
    virtual ~DescriptionRequestHandler(){}
    
    void Handle(HttpRequest * request, WebResponse * webResponse)
    {
       webResponse->AddHeader(RES_JSONHEAD_OK);

       DescriptionDto dto (JsonSerializer::GetInstance(), "123", "dosator", "v1.0.0");
       dto.Serialize(_content);
       webResponse->AddContent(_content);
       Flush();
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
