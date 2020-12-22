#ifndef TIMEDATE_VIEW_MENU_NODE_H_
#define TIMEDATE_VIEW_MENU_NODE_H_

#include "stddef.h"
#include "string.h"

#include "LCD/LCD.h"

#include "ViewMenuNode.h"
#include "Menu.h"



class TimeDateViewMenuNode: public ViewMenuNode
{
public:
    TimeDateViewMenuNode(Menu * menuCtx,
                         char * name) : ViewMenuNode(menuCtx, name)
    {

    }
    virtual ~TimeDateViewMenuNode(){}
    
    //отрисовать меню
    void Draw()
    {
        set_cursor_position(0, 0);
        set_text_eng((char*)"TIME DATE SETTINGS  ");
        set_cursor_position(1, 0);
        set_text_eng((char*)"====================");
        set_cursor_position(2, 0);
        set_text_eng((char*)"TIME: 22:07         ");
        set_cursor_position(3, 0);
        set_text_eng((char*)"DATE: 22.12.2020    ");
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