#ifndef DISPLAY_TASK_H_
#define DISPLAY_TASK_H_

#include "RTOS/Task.h"

class DisplayTask
{
public:
    DisplayTask(char * name, int stack_size, int priority)
        :RTOS::Task(name, stack_size, priority)
    {
        
    }
    
private:
    void Execute();
};


#endif