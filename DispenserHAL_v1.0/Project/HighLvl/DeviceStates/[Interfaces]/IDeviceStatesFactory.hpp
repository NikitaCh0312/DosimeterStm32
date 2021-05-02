#ifndef IDEVICE_STATES_FACTORY_HPP_
#define IDEVICE_STATES_FACTORY_HPP_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Enums]/DOSIMETER_STATES.h"




class IDeviceStatesFactory
{
public:
    IDeviceStatesFactory(){}
    virtual ~IDeviceStatesFactory(){}
    virtual IDeviceState * GetState(DOSIMETER_STATE_t state) = 0;
};


#endif