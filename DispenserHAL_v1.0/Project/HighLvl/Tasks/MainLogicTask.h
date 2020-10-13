#ifndef MAINLOGIC_TASK_H_
#define MAINLOGIC_TASK_H_

#include "RTOS/Task.h"

class MainLogicTask: public RTOS::Task
{
public:
    MainLogicTask(char * name, int stack_size, int priority)
        :RTOS::Task(name, stack_size, priority)
    {
        
    }
    
private:
    void Execute();
};


#endif