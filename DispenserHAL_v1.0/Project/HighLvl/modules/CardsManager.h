#ifndef CARDS_MANAGER_H_
#define CARDS_MANAGER_H_

#include "modules/[Interfaces]/ICardsManager.h"

class CardsManager: ICardsManager
{
public:

    static CardsManager * GetInstance()
    {
        if (_instance == NULL)
            _instance = new CardsManager();
        return _instance;
    }

    CARD_STATUS_t GetCardStatus (uint32_t cardId) 
    {
        if (cardId == 908904)
            return CARD_EXT_ACCESS_STATUS;

        if (cardId == 907894)
            return CARD_IS_ACTIVE_STATUS;
        
        return CARD_IS_NOT_BINDED_STATUS;
    }
    
    Card GetCard(uint32_t cardId)
    {
        if (cardId == 907894)
        {
          return debugCard1;
        }
    }
    
    int AddCard(Card card)
    {
      
    }


private:
    static CardsManager * _instance;
    CardsManager()
    {
        debugCard1.Id = 907894;
        debugCard1.TasksQuantity = 5;
        debugCard1.tasks[0].Volume = 1.0f;
        debugCard1.tasks[0].Concentration = 5.0f;
        debugCard1.tasks[1].Volume = 1;
        debugCard1.tasks[1].Concentration = 2.5f;
        debugCard1.tasks[2].Volume = 1;
        debugCard1.tasks[2].Concentration = 1.0f;
        debugCard1.tasks[3].Volume = 2;
        debugCard1.tasks[3].Concentration = 5.0f;
        debugCard1.tasks[4].Volume = 2;
        debugCard1.tasks[4].Concentration = 3.0f;

        //for (int i = 0; i < debugCard1.TasksQuantity; i++)
        //{
        //    debugCard1.tasks[i].Volume = 100 + i * 2;
        //    debugCard1.tasks[i].Concentration = 10 + i * 2;
        //}
        
        debugCard2.Id = 888888;
        debugCard2.TasksQuantity = 5;
        for (int i = 0; i < debugCard2.TasksQuantity; i++)
        {
            debugCard2.tasks[i].Volume = 200 + i * 2;
            debugCard2.tasks[i].Concentration = 20 + i * 2;
        }
    }
    
    Card debugCard1;
    Card debugCard2;
};

#endif