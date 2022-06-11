#ifndef CONFIG_H_
#define CONFIG_H_

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
    static Configuration * GetInstance()
    {
        if (_instance == NULL)
            _instance = new Configuration();
        return _instance;
    }
    virtual ~Configuration(){}
    
    void        SetIpAddr(IpAddr_t addr);
    void        SetIpMask(Mask_t mask);
    
    IpAddr_t   GetIpAddr();
    Mask_t   GetIpMask();
    
    
private:
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
    
    static Configuration * _instance;
        
    IpAddr_t   _ip_addr;
    Mask_t   _ip_mask;
    
};
#endif