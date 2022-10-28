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

#define CARD_DEFAULT_ID 0

#define EXTENDED_ACCESS_CARDS_NUMBER 10

extern w25qxx_t w25qxx;

//total 5168 bytes (= 1292 words (1word=32bit))
typedef struct
{
    //40 bytes
    uint32_t extendedAccessCards[EXTENDED_ACCESS_CARDS_NUMBER];
    //4 bytes
    uint32_t CardsQuantity;
    //256 * 20= 5120 bytes 
    Card CardsBuffer[MAX_CARDS_QUANTITY];
    //2 bytes
    uint16_t reserved;
    //2 bytes
    uint16_t Crc;
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
        ReadBufferBySectors((uint8_t*)&CardsStorageBuffer, CARDS_START_SECTOR_NUMBER, sizeof(CardsStorageBuffer_t));

        if (CheckCrc((uint8_t*)&CardsStorageBuffer, sizeof(CardsStorageBuffer_t)) == CRC_ERROR)
          SetDefaultValues();
    }
    
    void AddOrUpdateCard(Card card)
    {
        //if card exists - edit this card
        for (int i = 0; i < MAX_CARDS_QUANTITY; i++)
        {
            if (CardsStorageBuffer.CardsBuffer[i].Id == card.Id)
            {
                CardsStorageBuffer.CardsBuffer[i].Id = card.Id;
                CardsStorageBuffer.CardsBuffer[i].TasksQuantity = card.TasksQuantity;
                CardsStorageBuffer.CardsBuffer[i].SubstanceId = card.SubstanceId;
                for (int j = 0; j < MAX_TASKS_QUANTITY; j++)
                {
                    CardsStorageBuffer.CardsBuffer[i].tasks[j].Id = card.tasks[j].Id;
                    CardsStorageBuffer.CardsBuffer[i].tasks[j].Volume = card.tasks[j].Volume;
                    CardsStorageBuffer.CardsBuffer[i].tasks[j].Concentration = card.tasks[j].Concentration;
                }
                UpdateStorage();
                return;
            }
        }
        
        //add new card
        for (int i = 0; i < MAX_CARDS_QUANTITY; i++)
        {
            if (CardsStorageBuffer.CardsBuffer[i].Id == 0)
            {
                CardsStorageBuffer.CardsBuffer[i].Id = card.Id;
                CardsStorageBuffer.CardsBuffer[i].TasksQuantity = card.TasksQuantity;
                CardsStorageBuffer.CardsBuffer[i].SubstanceId = card.SubstanceId;
                for (int j = 0; j < MAX_TASKS_QUANTITY; j++)
                {
                    CardsStorageBuffer.CardsBuffer[i].tasks[j].Id = card.tasks[j].Id;
                    CardsStorageBuffer.CardsBuffer[i].tasks[j].Volume = card.tasks[j].Volume;
                    CardsStorageBuffer.CardsBuffer[i].tasks[j].Concentration = card.tasks[j].Concentration;
                }
                break;
            }
        }
        UpdateStorage();
    }
    
    Card GetCard(int cardId)
    {
        Card card;
        card.Id = 0;
        for (int i = 0; i < MAX_CARDS_QUANTITY; i++)
        {
            if (CardsStorageBuffer.CardsBuffer[i].Id == cardId)
              return CardsStorageBuffer.CardsBuffer[i];
        }
        return card;
    }
    
    int GetCardsQuantity()
    {
        int counter = 0;
        for (int i = 0; i < MAX_CARDS_QUANTITY; i++)
        {
            if (CardsStorageBuffer.CardsBuffer[i].Id != CARD_DEFAULT_ID)
              counter++;
        }
        return counter;
    }
    
    CardsListInfo_t GetCardsListInfo()
    {
        CardsListInfo_t cardsInfo;
        cardsInfo.CardsQuantity = GetCardsQuantity();
        
        int counter = 0;
        for (int i = 0; i < MAX_CARDS_QUANTITY; i++)
        {
            if (CardsStorageBuffer.CardsBuffer[i].Id != CARD_DEFAULT_ID)
            {
                cardsInfo.CardIdsList[counter++] = CardsStorageBuffer.CardsBuffer[i].Id;
            }
        }
        return cardsInfo;
    }
    
    void DeleteCard(int cardId)
    {
        for (int i = 0; i < MAX_CARDS_QUANTITY; i++)
        {
            if (CardsStorageBuffer.CardsBuffer[i].Id == cardId)
            {
                CardsStorageBuffer.CardsBuffer[i].Id = CARD_DEFAULT_ID;
                CardsStorageBuffer.CardsBuffer[i].TasksQuantity = 0;
                CardsStorageBuffer.CardsBuffer[i].SubstanceId = 0;
                for (int j = 0; j < MAX_TASKS_QUANTITY; j++)
                {
                    CardsStorageBuffer.CardsBuffer[i].tasks[j].Id = 0;
                    CardsStorageBuffer.CardsBuffer[i].tasks[j].Volume = 0;
                    CardsStorageBuffer.CardsBuffer[i].tasks[j].Concentration = 0;
                }
                break;
            }
        }
        UpdateStorage();
    }
    
    bool IsExtendedAccessCard(int cardId)
    {
        if (cardId == CARD_DEFAULT_ID)
            return false;
        
        for (int i = 0; i < EXTENDED_ACCESS_CARDS_NUMBER; i++)
        {
            if (CardsStorageBuffer.extendedAccessCards[i] == cardId)
              return true;
        }
        return false;
    }
    
