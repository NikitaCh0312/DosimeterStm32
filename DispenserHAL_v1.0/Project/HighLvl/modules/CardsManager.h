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
    }
    
    Card GetCard(uint32_t cardId)
    {
        if (cardId == 907894)
        {
          return debugCard1;
        }
    }


private:
    static CardsManager * _instance;
    CardsManager()
    {
        debugCard1.Id = 907894;
        debugCard1.TasksQuantity = 5;
        for (int i = 0; i < debugCard1.TasksQuantity; i++)
        {
            debugCard1.tasks[i].Volume = 100 + i * 2;
            debugCard1.tasks[i].Concentration = 10 + i * 2;
        }
        
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