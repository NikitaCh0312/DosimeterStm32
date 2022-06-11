#ifndef TASK_SELECTION_STATE_H_
#define TASK_SELECTION_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/States/TaskExecutionState.hpp"

#include "modules/[Interfaces]/ICardsManager.h"
#include "modules/ModulesLocator.h"

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
            set_text_rus((char*)StringResources::TasksQuantity);
            set_cursor_position(1, 0);
            set_text_rus((char*)StringResources::CurrentTask);
            set_cursor_position(2, 0);
            set_text_rus((char*)StringResources::SolutionVolume);
            set_cursor_position(3, 0);
            set_text_rus((char*)StringResources::SolutionConcentration);
            
            _selectedTask = 0;
            
            _selectedCard = _cardsManager->GetCard(_cardId);
            
            _stage = SELECTING_TASK_STAGE;
        }
        
        if (_stage == SELECTING_TASK_STAGE)
        {
            char viewValue[4];
            
            set_cursor_position(0, 16);
            sprintf(viewValue , "%d", _selectedCard.TasksQuantity);
            set_text_eng(viewValue);
            
            set_cursor_position(1, 16);
            sprintf(viewValue , "%d", (_selectedTask + 1));
            set_text_eng(viewValue);
            
            set_cursor_position(2, 16);
            sprintf(viewValue , "%d", _selectedCard.tasks[_selectedTask].Volume);
            set_text_eng(viewValue);
            
            set_cursor_position(3, 16);
            sprintf(viewValue , "%d", _selectedCard.tasks[_selectedTask].Concentration);
            set_text_eng(viewValue);
            
            if (action.buttonsEvent.event == BUTTON_SHORT_PRESSED_EVENT)
            {
                if (action.buttonsEvent.id == BUT_UP)
                {
                    if ( ++_selectedTask >= _selectedCard.TasksQuantity )
                        _selectedTask = _selectedCard.TasksQuantity - 1;
                }
                else if (action.buttonsEvent.id == BUT_DOWN)
                {
                    if ( --_selectedTask <= 0 )
                        _selectedTask = 0;
                }
                else if (action.buttonsEvent.id == BUT_ENTER)
                {
                    TaskExecutionState* executionState = (TaskExecutionState*)this->_statesFactory->GetState(TASK_EXECUTION_STATE);
                    executionState->InitExecutionState(_selectedCard.tasks[_selectedTask]);
                    _context->SetState(executionState);
                }
                else if (action.buttonsEvent.id == BUT_CANCEL)
                {
                    _context->SetState(this->_statesFactory->GetState(WAITING_USER_ACTION_STATE));
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
        _cardsManager = ModulesLocator::GetInstance()->cardsManager;
        
    }
    STAGE_t _stage;
    
    
    uint32_t _cardId;
    Card _selectedCard;
    uint32_t _selectedTask;

    ICardsManager * _cardsManager;
};



#endif