#ifndef TASK_TYPES_H_
#define TASK_TYPES_H_

#include "Buttons/Buttons.h"
#include "RTOS/RTOSManager.h"
#include "RFID/RFID.h"

/*
*BUTTONS TASK QUEUE
*/
typedef enum
{
    NONE_BUTTON_EVENT,
    BUTTON_SHORT_PRESSED_EVENT,
    BUTTON_LONG_PRESSED_EVENT,
    BUTTON_DOUBLE_PRESSED_EVENT,
}BUTTON_EVENT_t;

typedef struct
{
    BUTTON_EVENT_t event;
    BUTTONS_LIST_t id;
}ButtonsEvent_t;

extern xQueueHandle ButtonsQueue;

/*
*RFID TASK QUEUE
*/
typedef enum
{
    NONE_RFID_EVENT,
    NEW_CARD_DETECTED_EVENT,
}RFID_EVENT_TYPE_t;

typedef struct
{
    RFID_EVENT_TYPE_t event;
    RfidInfo_t rfidCard;    
}RfigCardEvent_t;

extern xQueueHandle RfidQueue;



/*
*DISPLAY TASK QUEUE
*/
typedef enum
{
    NONE_DISPLAY_EVENT,
    NEW_RFID_CARD_DISPLAY_EVENT,
}DISPLAY_TASK_EVENT_t;
typedef struct
{
    DISPLAY_TASK_EVENT_t event;
    RfidInfo_t rfidCard;    
}DisplayCardEvent_t;

extern xQueueHandle DisplayQueue;

#endif