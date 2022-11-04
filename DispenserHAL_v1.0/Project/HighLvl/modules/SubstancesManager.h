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

    bool IsIdEqualToSelectedSubstance(uint32_t substanceId)
    {
        return true;
    }
    
    int GetSubstancesQuantity()
    {
        return 0;
    }
    
    void AddSubstance(Substance_t* substance)
    {
      
    }
    
    void DeleteSubstance(uint32_t id)
    {
      
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