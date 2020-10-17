#ifndef BUTTONS_H_
#define BUTTONS_H_

#define       BUTTONS_CNT     4

typedef enum { 
    BUT_UP = 0,
    BUT_DOWN,
    BUT_ENTER,
    BUT_CANCEL,  
}BUTTONS_LIST_t;

typedef enum { 
    RELEASED = 0,
    PRESSED, 
}BUTTONS_STATE_t;

void ButtonsInit (BUTTONS_STATE_t *pButtons);
void scanButtonsState(BUTTONS_STATE_t *pButtons);

extern BUTTONS_STATE_t Buttons[BUTTONS_CNT];

#endif