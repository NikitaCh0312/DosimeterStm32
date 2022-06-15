#ifndef RTC_DRV_H_
#define RTC_DRV_H_

#include "time.h"
#include "stdint.h"

typedef struct
{
    uint8_t Seconds;
    uint8_t Minutes;
    uint8_t Hours;
    uint8_t WeekDay;
    uint8_t Day;
    uint8_t Month;
    uint8_t Year;
}RtcDateTime_t;

void RTC_Init();
void RTC_SetTime(struct tm *time);
void RTC_SetTimeUnix(time_t time);
void RTC_GetTime(struct tm *time);
void RTC_GetTimeUnix(time_t time);
int RtcSetDateTime(RtcDateTime_t * dateTime);
void RtcGetDateTime(RtcDateTime_t * dateTime);

#endif