#ifndef SUBSTANCE_SERVICE_TANK_CLEANING_STAGE_H_
#define SUBSTANCE_SERVICE_TANK_CLEANING_STAGE_H_

#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "Sensors/Sensors.h"
#include "Valve/Valve.h"
#include "Pump/PumpInit.h"

extern uint32_t global_timer;


class SubstanceServiceTankCleaningStage
{
public:
    SubstanceServiceTankCleaningStage(ISubstanceServiceState * substanceServiceState)
    {
        _substanceServiceState = substanceServiceState;
    }
    
    void Handle(UserAction_t action)
    {

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
    
    void HandleCleaningStage(UserAction_t action)
    {
        HandleCleaningStageView();
        if(global_timer - start_action_time >= 5000 && _sub_stage == WAITING_EMPTY_TANK)
        {
            if(getSensorState(LEVEL_SENSOR_TYPE) == ON_SENSOR_STATE) start_action_time = global_timer;
            else
            {
                _sub_stage = WAITING_FLUSHING_WITH_PUMP;
                start_action_time = global_timer;
                valveOn();
            }
        }
        else if(global_timer - start_action_time >= 5000 && _sub_stage == WAITING_FLUSHING_WITH_PUMP)
        {
            disablePump(getPumpDriver());
            start_action_time = global_timer;
            _sub_stage = WAITING_WATER_FLUSHING;
        }
        else if(global_timer - start_action_time >= 10000 && _sub_stage == WAITING_WATER_FLUSHING)
        {
            valveOff();
           
            _substanceServiceState->SwitchStage(COMPLETED_TANK_CLEANING_STAGE);
            _isInited = false;                   
        }
        
        HandleCleaningStateUserAction(action);
    }
    
    void HandleCleaningStageView()
    {
        if(!_isInited)
        {
          clear_display();
          set_cursor_position(0, 0);
          set_text_rus((char*)StringResources::TaskServiceMsgCleaning_1str);
          set_cursor_position(1, 1);
          set_text_rus((char*)StringResources::TaskServiceMsgCleaning_2str);
          
          _isInited = true;
          
          enablePump(getPumpDriver(), getA4988Conf());
          
          _sub_stage = WAITING_EMPTY_TANK;
          start_action_time = global_timer;
          pumpSubstance_ml(getPumpDriver(),6000.0, 250); 
        }
    }
    
    void HandleCleaningStateUserAction(UserAction_t action)
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