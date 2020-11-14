#include "MenuState.h"
#include "WaitingUserActionState.h"
#include "Dosimeter.h"

extern Menu * menu;
void MenuState::InitMenuState()
{
    menu->InitMenu();
}


void MenuState::Handle(UserAction_t action)
{
    MENU_ACTION_t menuAction;
    if (action.buttonsEvent.event == BUTTON_SHORT_PRESSED_EVENT)
    {
        if ( action.buttonsEvent.id == BUT_UP)
            menuAction = MENU_NEXT_ACTION;
        else if ( action.buttonsEvent.id == BUT_DOWN)
            menuAction = MENU_PREV_ACTION;
        else if ( action.buttonsEvent.id == BUT_ENTER)
            menuAction = MENU_ENTER_ACTION;
        else if ( action.buttonsEvent.id == BUT_CANCEL)
            menuAction = MENU_BACK_ACTION;
    }
    else
        menuAction = MENU_NONE_ACTION;
    
    MENU_RESULT_t res = menu->Handle(menuAction);
    if (res == MENU_EXIT_RESULT)
        _context->SetState( (IDeviceState*)WaitingUserActionState::GetInstance());
    menu->Draw();
}