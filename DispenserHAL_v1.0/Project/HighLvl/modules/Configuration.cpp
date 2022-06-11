#include "Configuration.h"

void Configuration::SetIpAddr(IpAddr_t addr)
{
    _ip_addr.addr_1 = addr.addr_1;
    _ip_addr.addr_2 = addr.addr_2;
    _ip_addr.addr_3 = addr.addr_3;
    _ip_addr.addr_4 = addr.addr_4;
}

void Configuration::SetIpMask(Mask_t mask)
{
    _ip_mask.mask_1 = mask.mask_1;
    _ip_mask.mask_2 = mask.mask_2;
    _ip_mask.mask_3 = mask.mask_3;
    _ip_mask.mask_4 = mask.mask_4;
}

IpAddr_t   Configuration::GetIpAddr()
{
    return _ip_addr;
}

Mask_t   Configuration::GetIpMask()
{
    return _ip_mask;
}