#include "LCD/LCD_Init.h"
#include "LCD/LCD.h"
#include "Ethernet/EthernetInit.h"
#include "Pump/PumpInit.h"
#include "Flash/W25Q256_Init.h"
#include "Buttons/Buttons.h"
#include "RTC/RTC_drv.h"

void boardInit()
{
    //display initialization
    LCD_Init();
    
    //ethernet intialization
    IPV4_t ipv4;
    ipv4.ipv4_1 = 192;
    ipv4.ipv4_2 = 168;
    ipv4.ipv4_3 = 0;
    ipv4.ipv4_4 = 10;
    MASK_t mask;
    mask.mask1 = 255;
    mask.mask2 = 255;
    mask.mask3 = 255;
    mask.mask4 = 0;
    EthernetInit(ipv4, mask);
    
    //pump init
    //initPumpDriver();

    //memory initialization
    w25q256Init();
    
    //buttons initialization
    ButtonsInit(Buttons);

    //rtc initialization
    RTC_Init();
}
