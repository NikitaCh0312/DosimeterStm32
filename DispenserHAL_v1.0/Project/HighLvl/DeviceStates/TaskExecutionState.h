#ifndef TASK_EXECUTION_STATE_H_
#define TASK_EXECUTION_STATE_H_

#include "IDeviceState.h"
#include "Dosimeter.h"

#include "DeviceStates/WaitingUserActionState.h"

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
        WaitingUserActionState * waitingState = WaitingUserActionState::GetInstance();
        _context->SetState((IDeviceState*)waitingState);
    }
private:
    typedef enum
    {
        INITIALIZATION_STAGE,
        SELECTING_TASK_STAGE,
    }STAGE_t;
    
    
    static TaskExecutionState * _instance;
    TaskExecutionState()
    {
        _stage = INITIALIZATION_STAGE;
    }
    STAGE_t _stage;

};



#endif