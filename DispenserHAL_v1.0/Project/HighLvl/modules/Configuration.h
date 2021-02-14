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
}IP_ADDR_t;

typedef struct
{
    uint8_t msk_1;
    uint8_t msk_2;
    uint8_t msk_3;
    uint8_t msk_4;   
}IP_MASK_t;


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
    
    void        SetIpAddr(IP_ADDR_t addr);
    void        SetIpMask(IP_MASK_t mask);
    
    IP_ADDR_t   GetIpAddr();
    IP_MASK_t   GetIpMask();
    
    
private:
    Configuration()
    {
        //defult IP ADDR
        _ip_addr.addr_1 = 192;
        _ip_addr.addr_2 = 103;
        _ip_addr.addr_3 = 0;
        _ip_addr.addr_4 = 10;
        
        //defult IP MASK
        _ip_mask.msk_1 = 255;
        _ip_mask.msk_2 = 255;
        _ip_mask.msk_3 = 255;
        _ip_mask.msk_4 = 0;
               
    }
    
    static Configuration * _instance;
        
    IP_ADDR_t   _ip_addr;
    IP_MASK_t   _ip_mask;
    
};
#endif