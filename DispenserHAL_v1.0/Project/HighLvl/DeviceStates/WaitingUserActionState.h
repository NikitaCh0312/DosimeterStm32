#ifndef WAITING_USER_ACTION_STATE_H_
#define WAITING_USER_ACTION_STATE_H_

#include "IDeviceState.h"


class WaitingUserActionState: public IDeviceState
{
public:
    static WaitingUserActionState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new WaitingUserActionState();
        return _instance;
    }
    void Handle()
    {
        
    }
private:
    static WaitingUserActionState * _instance;
    WaitingUserActionState(){}
};



#endif