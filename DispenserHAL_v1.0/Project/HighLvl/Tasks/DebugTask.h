#ifndef DEBUG_TASK_H_
#define DEBUG_TASK_H_

#include "RTOS/Task.h"

class DebugTask: public RTOS::Task
{
public:
    DebugTask(char * name, int stack_size, int priority)
        :RTOS::Task(name, stack_size, priority)
    {
        
    }
    
private:
    void Execute();
};


#endif