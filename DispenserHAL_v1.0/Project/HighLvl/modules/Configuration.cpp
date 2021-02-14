#include "Configuration.h"

void Configuration::SetIpAddr(IP_ADDR_t addr)
{
    _ip_addr.addr_1 = addr.addr_1;
    _ip_addr.addr_2 = addr.addr_2;
    _ip_addr.addr_3 = addr.addr_3;
    _ip_addr.addr_4 = addr.addr_4;
}

void Configuration::SetIpMask(IP_MASK_t mask)
{
    _ip_mask.msk_1 = mask.msk_1;
    _ip_mask.msk_2 = mask.msk_2;
    _ip_mask.msk_3 = mask.msk_3;
    _ip_mask.msk_4 = mask.msk_4;
}

IP_ADDR_t   Configuration::GetIpAddr()
{
    return _ip_addr;
}

IP_MASK_t   Configuration::GetIpMask()
{
    return _ip_mask;
}