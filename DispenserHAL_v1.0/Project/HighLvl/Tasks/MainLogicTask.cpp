#include "MainLogicTask.h"
#include "Tasks/TasksTypes.h"

void MainLogicTask::Execute()
{
    while(1)
    {
        //buttons handler
        BUTTONS_QUEUE_t queue;
        RTOS::QueueStatic::queue_receive(ButtonsQueue, &queue, 0);
        if (queue.event == BUTTON_LONG_PRESSED_EVENT)
        {
            int a = 10;
            a++;
        }
        else if (queue.event == BUTTON_SHORT_PRESSED_EVENT)
        {
            int a = 10;
            a++;
        }
        
        //rfid handler
        RfigCardEvent_t event = 
        {
            .event = NONE_RFID_EVENT,
        };
        RTOS::QueueStatic::queue_receive(RfidQueue, &event, 0);
        if (event.event == NEW_CARD_DETECTED_EVENT)
        {
            
        }
    }
}