#ifndef MANUAL_DOSATION_MENU_NODE_H_
#define MANUAL_DOSATION_MENU_NODE_H_

#include "stddef.h"
#include "string.h"

#include "DeviceStates/Dosimeter.hpp"
#include "DeviceStates/States/ManualDosationState.hpp"

#include "LCD/LCD.h"

#include "Resources/StringResources.h"

#include "ViewMenuNode.h"
#include "Menu.h"
#include "modules/Configuration.h"


class ManualDosationViewMenuNode: public ViewMenuNode
{
public:
    ManualDosationViewMenuNode(Menu * menuCtx,
                         char * name) : ViewMenuNode(menuCtx, name)
    {

    }
    virtual ~ManualDosationViewMenuNode(){}
    
    void Draw()
    {
        if (!_isInited)
        {
            clear_display();
            set_cursor_position(0, 2);
            set_text_rus((char*)menuNodeName);
            
            set_cursor_position(2, 3);
            set_text_rus((char*)StringResources::PressEnter);
            
            set_cursor_position(3, 4);
            set_text_rus((char*)StringResources::ToStart);
            
            _isInited = true;
        }
    }
        
    void Cancel()
    {
        _context->SetCurrentNode(_parent);
        _isInited = false;
        
        //CRUTCH SWITCH STATE SHOULD NOT BE HERE
        Dosimeter * dosimeter = Dosimeter::GetInstance();
        ManualDosationState * manualDosationState = ManualDosationState::GetInstance();
        dosimeter->SetState((IDeviceState *)manualDosationState);
    }
    
    void Enter()
    {

        Cancel();
        return;
    }
    
    void Up()
    {

    }
    
    void Down()
    {
    
    }
    
private:
};


#endif