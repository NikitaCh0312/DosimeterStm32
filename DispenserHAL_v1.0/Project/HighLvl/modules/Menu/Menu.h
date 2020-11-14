#ifndef MENU_H_
#define MENU_H_

#include "IViewMenuNode.h"

typedef enum
{
    MENU_OK_RESULT,
    MENU_EXIT_RESULT,
    
}MENU_RESULT_t;


typedef enum
{
    MENU_NONE_ACTION,
    MENU_ENTER_ACTION,
    MENU_BACK_ACTION,
    MENU_NEXT_ACTION,
    MENU_PREV_ACTION,
}MENU_ACTION_t;

class Menu
{
public:
    Menu()
    {

    }
    virtual ~Menu()
    {
        
    }
    void SetRootNode(IViewMenuNode * rootNode)
    {
        _currentMenuNode = rootNode;
        _rootNode = rootNode;
    }
    void InitMenu()
    {
        _currentMenuNode = _rootNode;
    }
    
    void SetCurrentNode (IViewMenuNode * node)
    {
        _currentMenuNode = node;
    }
    MENU_RESULT_t Handle(MENU_ACTION_t action)
    {
        MENU_RESULT_t res = MENU_OK_RESULT;
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
            res = MENU_EXIT_RESULT;
        return res;
    }
    
    void Draw()
    {
        if (_currentMenuNode != NULL)
            _currentMenuNode->Draw();        
    }
    
private:
    IViewMenuNode * _currentMenuNode;
    
    IViewMenuNode * _rootNode;
};

#endif