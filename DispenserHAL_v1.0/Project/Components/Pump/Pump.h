#ifndef PUMP_H_
#define PUMP_H_

#include "stdint.h"


typedef enum
{
    CLOCKWISE_PUMP_DIRECTION,
    COUNTERCLOCKWISE_PUMP_DIRECTION,
}PUMP_DIRECTION_t;

typedef struct
{
    void (*setPwmFrequencyHz)(uint32_t frequency);
    void (*setDirPin)(uint32_t state);
    void (*setMs1Pin)(uint32_t state);
    void (*setMs2Pin)(uint32_t state);
    void (*setMs3Pin)(uint32_t state);
    void (*setEnablePin)(uint32_t state);
}A4988Driver_t;


typedef enum
{
    FULL_STEP_RESOLUTION_TYPE,
    HALF_STEP_RESOLUTION_TYPE,
    QUARTER_STEP_RESOLUTION_TYPE,
    EIGHTH_STEP_RESOLUTION_TYPE,
    SIXTEENTH_STEP_RESOLUTION_TYPE,
}RESOLUTION_TYPE_t;
typedef struct
{
    RESOLUTION_TYPE_t resolution;
}A4988Conf_t;

/*
*init pump
*@param drv - driver
*/
void initPump(A4988Driver_t * drv, A4988Conf_t conf);


/*
*starts pump
*@param speed - from 0 to 100 
*       dir - direction
*       drv - driver
*/
void startPump(uint32_t speed,
               PUMP_DIRECTION_t dir,
               A4988Driver_t * drv);

/*
*stops pump
*@param drv - driver
*/
void stopPump(A4988Driver_t * drv);

#endif