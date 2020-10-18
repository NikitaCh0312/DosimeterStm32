#ifndef TASK_TYPES_H_
#define TASK_TYPES_H_

#include "Buttons/Buttons.h"
#include "RTOS/RTOSManager.h"
typedef enum
{
    BUTTON_PRESSED_EVENT,
    BUTTON_LONG_PRESSED_EVENT,
}BUTTON_EVENT_t;

typedef struct
{
    BUTTON_EVENT_t event;
    BUTTONS_LIST_t id;
}BUTTONS_QUEUE_t;

extern xQueueHandle ButtonsQueue;


typedef enum
{
    NEW_CARD_DETECTED_EVENT,
}RFID_EVENT_TYPE_t;
typedef struct
{
    RFID_EVENT_TYPE_t event;
    uint32_t card_id;    
}RfigCardEvent_t;
extern xQueueHandle RfidQueue;
#endif