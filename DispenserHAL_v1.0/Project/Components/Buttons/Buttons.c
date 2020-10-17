#include "Buttons.h"
#include "main.h"

BUTTONS_STATE_t Buttons[BUTTONS_CNT];

void ButtonsInit (BUTTONS_STATE_t *pButtons)
{
    for (uint8_t i = 0; i < BUTTONS_CNT; i++) 
    {
        pButtons[i] = RELEASED;
    } 
}

BUTTONS_STATE_t getButtonState(BUTTONS_LIST_t idBut)
{
    BUTTONS_STATE_t state = RELEASED;
    
    switch (idBut)
    {
        case BUT_UP:
        {
            if(!HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin))
            {
               state = PRESSED; 
            }
            else  state = RELEASED;           
            break;
        }
        case BUT_DOWN:
        {
            if(!HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin))
            {
               state = PRESSED; 
            }
            else  state = RELEASED;           
            break;
        }
        case BUT_ENTER:
        {
            if(!HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin))
            {
               state = PRESSED; 
            }
            else  state = RELEASED;            
            break;
        }
        case BUT_CANCEL:
        {
            if(!HAL_GPIO_ReadPin(BUTTON4_GPIO_Port, BUTTON4_Pin))
            {
               state = PRESSED; 
            }
            else  state = RELEASED;            
            break;
        }
        default: break;
    }
              
    return state;
}

void scanButtonsState(BUTTONS_STATE_t *pButtons)
{
    for (uint8_t i = 0; i < BUTTONS_CNT; i++) 
    {
        pButtons[i] = getButtonState((BUTTONS_LIST_t)i);
    }
    
}

