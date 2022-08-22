#ifndef SUBSTANCE_SERVICE_STATE_H_
#define SUBSTANCE_SERVICE_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"
#include "DeviceStates/States/SubstanceServiceState/ISubstanceServiceState.hpp"

#include "DeviceStates/States/SubstanceServiceState/SubstanceServiceInitStage.hpp"
#include "DeviceStates/States/SubstanceServiceState/SubstanceServiceTankCleaningStage.hpp"
#include "DeviceStates/States/SubstanceServiceState/SubstanceServiceTankCompletedStage.hpp"
#include "DeviceStates/States/SubstanceServiceState/SubstanceServiceFlushingStage.hpp"
#include "DeviceStates/States/SubstanceServiceState/SubstanceServiceFlushCompletedStage.hpp"
#include "DeviceStates/States/SubstanceServiceState/SubstanceServiceCancelStage.hpp"

#include "DeviceStates/States/SubstanceServiceState/SubstanceServiceTankInstallStage.hpp"
#include "DeviceStates/States/SubstanceServiceState/SubstanceServiceTankFillStage.hpp"
#include "DeviceStates/States/SubstanceServiceState/SubstanceServiceSubstanceSelectionStage.hpp"

class SubstanceServiceState: public IDeviceState, ISubstanceServiceState
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
                _substanceServiceInitStage->Handle(action);
                break;
            }
            case TANK_CLEANING_STAGE:
            {
                _substanceServiceTankCleaningStage->Handle(action);
                break;
            }
            case COMPLETED_TANK_CLEANING_STAGE:
            {
                _substanceServiceTankCompletedStage->Handle(action);
                break;
            }
            case FLUSHING_STAGE:
            {
                _substanceServiceFlushingStage->Handle(action);
                break;
            }
            case COMPLETED_FLUSHING_STAGE:
            {
                _substanceServiceFlushCompletedStage->Handle(action);
                break;
            }
            case CANCEL_SERVICE_MODE_STAGE:
            {
                _substanceServiceCancelStage->Handle(action);
                break;
            }
            case TANK_INSTALL_STAGE:
            {
                _substanceServiceTankInstallStage->Handle(action);
                break;
            }
            case TANK_FILL_STAGE:
            {
                _substanceServiceTankFillStage->Handle(action);
                break;
            }
            case SUBSTANCE_SELECTION_STAGE:
            {
                _substanceServiceSubstanceSelectionStage->Handle(action);
                break;
            }
            default:
              break;
        }
    }
    
    void SwitchStage(SUBSTANCE_SERVICE_STAGE_t stage)
    {
        _stage = stage;
    }
    
    void ExitState()
    {
        _stage = INIT_STAGE;
        _context->SetState(this->_statesFactory->GetState(WAITING_USER_ACTION_STATE));
    }
private:
  
    SUBSTANCE_SERVICE_STAGE_t _stage;

    SubstanceServiceInitStage * _substanceServiceInitStage;
    SubstanceServiceTankCleaningStage * _substanceServiceTankCleaningStage;
    SubstanceServiceTankCompletedStage * _substanceServiceTankCompletedStage;
    SubstanceServiceFlushingStage * _substanceServiceFlushingStage;
    SubstanceServiceFlushCompletedStage * _substanceServiceFlushCompletedStage;
    SubstanceServiceCancelStage * _substanceServiceCancelStage;
    
    SubstanceServiceTankInstallStage * _substanceServiceTankInstallStage;
    SubstanceServiceTankFillStage * _substanceServiceTankFillStage;
    
    SubstanceServiceSubstanceSelectionStage * _substanceServiceSubstanceSelectionStage;
        
    
    
    static SubstanceServiceState * _instance;
    SubstanceServiceState()
    {
        _stage = SUBSTANCE_SELECTION_STAGE;//INIT_STAGE;
      
        _substanceServiceInitStage = new SubstanceServiceInitStage(this);
        _substanceServiceTankCleaningStage = new SubstanceServiceTankCleaningStage(this);
        _substanceServiceTankCompletedStage = new SubstanceServiceTankCompletedStage(this);
        _substanceServiceFlushingStage = new SubstanceServiceFlushingStage(this);
        _substanceServiceFlushCompletedStage = new SubstanceServiceFlushCompletedStage(this);
        _substanceServiceCancelStage = new SubstanceServiceCancelStage(this);
        
        _substanceServiceTankInstallStage = new SubstanceServiceTankInstallStage(this);
        _substanceServiceTankFillStage = new SubstanceServiceTankFillStage(this);
        _substanceServiceSubstanceSelectionStage = new SubstanceServiceSubstanceSelectionStage(this);
    }
};



#endif