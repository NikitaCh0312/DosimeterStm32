#ifndef IDEVICE_STATE_H_
#define IDEVICE_STATE_H_

#include "stddef.h"
#include "Tasks/TasksTypes.h"

typedef struct
{
    ButtonsEvent_t buttonsEvent;
    RfigCardEvent_t rfidEvent;
}UserAction_t;

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
    virtual void Handle(UserAction_t action) = 0;
    
    Dosimeter * _context;
protected:
    
};







#endif