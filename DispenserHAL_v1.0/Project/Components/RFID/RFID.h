#ifndef RFID_H_
#define RFID_H_

#include "stdint.h"

typedef enum
{
    NO_CARD_STATE,
    NEW_CARD_STATE,
    READING_CARD_STATE,
}RFID_STATE_t;


RFID_STATE_t getRfidState();
uint32_t getNewCardId();

#endif