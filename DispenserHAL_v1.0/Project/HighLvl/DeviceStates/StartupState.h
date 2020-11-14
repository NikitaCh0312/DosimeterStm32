#ifndef STARTUP_STATE_H_
#define STARTUP_STATE_H_

#include "IDeviceState.h"
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
    void Handle(UserAction_t action);
    
private:
    static StartupState * _instance;
    StartupState(){}
};



#endif