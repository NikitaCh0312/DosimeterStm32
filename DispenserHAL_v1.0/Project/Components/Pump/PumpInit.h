#ifndef PUMP_INIT_H_
#define PUMP_INIT_H_

#include "Pump.h"

//extern A4988Driver_t pumpDriver;
A4988Driver_t* getPumpDriver();
void initPumpDriver();
A4988Conf_t getA4988Conf();

#endif