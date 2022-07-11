#ifndef FLUSHING_STATE_H_
#define FLUSHING_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"

extern uint32_t global_timer;


class FlushingState: public IDeviceState
{
public:
    static FlushingState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new FlushingState();
        return _instance;
    }
    
    void Handle(UserAction_t action)
    {

    }
    
private:
    static FlushingState * _instance;
    FlushingState()
    {

    }
};



#endif