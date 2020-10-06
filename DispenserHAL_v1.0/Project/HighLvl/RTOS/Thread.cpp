#include "Thread.h"


namespace RTOS
{
    int Thread:: create_thread(void (*p_function)(void *pvParameters), xTaskHandle *task_handler,int min_stack_multuplier, uint32_t task_priority)
    {
        portBASE_TYPE rc = pdFALSE; 
        rc = xTaskCreate(p_function, "TASK_NAME", configMINIMAL_STACK_SIZE * min_stack_multuplier, NULL, (portBASE_TYPE) task_priority , task_handler );
        if (rc != pdTRUE){
            return -1;
        }
        vTaskSuspend( *task_handler );
        //num_of_threads++;
        return 0;
    }
    
    int Thread::start_thread(ThreadHandle *thread_handler)
    {
        vTaskResume( *thread_handler );
        return 0;
    }
    
    int Thread::stop_thread(ThreadHandle *thread_handler)
    {
        vTaskSuspend( *thread_handler );
        return 0;
    }
    
    int Thread::delay_thread(uint32_t msec)
    {
        TickType_t ticks = pdMS_TO_TICKS(msec);
        vTaskDelay(ticks);
        return 0;
    }
    
    int Thread::start_scheduler()
    {
        vTaskStartScheduler();
        return 0;
    }
    int Thread::remove_thread(ThreadHandle *thread_handle)
    {
        vTaskDelete(*thread_handle);
        //num_of_threads--;
        return 0;
    }
    

    
}