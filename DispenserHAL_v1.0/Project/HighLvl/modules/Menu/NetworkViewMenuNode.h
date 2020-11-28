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
        set_text_eng((char*)"                    ");
        set_cursor_position(1, 0);
        set_text_eng((char*)"                    ");
        set_cursor_position(2, 3);
        set_text_eng((char*)menuNodeName);
        set_cursor_position(3, 0);
        set_text_eng((char*)"                    ");
    }
    
    void Cancel()
    {
        _context->SetCurrentNode(_parent);
    }
    void Enter()
    {
         _context->SetCurrentNode(_child);
    }
    void Up()
    {
         _context->SetCurrentNode(_next);
    }
    void Down()
    {
         _context->SetCurrentNode(_prev);
    }
private:

};


#endif