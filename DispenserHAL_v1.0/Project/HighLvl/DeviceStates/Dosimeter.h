#ifndef DOSIMETER_H_
#define DOSIMETER_H_

#include "stddef.h"
#include "IDeviceState.h"

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
    
    void handle()
    {
        if (_state != NULL)
            _state->Handle();
    }
private:
    static Dosimeter * _instance;
    Dosimeter(){}
    virtual ~Dosimeter(){}
    
    IDeviceState * _state;
    
};


#endif