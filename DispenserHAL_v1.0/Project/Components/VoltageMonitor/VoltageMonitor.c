#include "VoltageMonitor.h"
#include "main.h"
#include "stdint.h"

extern ADC_HandleTypeDef hadc1;

uint32_t getSupplyVoltage_mV()
{
  uint32_t val = 0;
  
  HAL_ADC_Start(&hadc1);
  // save from optimizator
  val = HAL_ADC_GetValue(&hadc1) * 1000 / 4095;
  val = val * (33+270) / 10;
  return val;  
}