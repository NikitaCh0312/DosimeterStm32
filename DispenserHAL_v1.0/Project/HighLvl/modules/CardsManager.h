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
          return debugCard;
        }
    }


private:
    static CardsManager * _instance;
    CardsManager()
    {
      debugCard.Id = 907894;
      debugCard.TasksQuantity = 5;
    }
    
    Card debugCard;
};

#endif