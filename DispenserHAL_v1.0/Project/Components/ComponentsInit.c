#include "LCD/LCD_Init.h"
#include "LCD/LCD.h"

#include "Ethernet/EthernetInit.h"
#include "Flash/W25Q256_Init.h"

void boardInit()
{
    //display initialization
    LCD_Init();
    
    //ethernet intialization
    EthernetInit();
    
    //memory initialization
    w25q256Init();
}