#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include "stdint.h"
#include "stddef.h"


typedef struct
{
    uint8_t addr_1;
    uint8_t addr_2;
    uint8_t addr_3;
    uint8_t addr_4;   
}IpAddr_t;

typedef struct
{
    uint8_t mask_1;
    uint8_t mask_2;
    uint8_t mask_3;
    uint8_t mask_4;   
}Mask_t;


class Configuration
{
public:
    Configuration()
    {
        //defult IP ADDR
        _ip_addr.addr_1 = 192;
        _ip_addr.addr_2 = 103;
        _ip_addr.addr_3 = 0;
        _ip_addr.addr_4 = 10;
        
        //defult IP MASK
        _ip_mask.mask_1 = 255;
        _ip_mask.mask_2 = 255;
        _ip_mask.mask_3 = 255;
        _ip_mask.mask_4 = 0;
    }
    virtual ~Configuration(){}
    
    void SetIp(IpAddr_t addr)
    {
        _ip_addr.addr_1 = addr.addr_1;
        _ip_addr.addr_2 = addr.addr_2;
        _ip_addr.addr_3 = addr.addr_3;
        _ip_addr.addr_4 = addr.addr_4;
    }
    void SetMask(Mask_t mask)
    {
        _ip_mask.mask_1 = mask.mask_1;
        _ip_mask.mask_2 = mask.mask_2;
        _ip_mask.mask_3 = mask.mask_3;
        _ip_mask.mask_4 = mask.mask_4;
    }
    
    IpAddr_t   GetIp()
    {
        return _ip_addr;
    }
    
    Mask_t   GetMask()
    {
        return _ip_mask;
    }
    
    
private:
        
    IpAddr_t   _ip_addr;
    Mask_t   _ip_mask;
    
};
#endif