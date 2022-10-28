#include "LCD/LCD_Init.h"
#include "LCD/LCD.h"
#include "Ethernet/EthernetInit.h"
#include "Pump/PumpInit.h"
#include "Flash/W25Q256_Init.h"
#include "Buttons/Buttons.h"
#include "RTC/RTC_drv.h"

void boardInit()
{
    //pump init
   initPumpDriver();

   //display initialization
    LCD_Init();

    //memory initialization
    w25q256Init();
    
    //buttons initialization
    ButtonsInit(Buttons);

    //rtc initialization
    RTC_Init();
}
