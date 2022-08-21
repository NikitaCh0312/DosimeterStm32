#ifndef SUBSTANCE_SERVICE_TANK_FILL_STAGE_H_
#define SUBSTANCE_SERVICE_TANK_FILL_STAGE_H_

#include "RTOS/RTOSManager.h"
#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "Sensors/Sensors.h"
#include "Valve/Valve.h"
#include "Pump/PumpInit.h"

extern uint32_t global_timer;


class SubstanceServiceTankFillStage
{
public:
    SubstanceServiceTankFillStage(ISubstanceServiceState * substanceServiceState)
    {
        _substanceServiceState = substanceServiceState;
        _isInited = false;
    }
    
    void Handle(UserAction_t action)
    {
        HandleTankFillStageView();
        
        if(global_timer - start_action_time >= 5000 && _sub_stage == WAITING_EMPTY_TANK)
        {
            _sub_stage = WAITING_FLUSHING_WITH_PUMP;
            start_action_time = global_timer;
            valveOn();
        }
        else if(global_timer - start_action_time >= 5000 && _sub_stage == WAITING_FLUSHING_WITH_PUMP)
        {
            disablePump(getPumpDriver());
            start_action_time = global_timer;
            _sub_stage = WAITING_WATER_FLUSHING;
        }
        else if(global_timer - start_action_time >= 5000 && _sub_stage == WAITING_WATER_FLUSHING)
        {
            valveOff();
            
            clear_display();
            set_cursor_position(1, 1);
            set_text_rus((char*)StringResources::TaskServiceMsgInfo_6_1str);
            set_cursor_position(2, 1);
            set_text_rus((char*)StringResources::TaskServiceMsgInfo_6_2str);
            
            RTOS::Thread::delay_thread(3500);
           
            _substanceServiceState->SwitchStage(SUBSTANCE_SELECTION_STAGE);
            _isInited = false;                   
        }
        
        HandleTankFillStateUserAction(action);

    }
    
private:
    
    typedef enum
    {
        WAITING_EMPTY_TANK,
        WAITING_FLUSHING_WITH_PUMP,
        WAITING_WATER_FLUSHING
    }SUB_STAGE_t;
    
    SUB_STAGE_t _sub_stage;
  
    bool _isInited;
    uint32_t start_action_time = 0;
    
    ISubstanceServiceState * _substanceServiceState;
    
    void HandleTankFillStageView()
    {
        if(!_isInited)
        {
          clear_display();
          set_cursor_position(0, 3);
          set_text_rus((char*)StringResources::TaskServiceMsgInfo_5_1str);
          set_cursor_position(1, 4);
          set_text_rus((char*)StringResources::TaskServiceMsgInfo_5_2str);
          set_cursor_position(2, 4);
          set_text_rus((char*)StringResources::TaskServiceMsgInfo_5_3str);
          
          _isInited = true;
          
          enablePump(getPumpDriver(), getA4988Conf());
          pumpSubstance_ml(getPumpDriver(),6000.0, 250); 
          
          _sub_stage = WAITING_EMPTY_TANK;
          start_action_time = global_timer;
        }
    }
    
    void HandleTankFillStateUserAction(UserAction_t action)
    {
        if (action.buttonsEvent.event == BUTTON_LONG_PRESSED_EVENT)
        {               
            if (action.buttonsEvent.id == BUT_CANCEL)
            {        
                _substanceServiceState->SwitchStage(CANCEL_SERVICE_MODE_STAGE);
                _isInited = false;
                valveOn();
            }
        }
    }
    
    
};

#endif