#ifndef NETWORK_VIEW_MENU_NODE_H_
#define NETWORK_VIEW_MENU_NODE_H_

#include "stddef.h"
#include "string.h"

#include "LCD/LCD.h"

#include "ViewMenuNode.h"
#include "Menu.h"



class NetworkViewMenuNode: public ViewMenuNode
{
public:
    NetworkViewMenuNode(Menu * menuCtx,
                        char * name): ViewMenuNode(menuCtx, name)
    {

    }
    virtual ~NetworkViewMenuNode(){}
    
    //отрисовать меню
    void Draw()
    {
        set_cursor_position(0, 0);
        set_text_eng((char*)"NETWORK SETTINGS    ");
        set_cursor_position(1, 0);
        set_text_eng((char*)"====================");
        set_cursor_position(2, 0);
        set_text_eng((char*)"IP: 192.168.0.10    ");
        set_cursor_position(3, 0);
        set_text_eng((char*)"MASK: 255.255.255.0 ");
    }
    
    void Cancel()
    {
        _context->SetCurrentNode(_parent);
    }
    void Enter()
    {
         
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