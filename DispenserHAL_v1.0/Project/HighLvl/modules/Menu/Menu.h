#ifndef MENU_H_
#define MENU_H_

#include "IViewMenuNode.h"

typedef enum
{
    MENU_NONE_ACTION,
    MENU_ENTER_ACTION,
    MENU_BACK_ACTION,
    MENU_NEXT_ACTION,
    MENU_PREV_ACTION,
}MenuAction_t;

class Menu
{
public:
    Menu(IViewMenuNode * rootNode)
    {
        _currentMenuNode = rootNode;
    }
    virtual ~Menu()
    {
        
    }
    
    void InitMenu()
    {
        
    }
    
    void SetCurrentNode (IViewMenuNode * node)
    {
        _currentMenuNode = node;
    }
    void Handle(MenuAction_t action)
    {
        switch(action)
        {
            case MENU_ENTER_ACTION:
                _currentMenuNode->Enter();
                break;
            case MENU_BACK_ACTION:
                _currentMenuNode->Down();
                break;
            case MENU_NEXT_ACTION:
                _currentMenuNode->Up();
                break;
            case MENU_PREV_ACTION:
                _currentMenuNode->Cancel();
                break;
            default:
                break;
        }

        if (_currentMenuNode == NULL)
        //выход из меню
            ;
    }
    
    void Draw()
    {
        if (_currentMenuNode != NULL)
            _currentMenuNode->Draw();        
    }
    
private:
    IViewMenuNode * _currentMenuNode;
};

#endif