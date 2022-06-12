#ifndef TASK_EXECUTION_STATE_H_
#define TASK_EXECUTION_STATE_H_

#define CNT_CHECK_PULSE 5
#define TIMEOUT_CHECK_PULSE_MS 200

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"

#include "modules/Card.h"

#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "string.h"
#include "stdio.h"
#include "Sensors/Sensors.h"
#include "Valve/Valve.h"
#include "Pump/PumpInit.h"

extern uint32_t global_timer;

class TaskExecutionState: public IDeviceState
{
public:
    static TaskExecutionState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new TaskExecutionState();
        return _instance;
    }
   
    void InitExecutionState(Task task)
    {
        _task = task;
    }
   
    void Handle(UserAction_t action)
    {
        static uint32_t startTime = 0;
        switch (_stage)
        {
            case INITIALIZATION_STAGE:
            {
                clear_display();
                set_cursor_position(0, 5);
                set_text_rus((char*)StringResources::TaskExecution_1str);
                set_cursor_position(1, 6);
                set_text_rus((char*)StringResources::TaskExecution_2str);
                set_cursor_position(2, 9);
                set_text_eng("...");
                
                flow_sensor_set_default_koef();
                
                _stage = CHECK_WATER_PREASURE_STAGE;
            
                break;
            }
            case CHECK_WATER_PREASURE_STAGE:
            {
              if(startTime == 0) 
              {
                  startTime = global_timer;
                  flow_sensor_start_measure(DMRV_SENSOR_TYPE);
                  valveOn();
              }
              else
              {
                  if((global_timer - startTime) > TIMEOUT_CHECK_PULSE_MS)
                  {
                     startTime = 0;
                     flow_sensor_stop_measure(DMRV_SENSOR_TYPE);
                     valveOff(); 
                     
                     _stage = ERR_WATER_PREASURE_STAGE;
                  }
                  else if(flow_sensor_get_cnt(DMRV_SENSOR_TYPE) >= CNT_CHECK_PULSE)
                  {
                      _stage = EXEUTING_TASK_STAGE;
                  }
                  
              }
           
                break;
            }
            case EXEUTING_TASK_STAGE:
            {
               // _task.Volume;
              //_task.Concentration;
           
                break;
            }
            case ERR_WATER_PREASURE_STAGE:
            {           
                break;
            }

            default: break;
        }
    
        //_context->SetState((IDeviceState*)factory->GetState(WAITING_USER_ACTION_STATE));
    }
private:
    typedef enum
    {
        INITIALIZATION_STAGE,
        CHECK_WATER_PREASURE_STAGE,
        EXEUTING_TASK_STAGE,
        ERR_WATER_PREASURE_STAGE
    }STAGE_t;
    
    IDeviceStatesFactory * factory;
    
    static TaskExecutionState * _instance;
    TaskExecutionState()
    {
        _stage = INITIALIZATION_STAGE;
    }
    STAGE_t _stage;
    
    Task _task;
    
    uint32_t getSetsPumpCnt();
    uint32_t getSetsFlowSensorCnt();
    
    void calculateSets(Task tmp_task);
    uint16_t    getSetsPumpFreq();
    float       getSetsFlowSensorVolume();
    float       getSetsPumpVolume();

};



#endif