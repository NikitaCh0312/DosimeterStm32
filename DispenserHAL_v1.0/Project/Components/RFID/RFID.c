#include "RFID.h"
#include "main.h"

#define READ_RFID_CARD_PAUSE 1000

extern uint32_t global_timer;
typedef struct
{
    RFID_STATE_t rfidState;
    
    uint32_t rfid_data;
    uint16_t counter;
    uint32_t lastRxTime;
    
    RfidInfo_t cardInfo;
}RFID_Driver_t;

static RFID_Driver_t rfidDriver;

/*
*returns rfid reader state
*/
RFID_STATE_t getRfidState()
{
    return rfidDriver.rfidState;
}

/*
*returns new rfid card structure
*/
RfidInfo_t getNewCard()
{
    rfidDriver.rfidState = NO_CARD_STATE;
    return rfidDriver.cardInfo;
}

/*
*initialization
*/
void rfidInit()
{
    rfidDriver.cardInfo.card_manufacturer = 0;
    rfidDriver.cardInfo.card_number = 0;
    rfidDriver.cardInfo.c1 = 0;
    rfidDriver.cardInfo.c2 = 0;
    rfidDriver.cardInfo.CardId = 0;
    rfidDriver.rfidState = NO_CARD_STATE;
    rfidDriver.counter = 0;
    rfidDriver.rfid_data = 0;
    rfidDriver.lastRxTime = 0;
}

static void reloadRfid()
{
    rfidDriver.counter = 0;
    rfidDriver.rfid_data = 0;
}
static int IsLastLinkTimeOK()
{
    if (global_timer - rfidDriver.lastRxTime > READ_RFID_CARD_PAUSE)
        return 0;
    return 1;
}
static void setRfidInfo(uint32_t rx_data)
{
    rfidDriver.cardInfo.card_manufacturer = (uint16_t)((rx_data >> 1) & 0x000F);
    rfidDriver.cardInfo.card_number = (uint16_t)(rx_data >> 9);
    rfidDriver.cardInfo.c1 = (uint16_t)(rx_data >> 13);
    rfidDriver.cardInfo.c2 = (uint16_t)(rx_data & 0x1FFF);
    rfidDriver.cardInfo.CardId = (rx_data & 0x1FFFFFF) >> 1;
}


static void RfidRx0()
{
    //check last rx time
    if (IsLastLinkTimeOK() == 0)
        reloadRfid();
    
    rfidDriver.lastRxTime = global_timer;
    rfidDriver.counter++;
    rfidDriver.rfid_data <<= 1;
    if (rfidDriver.counter < 26)
    {
        //rfidDriver.rfidState = READING_CARD_STATE;
        return;
    }
    setRfidInfo(rfidDriver.rfid_data);
    rfidDriver.rfidState = NEW_CARD_STATE;
    
    reloadRfid();
}
void RfidIrqHandler_0()
{
    if (HAL_GPIO_ReadPin(RFID_DATA0_GPIO_Port,RFID_DATA0_Pin))
    {
        RfidRx0();
    }
}


static void RfidRx1()
{
    // check last rx time
    if (IsLastLinkTimeOK() == 0)
        reloadRfid();
    
    rfidDriver.lastRxTime = global_timer;
    rfidDriver.counter++;
    rfidDriver.rfid_data <<= 1;
    rfidDriver.rfid_data |= 1;
    if (rfidDriver.counter < 26)
    {
        //rfidDriver.rfidState = READING_CARD_STATE;
        return;
    }
    setRfidInfo(rfidDriver.rfid_data);
    rfidDriver.rfidState = NEW_CARD_STATE;
    
    reloadRfid();
}
void RfidIrqHandler_1()
{
    if (HAL_GPIO_ReadPin(RFID_DATA1_GPIO_Port,RFID_DATA1_Pin))
    {
        RfidRx1();
    }
}