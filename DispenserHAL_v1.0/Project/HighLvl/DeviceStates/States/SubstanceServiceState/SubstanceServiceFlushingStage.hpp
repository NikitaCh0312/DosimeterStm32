#ifndef SUBSTANCE_SERVICE_FLUSHING_STAGE_H_
#define SUBSTANCE_SERVICE_FLUSHING_STAGE_H_

#include "RTOS/RTOSManager.h"
#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "Sensors/Sensors.h"
#include "Valve/Valve.h"
#include "Pump/PumpInit.h"

extern uint32_t global_timer;


class SubstanceServiceFlushingStage
{
public:
    SubstanceServiceFlushingStage(ISubstanceServiceState * substanceServiceState)
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