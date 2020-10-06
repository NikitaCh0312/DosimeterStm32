#ifndef ETHERNET_TASK_H_
#define ETHERNET_TASK_H_

#include "RTOS/Task.h"

class EthernetTask: public RTOS::Task
{
public:
    EthernetTask(char * name, int stack_size, int priority)
        :RTOS::Task(name, stack_size, priority)
    {
        
    }
    
private:
    void Execute();
};


#endif