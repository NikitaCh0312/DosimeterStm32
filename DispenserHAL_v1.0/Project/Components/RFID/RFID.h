#ifndef RFID_H_
#define RFID_H_

#include "stdint.h"

//prototol Dallas, Wiegand 26
//http://www.techportal.ru/glossary/interfeys-wiegand.html

typedef enum
{
    NO_CARD_STATE,
    NEW_CARD_STATE,
    READING_CARD_STATE,
}RFID_STATE_t;

typedef struct
{
    uint32_t CardId;
    uint16_t card_number;
    uint16_t card_manufacturer;
    uint16_t c1;
    uint16_t c2;
}RfidInfo_t;


void rfidInit();
RFID_STATE_t getRfidState();
RfidInfo_t getNewCard();

#endif