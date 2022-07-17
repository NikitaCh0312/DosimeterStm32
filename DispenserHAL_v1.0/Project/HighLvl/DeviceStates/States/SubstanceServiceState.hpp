#ifndef SUBSTANCE_SERVICE_STATE_H_
#define SUBSTANCE_SERVICE_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"

extern uint32_t global_timer;


class SubstanceServiceState: public IDeviceState
{
public:
    static SubstanceServiceState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new SubstanceServiceState();
        return _instance;
    }
    
    void Handle(UserAction_t action)
    {

    }
    
private:
    static SubstanceServiceState * _instance;
    SubstanceServiceState()
    {

    }
};



#endif