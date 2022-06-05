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


SENSOR_STATE_t getSensorState(SENSOR_TYPE_t type);
void flow_sensor_increment_cnt_FROM_ISR(SENSOR_TYPE_t type);
void flow_sensor_clear_cnt(SENSOR_TYPE_t type);

extern void flow_sensor_start_measure(SENSOR_TYPE_t type);
extern void flow_sensor_stop_measure(SENSOR_TYPE_t type);
extern uint32_t flow_sensor_get_cnt(SENSOR_TYPE_t type);

#endif