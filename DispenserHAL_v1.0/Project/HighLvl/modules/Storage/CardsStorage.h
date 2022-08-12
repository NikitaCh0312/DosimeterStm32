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

extern w25qxx_t w25qxx;

//total 5128 bytes (= 1282 words (1word=32bit))
typedef struct
{
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

//uint8_t bufferBefore[5500];
//uint8_t bufferAfter[5500];

class CardsStorage : BaseStorage
{
public:
    CardsStorage()
    {
      
    }
    
    void Load()
    {
        ReadBufferBySectors((uint8_t*)&CardsStorageBuffer, CARDS_START_SECTOR_NUMBER, sizeof(CardsStorageBuffer_t));
        
        //uint8_t* storage = (uint8_t*)&CardsStorageBuffer;
        //for (int i = 0; i < sizeof(CardsStorageBuffer_t); i++)
        //  bufferBefore[i] = storage[i];
        
        //uint16_t crc = GetCrc((uint8_t*)&CardsStorageBuffer, sizeof(CardsStorageBuffer_t) - 2);
        if (CheckCrc((uint8_t*)&CardsStorageBuffer, sizeof(CardsStorageBuffer_t)) == CRC_ERROR)
          SetDefaultValues();
        
        //uint8_t* storageAfter = (uint8_t*)&CardsStorageBuffer;
        //for (int i = 0; i < sizeof(CardsStorageBuffer_t); i++)
        //  bufferAfter[i] = storageAfter[i];
    }
    
    void AddCard(Card card)
    {
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
            }
        }
        UpdateStorage();
    }
    
    void RemoveCard(int cardId)
    {
        for (int i = 0; i < MAX_CARDS_QUANTITY; i++)
        {
            if (CardsStorageBuffer.CardsBuffer[i].Id == cardId)
              SetCardSlotDefaultValues((Card*)&(CardsStorageBuffer.CardsBuffer[i]));
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
            if (CardsStorageBuffer.CardsBuffer[i].Id != 0)
              counter++;
        }
        return counter;
    }
private:
  
    void SetDefaultValues()
    {
        //uint8_t *ptr = (uint8_t*)&CardsStorageBuffer;
        //for (int i = 0; i < sizeof(CardsStorageBuffer_t); i++)
        //{
        //  ptr[i] = i;
        //}
        
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
    
    void SetCardSlotDefaultValues(Card* card)
    {
      
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