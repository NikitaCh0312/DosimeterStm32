#ifndef CARD_H_
#define CARD_H_


#define MAX_TASKS_QUANTITY 20



typedef struct
{
    uint16_t Volume;
    uint8_t Concentration;
}Task;

typedef struct
{
    uint32_t Id;
    uint32_t TasksQuantity;
    uint32_t SubstanceId;
    Task tasks[MAX_TASKS_QUANTITY];
}Card;

#endif