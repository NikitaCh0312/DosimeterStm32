#ifndef ISUBSTANCE_SERVICE_STATE_H_
#define ISUBSTANCE_SERVICE_STATE_H_


typedef enum
{
    INIT_STAGE,
    TANK_CLEANING_STAGE,
    COMPLETED_TANK_CLEANING_STAGE,
    FLUSHING_STAGE,
    COMPLETED_FLUSHING_STAGE,

    CANCEL_SERVICE_MODE_STAGE
}SUBSTANCE_SERVICE_STAGE_t;
    
class ISubstanceServiceState
{
public:
    virtual void SwitchStage(SUBSTANCE_SERVICE_STAGE_t stage) = 0;
    virtual void ExitState() = 0;
};



#endif