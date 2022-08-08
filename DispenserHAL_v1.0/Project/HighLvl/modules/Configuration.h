#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "stdint.h"
#include "stddef.h"

#include "modules/Storage/ConfigurationStorage.h"



class Configuration
{
public:
    Configuration()
    {
        _storage = new ConfigurationStorage();
    }
    virtual ~Configuration(){}
    
    void Init()
    {
        _storage->Load();
    }
    
    void SetIp(IpAddr_t addr)
    {
        _storage->StorageValues.RuntimeParams.IpAddress.addr_1 = addr.addr_1;
        _storage->StorageValues.RuntimeParams.IpAddress.addr_2 = addr.addr_2;
        _storage->StorageValues.RuntimeParams.IpAddress.addr_3 = addr.addr_3;
        _storage->StorageValues.RuntimeParams.IpAddress.addr_4 = addr.addr_4;
        
        _storage->Update();
    }
    void SetMask(Mask_t mask)
    {
        _storage->StorageValues.RuntimeParams.Mask.mask_1 = mask.mask_1;
        _storage->StorageValues.RuntimeParams.Mask.mask_2 = mask.mask_2;
        _storage->StorageValues.RuntimeParams.Mask.mask_3 = mask.mask_3;
        _storage->StorageValues.RuntimeParams.Mask.mask_4 = mask.mask_4;
        
        _storage->Update();
    }
    
    IpAddr_t   GetIp()
    {
        return _storage->StorageValues.RuntimeParams.IpAddress;
    }
    
    Mask_t   GetMask()
    {
        return _storage->StorageValues.RuntimeParams.Mask;
    }
    
    
private:
    ConfigurationStorage * _storage;
    
};
#endif