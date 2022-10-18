#ifndef GET_CARD_DTO_H_
#define GET_CARD_DTO_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"
#include "modules/Card.h"

class GetCardDto: public IDtoObject
{
public:
  GetCardDto(JsonSerializer * serializer,
             Card card)
  {
      _serializer = serializer;
      _card = card;
  }
  
  void Serialize( char * outString )
  {
      _serializer->WriteStartObject(outString);
      _serializer->WriteProperty(outString, ID_PROPERTY_NAME, "7878");
      _serializer->WriteEndProperty(outString);
      _serializer->WriteProperty(outString, SUBSTANCE_ID_PROPERTY_NAME, "5656");
      _serializer->WriteEndProperty(outString);
      
      //creating list of cardsTasks
      strcat(outString, "\"");
      strcat(outString, TASKS_PROPERTY_NAME);
      strcat(outString, "\"");
      strcat(outString, ":");
      
      _serializer->WriteStartArray(outString);
      for (int i = 0; i < _card.TasksQuantity; i++)
      {
          _serializer->WriteStartObject(outString);
          _serializer->WriteProperty(outString, ID_PROPERTY_NAME, "111");
          _serializer->WriteEndProperty(outString);
          _serializer->WriteProperty(outString, VOLUME_PROPERTY_NAME, "222");
          _serializer->WriteEndProperty(outString);
          _serializer->WriteProperty(outString, CONCENTRATION_PROPERTY_NAME, "333");
          _serializer->WriteEndObject(outString);
          strcat(outString, ",");
      }
      _serializer->WriteEndArray(outString);
      
      _serializer->WriteEndObject(outString);
  }
  
private:
  
  char * ID_PROPERTY_NAME = "Id";
  char * SUBSTANCE_ID_PROPERTY_NAME = "SubstanceId";
  char * TASKS_PROPERTY_NAME = "Tasks";
  char * VOLUME_PROPERTY_NAME = "V";
  char * CONCENTRATION_PROPERTY_NAME = "C";

  JsonSerializer * _serializer;

  Card _card;
};

#endif