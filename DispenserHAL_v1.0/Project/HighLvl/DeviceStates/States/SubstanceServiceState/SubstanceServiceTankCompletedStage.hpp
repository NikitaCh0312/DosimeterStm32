#ifndef SUBSTANCE_SERVICE_TANK_COMPLETED_STAGE_H_
#define SUBSTANCE_SERVICE_TANK_COMPLETED_STAGE_H_

#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "Valve/Valve.h"


extern uint32_t global_timer;


class SubstanceServiceTankCompletedStage
{
public:
    SubstanceServiceTankCompletedStage(ISubstanceServiceState * substanceServiceState)
    {
        _substanceServiceState = substanceServiceState;
    }
    
    void Handle(UserAction_t action)
    {
        if (action.buttonsEvent.event == BUTTON_LONG_PRESSED_EVENT)
        {               
            if (action.buttonsEvent.id == BUT_CANCEL)
            {                 
                _substanceServiceState->SwitchStage(CANCEL_SERVICE_MODE_STAGE);
                valveOn();
            }
        }
    }
    
private:
    ISubstanceServiceState * _substanceServiceState;
};



#endif