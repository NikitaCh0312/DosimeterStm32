#ifndef TASK_SELECTION_STATE_H_
#define TASK_SELECTION_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"

#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "string.h"
#include "stdio.h"

class TaskSelectionState: public IDeviceState
{
public:
    static TaskSelectionState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new TaskSelectionState();
        return _instance;
    }
    
    void SetCardId(uint32_t cardId)
    {
        _cardId = cardId;
    }
    
    void Handle(UserAction_t action)
    {
        if (_stage == INITIALIZATION_STAGE)
        {
            set_cursor_position(0, 0);
            set_symbols(StringResources::TasksQuantity, strlen((char*)StringResources::TasksQuantity));
            set_cursor_position(1, 0);
            set_symbols(StringResources::CurrentTask, strlen((char*)StringResources::CurrentTask));
            set_cursor_position(2, 0);
            set_symbols(StringResources::SolutionVolume, strlen((char*)StringResources::SolutionVolume));
            set_cursor_position(3, 0);
            set_symbols(StringResources::SolutionConcentration, strlen((char*)StringResources::SolutionConcentration));
            
            _selectedTask = 0;
#warning TODO read from flash tasks quantity
            _tasksQuantity = 11;
        }
        
        if (_stage == SELECTING_TASK_STAGE)
        {
            char viewValue[4];
            
            set_cursor_position(0, 16);
            sprintf(viewValue , "%d", _tasksQuantity);
            set_text_eng(viewValue);
            
            set_cursor_position(1, 16);
            sprintf(viewValue , "%d", _selectedTask);
            set_text_eng(viewValue);
            
            if (action.buttonsEvent.event == BUTTON_SHORT_PRESSED_EVENT)
            {
                if (action.buttonsEvent.id == BUT_UP)
                {
                    if ( ++_selectedTask >= _tasksQuantity )
                        _selectedTask = _tasksQuantity - 1;
                }
                else if (action.buttonsEvent.id == BUT_DOWN)
                {
                    if ( --_selectedTask <= 0 )
                        _selectedTask = 0;
                }
                else if (action.buttonsEvent.id == BUT_ENTER)
                {
                    _context->SetState(this->_statesFactory->GetState(TASK_EXECUTION_STATE));
                }
                else if (action.buttonsEvent.id == BUT_CANCEL)
                {
                    
                }
            }
        }
    }
private:
    typedef enum
    {
        INITIALIZATION_STAGE,
        SELECTING_TASK_STAGE,
    }STAGE_t;
    
    
    static TaskSelectionState * _instance;
    TaskSelectionState()
    {
        _stage = INITIALIZATION_STAGE;
    }
    STAGE_t _stage;
    
    
    uint32_t _cardId;
    uint32_t _selectedTask;
    uint32_t _tasksQuantity;
};



#endif