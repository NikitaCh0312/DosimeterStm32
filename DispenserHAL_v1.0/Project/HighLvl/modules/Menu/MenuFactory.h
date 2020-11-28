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
        
        Menu * menu = new Menu();
        
        dateTimeNode = new ViewMenuNode(menu, "DateTime");
        dateTimeParamsNode = new TimeDateViewMenuNode(menu, "DateTimeParams");
        
        NetworkNode = new ViewMenuNode(menu, "Network");
        NetworkParamsNode = new NetworkViewMenuNode(menu, "Setting1");
        
        Setting1Node = new ViewMenuNode(menu, "Setting1");
        Setting2Node = new ViewMenuNode(menu, "Setting2");
        
        
        dateTimeNode->ConfigNode(NetworkNode, NULL, NULL, dateTimeParamsNode);
        dateTimeParamsNode->ConfigNode(NULL, NULL, dateTimeNode, NULL);
        
        NetworkNode->ConfigNode(Setting1Node, dateTimeNode, NULL, NetworkParamsNode);
        NetworkParamsNode->ConfigNode(NULL, NULL, NetworkNode, NULL);
        
        Setting1Node->ConfigNode(Setting2Node, NetworkNode, NULL, NULL);
        Setting2Node->ConfigNode(dateTimeNode, Setting1Node, NULL, NULL);
        
        menu->SetRootNode((IViewMenuNode*)dateTimeNode);
        
        return menu;
    }
   
private:

};

#endif