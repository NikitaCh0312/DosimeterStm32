#ifndef CARDS_MANAGER_H_
#define CARDS_MANAGER_H_

#include "modules/[Interfaces]/ICardsManager.h"

class CardsManager: ICardsManager
{
public:
    CardsManager()
    {
        debugCard1.Id = 907894;
        debugCard1.TasksQuantity = 10;
        debugCard1.tasks[0].Id = 1;
        debugCard1.tasks[0].Volume = 1.0f;
        debugCard1.tasks[0].Concentration = 5.0f;
        debugCard1.tasks[1].Id = 2;
        debugCard1.tasks[1].Volume = 1;
        debugCard1.tasks[1].Concentration = 2.5f;
        debugCard1.tasks[2].Id = 2;
        debugCard1.tasks[2].Volume = 1;
        debugCard1.tasks[2].Concentration = 1.0f;
        debugCard1.tasks[3].Id = 3;
        debugCard1.tasks[3].Volume = 2;
        debugCard1.tasks[3].Concentration = 5.0f;
        debugCard1.tasks[4].Id = 4;
        debugCard1.tasks[4].Volume = 2.5f;
        debugCard1.tasks[4].Concentration = 3.0f;
        debugCard1.tasks[5].Id = 5;
        debugCard1.tasks[5].Volume = 4.0f;
        debugCard1.tasks[5].Concentration = 0.5f;
        debugCard1.tasks[6].Id = 6;
        debugCard1.tasks[6].Volume = 10.0f;
        debugCard1.tasks[6].Concentration = 1.5f;
        debugCard1.tasks[7].Id = 7;
        debugCard1.tasks[7].Volume = 12.5f;
        debugCard1.tasks[7].Concentration = 1.0f;
        debugCard1.tasks[8].Id = 8;
        debugCard1.tasks[8].Volume = 15.0f;
        debugCard1.tasks[8].Concentration = 0.4f;
        debugCard1.tasks[9].Id = 9;
        debugCard1.tasks[9].Volume = 20.0f;
        debugCard1.tasks[9].Concentration = 1.0f;
        

        //for (int i = 0; i < debugCard1.TasksQuantity; i++)
        //{
        //    debugCard1.tasks[i].Volume = 100 + i * 2;
        //    debugCard1.tasks[i].Concentration = 10 + i * 2;
        //}
        
        debugCard2.Id = 9722774;
        debugCard2.TasksQuantity = 5;
        debugCard2.tasks[0].Id = 0;
        debugCard2.tasks[0].Volume = 1.0f;
        debugCard2.tasks[0].Concentration = 3.5f;
        debugCard2.tasks[1].Id = 1;
        debugCard2.tasks[1].Volume = 1.5f;
        debugCard2.tasks[1].Concentration = 4.5f;
        debugCard2.tasks[2].Id = 2;
        debugCard2.tasks[2].Volume = 3.0f;
        debugCard2.tasks[2].Concentration = 0.1f;
        debugCard2.tasks[3].Id = 3;
        debugCard2.tasks[3].Volume = 5.0f;
        debugCard2.tasks[3].Concentration = 2.0f;
        debugCard2.tasks[4].Id = 4;
        debugCard2.tasks[4].Volume = 7.5f;
        debugCard2.tasks[4].Concentration = 1.0f;
    }
    
    virtual ~CardsManager(){}
    
    CARD_STATUS_t GetCardStatus (int cardId) 
    {
        if (cardId == 908904)
            return CARD_EXT_ACCESS_STATUS;

        if (cardId == 907894)
            return CARD_IS_ACTIVE_STATUS;
        
        if (cardId == 9722774)
            return CARD_IS_ACTIVE_STATUS;
        
        return CARD_IS_NOT_BINDED_STATUS;
    }
    
    Card GetCard(int cardId)
    {
        if (cardId == 907894)
        {
          return debugCard1;
        }
        if (cardId == 9722774)
        {
          return debugCard2;
        }
    }
    
    int AddCard(Card card)
    {
      
    }


private:

    Card debugCard1;
    Card debugCard2;
};

#endif