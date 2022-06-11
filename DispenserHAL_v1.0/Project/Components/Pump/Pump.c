#include "Pump.h"

/* example

    initPumpDriver();
    enablePump(getPumpDriver(), getA4988Conf());
    startPump(getPumpDriver(), 1000, 200);
  
    while((*getPumpDriver()).getStatus() == PROGRESS_WORK) {};
      
    disablePump(getPumpDriver());

*/ 

/*
*set step resolution pump
*@param drv - driver
*       conf - stepRes
*/
void setStepResol(A4988Driver_t * drv, A4988Conf_t conf)
{
    if (conf.resolution == FULL_STEP_RESOLUTION_TYPE)
    {
        drv->setMs1Pin(0);
        drv->setMs2Pin(0);
        drv->setMs3Pin(0);
    }
    else if (conf.resolution == HALF_STEP_RESOLUTION_TYPE)
    {
        drv->setMs1Pin(1);
        drv->setMs2Pin(0);
        drv->setMs3Pin(0);
    }
    else if (conf.resolution == QUARTER_STEP_RESOLUTION_TYPE)
    {
        drv->setMs1Pin(0);
        drv->setMs2Pin(1);
        drv->setMs3Pin(0);
    }
    else if (conf.resolution == EIGHTH_STEP_RESOLUTION_TYPE)
    {
        drv->setMs1Pin(1);
        drv->setMs2Pin(1);
        drv->setMs3Pin(0);
    }
    else if (conf.resolution == SIXTEENTH_STEP_RESOLUTION_TYPE)
    {
        drv->setMs1Pin(1);
        drv->setMs2Pin(1);
        drv->setMs3Pin(1);
    }
}

/*
*enable pump
*@param drv - driver
*       conf - stepRes
*/
void enablePump(A4988Driver_t * drv, A4988Conf_t conf)
{
  setStepResol(drv, conf);
  drv->setDirPin(conf.direction);
  drv->setEnablePin(0);
  drv->delay_msec(2);   //timing for set
  
  drv->setStatus(READY_WORK);
}

/*
*disable pump
*@param drv - driver
*       conf - stepRes
*/
void disablePump(A4988Driver_t * drv)
{
  stopPump(drv);
  
  drv->setEnablePin(1);
  drv->delay_msec(2);   //timing for set
  drv->setStatus(READY_WORK);
}

/*
*starts pump
*@param speed - from 0 to 100 
*       perStepsUs - step period in microseconds
*       steps - number of steps
*       drv - driver
*/
void startPump(A4988Driver_t * drv, uint32_t perStepUs, uint32_t steps)
{
  //uint32_t newStepPer = perStepUs / 2;
  
    drv->setStepCnt(steps);
    drv->setStepPeroid(perStepUs);
    drv->setStatus(PROGRESS_WORK);
    drv->startTimPWM();
}

/*
*stops pump
*@param drv - driver
*/
void stopPump(A4988Driver_t * drv)
{
  drv->stopTimPWM();
  drv->setStatus(READY_WORK);
}

/*
*number of steps left
*@param drv - driver
*/
uint32_t getStepLeft(A4988Driver_t * drv)
{
  return drv->getStepCnt();
}
