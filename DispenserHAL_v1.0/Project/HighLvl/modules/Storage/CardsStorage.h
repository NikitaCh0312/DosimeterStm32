#ifndef CARDS_STORAGE_H_
#define CARDS_STORAGE_H_

#include "Components/Flash/W25Q256.h"
#include "modules/Storage/Crc16.h"
#include "modules/Storage/BaseStorage.h"

#include "modules/Card.h"

#define CARDS_START_ADDRESS 0x1000
#define CARDS_START_SECTOR_NUMBER 2
#define CARDS_END_SECTOR_NUMBER 4
#define CARD_SIZE_BYTES 255

#define MAX_CARDS_QUANTITY 20

typedef struct
{
    Card card;
    uint16_t crc;
}CardRecord_t;

typedef struct
{
    uint32_t CardsQuantity;
    CardRecord_t CardsBuffer[MAX_CARDS_QUANTITY];
}CardsStorageBuffer_t;

CardsStorageBuffer_t CardsStorageBuffer;

class CardsStorage : BaseStorage
{
public:
    CardsStorage()
    {
      
    }
    
    void Load()
    {
      W25qxx_ReadBytes((uint8_t*)&CardsStorageBuffer, CONFIGURATION_START_ADDRESS, sizeof(CardsStorageBuffer_t));
    }
    
    void AddCard(Card card)
    {
      
    }
    
    void RemoveCard(int cardId)
    {
      
    }
    
    Card GetCard(int cardId)
    {
      
    }
    
    int GetCardsQuantity()
    {
      
    }
private:
    
};


#endif