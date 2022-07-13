#ifndef MENU_FACTORY_H_
#define MENU_FACTORY_H_

#include "Menu.h"
#include "ViewMenuNode.h"
#include "NetworkViewMenuNode.h"
#include "TimeDateViewMenuNode.h"
#include "ManualDosationViewMenuNode.h"
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
        
        ViewMenuNode * manualDosationNode;
        ManualDosationViewMenuNode * manualDosationMenuNode;
        ViewMenuNode * Setting2Node;
        
        Menu * menu = new Menu();
        
        dateTimeNode = new ViewMenuNode(menu, (char*)StringResources::DateTime);
        dateTimeParamsNode = new TimeDateViewMenuNode(menu, (char*)StringResources::DateTime);
        
        NetworkNode = new ViewMenuNode(menu,  (char*)StringResources::Network);
        NetworkParamsNode = new NetworkViewMenuNode(menu, (char*)StringResources::Network);
        
        manualDosationNode = new ViewMenuNode(menu, (char*)StringResources::ManualDosation);
        manualDosationMenuNode = new ManualDosationViewMenuNode(menu, (char*)StringResources::ManualDosation);
        
        Setting2Node = new ViewMenuNode(menu, "MAINTENANCE OF DS&DS");
        
        
        dateTimeNode->ConfigNode(NetworkNode, Setting2Node, NULL, dateTimeParamsNode);
        dateTimeParamsNode->ConfigNode(NULL, NULL, dateTimeNode, NULL);
        
        NetworkNode->ConfigNode(manualDosationNode, dateTimeNode, NULL, NetworkParamsNode);
        NetworkParamsNode->ConfigNode(NULL, NULL, NetworkNode, NULL);
        
        manualDosationNode->ConfigNode(Setting2Node, NetworkNode, NULL, manualDosationMenuNode);
        manualDosationMenuNode->ConfigNode(NULL, NULL, manualDosationNode, NULL);
        
        Setting2Node->ConfigNode(dateTimeNode, manualDosationNode, NULL, NULL);
        
        menu->SetRootNode((IViewMenuNode*)dateTimeNode);
        
        return menu;
    }
   
private:

};

#endif