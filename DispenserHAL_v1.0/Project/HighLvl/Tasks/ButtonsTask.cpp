#include "ButtonsTask.h"
#include "Buttons/Buttons.h"
#include "Tasks/TasksTypes.h"

xQueueHandle ButtonsQueue;

void ButtonsTask::Execute()
{
    ButtonsInit(Buttons);
    RTOS::QueueStatic::create_queue(&ButtonsQueue, 10, sizeof(BUTTONS_QUEUE_t));
    while(1)
    {
       scanButtonsState(Buttons);
       BUTTONS_QUEUE_t queue;
       if (Buttons[BUT_UP] == PRESSED)
       {
           queue.event = BUTTON_PRESSED_EVENT;
           queue.id = BUT_UP;
           RTOS::QueueStatic::queue_send(ButtonsQueue, &queue);
       }
    }
}
