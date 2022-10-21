#ifndef CARDS_LIST_API_H_
#define CARDS_LIST_API_H_

#include "stddef.h"
#include "stdint.h"

#include "modules/Json/JsonSerializer.h"
#include "modules/api/RequestHandlers/[Interfaces]/IDtoObject.hpp"

class CardsListDto: public IDtoObject
{
public:
  CardsListDto(JsonSerializer * serializer, int * cardsList, int cardsQuantity)
  {
      _serializer = serializer;
      _cardsQuantity = cardsQuantity;
      _cardsList = cardsList;
  }
  
  void Serialize( char * outString )
  {
      _serializer->WriteStartObject(outString);
      
      strcat(outString, "\"");
      strcat(outString, CARD_IDS_PROPERTY);
      strcat(outString, "\"");
      strcat(outString, ":");
      
      //creating list of cards ids
      _serializer->WriteStartArray(outString);
      for (int i = 0; i < _cardsQuantity; i++)
      {
          strcat(outString, "\"");
          char cardIdValue[20];
          sprintf(cardIdValue, "%d", _cardsList[i]);
          strcat(outString, cardIdValue);
          strcat(outString, "\"");
          strcat(outString, ",");
      }
      _serializer->WriteEndArray(outString);
      
      _serializer->WriteEndObject(outString);
  }
  
private:
  
  JsonSerializer * _serializer;
  int * _cardsList;
  int _cardsQuantity;
  
  char * CARD_IDS_PROPERTY = "CardIds";
};

#endif