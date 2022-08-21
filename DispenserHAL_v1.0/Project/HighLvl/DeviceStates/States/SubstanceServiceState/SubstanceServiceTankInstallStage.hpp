#ifndef SUBSTANCE_SERVICE_TANK_INSTALL_STAGE_H_
#define SUBSTANCE_SERVICE_TANK_INSTALL_STAGE_H_

#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "Valve/Valve.h"


extern uint32_t global_timer;


class SubstanceServiceTankInstallStage
{
public:
    SubstanceServiceTankInstallStage(ISubstanceServiceState * substanceServiceState)
    {
        _substanceServiceState = substanceServiceState;
        _isViewInited = false;
    }
    
    void Handle(UserAction_t action)
    {
        HandleTankInstallStageView();
        
        if (action.buttonsEvent.event == BUTTON_SHORT_PRESSED_EVENT)
        {               
            if (action.buttonsEvent.id == BUT_ENTER)
            {     
                _substanceServiceState->SwitchStage(TANK_FILL_STAGE);
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
    
private:
    ISubstanceServiceState * _substanceServiceState;
    
    bool _isViewInited;
    
    void HandleTankInstallStageView()
    {
        if(!_isViewInited)
        {
          clear_display();
          set_cursor_position(0, 2);
          set_text_rus((char*)StringResources::TaskServiceMsgInfo_4_1str);
          set_cursor_position(1, 3);
          set_text_rus((char*)StringResources::TaskServiceMsgInfo_4_2str);
          set_cursor_position(2, 1);
          set_text_rus((char*)StringResources::TaskServiceMsgInfo_4_3str);
          set_cursor_position(3, 1);
          set_text_rus((char*)StringResources::TaskServiceMsgInfo_4_4str); 
          
          _isViewInited = true;
        }
    }
};

#endif