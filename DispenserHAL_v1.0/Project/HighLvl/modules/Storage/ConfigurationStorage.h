#ifndef CONFIGURATION_STORAGE_H_
#define CONFIGURATION_STORAGE_H_

#include "Components/Flash/W25Q256.h"
#include "modules/Storage/Crc16.h"

#define CONFIGURATION_START_ADDRESS 0x0
#define CONFIGURATION_END_ADDRESS 0x0

#define SECTOR_NUMBER 1


typedef struct
{
    uint8_t SNUM[6];
    uint8_t LNUM;
    uint8_t HNUM;
    uint8_t PONUM;
    uint8_t DAMF[3];
    uint8_t SMRADR[3];
    uint8_t TMSADR[5];
    uint8_t MACACDR[6];
    uint8_t RRCC;
    uint16_t PSNV;
    uint8_t SVT;
    uint8_t EACN;
    uint8_t TCN;
    uint8_t SCTN;
    uint16_t MIFV;
    uint16_t MAFV;
    uint8_t MICV;
    uint8_t MACV;
    uint8_t VCIN;
}SystemParams_t;

typedef struct
{
    uint8_t addr_1;
    uint8_t addr_2;
    uint8_t addr_3;
    uint8_t addr_4;   
}IpAddr_t;

typedef struct
{
    uint8_t mask_1;
    uint8_t mask_2;
    uint8_t mask_3;
    uint8_t mask_4;   
}Mask_t;

typedef struct
{
    IpAddr_t IpAddress;
    Mask_t Mask;
}RuntimeParams_t;

typedef struct
{
    SystemParams_t SystemParams;
    RuntimeParams_t RuntimeParams;
    uint16_t Crc;
}ConfigurationStorage_t;



class ConfigurationStorage
{
public:
    ConfigurationStorage()
    {

    }
    
    ConfigurationStorage_t StorageValues;
    
    void Load()
    {
        W25qxx_ReadBytes((uint8_t*)&StorageValues, CONFIGURATION_START_ADDRESS, sizeof(ConfigurationStorage_t));
        if (CheckCrc((uint8_t*)&StorageValues, sizeof(ConfigurationStorage_t)) == CRC_ERROR)
          SetDefaultValues();
    }

    void Update()
    {
        W25qxx_EraseSector(CONFIGURATION_START_ADDRESS);
        StorageValues.Crc = GetCrc((uint8_t*)&StorageValues, sizeof(ConfigurationStorage_t) - 2);
        W25qxx_WriteSector((uint8_t*)&StorageValues, CONFIGURATION_START_ADDRESS, 0, sizeof(ConfigurationStorage_t));
        
    }
private:
    
    void SetDefaultValues()
    {
        StorageValues.SystemParams.SNUM[0] = 11;
        StorageValues.SystemParams.SNUM[1] = 12;
        StorageValues.SystemParams.SNUM[2] = 13;
        StorageValues.SystemParams.SNUM[3] = 14;
        StorageValues.SystemParams.SNUM[4] = 15;
        StorageValues.SystemParams.SNUM[5] = 16;

        StorageValues.SystemParams.LNUM = 55;

        //defult IP ADDR
        StorageValues.RuntimeParams.IpAddress.addr_1 = 192;
        StorageValues.RuntimeParams.IpAddress.addr_2 = 103;
        StorageValues.RuntimeParams.IpAddress.addr_3 = 0;
        StorageValues.RuntimeParams.IpAddress.addr_4 = 10;

        //defult IP MASK
        StorageValues.RuntimeParams.Mask.mask_1 = 255;
        StorageValues.RuntimeParams.Mask.mask_2 = 255;
        StorageValues.RuntimeParams.Mask.mask_3 = 255;
        StorageValues.RuntimeParams.Mask.mask_4 = 0;

        Update();
    }
};

#endif