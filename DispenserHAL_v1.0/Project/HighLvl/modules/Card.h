#ifndef CARD_H_
#define CARD_H_


#define MAX_TASKS_QUANTITY 20


//12 bytes
typedef struct
{
    //4 bytes
    int Id;
    //4 bytes
    float Volume;
    //4 bytes
    float Concentration;
}Task;

//total 256 bytes
typedef struct
{
    //4 bytes
    uint32_t Id;
    //4 bytes
    uint32_t TasksQuantity;
    //4 bytes
    uint32_t SubstanceId;
    //12 * 20 = 240 bytes
    Task tasks[MAX_TASKS_QUANTITY];
    //4 bytes
    uint32_t reserved;
}Card;

#endif