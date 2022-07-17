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
            clear_display();
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
            CARD_STATUS_t status = _cardsManager->GetCardStatus(_cardId);
            if (status == CARD_IS_NOT_BINDED_STATUS)
                _context->SetState(this->_statesFactory->GetState(WAITING_USER_ACTION_STATE));
            _stage = SELECTING_TASK_STAGE;
        }
        
        if (_stage == SELECTING_TASK_STAGE)
        {
            char viewValue[6];
            
            set_cursor_position(0, 15);
            sprintf(viewValue , "%d", _selectedCard.TasksQuantity);
            set_text_eng(viewValue);
            
            set_cursor_position(1, 15);
            sprintf(viewValue , "%02d", (_selectedTask + 1));
            set_text_eng(viewValue);
            
            set_cursor_position(2, 15);
            sprintf(viewValue , "%.2f", _selectedCard.tasks[_selectedTask].Volume);
            set_text_eng(viewValue);
            
            set_cursor_position(3, 15);
            sprintf(viewValue , "%.2f", _selectedCard.tasks[_selectedTask].Concentration);
            set_text_eng(viewValue);
            
            if (_taskCardsSession->IsTaskExecuted(_selectedCard.tasks[_selectedTask].Id))
            {
                set_cursor_position(1, 11);
                set_text_rus((char*)"Г");
            }
            
            HandleUserAction(action);
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
    
    
    int _cardId;
    Card _selectedCard;
    int _selectedTask;

    ICardsManager * _cardsManager;
    TaskCardSession * _taskCardsSession;
    
    void HandleUserAction(UserAction_t action)
    {
        if (action.buttonsEvent.event != BUTTON_SHORT_PRESSED_EVENT)
            return;

        switch(action.buttonsEvent.id)
        {
            case BUT_UP:
            {
                if ( ++_selectedTask >= _selectedCard.TasksQuantity )
                    _selectedTask = _selectedCard.TasksQuantity - 1;
                break;
            }
            case BUT_DOWN:
            {
                if ( --_selectedTask <= 0 )
                    _selectedTask = 0;
            }
            case BUT_ENTER:
            {
                if (_taskCardsSession->IsTaskExecuted(_selectedCard.tasks[_selectedTask].Id))
                  return;
                
                TaskExecutionState* executionState = (TaskExecutionState*)this->_statesFactory->GetState(TASK_EXECUTION_STATE);
                executionState->InitExecutionState(_selectedCard.tasks[_selectedTask]);
                _context->SetState(executionState);
                _stage = INITIALIZATION_STAGE;
            }
            case BUT_CANCEL:
            {
                _taskCardsSession->EndSession();
                _context->SetState(this->_statesFactory->GetState(WAITING_USER_ACTION_STATE));
                _stage = INITIALIZATION_STAGE;
                _cardId = -1;
            }
        }
    }
};



#endif