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
    
#warning ERROR MENU INITIALIZATION!!!
    static Menu * CreateMenu()
    {
        ViewMenuNode * dateTimeNode;
        TimeDateViewMenuNode * dateTimeParamsNode;
        ViewMenuNode * NetworkNode;
        NetworkViewMenuNode * NetworkParamsNode;
        ViewMenuNode * Setting1Node;
        ViewMenuNode * Setting2Node;
        
        Menu * menu = new Menu();
        
        dateTimeNode = new ViewMenuNode(menu, NetworkNode, NULL, NULL, dateTimeParamsNode, "DateTime");
        dateTimeParamsNode = new TimeDateViewMenuNode(menu, NULL, NULL, dateTimeNode, NULL, "DateTimeParams");
        
        NetworkNode = new ViewMenuNode(menu, Setting1Node, dateTimeNode, NULL, NetworkParamsNode, "Network");
        NetworkParamsNode = new NetworkViewMenuNode(menu, NULL, NULL, NetworkNode, NULL, "Setting1");
        
        Setting1Node = new ViewMenuNode(menu, Setting2Node, NetworkNode, NULL, NULL, "Setting1");
        Setting2Node = new ViewMenuNode(menu, dateTimeNode, Setting1Node, NULL, NULL, "Setting2");
        
        menu->SetRootNode((IViewMenuNode*)dateTimeNode);
        
        return menu;
    }
   
private:

};

#endif