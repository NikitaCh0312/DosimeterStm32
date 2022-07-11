#ifndef ENUM_DOSIMETER_STATES_H_
#define ENUM_DOSIMETER_STATES_H_


typedef enum
{
    STARTUP_STATE,
    WAITING_USER_ACTION_STATE,
    MENU_STATE,
    TASK_SELECTION_STATE,
    TASK_EXECUTION_STATE,
    MANUAL_DOSATION_STATE,
    FLUSHING_STATE
}DOSIMETER_STATE_t;

#endif