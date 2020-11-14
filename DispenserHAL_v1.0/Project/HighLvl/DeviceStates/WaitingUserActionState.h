#ifndef WAITING_USER_ACTION_STATE_H_
#define WAITING_USER_ACTION_STATE_H_

#include "IDeviceState.h"


extern uint32_t global_timer;

typedef enum
{
    WAITING_STAGE,
    CARD_NOT_REGISTERED_STAGE,
}WAITING_STATE_STAGE_t;


class WaitingUserActionState: public IDeviceState
{
public:
    static WaitingUserActionState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new WaitingUserActionState();
        return _instance;
    }
    void Handle(UserAction_t action);
    
private:
    static WaitingUserActionState * _instance;
    WaitingUserActionState()
    {
        _stage = WAITING_STAGE;
    }
    
    
    WAITING_STATE_STAGE_t _stage;
};



#endif