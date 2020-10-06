#ifndef RTOS_MANAGER_H_
#define RTOS_MANAGER_H_

#include "RTOS_Library/FreeRTOS/include/FreeRTOS.h"
#include "RTOS_Library/FreeRTOS/include/semphr.h"
#include "RTOS_Library/FreeRTOS/include/queue.h"
#include "RTOS_Library/FreeRTOS/include/timers.h"
#include "Thread.h"

namespace RTOS
{ 
    //-----------------------------------------------//
    //типы данных
    //-----------------------------------------------//
    typedef xQueueHandle        queue_handle_t;
    typedef xSemaphoreHandle    semaphore_handle_t;
    
    
    void TaskEnterCritical();
    void TaskExitCritical();
    
    
    //-----------------------------------------------//
    //мьютексы
    //-----------------------------------------------//
    class MutexStatic
    {
      public:
        static int create_mutex(semaphore_handle_t *mutex);
        static int take_mutex(semaphore_handle_t mutex);
        static int take_mutex(semaphore_handle_t mutex, uint32_t msec_to_wait);
        static int give_mutex(semaphore_handle_t mutex);
      private:
    };
#warning not ready
    class Mutex
    {
      public:
        Mutex();
        int take_mutex();
        int take_mutex(uint32_t msec_to_wait);
        int give_mutex();
      private:
        semaphore_handle_t mutex_handler;
        int create_mutex(semaphore_handle_t *mutex);
    };    
    
    //-----------------------------------------------//
    //семафоры
    //-----------------------------------------------//
    class SemaphoreStatic
    {
      public:
        static int create_semaphore_binary(semaphore_handle_t *semaphore);
        static int wait_semaphore(semaphore_handle_t semaphore);
        static int wait_semaphore(semaphore_handle_t semaphore, uint32_t msec_to_wait);
        static int send_semaphore(semaphore_handle_t semaphore);
      private:
    };
#warning not ready    
    class Semaphore
    {
      public:
        Semaphore();
        int create_semaphore_binary(semaphore_handle_t *semaphore);
        int wait_semaphore(semaphore_handle_t semaphore);
        int wait_semaphore(semaphore_handle_t semaphore, uint32_t msec_to_wait);
        int send_semaphore(semaphore_handle_t semaphore);
      private:
        semaphore_handle_t semaphore_handler;  
    };    
    
    //-----------------------------------------------//
    //очереди
    //-----------------------------------------------//    
    class QueueStatic
    {
      public:
        static int create_queue(queue_handle_t *queue, uint32_t q_size, uint32_t q_item_size);
        static int get_queue_size();
        static int queue_receive(queue_handle_t queue, void* queue_item);
        static int queue_receive(queue_handle_t queue, void* queue_item, uint32_t ticks_to_wait);
        static int queue_send(queue_handle_t queue, void*item, uint32_t msec_to_wait);
        static int queue_send(queue_handle_t queue, void*item);
        static int get_queue_messages( queue_handle_t queue );
      private:
          
    };
    
    //-----------------------------------------------//
    //таймеры
    //-----------------------------------------------//
#warning not ready   
    class Timer
    {
      public:
          static int create_timer();
          static int set_timer_callback(void (*p_callback)(void));
      private:
          
    };
}

#endif

