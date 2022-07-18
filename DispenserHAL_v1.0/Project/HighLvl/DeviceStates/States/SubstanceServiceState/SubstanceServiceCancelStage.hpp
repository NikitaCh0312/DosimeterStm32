#ifndef SUBSTANCE_SERVICE_CANCEL_STAGE_H_
#define SUBSTANCE_SERVICE_CANCEL_STAGE_H_

#include "DeviceStates/States/SubstanceServiceState/ISubstanceServiceState.hpp"

#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "Pump/PumpInit.h"

extern uint32_t global_timer;


class SubstanceServiceCancelStage
{
public:
    SubstanceServiceCancelStage(ISubstanceServiceState * substanceServiceState)
    {
        _substanceServiceState = substanceServiceState;
    }
    
    void Handle(UserAction_t action)
    {
        clear_display();
        set_cursor_position(0, 5);
        set_text_rus((char*)StringResources::TaskServiceMsgCancel_1str);
        set_cursor_position(1, 1);
        set_text_rus((char*)StringResources::TaskServiceMsgCancel_2str);
        set_cursor_position(2, 5);
        set_text_rus((char*)StringResources::TaskServiceMsgCancel_3str);
        
        disablePump(getPumpDriver());
        
        RTOS::Thread::delay_thread(5000);
        valveOff();
        
        _substanceServiceState->ExitState();
    }
    
private:
    ISubstanceServiceState * _substanceServiceState;
};



#endif