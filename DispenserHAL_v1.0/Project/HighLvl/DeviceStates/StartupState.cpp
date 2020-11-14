#include "StartupState.h"
#include "WaitingUserActionState.h"
#include "Dosimeter.h"


void StartupState::Handle(UserAction_t action)
{
    //check device state
    
    //set to WaitingUserActionState
    _context->SetState( (IDeviceState*)WaitingUserActionState::GetInstance());
}