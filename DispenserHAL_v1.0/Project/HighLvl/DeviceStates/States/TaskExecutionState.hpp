#ifndef TASK_EXECUTION_STATE_H_
#define TASK_EXECUTION_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"

#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "string.h"
#include "stdio.h"

class TaskExecutionState: public IDeviceState
{
public:
    static TaskExecutionState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new TaskExecutionState();
        return _instance;
    }
    
   
    void Handle(UserAction_t action)
    {
        if (_stage == INITIALIZATION_STAGE)
        {
            clear_display();
            set_cursor_position(0, 5);
            set_text_rus((char*)StringResources::TaskExecution_1str);
            set_cursor_position(1, 6);
            set_text_rus((char*)StringResources::TaskExecution_2str);
            set_cursor_position(2, 9);
            set_text_eng("...");
            _stage = EXEUTING_TASK_STAGE;
        }
        else if (_stage == INITIALIZATION_STAGE)
        {
          
        }


        //_context->SetState((IDeviceState*)factory->GetState(WAITING_USER_ACTION_STATE));
    }
private:
    typedef enum
    {
        INITIALIZATION_STAGE,
        EXEUTING_TASK_STAGE
    }STAGE_t;
    
    IDeviceStatesFactory * factory;
    
    static TaskExecutionState * _instance;
    TaskExecutionState()
    {
        _stage = INITIALIZATION_STAGE;
    }
    STAGE_t _stage;

};



#endif