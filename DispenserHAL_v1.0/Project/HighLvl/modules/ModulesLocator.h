#ifndef MODULES_LOCATOR_H
#define MODULES_LOCATOR_H

#include "modules/[Interfaces]/ICardsManager.h"
#include "modules/CardsManager.h"
#include "modules/TaskCardSession.h"
#include "modules/EventJournal.h"
#include "modules/Configuration.h"

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
    EventJournal * eventJournal;
    Configuration * configuration;
    
    void InitModules()
    {
        configuration->Init();
        cardsManager->Init();
    }
    
private:
    static ModulesLocator * _instance;
    ModulesLocator()
    {
      cardsManager = (ICardsManager*) new CardsManager();
      taskCardsSession = new TaskCardSession();
      eventJournal = new EventJournal();
      configuration = new Configuration();
    }
    virtual ~ModulesLocator(){}
};

#endif