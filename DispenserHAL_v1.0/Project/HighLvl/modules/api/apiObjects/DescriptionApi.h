#ifndef NETWORK_SETTINGS_API_H_
#define NETWORK_SETTINGS_API_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/apiObjects/[Interfaces]/IApiObject.h"
#include "modules/Configuration.h"

class DescriptionApi: public IApiObject
{
public:
  DescriptionApi(JsonSerializer * serializer,
                 char * serialNumber,
                 char * model,
                 char * firmwareVersion)
  {
      strcpy(_serialNumber, serialNumber);
      strcpy(_model, model);
      strcpy(_firmwareVersion, firmwareVersion);      
  }
  
  void Serialize( char * outString )
  {
      _serializer->WriteStartObject(outString);
      _serializer->WriteProperty(outString, SERIAL_NUMBER_PROPERTY_NAME, _serialNumber);
      _serializer->WriteProperty(outString, MODEL_PROPERTY_NAME, _model);
      _serializer->WriteProperty(outString, FIRMWARE_PROPERTY_NAME, _firmwareVersion);
      _serializer->WriteEndObject(outString);
  }
private:
  char * SERIAL_NUMBER_PROPERTY_NAME = "serial_number";
  char * MODEL_PROPERTY_NAME = "model";
  char * FIRMWARE_PROPERTY_NAME = "firmware";
    
  JsonSerializer * _serializer;
  
  char _serialNumber[10];
  
  char _model[10];
  
  char _firmwareVersion[10];
};

#endif