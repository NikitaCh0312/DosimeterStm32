#include "Pump.h"

#define SPEED_100_RPM 375
#define SPEED_150_RPM 250
#define SPEED_200_RPM 188
#define SPEED_250_RPM 150
#define SPEED_300_RPM 125


                                             //float oneRot = 0.85 ml; // = 85.0/100.0;
const float oneStep_ml_fl = 0.00425;       // oneRot / 200.0 (200 steps in one rot.)

float substr_ml = 0;

void setSubstr_ml(float _substr_ml)
{
  substr_ml = _substr_ml;
}

float getSubstr_ml()
{
  return substr_ml;
}

/* example

    initPumpDriver(); // call in init device func


    enablePump(getPumpDriver(), getA4988Conf());
    startPump(getPumpDriver(), 1000, 200);   or  pumpSubstance_ml(getPumpDriver(), 85);
  
    while((*getPumpDriver()).getStatus() == PROGRESS_WORK) {};
      
    disablePump(getPumpDriver());

*/

/*
*set step resolution pump
*@param drv - driver
*/
float getSpentSubst_ml(A4988Driver_t * drv)
{
  float res = getSubstr_ml() - drv->getStepCnt() * oneStep_ml_fl;
  
  if(res > 0)
    return res;
  else  
    return 0;
}


uint32_t convRPMToPer(uint32_t rpm)
{
  // = 1 / rpm / 200 * 60 / 8  = 37500 / rpm;  // (8 is step rso;lv 1/8)
  
  return 37500 / rpm;
}

uint32_t convPerToRPM(uint32_t per_us)
{
  // = 1 / per_us / 200 * 60 / 8 = 37500 / per_us;  // (8 is step rso;lv 1/8)
  
  return 37500 / per_us;
}

/*
*get max speed
*/
uint32_t getMaxSpeedRPM()
{
  return convPerToRPM(SPEED_300_RPM);
}

/*
*set step resolution pump
*@param drv - driver
*       conf - stepRes
*/

int pumpSubstance_ml(A4988Driver_t * drv, float ml_fl, uint32_t speed)
{
  if(ml_fl < 0.1)
    return -1;
  
  setSubstr_ml(ml_fl);
  
  uint32_t numTick = (uint32_t)(ml_fl / oneStep_ml_fl);
  
  startPump(drv, convRPMToPer(speed), numTick);
  return 1;
}

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
    const int stepResol = 8;
    steps *= stepResol;
    
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
