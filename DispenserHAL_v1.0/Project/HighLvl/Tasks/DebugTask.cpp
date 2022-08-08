#include "DebugTask.h"
#include "LCD/LCD.h"
#include "main.h"
#include "Pump/PumpInit.h"
#include "Sensors/Sensors.h"
#include "Tasks/TasksTypes.h"
#include "Valve/Valve.h"
#include "VoltageMonitor/VoltageMonitor.h"
//#include "modules/Storage/ConfigurationStorage.h"

void DebugTask::Execute()
{
    //ConfigurationStorage* storage = new ConfigurationStorage();
    //storage->Load();
    //HAL_Delay(3000);
    
    //initPumpDriver();
    //enablePump(getPumpDriver(), getA4988Conf());
    //startPump(getPumpDriver(), 1000, 200);
  
    //while((*getPumpDriver()).getStatus() == PROGRESS_WORK) {};
      
    //disablePump(getPumpDriver());
    //flow_sensor_set_default_koef();
    //flow_sensor_start_measure(DMRV_SENSOR_TYPE);
    //valveOn();
    
    while(1)
    {
      //startPump(&(getPumpDriver()), 100000, 10);
      //enablePump(getPumpDriver(), getA4988Conf());
      //startPump(getPumpDriver(), 100000, 200);
      //disablePump(getPumpDriver());
      //getSupplyVoltage();
       
      /*
       if(flow_sensor_get_cnt(DMRV_SENSOR_TYPE) >= 1000)
       {
         static float volume = 0;
         volume =  flow_sensor_get_volume_liters(DMRV_SENSOR_TYPE);
         
         flow_sensor_stop_measure(DMRV_SENSOR_TYPE);
         valveOff(); 

         HAL_Delay(1);
       }
      */
       HAL_Delay(2000);
    
       //static int en_flag = 1;
       //if(en_flag)
       //{
       //    enablePump(getPumpDriver(), getA4988Conf());
       //    pumpSubstance_ml(getPumpDriver(), 50);
       //    en_flag = 0;
       //}
           
      
    }
}