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
        Task( int priority )
        {
            portBASE_TYPE rc = pdFALSE; 
            rc = xTaskCreate(static_cast<TaskFunction_t>(RTOS::Run), "TASK_NAME",
                             configMINIMAL_STACK_SIZE * 2, this, (portBASE_TYPE) priority ,
                             &TaskHandler );
            if (rc != pdTRUE){
                while(1);
            }
            vTaskSuspend( TaskHandler );
        }
        void startTask();
        void suspendTask();
        void Run();
        virtual void Execute() = 0;
        
    private:
        xTaskHandle TaskHandler;
        
        
        void (*tskHandler)(void *pvParameters);
    };
    
    
    
    
    static void Run(void * pvParameters)
    {
        static_cast<Task*>(pvParameters) -> Run();
    } 
}

#endif

