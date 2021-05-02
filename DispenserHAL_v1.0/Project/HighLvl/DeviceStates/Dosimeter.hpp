#ifndef DOSIMETER_H_
#define DOSIMETER_H_

#include "stddef.h"
#include "[Interfaces]/IDeviceState.hpp"

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
};


#endif