#ifndef MENU_FACTORY_H_
#define MENU_FACTORY_H_

#include "Menu.h"
#include "ViewMenuNode.h"
#include "NetworkViewMenuNode.h"
#include "TimeDateViewMenuNode.h"

class MenuFactory
{
public:
    MenuFactory()
    {
        
    }
    virtual ~MenuFactory()
    {
        
    }
    
    static Menu * CreateMenu()
    {
        ViewMenuNode * dateTimeNode;
        TimeDateViewMenuNode * dateTimeParamsNode;
        ViewMenuNode * NetworkNode;
        NetworkViewMenuNode * NetworkParamsNode;
        ViewMenuNode * Setting1Node;
        ViewMenuNode * Setting2Node;
        
        dateTimeNode = new ViewMenuNode(NetworkNode, NULL, NULL, dateTimeParamsNode, "DateTime");
        dateTimeParamsNode = new TimeDateViewMenuNode(NULL, NULL, dateTimeNode, NULL, "DateTimeParams");
        
        NetworkNode = new ViewMenuNode(Setting1Node, dateTimeNode, NULL, NetworkParamsNode, "Network");
        NetworkParamsNode = new NetworkViewMenuNode(NULL, NULL, NetworkNode, NULL, "Setting1");
        
        Setting1Node = new ViewMenuNode(Setting2Node, NetworkNode, NULL, NULL, "Setting1");
        Setting2Node = new ViewMenuNode(dateTimeNode, Setting1Node, NULL, NULL, "Setting2");
        
        Menu *  menu = new Menu((IViewMenuNode*)dateTimeNode);
        
        return menu;
    }
   
private:

};

#endif