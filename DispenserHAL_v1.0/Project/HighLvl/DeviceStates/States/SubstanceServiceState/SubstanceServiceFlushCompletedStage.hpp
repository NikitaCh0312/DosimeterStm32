#ifndef SUBSTANCE_SERVICE_FLUSH_COMPLETED_STAGE_H_
#define SUBSTANCE_SERVICE_FLUSH_COMPLETED_STAGE_H_


#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "Sensors/Sensors.h"
#include "Valve/Valve.h"
#include "Pump/PumpInit.h"

extern uint32_t global_timer;


class SubstanceServiceFlushCompletedStage
{
public:
    SubstanceServiceFlushCompletedStage(ISubstanceServiceState * substanceServiceState)
    {
        _substanceServiceState = substanceServiceState;
        _isViewInited = false;
    }
    
    void Handle(UserAction_t action)
    {
        HandleFlushCompletedStageView();
        
        if (action.buttonsEvent.event == BUTTON_SHORT_PRESSED_EVENT)
        {               
            if (action.buttonsEvent.id == BUT_ENTER)
            {     
                _substanceServiceState->SwitchStage(TANK_INSTALL_STAGE);
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
    
    void HandleFlushCompletedStageView()
    {
        if(!_isViewInited)
        {
          clear_display();
          set_cursor_position(0, 1);
          set_text_rus((char*)StringResources::TaskServiceMsgInfo_3_1str);
          set_cursor_position(1, 1);
          set_text_rus((char*)StringResources::TaskServiceMsgInfo_3_2str);
          set_cursor_position(2, 0);
          set_text_rus((char*)StringResources::TaskServiceMsgInfo_3_3str);
          set_cursor_position(3, 1);
          set_text_rus((char*)StringResources::TaskServiceMsgInfo_3_4str); 
          
          _isViewInited = true;
        }
    }
};



#endif