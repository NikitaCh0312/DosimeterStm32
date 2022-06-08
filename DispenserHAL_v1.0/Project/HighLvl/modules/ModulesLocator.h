#ifndef MODULES_LOCATOR_H
#define MODULES_LOCATOR_H

#include "modules/[Interfaces]/ICardsManager.h"
#include "modules/CardsManager.h"

class ModulesLocator
{
public:
    static ModulesLocator * GetInstance()
    {
        if (_instance == NULL)
            _instance = new ModulesLocator();
        return _instance;
    }
    
    ICardsManager * cardsManager;
    
private:
    static ModulesLocator * _instance;
    ModulesLocator()
    {
      cardsManager = (ICardsManager*)CardsManager::GetInstance();
    }
    virtual ~ModulesLocator(){}
};

#endif