#include "RfidTask.h"
#include "Tasks/TasksTypes.h"

xQueueHandle RfidQueue;

void RfidTask::Execute()
{
    RTOS::QueueStatic::create_queue(&RfidQueue, 10, sizeof(RfigCardEvent_t));
    RfigCardEvent_t event;
    while(1)
    {
        if (getRfidState() == NEW_CARD_STATE)
        {
            RfidInfo_t card = getNewCard();
            event.event = NEW_CARD_DETECTED_EVENT;
            event.rfidCard = card;
            RTOS::QueueStatic::queue_send(RfidQueue, &event);
        }
    }
}