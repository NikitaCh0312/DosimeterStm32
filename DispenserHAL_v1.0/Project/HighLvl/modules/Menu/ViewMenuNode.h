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
                 char * name)
    {
        if (strlen(name) > 20)
            while(1);
        strcpy(menuNodeName, name);
        _context = menuCtx;
    }
    virtual ~ViewMenuNode(){}
    
    void ConfigNode(IViewMenuNode * next,
                    IViewMenuNode * prev,
                    IViewMenuNode * parent,
                    IViewMenuNode * child)
    {
        _next = next;
        _prev = prev;
        _parent = parent;
        _child = child;
        _isInited = false;
    }
    
    //отрисовать меню
    virtual void Draw()
    {
        if (_isInited)
            return;

        clear_display();
        set_cursor_position(0, 0);
        set_text_eng((char*)"MENU                ");
        set_cursor_position(1, 0);
        set_text_eng((char*)"--------------------");
        set_cursor_position(2, 0);
        set_text_eng((char*)menuNodeName);
        set_cursor_position(3, 0);
        set_text_eng((char*)"                    ");
        _isInited = true;
    }
    
    virtual void Cancel()
    {
        _isInited = false;
        _context->SetCurrentNode(_parent);
    }
    
    virtual void Enter()
    {
        if (_child != NULL)
        {
            _isInited = false;
            _context->SetCurrentNode(_child);
        }
    }
    
    virtual void Up()
    {
        if (_next != NULL)
        {
            _isInited = false;
            _context->SetCurrentNode(_next);
        }
    }
    
    virtual void Down()
    {
        if (_prev != NULL)
        {
            _isInited = false;
            _context->SetCurrentNode(_prev);
        }
    }
    
protected:
    IViewMenuNode * _next;
    IViewMenuNode * _prev;
    IViewMenuNode * _parent;
    IViewMenuNode * _child;
    char menuNodeName[21];
    Menu * _context;
    
    bool _isInited;
};


#endif