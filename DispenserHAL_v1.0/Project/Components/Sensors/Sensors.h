#ifndef SENSORS_H_
#define SENSORS_H_

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

#endif