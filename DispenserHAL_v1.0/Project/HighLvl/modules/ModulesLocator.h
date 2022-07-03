#ifndef MODULES_LOCATOR_H
#define MODULES_LOCATOR_H

#include "modules/[Interfaces]/ICardsManager.h"
#include "modules/CardsManager.h"
#include "modules/TaskCardSession.h"

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
    TaskCardSession * taskCardsSession;
    
private:
    static ModulesLocator * _instance;
    ModulesLocator()
    {
      cardsManager = (ICardsManager*)CardsManager::GetInstance();
      taskCardsSession = new TaskCardSession();
    }
    virtual ~ModulesLocator(){}
};

#endif