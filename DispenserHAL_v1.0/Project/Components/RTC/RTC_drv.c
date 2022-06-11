#include "RTC_drv.h"
#include "main.h"
#include "rtc.h"


RTC_DateTypeDef sDate;
RTC_TimeTypeDef sTime;

/*
static uint8_t BCD_to_DEC(uint8_t val)
{
    return (val >> 4) * 10 + (val & 0x0f);
}

static uint8_t DEC_to_BCD(uint8_t val)
{
    return ((val / 10) << 4) + (val % 10);
}
*/

static void RTC_GetDateTimeHAL(RTC_DateTypeDef *Date, RTC_TimeTypeDef *Time)
{   
    HAL_RTC_GetTime(&hrtc, Time, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, Date, RTC_FORMAT_BIN);         
}

static int RTC_SetDateTimeHAL(RTC_DateTypeDef *Date, RTC_TimeTypeDef *Time)
{

    if(HAL_RTC_SetDate(&hrtc,Date, RTC_FORMAT_BIN) != HAL_OK)
    {
          return -1;
    }

    if (HAL_RTC_SetTime(&hrtc, Time, RTC_FORMAT_BIN) != HAL_OK)
    {
          return -1;
    }

    /* Writes a data in a RTC Backup data Register1*/
    HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2);  
}


void RTC_Init()
{
    MX_RTC_Init();
}

void RTC_SetTime(struct tm *time)
{

    /* Configure the Date */
    sDate.Year          = time->tm_year - 100;
    sDate.Month         = time->tm_mon + 1;
    sDate.Date          = time->tm_mday;
    //sDate.WeekDay       = time->tm_wday + 1;
    if(time->tm_wday == 0) sDate.WeekDay = 7;
    else sDate.WeekDay = time->tm_wday;

    if(HAL_RTC_SetDate(&hrtc,&sDate,RTC_FORMAT_BIN) != HAL_OK)
    {
          Error_Handler();
    }

    /* Configure the Time */
    sTime.Hours         = time->tm_hour;
    sTime.Minutes       = time->tm_min;
    sTime.Seconds       = time->tm_sec;
    sTime.TimeFormat    = RTC_HOURFORMAT12_AM;
    sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE ;
    sTime.StoreOperation = RTC_STOREOPERATION_RESET;

    if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
    {
          Error_Handler();
    }

    /* Writes a data in a RTC Backup data Register1*/
    HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2);  
}

void RTC_SetTimeUnix(time_t time)
{
    struct tm * timeinfo;
    timeinfo = localtime (&time);
    RTC_SetTime(timeinfo);
}

void RTC_GetTime(struct tm *time)
{   
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN); 
    
    time->tm_hour       = sTime.Hours;
    time->tm_min        = sTime.Minutes;
    time->tm_sec        = sTime.Seconds;
    
    time->tm_year       = sDate.Year + 100;
    time->tm_mon        = sDate.Month - 1;
    time->tm_mday       = sDate.Date;
    time->tm_isdst      = 0;
    //time->tm_wday       = sDate.WeekDay - 1;
    if(sDate.WeekDay == 7) time->tm_wday = 0;
    else time->tm_wday = sDate.WeekDay;
    
}

void RTC_GetTimeUnix(time_t *time)
{
    struct tm timeinfo = {};
    
    RTC_GetTime(&timeinfo);
    *time = mktime(&timeinfo);
}

int RtcSetDateTime(RtcDateTime_t * dateTime)
{
    RTC_DateTypeDef date;
    date.Date = dateTime->Day;
    date.Month = dateTime->Month;
    date.Year = dateTime->Year;
    RTC_TimeTypeDef time;
    time.Seconds = dateTime->Seconds;
    time.Minutes = dateTime->Minutes;
    time.Hours = dateTime->Hours;
    RTC_SetDateTimeHAL(&date, &time);
    return 0;
}

void RtcGetDateTime(RtcDateTime_t * dateTime)
{
    RTC_DateTypeDef date;
    RTC_TimeTypeDef time;
    RTC_GetDateTimeHAL(&date, &time);
    dateTime->Day = date.Date;
    dateTime->Month = date.Month;
    dateTime->Year = date.Year;
    dateTime->Seconds = time.Seconds;
    dateTime->Minutes = time.Minutes;
    dateTime->Hours = time.Hours;

}