#ifndef WAITING_USER_ACTION_STATE_H_
#define WAITING_USER_ACTION_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"
#include "DeviceStates/States/TaskSelectionState.hpp"

#include "LCD/LCD.h"
#include "RTC/RTC_drv.h"
#include "Resources/StringResources.h"
#include "modules/[Interfaces]/ICardsManager.h"
#include "modules/ModulesLocator.h"
#include "string.h"

extern uint32_t global_timer;




class WaitingUserActionState: public IDeviceState
{
public:
    static WaitingUserActionState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new WaitingUserActionState();
        return _instance;
    }
    
    void Handle(UserAction_t action)
    {
        static uint32_t stageTimer;
        
        if (_stage == WAITING_STAGE)
        {
            if (!_isWaitingUserActionDisplayInited)
            {
                clear_display();
                set_cursor_position(0, 5);
                set_text_rus((char*)StringResources::Attach_RFID_Card_1str);
                set_cursor_position(1, 7);
                set_text_rus((char*)StringResources::Attach_RFID_Card_2str);
                _isWaitingUserActionDisplayInited = true;
            }
            DrawDateTime();
            
            if (action.rfidEvent.event != NEW_CARD_DETECTED_EVENT)
                return;
            uint32_t cardId = action.rfidEvent.rfidCard.CardId;

            CARD_STATUS_t status = _cardsManager->GetCardStatus(cardId);
            switch (status)
            {
                case CARD_EXT_ACCESS_STATUS:
                {
                    _stage = WAITING_STAGE;
                    _context->SetState(this->_statesFactory->GetState(MENU_STATE));
                    clear_display();
#warning NEED REFACTORING!!!
                    _isWaitingUserActionDisplayInited = false;
                    _currentDateTime.Minutes = 100;
                    _currentDateTime.Hours = 100;
                    break;
                }
                case CARD_IS_INACTIVE_STATUS:
                {
                    stageTimer = global_timer;
                    _stage = CARD_IS_INACTIVE_STAGE;
                    clear_display();
#warning NEED REFACTORING!!!
                    _isWaitingUserActionDisplayInited = false;
                    _currentDateTime.Minutes = 100;
                    _currentDateTime.Hours = 100;
                    break;
                }
                case CARD_IS_NOT_BINDED_STATUS:
                {
                    stageTimer = global_timer;
                    _stage = CARD_NOT_BINDED_STAGE;
                    clear_display();
#warning NEED REFACTORING!!!
                    _isWaitingUserActionDisplayInited = false;
                    _currentDateTime.Minutes = 100;
                    _currentDateTime.Hours = 100;
                    break;
                }
                case CARD_IS_ACTIVE_STATUS:
                {
                    _stage = WAITING_STAGE;
                    TaskSelectionState * taskSelectionState = (TaskSelectionState*)this->_statesFactory->GetState(TASK_SELECTION_STATE);
                    taskSelectionState->SetCardId(cardId);
                    _context->SetState(taskSelectionState);
                    clear_display();
#warning NEED REFACTORING!!!
                    _isWaitingUserActionDisplayInited = false;
                    _currentDateTime.Minutes = 100;
                    _currentDateTime.Hours = 100;
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

        
        if (_stage == CARD_NOT_BINDED_STAGE)
        { 
            set_cursor_position(0, 6);
            set_text_rus((char*)StringResources::Attention); 
            set_cursor_position(1, 1);
            set_text_rus((char*)StringResources::CardIsNotBinded); 
            set_cursor_position(2, 4);
            set_text_rus((char*)StringResources::ToThisDevice); 
            
            if (global_timer - stageTimer > 5000)
            {
                _stage = WAITING_STAGE;
                clear_display();
                _isWaitingUserActionDisplayInited = false;
            }
            return;
        }
        
        
        if (_stage == CARD_IS_INACTIVE_STAGE)
        {
            set_cursor_position(0, 6);
            set_text_rus((char*)StringResources::Attention); 
            set_cursor_position(1, 1);
            set_text_rus((char*)StringResources::CardIsNotBinded); 
            set_cursor_position(2, 4);
            set_text_rus((char*)StringResources::ToThisDevice); 
            
            if (global_timer - stageTimer > 5000)
            {
                _stage = WAITING_STAGE;
                clear_display();
                _isWaitingUserActionDisplayInited = false;
            }
            return;
        }
    }
    
private:
    typedef enum
    {
        INITIALIZATION_STAGE,
        WAITING_STAGE,
        CARD_NOT_BINDED_STAGE,
        CARD_IS_INACTIVE_STAGE,
    }STAGE_t;
    
   
    static WaitingUserActionState * _instance;
    WaitingUserActionState()
    {
        _stage = WAITING_STAGE;
        _cardsManager = ModulesLocator::GetInstance()->cardsManager;
        _isWaitingUserActionDisplayInited = false;
    }
    
    
    STAGE_t _stage;

    ICardsManager * _cardsManager;
    RtcDateTime_t _currentDateTime;
    bool _isWaitingUserActionDisplayInited;
    
    
    const const int DATE_TIME_START_POSITION = 6;
    void DrawDateTime()
    {
        RtcDateTime_t dateTime;
        RtcGetDateTime(&dateTime);
        if (_currentDateTime.Seconds != dateTime.Seconds)
        {
            _currentDateTime.Seconds = dateTime.Seconds;
            DrawSeconds();
        }
        if (_currentDateTime.Minutes != dateTime.Minutes)
        {
            _currentDateTime.Minutes = dateTime.Minutes;
            DrawMinutes();
        }
        if (_currentDateTime.Hours != dateTime.Hours)
        {
            _currentDateTime.Hours = dateTime.Hours;
            DrawHours();
        }
        set_cursor_position(3, DATE_TIME_START_POSITION + 2);
        set_text_eng(":");
        set_cursor_position(3, DATE_TIME_START_POSITION + 5);
        set_text_eng(":");
    }
    
    void DrawHours()
    {
        char viewHoursValue[4];
        sprintf(viewHoursValue , "%02d", _currentDateTime.Hours);
        set_cursor_position(3, DATE_TIME_START_POSITION);
        set_text_eng(viewHoursValue);
    }
    
    void DrawMinutes()
    {
        char viewMinutesValue[4];
        sprintf(viewMinutesValue , "%02d", _currentDateTime.Minutes);
        set_cursor_position(3, DATE_TIME_START_POSITION + 3);
        set_text_eng(viewMinutesValue);
    }
    
    void DrawSeconds()
    {
        char viewSecondsValue[4];
        sprintf(viewSecondsValue , "%02d", _currentDateTime.Seconds);
        set_cursor_position(3, DATE_TIME_START_POSITION + 6);
        set_text_eng(viewSecondsValue);
        
    }
    

    
};



#endif