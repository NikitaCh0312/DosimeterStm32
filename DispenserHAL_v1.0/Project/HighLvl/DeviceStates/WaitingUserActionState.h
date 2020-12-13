#ifndef WAITING_USER_ACTION_STATE_H_
#define WAITING_USER_ACTION_STATE_H_

#include "IDeviceState.h"
#include "Dosimeter.h"

extern uint32_t global_timer;




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
    typedef enum
    {
        WAITING_STAGE,
        CARD_NOT_BINDED_STAGE,
        CARD_IS_INACTIVE_STAGE,
    }STAGE_t;
    
    typedef enum
    {
        CARD_IS_NOT_BINDED_RES,
        CARD_IS_INACTIVE_RES,
        CARD_IS_ACTIVE_RES,
        CARD_EXT_ACCESS_RES,
    }CARD_VERIFICATION_RES_t;
    
    static WaitingUserActionState * _instance;
    WaitingUserActionState()
    {
        _stage = WAITING_STAGE;
    }
    
    
    STAGE_t _stage;
};



#endif