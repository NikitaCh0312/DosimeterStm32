#ifndef MENU_H_
#define MENU_H_

#include "IViewMenuNode.h"

typedef enum
{
    MENU_OK_RESULT,
    MENU_EXIT_RESULT,
    MENU_SWITCH_TO_MANUAL_DOSATION_STATE,
    MENU_SWITCH_TO_SUBSTANCE_SERVICE_STATE
}MENU_RESULT_t;


typedef enum
{
    MENU_NONE_ACTION,
    MENU_ENTER_ACTION,
    MENU_BACK_ACTION,
    MENU_NEXT_ACTION,
    MENU_PREV_ACTION,
}MENU_ACTION_t;


typedef enum
{
    MENU_NODE_NONE_ACTION,
    MENU_NODE_SWITCH_TO_MANUAL_DOSATION_STATE,
    MENU_NODE_SWITCH_TO_SUBSTANCE_SERVICE_STATE
}MENU_NODE_ACTION_t;

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
        _nodeAction = MENU_NODE_NONE_ACTION;
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
                _currentMenuNode->Cancel();
                break;
            case MENU_NEXT_ACTION:
                _currentMenuNode->Up();
                break;
            case MENU_PREV_ACTION:
                _currentMenuNode->Down();
                break;
            default:
                break;
        }

        if (_currentMenuNode == NULL)
        //выход из меню
            return MENU_EXIT_RESULT;
        
        if (_nodeAction == MENU_NODE_SWITCH_TO_MANUAL_DOSATION_STATE)
            return MENU_SWITCH_TO_MANUAL_DOSATION_STATE;
        if (_nodeAction == MENU_NODE_SWITCH_TO_SUBSTANCE_SERVICE_STATE)
            return MENU_SWITCH_TO_SUBSTANCE_SERVICE_STATE;
        
        return res;
    }
    
    void Draw()
    {
        if (_currentMenuNode != NULL)
            _currentMenuNode->Draw();        
    }
    
    void SetNodeAction(MENU_NODE_ACTION_t action)
    {
        _nodeAction = action;
    }
    
    
private:
    IViewMenuNode * _currentMenuNode;
    
    IViewMenuNode * _rootNode;
    
    MENU_NODE_ACTION_t _nodeAction;
};

#endif