#ifndef THREAD_H_
#define THREAD_H_


#include "RTOS_Library/FreeRTOS/include/FreeRTOS.h"
#include "RTOS_Library/FreeRTOS/include/task.h"

namespace RTOS
{
    typedef  xTaskHandle ThreadHandle;
    //---------------------------------------
    //Класс Thread
    //управляет потоком/задачей
    //---------------------------------------
    class Thread
    {
    public:
        static int create_thread(void (*p_function)(void *pvParameters),
                                 xTaskHandle *task_handler,
                                 int min_stack_multuplier,
                                 uint32_t task_priority);
        static int remove_thread(ThreadHandle *thread_handle);
        static int stop_thread(ThreadHandle *thread_handler);
        static int start_thread(ThreadHandle *thread_handler);
        static int delay_thread(uint32_t msec);
        static int start_scheduler();
        static uint32_t get_num_of_threads();
        static uint32_t num_of_threads;
    private:
        
        
    };
}

#endif