private:
  
    void SetDefaultValues()
    {
        for (int i = 0; i < EXTENDED_ACCESS_CARDS_NUMBER; i++)
        {
            CardsStorageBuffer.extendedAccessCards[i] = CARD_DEFAULT_ID;
        }
      
        CardsStorageBuffer.CardsQuantity = 0;
        for (int i = 0; i < MAX_CARDS_QUANTITY; i++)
        {
            CardsStorageBuffer.CardsBuffer[i].Id = 0;
            CardsStorageBuffer.CardsBuffer[i].TasksQuantity = 0;
            CardsStorageBuffer.CardsBuffer[i].SubstanceId = 0;
            for (int j = 0; j < MAX_TASKS_QUANTITY; j++)
            {
                CardsStorageBuffer.CardsBuffer[i].tasks[j].Id = 0;
                CardsStorageBuffer.CardsBuffer[i].tasks[j].Volume = 0.0f;
                CardsStorageBuffer.CardsBuffer[i].tasks[j].Concentration = 0.0f;
            }
        }
        UpdateStorage();
    }
    
    void UpdateStorage()
    {
        W25qxx_EraseSector(CARDS_START_SECTOR_NUMBER);
        W25qxx_EraseSector(CARDS_START_SECTOR_NUMBER + 1);
        W25qxx_EraseSector(CARDS_START_SECTOR_NUMBER + 2);
        CardsStorageBuffer.Crc = GetCrc((uint8_t*)&CardsStorageBuffer, sizeof(CardsStorageBuffer_t) - 2);
        WriteBufferBySectors((uint8_t*)&CardsStorageBuffer, CARDS_START_SECTOR_NUMBER, sizeof(CardsStorageBuffer_t));
    }
    
    void WriteBufferBySectors(uint8_t* buffer, uint32_t sectorAddress, uint32_t bytesNumber)
    {
        int bytesLeft = bytesNumber;
        int currentSectorAddress = sectorAddress;
        int bufferOffset = 0;
        do
        {
            if (bytesLeft >= w25qxx.SectorSize)
            {
                W25qxx_WriteSector(buffer + bufferOffset, currentSectorAddress, 0, w25qxx.SectorSize);
                bytesLeft = bytesLeft - w25qxx.SectorSize;
                currentSectorAddress += 1;
                bufferOffset += w25qxx.SectorSize;
            }
            else
            {
                W25qxx_WriteSector(buffer + bufferOffset, currentSectorAddress, 0, bytesLeft);
                bytesLeft = 0;
            }
        }
        while(bytesLeft > 0);
    }
    
    void ReadBufferBySectors(uint8_t* buffer, uint32_t sectorAddress, uint32_t bytesNumber)
    {
        int bytesLeft = bytesNumber;
        int currentSectorAddress = sectorAddress;
        int bufferOffset = 0;
        do
        {
            if (bytesLeft >= w25qxx.SectorSize)
            {
                W25qxx_ReadSector(buffer + bufferOffset, currentSectorAddress, 0, w25qxx.SectorSize);
                bytesLeft = bytesLeft - w25qxx.SectorSize;
                currentSectorAddress += 1;
                bufferOffset += w25qxx.SectorSize;
            }
            else
            {
                W25qxx_ReadSector(buffer + bufferOffset, currentSectorAddress, 0, bytesLeft);
                bytesLeft = 0;
            }
        }
        while(bytesLeft > 0);
    }
};


#endif