#include "Sensors.h"
#include "main.h"

static flow_sens_koef_A_t _default_koef_A = 
{
    .A_0 = 0,
    .A_1 = 0.001,
    .A_2 = 0,
    .A_3 = 0    
};

static flow_sens_koef_B_t _default_koef_B = 
{
    .B_0 = 0,
    .B_1 = 0,
    .B_2 = 0,
    .B_3 = 0    
};

static  uint32_t _flow_sensor_cnt_DMRV = 0;
static  uint32_t _flow_sensor_cnt_DMRK = 0;
static  bool _enable_measure_DMRV = false;
static  bool _enable_measure_DMRK = false;

static flow_sens_koef_A_t _flow_sens_koef_A = {0};
static flow_sens_koef_B_t _flow_sens_koef_B = {0};

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
    else if (type == DMRK_SENSOR_TYPE) return _flow_sensor_cnt_DMRK;
    else return 0;
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

void flow_sensor_set_koef(flow_sens_koef_A_t *koef_A, flow_sens_koef_B_t *koef_B)
{
    
    _flow_sens_koef_A.A_0 = koef_A -> A_0;
    _flow_sens_koef_A.A_1 = koef_A -> A_1;
    _flow_sens_koef_A.A_2 = koef_A -> A_2;
    _flow_sens_koef_A.A_3 = koef_A -> A_3;
    
    _flow_sens_koef_B.B_0 = koef_B -> B_0;
    _flow_sens_koef_B.B_1 = koef_B -> B_1;
    _flow_sens_koef_B.B_2 = koef_B -> B_2;
    _flow_sens_koef_B.B_3 = koef_B -> B_3;
    
}

void flow_sensor_set_default_koef()
{
    
    _flow_sens_koef_A.A_0 = _default_koef_A.A_0;
    _flow_sens_koef_A.A_1 = _default_koef_A.A_1;
    _flow_sens_koef_A.A_2 = _default_koef_A.A_2;
    _flow_sens_koef_A.A_3 = _default_koef_A.A_3;
    
    _flow_sens_koef_B.B_0 = _default_koef_B.B_0;
    _flow_sens_koef_B.B_1 = _default_koef_B.B_1;
    _flow_sens_koef_B.B_2 = _default_koef_B.B_2;
    _flow_sens_koef_B.B_3 = _default_koef_B.B_3;
    
}

void flow_sensor_get_koef(flow_sens_koef_A_t *koef_A, flow_sens_koef_B_t *koef_B)
{
    
    koef_A -> A_0 = _flow_sens_koef_A.A_0;
    koef_A -> A_1 = _flow_sens_koef_A.A_1;
    koef_A -> A_2 = _flow_sens_koef_A.A_2;
    koef_A -> A_3 = _flow_sens_koef_A.A_3;
    
    koef_B -> B_0 = _flow_sens_koef_B.B_0;
    koef_B -> B_1 = _flow_sens_koef_B.B_1;
    koef_B -> B_2 = _flow_sens_koef_B.B_2;
    koef_B -> B_3 = _flow_sens_koef_B.B_3;
    
}

float flow_sensor_get_volume_liters(SENSOR_TYPE_t type)
{
    float volume = 0;
    float cnt = 0;
    
    cnt = (float)flow_sensor_get_cnt(type);
    
    volume = _flow_sens_koef_A.A_0 + (_flow_sens_koef_A.A_1 * cnt) + (_flow_sens_koef_A.A_2 * cnt * cnt) + (_flow_sens_koef_A.A_3 * cnt * cnt * cnt);
    
    return volume;
}