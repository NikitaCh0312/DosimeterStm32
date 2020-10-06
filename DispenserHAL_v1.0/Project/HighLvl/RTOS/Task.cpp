#include "Task.h"


namespace RTOS
{
    void Task::startTask()
    {
        vTaskResume( TaskHandler );
    }
    
    void Task::suspendTask()
    {
        vTaskSuspend( TaskHandler );
    }
    
    void Task::Run()
    {
        this->Execute();
    }
}