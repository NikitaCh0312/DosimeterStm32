#ifndef IAPI_OBJECT_H_
#define IAPI_OBJECT_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
class IApiObject
{
public:
  IApiObject() {  }
  
  virtual ~IApiObject() {  }
  
  virtual void Serialize( char * outString ) = 0;
};

#endif