#ifndef MANUAL_DOSATION_STATE_STATE_H_
#define MANUAL_DOSATION_STATE_STATE_H_

#include "string.h"
#include "stdio.h"

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"

#include "DeviceStates/States/TaskExecutionState.hpp"

#include "LCD/LCD.h"
#include "Resources/StringResources.h"

extern uint32_t global_timer;

uint32_t fromManualStateCruth = 0;

class ManualDosationState: public IDeviceState
{
public:
    static ManualDosationState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new ManualDosationState();
        return _instance;
    }
    
    void Handle(UserAction_t action)
    {
        switch(_stage)
        {
            case SELECTING_VOLUME_STAGE:
              HandleSelectingVolumeStage(action);
              break;
            case SELECTING_CONCENTRATION_STAGE:
              HandleSelectingConcentrationStage(action);
              break;
            case READY_STAGE:
              HandleReadyStage(action);
            default:
              break;
        }
    }
    
private:
    static ManualDosationState * _instance;
    ManualDosationState()
    {
        _stage = SELECTING_VOLUME_STAGE;
        _isBaseViewInited = false;
        _isSelectionVolumeStageInited = false;
        _isSelectionConcentrationStageInited = false;
        _isReadyStageInited = false;
        _selectedConcentration = 0;
        _selectedVolume = 0;
        _maxVolumes = sizeof(_availableVolumes);
        _maxConcentrations = sizeof (_availableConcentrations);
    }
    
    typedef enum
    {
        SELECTING_VOLUME_STAGE,
        SELECTING_CONCENTRATION_STAGE,
        READY_STAGE
    }STAGE_t;
    STAGE_t _stage;

    int _selectedVolume;
    uint8_t _maxVolumes;
    float _availableVolumes[20] = {1.0f, 1.25f, 1.5, 1.75f, 2.0f, 2.5f, 3.0f, 3.5f, 4.0f, 4.5f, 5.0f, 7.5f, 10.0f, 12.5f, 15.0f, 20.0f, 25.0f, 30.0f, 40.0f, 50.0f};
    
    int _selectedConcentration;
    uint8_t _maxConcentrations;
    float _availableConcentrations[20] = {0.1f, 0.15f, 0.2f, 0.25f, 0.3f, 0.4f, 0.5f, 0.75f, 1.0f, 1.25f, 1.5f, 1.75f, 2.0f, 2.25f, 2.5f, 3.0f, 3.5f, 4.0f, 4.5f, 5.0f};
    
    bool _isBaseViewInited;
    bool _isSelectionVolumeStageInited;
    bool _isSelectionConcentrationStageInited;
    bool _isReadyStageInited;
    
    void DrawBaseView()
    {
        if (!_isBaseViewInited)
        {
            clear_display();
            set_cursor_position(0, 0);
            set_text_rus((char*)StringResources::ManualDosationMode);
            set_cursor_position(1, 0);
            set_text_rus((char*)StringResources::Select);
            _isBaseViewInited = true;
            _isSelectionVolumeStageInited = false;
            _isSelectionConcentrationStageInited = false;
            _isReadyStageInited = false;
        }
    }
    
    void HandleSelectingVolumeStage(UserAction_t action)
    {
        DrawBaseView();
        if (!_isSelectionVolumeStageInited)
        {
            set_cursor_position(1, 10);
            set_text_eng((char*)"         ");
            set_cursor_position(1, 10);
            set_text_rus((char*)StringResources::Volume);
            set_cursor_position(1, 15);
            set_text_rus((char*)"л");
            _isSelectionVolumeStageInited = true;
            _isSelectionConcentrationStageInited = false;
            _isReadyStageInited = false;
        }

        char viewValue[6];
        sprintf(viewValue , "%.2f", _availableVolumes[_selectedVolume]);
        set_cursor_position(2, 8);
        set_text_eng(viewValue);
        
        if (action.buttonsEvent.event != BUTTON_SHORT_PRESSED_EVENT)
            return;
        switch(action.buttonsEvent.id)
        {
            case BUT_UP:
            {
                if (_selectedVolume < 19)
                    _selectedVolume++;
                break;
            }
            case BUT_DOWN:
            {
                if (_selectedVolume > 0)
                    _selectedVolume--;
                break;
            }
            case BUT_ENTER:
            {
                _stage = SELECTING_CONCENTRATION_STAGE;
                break;
            }
            case BUT_CANCEL:
            {
                IDeviceState* state = this->_statesFactory->GetState(WAITING_USER_ACTION_STATE);
                _context->SetState(state);
                SetInitialState();
                break;
            }
        }
    }
    
    void HandleSelectingConcentrationStage(UserAction_t action)
    {
        DrawBaseView();
        if (!_isSelectionConcentrationStageInited)
        {
            set_cursor_position(1, 10);
            set_text_rus((char*)StringResources::Concentration);
            set_cursor_position(1, 16);
            set_text_eng((char*)",%");
            
            _isSelectionConcentrationStageInited = true;
            _isReadyStageInited = false;
            _isSelectionVolumeStageInited = false;
        }

        char viewValue[6];
        sprintf(viewValue , "%.2f", _availableConcentrations[_selectedConcentration]);
        set_cursor_position(2, 8);
        set_text_eng(viewValue);
        
        if (action.buttonsEvent.event != BUTTON_SHORT_PRESSED_EVENT)
            return;
        switch(action.buttonsEvent.id)
        {
            case BUT_UP:
            {
                if (_selectedConcentration < 19)
                    _selectedConcentration++;
                break;
            }
            case BUT_DOWN:
            {
                if (_selectedConcentration > 0)
                    _selectedConcentration--;
                break;
            }
            case BUT_ENTER:
            {
                _stage = READY_STAGE;
                break;
            }
            case BUT_CANCEL:
            {
                _stage = SELECTING_VOLUME_STAGE;
                break;
            }
        }
    }
    
    void HandleReadyStage(UserAction_t action)
    {
        char viewValue[6];
     
        if (!_isReadyStageInited)
        {
            clear_display();
          
            set_cursor_position(0, 2);
            set_text_rus((char*)StringResources::SelectedParams);
            
            set_cursor_position(1, 3);
            set_text_rus((char*)StringResources::Volume);
            sprintf(viewValue , "%.2f", _availableVolumes[_selectedVolume]);
            set_cursor_position(1, 11);
            set_text_eng(viewValue);
            
            set_cursor_position(2, 3);
            set_text_rus((char*)StringResources::Concentration);
            sprintf(viewValue , "%.2f", _availableConcentrations[_selectedConcentration]);
            set_cursor_position(2, 11);
            set_text_eng(viewValue);
            
            set_cursor_position(3, 2);
            set_text_rus((char*)StringResources::PressEnter);
            
            _isReadyStageInited = true;
            _isSelectionConcentrationStageInited = false;
            _isSelectionVolumeStageInited = false;
            _isBaseViewInited = false;
        }

        if (action.buttonsEvent.event != BUTTON_SHORT_PRESSED_EVENT)
            return;
        switch(action.buttonsEvent.id)
        {
            case BUT_UP:
            {
                break;
            }
            case BUT_DOWN:
            {
                break;
            }
            case BUT_ENTER:
            {
                fromManualStateCruth = 1;
                Task task;
                task.Volume = _availableVolumes[_selectedVolume];
                task.Concentration = _availableConcentrations[_selectedConcentration];
                TaskExecutionState* executionState = (TaskExecutionState*)this->_statesFactory->GetState(TASK_EXECUTION_STATE);
                executionState->InitExecutionState(task);
                _context->SetState(executionState);
                
                SetInitialState();
                break;
            }
            case BUT_CANCEL:
            {
                _stage = SELECTING_CONCENTRATION_STAGE;
                break;
            }
        }
    }
    
    void SetInitialState()
    {
        _isBaseViewInited = false;
        _isSelectionVolumeStageInited = false;
        _isSelectionConcentrationStageInited = false;
        _isReadyStageInited = false;
        
        _stage = SELECTING_VOLUME_STAGE;
    }
};



#endif