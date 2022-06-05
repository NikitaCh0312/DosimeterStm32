#include "Sensors.h"
#include "main.h"

static  uint32_t _flow_sensor_cnt_DMRV = 0;
static  uint32_t _flow_sensor_cnt_DMRK = 0;
static  bool _enable_measure_DMRV = false;
static  bool _enable_measure_DMRK = false;

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

void flow_sensor_increment_cnt_FROM_ISR(SENSOR_TYPE_t type)
{
    if(type == DMRV_SENSOR_TYPE && _enable_measure_DMRV == true) _flow_sensor_cnt_DMRV++;
    if(type == DMRK_SENSOR_TYPE && _enable_measure_DMRK == true) _flow_sensor_cnt_DMRK++;
}

uint32_t flow_sensor_get_cnt(SENSOR_TYPE_t type)
{
    if(type == DMRV_SENSOR_TYPE) return _flow_sensor_cnt_DMRV;
    if(type == DMRK_SENSOR_TYPE) return _flow_sensor_cnt_DMRK;
}

void flow_sensor_clear_cnt(SENSOR_TYPE_t type)
{
    if(type == DMRV_SENSOR_TYPE) _flow_sensor_cnt_DMRV = 0;
    if(type == DMRK_SENSOR_TYPE) _flow_sensor_cnt_DMRK = 0;
}

void flow_sensor_start_measure(SENSOR_TYPE_t type)
{
    if(type == DMRV_SENSOR_TYPE) 
    {   
        flow_sensor_clear_cnt(DMRV_SENSOR_TYPE);
        _enable_measure_DMRV = true;
        
    }
    if(type == DMRK_SENSOR_TYPE)
    {   
        flow_sensor_clear_cnt(DMRK_SENSOR_TYPE);
        _enable_measure_DMRK = true;
    }
}

void flow_sensor_stop_measure(SENSOR_TYPE_t type)
{
        if(type == DMRV_SENSOR_TYPE) 
    {   
        _enable_measure_DMRV = false;
        
    }
    if(type == DMRK_SENSOR_TYPE)
    {   
        _enable_measure_DMRK = false;
    }
}