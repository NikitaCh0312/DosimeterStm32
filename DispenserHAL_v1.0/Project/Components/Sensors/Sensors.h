#ifndef SENSORS_H_
#define SENSORS_H_

#include "stdint.h"

typedef enum
{
    DMRV_SENSOR_TYPE,
    DMRK_SENSOR_TYPE,
    LEVEL_SENSOR_TYPE,
}SENSOR_TYPE_t;

typedef enum
{
    OFF_SENSOR_STATE,
    ON_SENSOR_STATE,
}SENSOR_STATE_t;

struct flow_sens_koef_A_t
{
  float A_0; 
  float A_1;
  float A_2;
  float A_3;
};

struct flow_sens_koef_B_t
{
  float B_0; 
  float B_1;
  float B_2;
  float B_3;
};

SENSOR_STATE_t getSensorState(SENSOR_TYPE_t type);
void flow_sensor_increment_cnt_FROM_ISR(SENSOR_TYPE_t type);
void flow_sensor_clear_cnt(SENSOR_TYPE_t type);

extern void flow_sensor_start_measure(SENSOR_TYPE_t type);
extern void flow_sensor_stop_measure(SENSOR_TYPE_t type);
extern uint32_t flow_sensor_get_cnt(SENSOR_TYPE_t type);

#endif