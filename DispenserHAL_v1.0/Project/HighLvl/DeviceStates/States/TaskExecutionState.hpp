#ifndef TASK_EXECUTION_STATE_H_
#define TASK_EXECUTION_STATE_H_

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
                _stage = EXEUTING_TASK_STAGE;
            
                break;
            }
            case CHECK_WATER_PREASURE_STAGE:
            {
           
                break;
            }
            case EXEUTING_TASK_STAGE:
            {
               // _task.Volume;
              //_task.Concentration;
           
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
        EXEUTING_TASK_STAGE 
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