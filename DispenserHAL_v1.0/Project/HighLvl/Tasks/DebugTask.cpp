#include "DebugTask.h"
#include "LCD/LCD.h"
#include "main.h"
#include "Pump/PumpInit.h"
#include "Tasks/TasksTypes.h"

void DebugTask::Execute()
{
    HAL_Delay(1000);
    while(1)
    {
      static uint32_t speed = 2000;
      
      startPump(speed, CLOCKWISE_PUMP_DIRECTION, &pumpDriver);
      RTOS::Thread::delay_thread(1000);
      stopPump(&pumpDriver);
      RTOS::Thread::delay_thread(1000);
    }
}