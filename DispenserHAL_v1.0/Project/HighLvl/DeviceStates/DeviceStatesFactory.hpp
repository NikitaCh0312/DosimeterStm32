#ifndef DEVICE_STATES_FACTORY_HPP_
#define DEVICE_STATES_FACTORY_HPP_

#include "stddef.h"
#include "[Interfaces]/IDeviceState.hpp"
#include "States/StartupState.hpp"
#include "States/WaitingUserActionState.hpp"
#include "States/MenuState.hpp"
#include "States/TaskExecutionState.hpp"
#include "States/TaskSelectionState.hpp"
#include "States/ManualDosationState.hpp"
#include "States/SubstanceServiceState.hpp"

class DeviceStatesFactory: public IDeviceStatesFactory
{
public:
    
    static DeviceStatesFactory * GetInstance()
    {
        if (_instance == NULL)
            _instance = new DeviceStatesFactory();
        return _instance;
    }

    IDeviceState * GetState(DOSIMETER_STATE_t state)
    {
        switch (state)
        {
            case STARTUP_STATE:
                return StartupState::GetInstance();
            case WAITING_USER_ACTION_STATE:
                return WaitingUserActionState::GetInstance();
            case MENU_STATE:
                MenuState * menu = MenuState::GetInstance();
                menu->InitMenuState();
                return menu;
            case TASK_SELECTION_STATE:
                return TaskSelectionState::GetInstance();
            case TASK_EXECUTION_STATE:
                return TaskExecutionState::GetInstance();
            case MANUAL_DOSATION_STATE:
                return ManualDosationState::GetInstance();
            case FLUSHING_STATE:
                return SubstanceServiceState::GetInstance();
            default:
                return NULL;
        }
    }

private:
    static DeviceStatesFactory * _instance;
    DeviceStatesFactory(){}
    virtual ~DeviceStatesFactory(){}

};


#endif