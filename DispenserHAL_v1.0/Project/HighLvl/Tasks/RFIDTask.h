#ifndef RFID_TASK_H_
#define RFID_TASK_H_

#include "RTOS/Task.h"

class RfidTask: public RTOS::Task
{
public:
    RfidTask(char * name, int stack_size, int priority)
        :RTOS::Task(name, stack_size, priority)
    {
        
    }
    
private:
    void Execute();
};


#endif