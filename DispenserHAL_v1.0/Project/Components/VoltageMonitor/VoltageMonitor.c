#include "VoltageMonitor.h"
#include "main.h"
#include "stdint.h"

extern ADC_HandleTypeDef hadc1;

uint32_t getSupplyVoltage()
{
    HAL_ADC_Start(&hadc1);
    return HAL_ADC_GetValue(&hadc1);
}