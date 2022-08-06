#include "W25Q256_Init.h"
#include "W25Q256.h"

#include "main.h"
#include "spi.h"
#include "stdint.h"


static void transmit(uint8_t * buffer, uint32_t buffer_size)
{
    HAL_SPI_Transmit(&hspi3, buffer, buffer_size, 100);
}

static void receive(uint8_t * buffer, uint32_t buffer_size)
{
    HAL_SPI_Receive(&hspi3, buffer, buffer_size, 100);
}

static uint8_t transmitReceiveByteSpi(uint8_t * byte)
{
    uint8_t ret;
    HAL_SPI_TransmitReceive(&hspi3, byte, &ret, 1, 100);
    return ret;
}

static void setCsPin(uint32_t state)
{
    if (state == 1)
        HAL_GPIO_WritePin(FLASH_CS_SPI_GPIO_Port, FLASH_CS_SPI_Pin, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(FLASH_CS_SPI_GPIO_Port, FLASH_CS_SPI_Pin, GPIO_PIN_RESET);
}

static void setWpPin(uint32_t state)
{
    
}

static void setHoldPin(uint32_t state)
{
    
}

static void setResetPin(uint32_t state)
{
    
}

static void delay(uint32_t msec)
{
    HAL_Delay(msec);
}

uint8_t rxMemoryBuffer[10];
uint8_t page[400];
static void TestMemory()
{
    W25qxx_EraseSector(0);
    W25qxx_WriteByte(0x01, 0x00);
    W25qxx_WriteByte(0x02, 0x01);
    W25qxx_WriteByte(0x03, 0x02);
    
    W25qxx_ReadBytes(rxMemoryBuffer, 0x00, 3);
    
    //benchmark test (about 30 seconds)
    //uint32_t pageAddress = 0;
    //for (int i = 0; i < 16384; i++)
    //{
    //    W25qxx_ReadPage(page, pageAddress, 0, 256);
    //    pageAddress += 256;
    //}
}

void w25q256Init()
{
    W25QXX_Driver_t drv;
    drv.delay = &delay;
    drv.receive = &receive;
    drv.transmit = &transmit;
    drv.transmitReceiveByteSpi = &transmitReceiveByteSpi;
    drv.setCsPin = &setCsPin;
    drv.setHoldPin = &setHoldPin;
    drv.setResetPin = &setResetPin;
    drv.setWpPin = &setWpPin;
    W25qxx_Init(&drv);
    
    //TestMemory();
}
