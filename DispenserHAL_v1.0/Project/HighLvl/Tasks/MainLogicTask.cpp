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
        if (RfidQueue == NULL || ButtonsQueue == NULL)
            continue;
        
        //buttons task events
        ButtonsEvent_t buttonsEvent; 
        buttonsEvent.event = NONE_BUTTON_EVENT;
        RTOS::QueueStatic::queue_receive(ButtonsQueue, &buttonsEvent, 0);
        
        //rfid task events
        RfigCardEvent_t rfidEvent;
        rfidEvent.event = NONE_RFID_EVENT;
        RTOS::QueueStatic::queue_receive(RfidQueue, &rfidEvent, 0);
        
        //send to dosimeter
        UserAction_t action;
        action.buttonsEvent = buttonsEvent;
        action.rfidEvent = rfidEvent;
        dosimeter->handle(action);
    }
}