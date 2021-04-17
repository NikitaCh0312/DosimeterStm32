#ifndef DTO_OBJECT_H_
#define DTO_OBJECT_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
class IDtoObject
{
public:
  IDtoObject() {  }
  
  virtual ~IDtoObject() {  }
  
  virtual void Serialize( char * outString ) = 0;
};

#endif