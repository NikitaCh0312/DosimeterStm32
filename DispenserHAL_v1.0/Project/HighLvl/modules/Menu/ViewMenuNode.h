#ifndef VIEW_MENU_NODE_H_
#define VIEW_MENU_NODE_H_

#include "stddef.h"
#include "string.h"

#include "LCD/LCD.h"

#include "IViewMenuNode.h"
#include "Menu.h"


class ViewMenuNode: public IViewMenuNode
{
public:
    ViewMenuNode(Menu * menuCtx,
                 IViewMenuNode * next,
                 IViewMenuNode * prev,
                 IViewMenuNode * parent,
                 IViewMenuNode * child,
                 char * name)
    {
        if (strlen(name) > 20)
            while(1);
        strcpy(menuNodeName, name);
        _next = next;
        _prev = prev;
        _parent = parent;
        _child = child;
        _context = menuCtx;
    }
    virtual ~ViewMenuNode(){}
    
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
    IViewMenuNode * _next;
    IViewMenuNode * _prev;
    IViewMenuNode * _parent;
    IViewMenuNode * _child;
    char menuNodeName[20];
    Menu * _context;
};


#endif