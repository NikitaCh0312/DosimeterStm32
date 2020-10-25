#include "LCD/LCD_Init.h"
#include "LCD/LCD.h"

#include "Ethernet/EthernetInit.h"

#include "Pump/PumpInit.h"

void boardInit()
{
    //display initialization
    LCD_Init();
    
    //ethernet intialization
    EthernetInit();
    
    //pump init
    initPumpDriver();
}