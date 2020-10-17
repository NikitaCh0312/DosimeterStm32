#include "RFID.h"
#include "main.h"

typedef struct
{
    RFID_STATE_t rfidState;
    uint32_t readCardId;
}RFID_Driver_t;

static RFID_Driver_t driver;

RFID_STATE_t getRfidState()
{
    return driver.rfidState;
}


uint32_t getNewCardId()
{
    return driver.readCardId;
}


static void RfidRx0()
{
    
}
void RfidIrqHandler_0()
{
    if (HAL_GPIO_ReadPin(DATA_0_GPIO_Port,DATA_0_Pin))
    {
        RfidRx0();
    }
}

static void RfidRx1()
{
    
}
void RfidIrqHandler_1()
{
    
}