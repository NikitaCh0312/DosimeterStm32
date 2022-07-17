#ifndef SUBSTANCE_SERVICE_STATE_H_
#define SUBSTANCE_SERVICE_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"

#include "RTOS/RTOSManager.h"
#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "string.h"
#include "stdio.h"
#include "Sensors/Sensors.h"
#include "Valve/Valve.h"
#include "Pump/PumpInit.h"

extern uint32_t global_timer;


class SubstanceServiceState: public IDeviceState
{
public:
    static SubstanceServiceState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new SubstanceServiceState();
        return _instance;
    }
    
    void Handle(UserAction_t action)
    {
        switch (_stage)
        {
            case INIT_STAGE:
            {
            
                break;
            }
            case TANK_CLEANING_STAGE:
            {
                if(!exitStateDisplayInited)
                {
                  clear_display();
                  set_cursor_position(0, 0);
                  set_text_rus((char*)StringResources::TaskServiceMsgCleaning_1str);
                  set_cursor_position(1, 1);
                  set_text_rus((char*)StringResources::TaskServiceMsgCleaning_2str);
                  
                  exitStateDisplayInited = 1;
                  
                  enablePump(getPumpDriver(), getA4988Conf());
                }
               
                pumpSubstance_ml(getPumpDriver(),6000.0, 250); 
                do
                {
                   RTOS::Thread::delay_thread(5000);  
                }
                while(getSensorState(LEVEL_SENSOR_TYPE) != OFF_SENSOR_STATE);
                
                valveOn();
                
                RTOS::Thread::delay_thread(5000); 
                
                disablePump(getPumpDriver());
                
                RTOS::Thread::delay_thread(10000);
                
                valveOff();
                
                _stage = COMPLETED_TANK_CLEANING_STAGE;
                exitStateDisplayInited = 0;
                           
                break;
            }
            case COMPLETED_TANK_CLEANING_STAGE:
            {
            
                break;
            }
            case FLUSHING_STAGE:
            {
            
                break;
            }
            case COMPLETED_FLUSHING_STAGE:
            {
            
                break;
            }
            case CANCEL_SERVICE_MODE_STAGE:
            {
                if(!exitStateDisplayInited)
                {
                  clear_display();
                  set_cursor_position(0, 5);
                  set_text_rus((char*)StringResources::TaskServiceMsgCancel_1str);
                  set_cursor_position(1, 0);
                  set_text_rus((char*)StringResources::TaskServiceMsgCancel_2str);
                  set_cursor_position(2, 7);
                  set_text_rus((char*)StringResources::TaskServiceMsgCancel_3str);
                  
                  exitStateDisplayInited = 1;
                }
                
                disablePump(getPumpDriver());
                
                RTOS::Thread::delay_thread(5000);
                valveOff();
                _context->SetState(this->_statesFactory->GetState(TASK_SELECTION_STATE));
                
                break;
            }
            
            default: break;
        }
        
        // HNMI
        if (_stage == INIT_STAGE)
        {
            if(!exitStateDisplayInited)
            {
              clear_display();
              set_cursor_position(0, 0);
              set_text_rus((char*)StringResources::TaskServiceMsgInit_1str);
              set_cursor_position(1, 0);
              set_text_rus((char*)StringResources::TaskServiceMsgInit_2str);
              set_cursor_position(2, 0);
              set_text_rus((char*)StringResources::TaskServiceMsgInit_3str);
              set_cursor_position(3, 0);
              set_text_rus((char*)StringResources::TaskServiceMsgInit_4str); 
              
              exitStateDisplayInited = 1;
            }
            
            if (action.buttonsEvent.event == BUTTON_SHORT_PRESSED_EVENT)
            {               
                if (action.buttonsEvent.id == BUT_ENTER)
                {                 
                    _stage = TANK_CLEANING_STAGE;
                    exitStateDisplayInited = 0;

                }
            }
            if (action.buttonsEvent.event == BUTTON_LONG_PRESSED_EVENT)
            {               
                if (action.buttonsEvent.id == BUT_CANCEL)
                {                 
                    _stage = CANCEL_SERVICE_MODE_STAGE;
                    exitStateDisplayInited = 0;
                }
            }
        }
        
        if (_stage == TANK_CLEANING_STAGE)
        {
            
            if (action.buttonsEvent.event == BUTTON_LONG_PRESSED_EVENT)
            {               
                if (action.buttonsEvent.id == BUT_CANCEL)
                {                 
                    _stage = CANCEL_SERVICE_MODE_STAGE;
                    exitStateDisplayInited = 0;
                    valveOn();
                }
            }
            
        }

    }
    
private:
        typedef enum
    {
        INIT_STAGE,
        TANK_CLEANING_STAGE,
        COMPLETED_TANK_CLEANING_STAGE,
        FLUSHING_STAGE,
        COMPLETED_FLUSHING_STAGE,

        CANCEL_SERVICE_MODE_STAGE
    }STAGE_t;
    
    STAGE_t _stage;
    int exitStateDisplayInited;
    
    static SubstanceServiceState * _instance;
    SubstanceServiceState()
    {
        _stage = INIT_STAGE;
        exitStateDisplayInited = 0;
    }
};



#endif