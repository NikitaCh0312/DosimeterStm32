#ifndef TASK_EXECUTION_STATE_H_
#define TASK_EXECUTION_STATE_H_

#include "IDeviceState.h"


class TaskExecutionState: public IDeviceState
{
public:
    static TaskExecutionState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new TaskExecutionState();
        return _instance;
    }
    void Handle()
    {
        
    }
private:
    static TaskExecutionState * _instance;
    TaskExecutionState(){}
};



#endif