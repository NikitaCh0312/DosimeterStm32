#include "DebugTask.h"
#include "LCD/LCD.h"
#include "main.h"

extern uint8_t testDisplayBuffer[100];
extern uint32_t RxMessageSizeBytes;
void DebugTask::Execute()
{
    HAL_Delay(1000);
    while(1)
    {
        set_cursor_position(0, 0);
        set_symbols(testDisplayBuffer, RxMessageSizeBytes);
        HAL_Delay(1000);
    }
}