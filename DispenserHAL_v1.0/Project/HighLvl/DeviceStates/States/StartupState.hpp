#ifndef STARTUP_STATE_H_
#define STARTUP_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"
#include "LCD/LCD.h"
#include "VoltageMonitor/VoltageMonitor.h"
#include "Resources/StringResources.h"
#include "LCD/FontRusConverter.h"

extern uint32_t global_timer;

typedef enum
{
    NONE_ERROR_TYPE_t,
    VOLTAGE_ERROR_TYPE_t,
    MEMORY_ERROR_TYPE_t,
    //...
}ERROR_TYPE_t;

class StartupState: public IDeviceState
{
public:
    static StartupState* GetInstance()
    {
        if (_instance == NULL)
            _instance = new StartupState();
        return _instance;
    }
    
    void Handle(UserAction_t action)
    {
        DrawStartupState();

        DelayMsec(2000);
        
        ERROR_TYPE_t error = CheckForError();
        if (error != NONE_ERROR_TYPE_t)
        {
            DrawError(error);
            while(1);
        }

        DelayMsec(2000);

        //set to WaitingUserActionState
        clear_display();
        _context->SetState( this->_statesFactory->GetState(WAITING_USER_ACTION_STATE));
    }
    
private:
    static StartupState * _instance;
    StartupState(){}
    
    void DrawStartupState()
    {
        set_cursor_position(0, 0);
        set_text_rus((char*)StringResources::Attention);
        set_cursor_position(1, 0);
        set_text_rus((char*)StringResources::DevicePreparing);
        set_cursor_position(2, 0);
        set_text_rus((char*)StringResources::PleaseWait);
    }
    
    ERROR_TYPE_t CheckForError()
    {
        //check voltage
        uint32_t sum = 0;
        for (int i = 0; i < 4000; i++)
            sum += getSupplyVoltage();
        uint32_t res = sum / 4000;
        if (res == 0)    
            return VOLTAGE_ERROR_TYPE_t;
        
        return NONE_ERROR_TYPE_t;
    }

    void DrawError(ERROR_TYPE_t error)
    {
        clear_display();
        set_cursor_position(0, 0);
        set_text_rus((char*)StringResources::Error);
        if (error == VOLTAGE_ERROR_TYPE_t)
            DrawVoltageError();
    }

    void DrawVoltageError()
    {
        set_cursor_position(1, 0);
        set_text_rus((char*)StringResources::VoltageError);
    }

    void DelayMsec(uint32_t delayMsec)
    {
        uint32_t startTime = global_timer;
        while(global_timer - startTime < delayMsec);
    }
};



#endif