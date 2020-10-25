#include "Pump.h"



/*
*init pump
*@param drv - driver
*/
void initPump(A4988Driver_t * drv, A4988Conf_t conf)
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
    drv->setEnablePin(1);
}


/*
*starts pump
*@param speed - from 0 to 100 
*       dir - direction
*       drv - driver
*/
void startPump(uint32_t speed,
               PUMP_DIRECTION_t dir,
               A4988Driver_t * drv)
{
    drv->setEnablePin(0);
    drv->delay_msec(2);
    if (dir == CLOCKWISE_PUMP_DIRECTION)
        drv->setDirPin(1);
    else
        drv->setDirPin(0);
    drv->delay_msec(2);
    drv->setPwmFrequencyHz(1000);
}

/*
*stops pump
*@param drv - driver
*/
void stopPump(A4988Driver_t * drv)
{
    drv->setPwmFrequencyHz(0);
    drv->setEnablePin(1);
}