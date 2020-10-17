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


#endif