#ifndef ADD_CARD_REQUEST_HANDLER_H_
#define ADD_CARD_REQUEST_HANDLER_H_

#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandler.hpp"
#include "modules/api/RequestHandlers/AddCardRequestHandler/AddCardDto.hpp"
#include "modules/ModulesLocator.h"
#include "stddef.h"
#include "stdlib.h"

class AddCardRequestHandler: public IRequestHandler
{
public:
    AddCardRequestHandler()
    {
        _cardsManager = ModulesLocator::GetInstance()->cardsManager;
    }
    
    virtual ~AddCardRequestHandler(){}
  
    bool Handle(HttpRequest * request, WebResponse * webResponse)
    {
        if (request->GetMethod() != METHOD_GET)
            return false;

        Card card;
        bool result = ParseQuery(request->GetQueryString(), &card);
        if (result)
        {
            if (!_cardsManager->AddOrUpdateCard(card))
                return false;
            
        }
        CreateResponse(webResponse, result);
        return true;
    }
private:
  
    char _content[100];

    ICardsManager * _cardsManager;
    
    void Flush()
    {
        for (int i = 0; i < sizeof(_content); i++)
          _content[i] = '\0';
    }
    
    bool ParseQuery(char * query, Card * outCard)
    {
        char* card_id = strtok((char*)query, "&=");
        if (strcmp(card_id, "card_id"))
          return false;
        char* cardIdValue = strtok(NULL, "&=");
        int cardIdInt = atoi(cardIdValue);
        
        char* quantity = strtok(NULL, "&=");
        if (strcmp(quantity, "quantity"))
          return false;
        char* quantityValue = strtok(NULL, "&=");
        int quantityValueInt = atoi(quantityValue);
        
        char* substanceId = strtok(NULL, "&=");
        if (strcmp(substanceId, "substanceId"))
          return false;
        char* substanceIdValue = strtok(NULL, "&=");
        int substanceIdValueInt = atoi(substanceIdValue);
        
        outCard->Id = cardIdInt;
        outCard->TasksQuantity = quantityValueInt;
        outCard->SubstanceId = substanceIdValueInt;

        for (int i = 0; i < quantityValueInt; i++)
        {
            char number[4];
            sprintf(number , "%d", i + 1);
            
            char vol[4] = {'v', '\0'};
            strcat(vol, number);
            char* vi = strtok(NULL, "&=");
            if (strcmp(vol, vi))
                return false;
            
            char* VolValue = strtok(NULL, "&=");
            float VolValueInt = atof(VolValue);
            
            char conc[4] = {'c', '\0'};
            strcat(conc, number);
            char* ci = strtok(NULL, "&=");
            if (strcmp(conc, ci))
                return false;
            
            char* ConValue = strtok(NULL, "&=");
            float ConValueInt = atof(ConValue);

            outCard->tasks[i].Id = i + 1;
            outCard->tasks[i].Volume = VolValueInt;
            outCard->tasks[i].Concentration = ConValueInt;
        }
        return true;
    }
    
    void CreateResponse(WebResponse * webResponse, bool result)
    {
        Flush();
        webResponse->AddHeader((char*)RES_JSONHEAD_OK);
        AddCardDto dto (JsonSerializer::GetInstance(), result);
        dto.Serialize(_content);
        webResponse->AddContent(_content);
        Flush();
    }
};






#endif
