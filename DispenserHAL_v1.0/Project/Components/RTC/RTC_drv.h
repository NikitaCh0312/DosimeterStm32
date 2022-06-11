#ifndef RTC_DRV_H_
#define RTC_DRV_H_

#include "time.h"
#include "rtc.h"

void RTC_Init();
void RTC_SetTime(struct tm *time);
void RTC_SetTimeUnix(time_t time);
void RTC_GetTime(struct tm *time);
void RTC_GetTimeUnix(time_t time);
void RTC_GetTimeHAL(RTC_DateTypeDef *Date, RTC_TimeTypeDef *Time);
void RTC_SetTimeHAL(RTC_DateTypeDef *Date, RTC_TimeTypeDef *Time);

#endif