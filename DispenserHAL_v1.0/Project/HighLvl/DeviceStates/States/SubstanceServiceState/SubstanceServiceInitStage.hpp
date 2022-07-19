#ifndef SUBSTANCE_SERVICE_INIT_STAGE_H_
#define SUBSTANCE_SERVICE_INIT_STAGE_H_

#include "DeviceStates/States/SubstanceServiceState/ISubstanceServiceState.hpp"

#include "LCD/LCD.h"
#include "Resources/StringResources.h"

extern uint32_t global_timer;

class SubstanceServiceInitStage
{
public:
    SubstanceServiceInitStage(ISubstanceServiceState * substanceServiceState)
    {
        _substanceServiceState = substanceServiceState;
        _isViewInited = false;
    }
    
    void Handle(UserAction_t action)
    {
        HandleInitStageView();
        HandleInitStageUserAction(action);
    }
    
private:
    ISubstanceServiceState * _substanceServiceState;
    bool _isViewInited;
    
    void HandleInitStageView()
    {
        if(!_isViewInited)
        {
          clear_display();
          set_cursor_position(0, 1);
          set_text_rus((char*)StringResources::TaskServiceMsgInit_1str);
          set_cursor_position(1, 1);
          set_text_rus((char*)StringResources::TaskServiceMsgInit_2str);
          set_cursor_position(2, 2);
          set_text_rus((char*)StringResources::TaskServiceMsgInit_3str);
          set_cursor_position(3, 2);
          set_text_rus((char*)StringResources::TaskServiceMsgInit_4str); 
          
          _isViewInited = true;
        }
    }
    
    void HandleInitStageUserAction(UserAction_t action)
    {
        if (action.buttonsEvent.event == BUTTON_SHORT_PRESSED_EVENT)
        {               
            if (action.buttonsEvent.id == BUT_ENTER)
            {     
                _substanceServiceState->SwitchStage(TANK_CLEANING_STAGE);
                _isViewInited = false;

            }
        }
        if (action.buttonsEvent.event == BUTTON_LONG_PRESSED_EVENT)
        {               
            if (action.buttonsEvent.id == BUT_CANCEL)
            {              
                _substanceServiceState->SwitchStage(CANCEL_SERVICE_MODE_STAGE);
                _isViewInited = false;
            }
        }
    }
};



#endif