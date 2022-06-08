#ifndef MENU_STATE_H_
#define MENU_STATE_H_

#include "DeviceStates/[Interfaces]/IDeviceState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"
#include "modules/Menu/Menu.h"

class MenuState: public IDeviceState
{
public:
    static MenuState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new MenuState();
        return _instance;
    }
    
    void SetMenu(Menu * menu)
    {
      _menu = menu;
    }
    
    void InitMenuState()
    {
        _menu->InitMenu();
    }


    void Handle(UserAction_t action)
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
        
        MENU_RESULT_t res = _menu->Handle(menuAction);
        if (res == MENU_EXIT_RESULT)
        {
            clear_display();
            _context->SetState(this->_statesFactory->GetState(WAITING_USER_ACTION_STATE));
        }
        _menu->Draw();
    }
    
private:
    static MenuState * _instance;
    MenuState()
    {
      _menu = NULL;
    }
    
    Menu * _menu;
};


#endif