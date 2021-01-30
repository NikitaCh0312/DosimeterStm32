#include "EthernetInit.h"
#include "Ethernet/Ethernet/wizchip_conf.h"
#include "Ethernet/Ethernet/socket.h"
#include "spi.h"

void W5500_Select(void)
{
    HAL_GPIO_WritePin(W55_CS_SPI_GPIO_Port, W55_CS_SPI_Pin,
                      GPIO_PIN_RESET);
}

void W5500_Unselect(void)
{
    HAL_GPIO_WritePin(W55_CS_SPI_GPIO_Port, W55_CS_SPI_Pin,
                      GPIO_PIN_SET);
}

void W5500_ReadBuff(uint8_t* buff, uint16_t len)
{
    HAL_SPI_Receive(&hspi1, buff, len, 1000);
}

void W5500_WriteBuff(uint8_t* buff, uint16_t len)
{
    HAL_SPI_Transmit(&hspi1, buff, len, 1000);
}

uint8_t W5500_ReadByte(void)
{
    uint8_t byte = 0;
    W5500_ReadBuff(&byte, 1);
    return byte;
}

void W5500_WriteByte(uint8_t byte)
{
    W5500_WriteBuff(&byte, 1);
}


void EthernetInit()
{
    // Init W5500
    // Registering W5500 callbacks
    reg_wizchip_cs_cbfunc(W5500_Select, W5500_Unselect);
    reg_wizchip_spi_cbfunc(W5500_ReadByte, W5500_WriteByte);
    reg_wizchip_spiburst_cbfunc(W5500_ReadBuff, W5500_WriteBuff);
    
    
    uint8_t rx_tx_buff_sizes[] = {2, 2, 2, 2, 2, 2, 2, 2};

    wiz_NetInfo net_info;
    // Init MAC-address
    net_info.mac[0] = 0xEA;
    net_info.mac[1] = 0x11;
    net_info.mac[2] = 0x22;
    net_info.mac[3] = 0x33;
    net_info.mac[4] = 0x44;
    net_info.mac[5] = 0xEA;
    //net mask
    net_info.sn[0] = 255;
    net_info.sn[1] = 255;
    net_info.sn[2] = 255;
    net_info.sn[3] = 0;
    // Init IP-address
    net_info.ip[0] = 192;
    net_info.ip[1] = 168;
    net_info.ip[2] = 0;
    net_info.ip[3] = 9;
    //net_info.dhcp = NETINFO_DHCP;
    net_info.dhcp = NETINFO_STATIC;

    wizchip_init(rx_tx_buff_sizes, rx_tx_buff_sizes);
    // set MAC address before using DHCP
    setSHAR(net_info.mac);
    // Calling wizchip_setnetinfo()
    wizchip_setnetinfo(&net_info);
}