#ifndef CARD_H_
#define CARD_H_


#define MAX_TASKS_QUANTITY 20



typedef struct
{
    int Id;
    float Volume;
    float Concentration;
}Task;

typedef struct
{
    uint32_t Id;
    uint32_t TasksQuantity;
    uint32_t SubstanceId;
    Task tasks[MAX_TASKS_QUANTITY];
}Card;

#endif