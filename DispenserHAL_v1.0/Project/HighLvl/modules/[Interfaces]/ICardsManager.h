#ifndef ICARDS_MANAGER_H_
#define ICARDS_MANAGER_H_

#include "modules/Card.h"
typedef enum
{
    CARD_IS_NOT_BINDED_STATUS,
    CARD_IS_INACTIVE_STATUS,
    CARD_IS_ACTIVE_STATUS,
    CARD_EXT_ACCESS_STATUS,
}CARD_STATUS_t;


class ICardsManager
{
public:
    ICardsManager(){}
    virtual ~ICardsManager(){}
    
    virtual CARD_STATUS_t GetCardStatus (uint32_t cardId) = 0;
    
    virtual Card GetCardTasks() = 0;
};


#endif