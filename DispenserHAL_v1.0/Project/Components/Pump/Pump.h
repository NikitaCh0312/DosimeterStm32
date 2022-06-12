#ifndef PUMP_H_
#define PUMP_H_

#include "stdint.h"

typedef enum
{
  READY_WORK,
  PROGRESS_WORK,
}PUMP_STATUS_t;

typedef enum
{
    CLOCKWISE_PUMP_DIRECTION,
    COUNTERCLOCKWISE_PUMP_DIRECTION,
}PUMP_DIRECTION_t;

typedef struct
{
    void (*setPwmFrequencyHz)(uint32_t frequency) = 0;
    void (*setDirPin)(uint32_t state) = 0;
    void (*setMs1Pin)(uint32_t state) = 0;
    void (*setMs2Pin)(uint32_t state) = 0;
    void (*setMs3Pin)(uint32_t state) = 0;
    void (*setEnablePin)(uint32_t state) = 0;
    void (*delay_msec)(uint32_t msec) = 0;
    void (*startTimPWM)(void) = 0;
    void (*stopTimPWM)(void) = 0;
    void (*setStepCnt)(uint32_t steps) = 0;
    void (*setStepPeroid)(uint32_t steps) = 0;    
    uint32_t (*getStepCnt)(void) = 0;
    void (*setStatus)(PUMP_STATUS_t _status) = 0;
    PUMP_STATUS_t (*getStatus)(void) = 0;
    
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
    PUMP_DIRECTION_t direction;
}A4988Conf_t;

int pumpSubstance_ml(A4988Driver_t * drv, float ml_fl);

void setStepResol(A4988Driver_t * drv, A4988Conf_t conf);

/*
*enable pump
*@param drv - driver
*       conf - stepRes
*/
void enablePump(A4988Driver_t * drv, A4988Conf_t conf);

/*
*disable pump
*@param drv - driver
*       conf - stepRes
*/
void disablePump(A4988Driver_t * drv);

/*
*starts pump
*@param speed - from 0 to 100 
*       perStepsUs - step period in microseconds
*       steps - number of steps
*       drv - driver
*/
void startPump(A4988Driver_t * drv, uint32_t perStepUs, uint32_t steps);

/*
*stops pump
*@param drv - driver
*/
void stopPump(A4988Driver_t * drv);

/*
*number of steps left
*@param drv - driver
*/
uint32_t getStepLeft(A4988Driver_t * drv);
#endif