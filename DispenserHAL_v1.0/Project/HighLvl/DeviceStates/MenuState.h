#ifndef MENU_STATE_H_
#define MENU_STATE_H_

#include "IDeviceState.h"
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
    
    void InitMenuState();
    void Handle(UserAction_t action);
    
private:
    static MenuState * _instance;
    MenuState(){}
};


#endif