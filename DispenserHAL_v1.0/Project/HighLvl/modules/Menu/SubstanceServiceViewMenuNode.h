#ifndef SUBSTANCE_SERVICE_MENU_NODE_H_
#define SUBSTANCE_SERVICE_MENU_NODE_H_

#include "stddef.h"
#include "string.h"

#include "DeviceStates/Dosimeter.hpp"
#include "DeviceStates/States/SubstanceServiceState.hpp"

#include "LCD/LCD.h"

#include "Resources/StringResources.h"

#include "ViewMenuNode.h"
#include "Menu.h"
#include "modules/Configuration.h"


class SubstanceServiceViewMenuNode: public ViewMenuNode
{
public:
    SubstanceServiceViewMenuNode(Menu * menuCtx,
                         char * name) : ViewMenuNode(menuCtx, name)
    {

    }
    virtual ~SubstanceServiceViewMenuNode(){}
    
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
        
        _context->SetNodeAction(MENU_NODE_SWITCH_TO_SUBSTANCE_SERVICE_STATE);
        //CRUTCH SWITCH STATE SHOULD NOT BE HERE
        //Dosimeter * dosimeter = Dosimeter::GetInstance();
        //SubstanceServiceState * substanceServiceState = SubstanceServiceState::GetInstance();
        //dosimeter->SetState((IDeviceState *)substanceServiceState);
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