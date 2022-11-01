#ifndef CARDS_MANAGER_H_
#define CARDS_MANAGER_H_

#include "modules/[Interfaces]/ICardsManager.h"
#include "modules/Storage/CardsStorage.h"

class CardsManager: ICardsManager
{
public:
    CardsManager()
    {
        _storage = new CardsStorage();
    }
    virtual ~CardsManager(){}
    
    void Init()
    {
        _storage->Load();
    }
    
    CARD_STATUS_t GetCardStatus (int cardId) 
    {
        if (_storage->IsExtendedAccessCard(cardId))
            return CARD_EXT_ACCESS_STATUS;
      
        Card card = _storage->GetCard(cardId);
        if (card.Id != 0)
          return CARD_IS_ACTIVE_STATUS;
        
        return CARD_IS_NOT_BINDED_STATUS;
    }
    
    Card GetCard(int cardId)
    {
        return _storage->GetCard(cardId);
    }
    
    int AddOrUpdateCard(Card card)
    {
        if (card.TasksQuantity > MAX_TASKS_QUANTITY)
            return -1;
        
        //fill tasks that don't exist with zero values
        for (int i = card.TasksQuantity; i < MAX_TASKS_QUANTITY; i++)
        {
            card.tasks[i].Id = 0;
        }
        _storage->AddOrUpdateCard(card);
        return 0;
    }

    CardsListInfo_t GetCardsInfo()
    {
        return _storage->GetCardsListInfo();
    }
    
    void DeleteCard(int cardId)
    {
        _storage->DeleteCard(cardId);
    }
    
    void SetExtendedAccessCards(uint32_t* cardsBuffer, uint32_t cardsQuantity)
    {
        _storage->SetExtendedAccessCards(cardsBuffer, cardsQuantity);
    }
    
    uint32_t * GetExtendedAccessCards()
    {
        return _storage->GetExtendedAccessCards();
    }
    
private:
    CardsStorage* _storage;
    uint32_t _cardsQuantity;
};

#endif