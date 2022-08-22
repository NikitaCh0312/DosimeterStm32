#ifndef STARTUP_STATE_H_
#define STARTUP_STATE_H_

#define PSNV    24000
#define SVT     5

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"
#include "LCD/LCD.h"
#include "VoltageMonitor/VoltageMonitor.h"
#include "Resources/StringResources.h"
#include "LCD/FontRusConverter.h"
#include "Sensors/Sensors.h"

extern uint32_t global_timer;

typedef enum
{
    NONE_ERROR_TYPE_t,
    VOLTAGE_ERROR_TYPE_t,
    MEMORY_ERROR_TYPE_t,
    RTC_ERROR_TYPE_t,
    SUBSTANCE_ERROR_TYPE_t,
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

        DelayMsec(3500);
        
        ERROR_TYPE_t error = CheckForError();
        if (error != NONE_ERROR_TYPE_t)
        {
            DrawError(error);
            while(1);
        }

        DelayMsec(1000);

        //set to WaitingUserActionState
        if (error == NONE_ERROR_TYPE_t)
        {
          clear_display();
          DrawAboutDevice();
          DelayMsec(3500);
          clear_display();
          _context->SetState( this->_statesFactory->GetState(WAITING_USER_ACTION_STATE));
        }
        else {while(1);}
    }
    
private:
    static StartupState * _instance;
    StartupState(){}
    
    void DrawStartupState()
    {
        clear_display();
        set_cursor_position(0, 6);
        set_text_rus((char*)StringResources::Attention);
        set_cursor_position(1, 2);
        set_text_rus((char*)StringResources::DevicePreparing_1);
        set_cursor_position(2, 0);
        set_text_rus((char*)StringResources::DevicePreparing_2);
        set_cursor_position(3, 2);
        set_text_rus((char*)StringResources::DevicePreparing_3);

    }
    
    ERROR_TYPE_t CheckForError()
    {
        ERROR_TYPE_t err_code = NONE_ERROR_TYPE_t;
        
        //check voltage
        uint32_t sum = 0;
        for (int i = 0; i < 4000; i++) sum += getSupplyVoltage_mV();
        uint32_t res = sum / 4000;
        if (((PSNV * (100 - SVT)) / 100 > res) || ((PSNV * (100 + SVT)) / 100 < res))  err_code = VOLTAGE_ERROR_TYPE_t;       
        //check substance 
        //else if(getSensorState(LEVEL_SENSOR_TYPE) != ON_SENSOR_STATE) err_code = SUBSTANCE_ERROR_TYPE_t;
        
        return err_code;
    }

    void DrawError(ERROR_TYPE_t error)
    {
        clear_display();
        set_cursor_position(0, 5);
        set_text_rus((char*)StringResources::Error);
        if (error == VOLTAGE_ERROR_TYPE_t) DrawVoltageError();
        else if (error == SUBSTANCE_ERROR_TYPE_t) DrawSubstanceError();
            
    }

    void DrawVoltageError()
    {
        set_cursor_position(1, 1);
        set_text_rus((char*)StringResources::VoltageError_1);
        set_cursor_position(2, 4);
        set_text_rus((char*)StringResources::VoltageError_2);
    }
    
    void DrawSubstanceError()
    {
        set_cursor_position(1, 1);
        set_text_rus((char*)StringResources::TaskErrorAvalibilitySubstance_1str);
        set_cursor_position(2, 4);
        set_text_rus((char*)StringResources::TaskErrorAvalibilitySubstance_2str);
    }
    
    void DrawAboutDevice()
    {
        set_cursor_position(0, 0);
        set_text_rus((char*)StringResources::DeviceInfo_1);
        set_cursor_position(1, 0);
        set_text_rus((char*)StringResources::DeviceInfo_2);
        set_cursor_position(2, 4);
        set_text_rus((char*)StringResources::DeviceInfo_3);
        set_cursor_position(3, 0);
        set_text_rus((char*)StringResources::DeviceInfo_4);
    }

    void DelayMsec(uint32_t delayMsec)
    {
        uint32_t startTime = global_timer;
        while(global_timer - startTime < delayMsec);
    }
};



#endif