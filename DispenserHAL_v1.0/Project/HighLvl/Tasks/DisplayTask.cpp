#include "DisplayTask.h"
#include "LCD/LCD.h"
#include "Tasks/TasksTypes.h"
#include "string.h"
#include "stdio.h"


xQueueHandle DisplayQueue;


void DisplayTask::Execute()
{
    set_cursor_position(0, 3);
    set_text_eng("ip:192.168.0.10");
    set_cursor_position(1, 3);
    set_text_eng("port: 667");
    set_cursor_position(2, 3);
    set_text_eng("RFID card ID:");
    
    
    RTOS::QueueStatic::create_queue(&DisplayQueue, 10, sizeof(DisplayCardEvent_t));
    
    while(1)
    {
        DisplayCardEvent_t event;
        RTOS::QueueStatic::queue_receive(DisplayQueue, &event, 0);
        if (event.event == NEW_RFID_CARD_DISPLAY_EVENT)
        {
            set_cursor_position(3, 3);
            char rfidId[20];
            sprintf(rfidId, "%d", event.rfidCard.CardId);
            set_text_eng(rfidId);
        }
    }
}