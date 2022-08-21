#ifndef SET_CONFIGURATION_DTO_H_
#define SET_CONFIGURATION_DTO_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"

class SetConfigurationDto: public IDtoObject
{
public:
  SetConfigurationDto(JsonSerializer * serializer)
  {
      _serializer = serializer;
  }
  
  void Serialize( char * outString )
  {
      
  }
  
private:
  
  JsonSerializer * _serializer;
};

#endif