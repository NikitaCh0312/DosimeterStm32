#ifndef TASK_H_
#define TASK_H_


#include "RTOS_Library/FreeRTOS/include/FreeRTOS.h"
#include "RTOS_Library/FreeRTOS/include/task.h"


namespace RTOS
{
static void Run(void * pvParameters);
    
    
    class Task
    {
    public:
        Task( char * name, int stack_size, int priority)
        {
            portBASE_TYPE rc = pdFALSE; 
            rc = xTaskCreate(static_cast<TaskFunction_t>(RTOS::Run), name,
                             stack_size, this, (portBASE_TYPE) priority ,
                             &TaskHandler );
            if (rc != pdTRUE){
                while(1);
            }
        }
        void startTask();
        void suspendTask();
        void Run();
    private:
        xTaskHandle TaskHandler;
        virtual void Execute() = 0;
    };
    
    
    
static void Run(void * pvParameters)
{
    static_cast<Task*>(pvParameters) -> Run();
}     

}

#endif

