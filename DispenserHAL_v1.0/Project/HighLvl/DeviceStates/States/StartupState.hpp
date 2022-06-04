#ifndef STARTUP_STATE_H_
#define STARTUP_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"
#include "LCD/LCD.h"

class StartupState: public IDeviceState
{
public:
    static StartupState* GetInstance()
    {
        if (_instance == NULL)
            _instance = new StartupState();
        return _instance;
    }
    
    void Handle(UserAction_t action)
    {
        //check device state
        
        //set to WaitingUserActionState
        _context->SetState( this->_statesFactory->GetState(WAITING_USER_ACTION_STATE));
    }
    
private:
    static StartupState * _instance;
    StartupState(){}
};



#endif