#include "ButtonsTask.h"
#include "Buttons/Buttons.h"
#include "Tasks/TasksTypes.h"

xQueueHandle ButtonsQueue;

void ButtonsTask::Execute()
{
    BUTTON_PARAMETERS_t ButtonPARAM[BUTTONS_CNT];
    
    for(uint8_t i = 0; i < BUTTONS_CNT; i++) //set default parametrs
    {
        ButtonPARAM[i].startTime                = 0;
        ButtonPARAM[i].flagOldState             = 0;
        ButtonPARAM[i].flagWasLongPressed       = 0;
    }
    
    BUTTONS_QUEUE_t queue;
    
    RTOS::QueueStatic::create_queue(&ButtonsQueue, 10, sizeof(BUTTONS_QUEUE_t));
    
    while(1)
    {
       scanButtonsState(Buttons);
       
        for (uint8_t _j = 0; _j < BUTTONS_CNT; _j++)  
        {
            if (Buttons[_j] == PRESSED) 
            {
                if(ButtonPARAM[_j].flagOldState == 0)
                {
                    ButtonPARAM[_j].startTime = getSysTime_ms();
                    ButtonPARAM[_j].flagOldState = 1;
                }
                else if(((getSysTime_ms() - ButtonPARAM[_j].startTime) >= LONG_PRESSED_TIME_MS) && (ButtonPARAM[_j].flagWasLongPressed == 0))
                {
                    ButtonPARAM[_j].flagWasLongPressed = 1;
                    
                    queue.event = BUTTON_LONG_PRESSED_EVENT;
                    queue.id = (BUTTONS_LIST_t)_j; 
                    RTOS::QueueStatic::queue_send(ButtonsQueue, &queue);
                }
            }
            else
            {
                if(ButtonPARAM[_j].flagOldState == 1)
                {
                    if(((getSysTime_ms() - ButtonPARAM[_j].startTime) > TRASH_TIME_MS) && ((getSysTime_ms() - ButtonPARAM[_j].startTime) < LONG_PRESSED_TIME_MS))
                    {
                        
                        queue.event = BUTTON_SHORT_PRESSED_EVENT;
                        queue.id = (BUTTONS_LIST_t)_j; 
                        RTOS::QueueStatic::queue_send(ButtonsQueue, &queue);
                        
                    }
                }
                
                ButtonPARAM[_j].flagOldState = 0; 
                ButtonPARAM[_j].flagWasLongPressed = 0;
            }
        }
        //delay 10msec
        RTOS::Thread::delay_thread(10);
    }
}
