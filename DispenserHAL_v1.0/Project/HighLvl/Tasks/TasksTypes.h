#ifndef TASK_TYPES_H_
#define TASK_TYPES_H_

#include "Buttons/Buttons.h"
#include "RTOS/RTOSManager.h"

#define LONG_PRESSED_TIME_MS            2500
#define TRASH_TIME_MS                   50

typedef enum
{
    BUTTON_SHORT_PRESSED_EVENT,
    BUTTON_LONG_PRESSED_EVENT,
    BUTTON_DOUBLE_PRESSED_EVENT,
}BUTTON_EVENT_t;

typedef struct
{
    BUTTON_EVENT_t event;
    BUTTONS_LIST_t id;
}BUTTONS_QUEUE_t;

typedef struct
{
    uint32_t    startTime;
    uint8_t     flagOldState;
    uint8_t     flagWasLongPressed;
}BUTTON_PARAMETERS_t;

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