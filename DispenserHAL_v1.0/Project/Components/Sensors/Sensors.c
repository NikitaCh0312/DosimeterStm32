#include "Sensors.h"
#include "main.h"


SENSOR_STATE_t getSensorState(SENSOR_TYPE_t type)
{
    int res = 1;
    
    if (type == DMRV_SENSOR_TYPE)
        res = (int)HAL_GPIO_ReadPin(SENSOR_DMRV_GPIO_Port, SENSOR_DMRV_Pin);
    else if (type == DMRK_SENSOR_TYPE)
        res = (int)HAL_GPIO_ReadPin(SENSOR_DMRK_GPIO_Port, SENSOR_DMRK_Pin);
    else if (type == LEVEL_SENSOR_TYPE)
        res = (int)HAL_GPIO_ReadPin(SNSOR_LEVEL_GPIO_Port, SNSOR_LEVEL_Pin);
    
    if (res)
        return OFF_SENSOR_STATE;
    return ON_SENSOR_STATE;
}