#ifndef DOSIMETER_H_
#define DOSIMETER_H_

#include "stddef.h"
#include "IDeviceState.h"



typedef enum
{
    STARTUP_STATE,
    WAITING_USER_ACTION_STATE,
    MENU_STATE,
}DOSIMETER_STATE_t;

class Dosimeter
{
public:
    
    static Dosimeter * GetInstance()
    {
        if (_instance == NULL)
            _instance = new Dosimeter();
        return _instance;
    }
    void SetState(IDeviceState * state)
    {
        _state = state;
    }
    
#warning UNUSED
    DOSIMETER_STATE_t GetState()
    {
        return _dosimeterState;
    }
    void handle(UserAction_t action)
    {
        if (_state != NULL)
            _state->Handle(action);
    }
private:
    static Dosimeter * _instance;
    Dosimeter(){}
    virtual ~Dosimeter(){}
    
    
    IDeviceState * _state;
    
    DOSIMETER_STATE_t _dosimeterState;
};


#endif