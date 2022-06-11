#include "DebugTask.h"
#include "LCD/LCD.h"
#include "main.h"
#include "Pump/PumpInit.h"
#include "Sensors/Sensors.h"
#include "Tasks/TasksTypes.h"
#include "Valve/Valve.h"
#include "VoltageMonitor/VoltageMonitor.h"

void DebugTask::Execute()
{
    //HAL_Delay(3000);
    
    //initPumpDriver();
    //enablePump(getPumpDriver(), getA4988Conf());
    //startPump(getPumpDriver(), 1000, 200);
  
    //while((*getPumpDriver()).getStatus() == PROGRESS_WORK) {};
      
    //disablePump(getPumpDriver());
    
    while(1)
    {
      //startPump(&(getPumpDriver()), 100000, 10);
      //enablePump(getPumpDriver(), getA4988Conf());
      //startPump(getPumpDriver(), 100000, 200);
      //disablePump(getPumpDriver());
      //getSupplyVoltage();
      HAL_Delay(10000);
    }
}