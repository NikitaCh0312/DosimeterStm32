#ifndef SUBSTANCES_STORAGE_H_
#define SUBSTANCES_STORAGE_H_

#include "Components/Flash/W25Q256.h"
#include "modules/Storage/BaseStorage.h"
#include "modules/Storage/Crc16.h"

#define SUBSTANCES_START_SECTOR_NUMBER 5
#define SUBSTANCES_END_SECTOR_NUMBER 5
#define SUBSTANCES_START_SECTOR_ADDRESS 0x5000
#define SUBSTANCES_END_SECTOR_ADDRESS 0xA000

#define MAX_SUBSTANCES_QUANTITY 20

//total 44 bytes = 11 32bit words
typedef struct
{
    //4
    uint32_t Id;
    //4
    float Volume_L;
    //36
    char Name[36];
}Substance_t;

//total 888 bytes
typedef struct
{
    //4 bytes
    uint32_t SelectedId;
    //44 * MAX_SUBSTANCES_QUANTITY = 880 bytes
    Substance_t SubstancesList[MAX_SUBSTANCES_QUANTITY];
    //2 bytes
    uint16_t reserved;
    //2 bytes
    uint16_t Crc;
}SubstanceStorageBuffer_t;

SubstanceStorageBuffer_t SubstanceStorageValues;

class SubstancesStorage : BaseStorage
{
public:
    SubstancesStorage()
    {
    
    }
  
    void Load()
    {
        W25qxx_ReadSector((uint8_t*)&SubstanceStorageValues, SUBSTANCES_START_SECTOR_NUMBER, 0, sizeof(SubstanceStorageBuffer_t));
        if (CheckCrc((uint8_t*)&SubstanceStorageValues, sizeof(SubstanceStorageBuffer_t)) == CRC_ERROR)
          SetDefaultValues();
    }
    
    int GetSubstancesQuantity()
    {
        int counter = 0;
        for (int i = 0; i < MAX_SUBSTANCES_QUANTITY; i++)
        {
            if (SubstanceStorageValues.SubstancesList[i].Id != 0)
                counter++;
            
        }
        return counter;
    }
    
    int AddSubstance()
    {
        return 0;
    }
    
    void SetSelectedSubstance(uint32_t id)
    {
        SubstanceStorageValues.SelectedId = id;
        Update();
    }
    
    Substance_t GetSubstance(uint32_t id)
    {
        Substance_t substance;
        substance.Id = 0;
        for (int i = 0; i < MAX_SUBSTANCES_QUANTITY; i++)
        {
            if (SubstanceStorageValues.SubstancesList[i].Id != id)
            {
                substance.Id = SubstanceStorageValues.SubstancesList[i].Id;
                substance.Volume_L = SubstanceStorageValues.SubstancesList[i].Volume_L;
                strcpy(substance.Name, SubstanceStorageValues.SubstancesList[i].Name);
            }
            
        }
        return substance;
    }
    
    Substance_t * GetSubstancesListValuesPtr()
    {
        return &SubstanceStorageValues.SubstancesList[0];
    }
private:
    void SetDefaultValues()
    {
        SubstanceStorageValues.SelectedId = 1;
        for (int i = 0; i < MAX_SUBSTANCES_QUANTITY; i++)
        {
            SubstanceStorageValues.SubstancesList[i].Id = 0;
            SubstanceStorageValues.SubstancesList[i].Volume_L = 0;
            strcpy(SubstanceStorageValues.SubstancesList[i].Name, "empty");
        }
        
        SubstanceStorageValues.SubstancesList[0].Id = 4532;
        SubstanceStorageValues.SubstancesList[0].Volume_L = 1.25;
        strcpy(SubstanceStorageValues.SubstancesList[0].Name, "Piter Parker");
        
        SubstanceStorageValues.SubstancesList[1].Id = 2345;
        SubstanceStorageValues.SubstancesList[1].Volume_L = 2.75;
        strcpy(SubstanceStorageValues.SubstancesList[1].Name, "Gandalf");
        
        SubstanceStorageValues.SubstancesList[2].Id = 9878;
        SubstanceStorageValues.SubstancesList[2].Volume_L = 4.60;
        strcpy(SubstanceStorageValues.SubstancesList[2].Name, "Aragorn");
        
        Update();
    }
    
    void Update()
    {
        W25qxx_EraseSector(SUBSTANCES_START_SECTOR_NUMBER);
        SubstanceStorageValues.Crc = GetCrc((uint8_t*)&SubstanceStorageValues, sizeof(SubstanceStorageBuffer_t) - 2);
        W25qxx_WriteSector((uint8_t*)&SubstanceStorageValues, SUBSTANCES_START_SECTOR_NUMBER, 0, sizeof(SubstanceStorageBuffer_t));
    }
};

#endif