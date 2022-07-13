#ifndef MANUAL_DOSATION_STATE_STATE_H_
#define MANUAL_DOSATION_STATE_STATE_H_

#include "string.h"
#include "stdio.h"

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"

#include "LCD/LCD.h"
#include "Resources/StringResources.h"

extern uint32_t global_timer;

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
        DrawBaseView();
        
        switch(_stage)
        {
            case SELECTING_VOLUME_STAGE:
              HandleSelectingVolumeStage(action);
              break;
            case SELECTING_CONCENTRATION_STAGE:
              HandleSelectingConcentrationStage(action);
              break;
              
            default:
              break;
        }
    }
    
private:
    static ManualDosationState * _instance;
    ManualDosationState()
    {
        _stage = SELECTING_VOLUME_STAGE;
        _isInited = false;
        _selectedConcentration = 0;
        _selectedVolume = 0;
    }
    
    typedef enum
    {
        SELECTING_VOLUME_STAGE,
        SELECTING_CONCENTRATION_STAGE,
        READY_STAGE
    }STAGE_t;
    STAGE_t _stage;
    
    bool _isInited;
    int _selectedVolume;
    int _selectedConcentration;
    
    void DrawBaseView()
    {
        if (_isInited)
            return;
        
        _isInited = true;
        clear_display();
        set_cursor_position(0, 0);
        set_text_rus((char*)StringResources::ManualDosationMode);
        set_cursor_position(1, 0);
        set_text_rus((char*)StringResources::Select);
    }
    
    void HandleSelectingVolumeStage(UserAction_t action)
    {
        set_cursor_position(1, 10);
        set_text_rus((char*)StringResources::Volume);
        
        if (action.buttonsEvent.event != BUTTON_SHORT_PRESSED_EVENT)
            return;
        switch(action.buttonsEvent.id)
        {
            case BUT_UP:
            {
                ++_selectedVolume;
                break;
            }
            case BUT_DOWN:
            {
                --_selectedVolume;
            }
            case BUT_ENTER:
            {
                _stage = SELECTING_CONCENTRATION_STAGE;
            }
            case BUT_CANCEL:
            {

            }
        }
    }
    
    void HandleSelectingConcentrationStage(UserAction_t action)
    {
        set_cursor_position(1, 10);
        set_text_rus((char*)StringResources::Concentration);
        
        if (action.buttonsEvent.event != BUTTON_SHORT_PRESSED_EVENT)
            return;
        switch(action.buttonsEvent.id)
        {
            case BUT_UP:
            {
                ++_selectedConcentration;
                break;
            }
            case BUT_DOWN:
            {
                --_selectedConcentration;
            }
            case BUT_ENTER:
            {
                //_stage = SELECTING_CONCENTRATION_STAGE;
            }
            case BUT_CANCEL:
            {

            }
        }
    }
};



#endif