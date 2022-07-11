#ifndef MENU_FACTORY_H_
#define MENU_FACTORY_H_

#include "Menu.h"
#include "ViewMenuNode.h"
#include "NetworkViewMenuNode.h"
#include "TimeDateViewMenuNode.h"
#include "Resources/StringResources.h"

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
        
        dateTimeNode = new ViewMenuNode(menu, (char*)StringResources::DateTime);
        dateTimeParamsNode = new TimeDateViewMenuNode(menu, (char*)StringResources::DateTime);
        
        NetworkNode = new ViewMenuNode(menu,  (char*)StringResources::Network);
        NetworkParamsNode = new NetworkViewMenuNode(menu, (char*)StringResources::Network);
        
        Setting1Node = new ViewMenuNode(menu, "FORCED DISPENCING   ");
        Setting2Node = new ViewMenuNode(menu, "MAINTENANCE OF DS&DS");
        
        
        dateTimeNode->ConfigNode(NetworkNode, Setting2Node, NULL, dateTimeParamsNode);
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