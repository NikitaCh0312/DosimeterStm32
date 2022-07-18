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
    }
    
    void Handle(UserAction_t action)
    {

    }
    
private:
    ISubstanceServiceState * _substanceServiceState;
};



#endif