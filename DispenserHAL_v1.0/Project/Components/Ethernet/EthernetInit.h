#ifndef ETHERNET_INIT_H_
#define ETHERNET_INIT_H_


typedef struct
{
  uint8_t ipv4_1;
  uint8_t ipv4_2;
  uint8_t ipv4_3;
  uint8_t ipv4_4;
}IPV4_t;

typedef struct
{
  uint8_t mask1;
  uint8_t mask2;
  uint8_t mask3;
  uint8_t mask4; 
}MASK_t;

void EthernetInit(IPV4_t ip_addr, MASK_t mask);


#endif
