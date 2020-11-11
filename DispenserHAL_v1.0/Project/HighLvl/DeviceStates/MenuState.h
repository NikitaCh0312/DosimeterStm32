#ifndef MENU_STATE_H_
#define MENU_STATE_H_

#include "IDeviceState.h"


class MenuState: public IDeviceState
{
public:
    static MenuState * GetInstance()
    {
        if (_instance == NULL)
            _instance = new MenuState();
        return _instance;
    }
    void Handle()
    {
        
    }
private:
    static MenuState * _instance;
    MenuState(){}
};


#endif