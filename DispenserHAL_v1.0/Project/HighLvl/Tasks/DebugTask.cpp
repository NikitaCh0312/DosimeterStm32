#include "DebugTask.h"
#include "LCD/LCD.h"
#include "main.h"
#include "Pump/PumpInit.h"
#include "Sensors/Sensors.h"
#include "Tasks/TasksTypes.h"
#include "Valve/Valve.h"

void DebugTask::Execute()
{
    HAL_Delay(1000);
    SENSOR_TYPE_t sens_type = LEVEL_SENSOR_TYPE;
    static SENSOR_STATE_t sens_state = OFF_SENSOR_STATE;
    
    while(1)
    {
      static uint32_t speed = 1000;
      
/*      startPump(speed, CLOCKWISE_PUMP_DIRECTION, &pumpDriver);
      RTOS::Thread::delay_thread(1000);
      stopPump(&pumpDriver);
      RTOS::Thread::delay_thread(1000);
*/
      sens_state = getSensorState(sens_type);
      valveOn();
      RTOS::Thread::delay_thread(500);
      valveOff();
      RTOS::Thread::delay_thread(500);
      
    }
}