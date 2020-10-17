#include "MainLogicTask.h"
#include "Tasks/TasksTypes.h"

void MainLogicTask::Execute()
{
    while(1)
    {
        BUTTONS_QUEUE_t queue;
        RTOS::QueueStatic::queue_receive(ButtonsQueue, &queue);
        if (queue.event == BUTTON_PRESSED_EVENT)
        {
            int a = 10;
            a++;
        }
    }
}