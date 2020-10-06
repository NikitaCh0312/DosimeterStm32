#include "RTOSManager.h"


namespace RTOS
{
    void TaskEnterCritical()
    {
        taskENTER_CRITICAL();
    }
    void TaskExitCritical()
    {
        taskEXIT_CRITICAL();
    }
    
    
    
    
    //mutex
    int MutexStatic::create_mutex(semaphore_handle_t *mutex)
    {
        if (mutex == NULL)
            return -1;
        semaphore_handle_t rc = xSemaphoreCreateMutex();
        if (rc == NULL)
            return -1;
        *mutex = rc;
        return 0;
    }
    int MutexStatic:: take_mutex(semaphore_handle_t mutex)
    {
        portBASE_TYPE  rc = pdFALSE; 
        rc = xSemaphoreTake(mutex, portMAX_DELAY );
        if ( rc == pdPASS)
          return 0;
        return -1;
    }
    int MutexStatic:: take_mutex(semaphore_handle_t mutex, uint32_t msec_to_wait)
    {
        portBASE_TYPE  rc = pdFALSE; 
        TickType_t ticks_to_wait;
        if (msec_to_wait == 0)
            ticks_to_wait = 0;
        else
            ticks_to_wait = pdMS_TO_TICKS(msec_to_wait);
        rc = xSemaphoreTake(mutex, ticks_to_wait );
        
        if ( rc == pdPASS)
          return 0;
        return -1;        
    }
    int MutexStatic:: give_mutex(semaphore_handle_t mutex)
    {
        xSemaphoreGive(mutex);
        return 0;
    }
    
    
    
    //semaphore
    int SemaphoreStatic:: create_semaphore_binary(semaphore_handle_t *semaphore)
    {
        if (semaphore == NULL)
            return -1;
        vSemaphoreCreateBinary(*semaphore);
        if (*semaphore == NULL)
            return -1;
        return 0;        
    }
    int SemaphoreStatic:: wait_semaphore(semaphore_handle_t semaphore)
    {
        portBASE_TYPE  rc = pdFALSE; 
        rc = xSemaphoreTake(semaphore, portMAX_DELAY );
        if ( rc == pdPASS)
          return 0;
        return -1;
    }
    int SemaphoreStatic:: wait_semaphore(semaphore_handle_t semaphore, uint32_t msec_to_wait)
    {
        portBASE_TYPE  rc = pdFALSE; 
        TickType_t ticks_to_wait;
        if (msec_to_wait == 0)
            ticks_to_wait = 0;
        else
            ticks_to_wait = pdMS_TO_TICKS(msec_to_wait);
        rc = xSemaphoreTake(semaphore, ticks_to_wait );
        
        if ( rc == pdPASS)
          return 0;
        return -1;          
     }    
    int SemaphoreStatic:: send_semaphore(semaphore_handle_t semaphore)
    {
        xSemaphoreGive(semaphore);
        return 0;
    }
    
    
    //queue
    int QueueStatic::create_queue(queue_handle_t *queue, uint32_t q_size, uint32_t q_item_size)
    {
        if (queue == NULL)
            return -1;
        *queue = xQueueCreate((portBASE_TYPE)q_size, (portBASE_TYPE)q_item_size);
        if (queue == NULL)
            return -1;
        return 0;
    }
    int QueueStatic:: queue_send(queue_handle_t queue, void*item, uint32_t msec_to_wait)
    {
        portBASE_TYPE rc = errQUEUE_FULL ;
        TickType_t ticks_to_wait;
        if (item == NULL)
            return -1;
        if (msec_to_wait == 0)
            ticks_to_wait = 0;
        else
            ticks_to_wait = pdMS_TO_TICKS(msec_to_wait);        
        rc = xQueueSend(queue, item, ticks_to_wait);
        if (rc != pdPASS)
            return -1;
        return 0;
    }
    int QueueStatic:: queue_send(queue_handle_t queue, void*item)
    {
        portBASE_TYPE rc;
        if (item == NULL)
            return -1;
        rc = xQueueSend(queue, item, portMAX_DELAY);
        if (rc != pdPASS )
            return -1;
        return 0;
    }
     
    int QueueStatic::queue_receive(queue_handle_t queue, void*item, uint32_t msec_to_wait)
    {
        portBASE_TYPE rc = pdFALSE;
        TickType_t ticks_to_wait;
        if (msec_to_wait == 0)
            ticks_to_wait = 0;
        else
            ticks_to_wait = pdMS_TO_TICKS(msec_to_wait);  
        
        rc = xQueueReceive(queue, item, ticks_to_wait);
        
        if (rc != pdPASS )
            return -1;
        return 0;
    }
    int QueueStatic::queue_receive(queue_handle_t queue, void*item)
    {
        portBASE_TYPE rc = pdFALSE;
        
        rc = xQueueReceive(queue, item, portMAX_DELAY);
        
        if (rc != pdPASS )
            return -1;
        return 0;
    }
    
    int QueueStatic:: get_queue_messages( queue_handle_t queue )
    {
        portBASE_TYPE rc = uxQueueMessagesWaiting(queue);
        return ((int) rc);
    }
}

