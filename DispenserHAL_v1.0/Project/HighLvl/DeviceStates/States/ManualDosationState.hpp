#ifndef MANUAL_DOSATION_STATE_STATE_H_
#define MANUAL_DOSATION_STATE_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"

extern uint32_t global_timer;

class ManualDosationState: public IDeviceState
{
public:
    static ManualDosationState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new ManualDosationState();
        return _instance;
    }
    
    void Handle(UserAction_t action)
    {

    }
    
private:
    static ManualDosationState * _instance;
    ManualDosationState()
    {

    }

};



#endif