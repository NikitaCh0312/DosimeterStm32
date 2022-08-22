#ifndef SUBSTANCES_MANAGER_H_
#define SUBSTANCES_MANAGER_H_

#include "modules/Storage/SubstancesStorage.h"

class SubstancesManager
{
public:
    SubstancesManager()
    {
        _storage = new SubstancesStorage();

    }
    virtual ~SubstancesManager(){}
    
    void Init()
    {
        _storage->Load();
    }

    bool IsIdEqualToSelectedSubstance()
    {
        return true;
    }
    
    int GetSubstancesQuantity()
    {
        return 0;
    }
    
    void SetSelectedSubstance(uint32_t id)
    {
        Substance_t substance = _storage->GetSubstance(id);
        if (substance.Id != 0)
            _storage->SetSelectedSubstance(id);
    }
    
    Substance_t * GetSubstancesPtr()
    {
        return _storage->GetSubstancesListValuesPtr();
    }
private:
    SubstancesStorage* _storage;
};

#endif