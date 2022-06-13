#ifndef TASK_EXECUTION_STATE_H_
#define TASK_EXECUTION_STATE_H_

#define CNT_CHECK_PULSE 4
#define TIMEOUT_CHECK_PULSE_MS 1000

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"

#include "modules/Card.h"

#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "string.h"
#include "stdio.h"
#include "Sensors/Sensors.h"
#include "Valve/Valve.h"
#include "Pump/PumpInit.h"

extern uint32_t global_timer;

class TaskExecutionState: public IDeviceState
{
public:
    static TaskExecutionState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new TaskExecutionState();
        return _instance;
    }
   
    void InitExecutionState(Task task)
    {
        _task = task;
    }
   
    void Handle(UserAction_t action)
    {
        switch (_stage)
        {
            case INITIALIZATION_STAGE:
            {
                clear_display();
                set_cursor_position(0, 5);
                set_text_rus((char*)StringResources::TaskExecution_1str);
                set_cursor_position(1, 6);
                set_text_rus((char*)StringResources::TaskExecution_2str);
                set_cursor_position(2, 9);
                set_text_eng("...");
                
                flow_sensor_set_default_koef();
                
                _stage = CHECK_WATER_PREASURE_STAGE;
            
                break;
            }
            case CHECK_WATER_PREASURE_STAGE:
            {
              if(startTime == 0) 
              {
                  startTime = global_timer;
                  flow_sensor_start_measure(DMRV_SENSOR_TYPE);
                  valveOn();
                  enablePump(getPumpDriver(), getA4988Conf());
              }
              else
              {
                  if((global_timer - startTime) > TIMEOUT_CHECK_PULSE_MS)
                  {                    
                     _stage = ERR_WATER_PREASURE_STAGE;
                  }
                  else if(flow_sensor_get_cnt(DMRV_SENSOR_TYPE) >= CNT_CHECK_PULSE)
                  {
                       startTime = global_timer;
                       prev_flow_sensor_cnt = flow_sensor_get_cnt(DMRV_SENSOR_TYPE);
                       
                       _substanceVolumeLiters =  (_task.Volume / 100.0) * _task.Concentration;
                       _waterVolumeLiters =  _task.Volume - _substanceVolumeLiters;          

                      _stage = EXEUTING_TASK_STAGE;
                  }
                  
              }
           
                break;
            }
            case EXEUTING_TASK_STAGE:
            {
               
                  if((global_timer - startTime) > TIMEOUT_CHECK_PULSE_MS)
                  {                    
                     _stage = ERR_WATER_PREASURE_STAGE;
                  }
                  else if(flow_sensor_get_cnt(DMRV_SENSOR_TYPE) - prev_flow_sensor_cnt >= CNT_CHECK_PULSE)
                  {
                      if(flow_sensor_get_volume_liters(DMRV_SENSOR_TYPE) <= _waterVolumeLiters) //task on the water volume 
                      {
                        
                        startTime = global_timer;
                        prev_flow_sensor_cnt = flow_sensor_get_cnt(DMRV_SENSOR_TYPE);
                        
                        static uint8_t en_flag = 1;
                        
                        if(en_flag)
                        {
                            pumpSubstance_ml(getPumpDriver(), (1000.0*_substanceVolumeLiters));  //task on the substance volume
                            
                            en_flag = 0;   
                        };
                        
                      }
                      else
                      {                         
                          _stage = COMPLETED_STAGE;
                      }                          
                  }
                          
                break;
            }
            case ERR_WATER_PREASURE_STAGE:
            {    
               startTime = 0;
               flow_sensor_stop_measure(DMRV_SENSOR_TYPE);
               valveOff(); 
               disablePump(getPumpDriver());
               break;
            }
            case COMPLETED_STAGE:
            {  
                startTime = 0;
                flow_sensor_stop_measure(DMRV_SENSOR_TYPE);
                valveOff();
                while((*getPumpDriver()).getStatus() == PROGRESS_WORK) {};
                disablePump(getPumpDriver());
                
                break;
            }

            default: break;
        }
    
        if (_stage == COMPLETED_STAGE)
        {
            if (!exitStateDisplayInited)
            {
                clear_display();
                exitStateDisplayInited = 1;
                set_cursor_position(1, 6);
                set_text_rus((char*)StringResources::TaskExecuted_1str);
                set_cursor_position(2, 5);
                set_text_rus((char*)StringResources::TaskExecuted_2str);
            }


            if (action.buttonsEvent.event == BUTTON_SHORT_PRESSED_EVENT)
            {
                if (action.buttonsEvent.id == BUT_CANCEL)
                {
                    _stage = INITIALIZATION_STAGE;
                    exitStateDisplayInited = 0;
                    startTime = 0;
                    prev_flow_sensor_cnt = 0;
                    _waterVolumeLiters = 0;
                    _substanceVolumeLiters = 0;
                    _context->SetState(this->_statesFactory->GetState(TASK_SELECTION_STATE));
                }
            }
        }
        if (_stage == ERR_WATER_PREASURE_STAGE)
        {
            if (!exitStateDisplayInited)
            {
                clear_display();
                exitStateDisplayInited = 1;
                set_cursor_position(1, 6);
                set_text_rus((char*)StringResources::TaskErrorExecuted_1str);
                set_cursor_position(2, 6);
                set_text_rus((char*)StringResources::TaskErrorExecuted_2str);
            }

            if (action.buttonsEvent.event == BUTTON_SHORT_PRESSED_EVENT)
            {
                if (action.buttonsEvent.id == BUT_CANCEL)
                {
                    _stage = INITIALIZATION_STAGE;
                    exitStateDisplayInited = 0;
                    startTime = 0;
                    prev_flow_sensor_cnt = 0;
                    _waterVolumeLiters = 0;
                    _substanceVolumeLiters = 0;
                    _context->SetState(this->_statesFactory->GetState(TASK_SELECTION_STATE));
                }
            }
        }
    }
private:
    typedef enum
    {
        INITIALIZATION_STAGE,
        CHECK_WATER_PREASURE_STAGE,
        EXEUTING_TASK_STAGE,
        ERR_WATER_PREASURE_STAGE,
        COMPLETED_STAGE
    }STAGE_t;
    
    IDeviceStatesFactory * factory;
    
    static TaskExecutionState * _instance;
    TaskExecutionState()
    {
        _stage = INITIALIZATION_STAGE;
        exitStateDisplayInited = 0;
        startTime = 0;
        prev_flow_sensor_cnt = 0;
        _waterVolumeLiters = 0;
        _substanceVolumeLiters = 0;
    }
    STAGE_t _stage;
    
    Task _task;
    
    uint32_t getSetsPumpCnt();
    uint32_t getSetsFlowSensorCnt();
    
    void calculateSets(Task tmp_task);
    uint16_t    getSetsPumpFreq();
    float       getSetsFlowSensorVolume();
    float       getSetsPumpVolume();

    int exitStateDisplayInited;
    
    uint32_t startTime = 0;
    uint32_t prev_flow_sensor_cnt = 0;
    float _waterVolumeLiters = 0;
    float _substanceVolumeLiters = 0;
};



#endif