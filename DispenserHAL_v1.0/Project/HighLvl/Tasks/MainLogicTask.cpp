#include "MainLogicTask.h"
#include "Tasks/TasksTypes.h"
#include "Pump/Pump.h"
#include "DeviceStates/Dosimeter.h"

extern A4988Driver_t pumpDriver;


void MainLogicTask::Execute()
{
//    DisplayCardEvent_t displayEvent;
    Dosimeter * dosimeter = Dosimeter::GetInstance();
    while(1)
    {
        dosimeter->handle();
        
//        if (RfidQueue == NULL || ButtonsQueue == NULL || DisplayQueue == NULL)
//            continue;
//        //buttons handler
//        BUTTONS_QUEUE_t buttonsEvent;
//        RTOS::QueueStatic::queue_receive(ButtonsQueue, &buttonsEvent, 0);
//        if (buttonsEvent.event == BUTTON_LONG_PRESSED_EVENT)
//        {
//
//        }
//        else if (buttonsEvent.event == BUTTON_SHORT_PRESSED_EVENT)
//        {
//            if (buttonsEvent.id == BUT_ENTER)
//                startPump(500, CLOCKWISE_PUMP_DIRECTION, &pumpDriver);
//            else if (buttonsEvent.id == BUT_CANCEL)
//                stopPump(&pumpDriver);
//        }
//        
//        //rfid handler
//        RfigCardEvent_t rfidEvent = 
//        {
//            .event = NONE_RFID_EVENT,
//        };
//        
//        RTOS::QueueStatic::queue_receive(RfidQueue, &rfidEvent, 0);
//        if (rfidEvent.event == NEW_CARD_DETECTED_EVENT)
//        {
//            displayEvent.event = NEW_RFID_CARD_DISPLAY_EVENT;
//            displayEvent.rfidCard = rfidEvent.rfidCard;
//            RTOS::QueueStatic::queue_send(DisplayQueue, &displayEvent);
//        }
    }
}