#ifndef BUTTONS_TASK_H_
#define BUTTONS_TASK_H_

#include "RTOS/Task.h"

class ButtonsTask: public RTOS::Task
{
public:
    ButtonsTask(char * name, int stack_size, int priority)
        :RTOS::Task(name, stack_size, priority)
    {
        
    }
    
private:
    void Execute();
};






#endif