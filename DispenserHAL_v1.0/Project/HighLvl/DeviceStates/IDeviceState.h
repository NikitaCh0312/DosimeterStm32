#ifndef IDEVICE_STATE_H_
#define IDEVICE_STATE_H_

#include "stddef.h"

class Dosimeter;

class IDeviceState
{
public:
    IDeviceState(){}

    virtual ~IDeviceState(){}

    void SetContext(Dosimeter * ctx)
    {
        _context = ctx;
    }
    virtual void Handle() = 0;
private:
    Dosimeter * _context;
};







#endif