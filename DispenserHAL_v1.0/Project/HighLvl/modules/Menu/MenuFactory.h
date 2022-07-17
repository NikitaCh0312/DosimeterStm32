#ifndef MENU_FACTORY_H_
#define MENU_FACTORY_H_

#include "Menu.h"
#include "ViewMenuNode.h"
#include "NetworkViewMenuNode.h"
#include "TimeDateViewMenuNode.h"
#include "ManualDosationViewMenuNode.h"
#include "SubstanceServiceViewMenuNode.h"
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
        
        ViewMenuNode * substanceServiceNode;
        SubstanceServiceViewMenuNode * substanceServiceViewMenuNode;
          
        Menu * menu = new Menu();
        
        dateTimeNode = new ViewMenuNode(menu, (char*)StringResources::DateTime);
        dateTimeParamsNode = new TimeDateViewMenuNode(menu, (char*)StringResources::DateTime);
        
        NetworkNode = new ViewMenuNode(menu,  (char*)StringResources::Network);
        NetworkParamsNode = new NetworkViewMenuNode(menu, (char*)StringResources::Network);
        
        manualDosationNode = new ViewMenuNode(menu, (char*)StringResources::ManualDosation);
        manualDosationMenuNode = new ManualDosationViewMenuNode(menu, (char*)StringResources::ManualDosation);
        
        substanceServiceNode = new ViewMenuNode(menu, (char*)StringResources::SubstanceService);
        substanceServiceViewMenuNode = new SubstanceServiceViewMenuNode(menu, (char*)StringResources::SubstanceService);
        
        dateTimeNode->ConfigNode(NetworkNode, substanceServiceNode, NULL, dateTimeParamsNode);
        dateTimeParamsNode->ConfigNode(NULL, NULL, dateTimeNode, NULL);
        
        NetworkNode->ConfigNode(manualDosationNode, dateTimeNode, NULL, NetworkParamsNode);
        NetworkParamsNode->ConfigNode(NULL, NULL, NetworkNode, NULL);
        
        manualDosationNode->ConfigNode(substanceServiceNode, NetworkNode, NULL, manualDosationMenuNode);
        manualDosationMenuNode->ConfigNode(NULL, NULL, manualDosationNode, NULL);
        
        substanceServiceNode->ConfigNode(dateTimeNode, manualDosationNode, NULL, substanceServiceViewMenuNode);
        substanceServiceViewMenuNode->ConfigNode(NULL, NULL, substanceServiceNode, NULL);
        
        menu->SetRootNode((IViewMenuNode*)dateTimeNode);
        
        return menu;
    }
   
private:

};

#endif