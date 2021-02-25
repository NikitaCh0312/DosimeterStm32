#ifndef API_HANDLER_H_
#define API_HANDLER_H_


#include "modules/api/WebResponse.h"

class ApiHandler
{
public:
  ApiHandler()
  {
    
  }
  virtual ~ApiHandler(){}
  
  virtual WebResponse Handle(char * uri) = 0;
  
private:
  
  
};






#endif
