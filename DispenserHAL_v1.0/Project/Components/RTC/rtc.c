/**
  ******************************************************************************
  * File Name          : RTC.c
  * Description        : This file provides code for the configuration
  *                      of the RTC instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "rtc.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

RTC_HandleTypeDef hrtc;

/* RTC init function */
void MX_RTC_Init(void)
{

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  
  if((RCC->BDCR & RCC_BDCR_RTCEN) == 0 ) 
  {
    if (HAL_RTC_Init(&hrtc) != HAL_OK)
    {
          Error_Handler();
    }
    
    if (HAL_RTCEx_SetCalibrationOutPut(&hrtc) != HAL_OK)
    {
          Error_Handler();
    }
  }
  else
  {
    HAL_PWR_EnableBkUpAccess();
    __HAL_RCC_BKPSRAM_CLK_ENABLE();
    __HAL_RCC_RTC_ENABLE();
  }

/*##-2- Check if Data stored in BackUp register1: No Need to reconfigure RTC#*/
  /* Read the Back Up Register 1 Data */
  if (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1) != 0x32F2) 
  {
            /* Configure RTC Calendar */
            RTC_DateTypeDef sdatestructure;
            RTC_TimeTypeDef stimestructure;

            /*##-1- Configure the Date #################################################*/
            /* Set Date: WEDNESDAY NOVEMBER 04th 2020 */
            sdatestructure.Year = 0x20;
            sdatestructure.Month = RTC_MONTH_NOVEMBER;
            sdatestructure.Date = 0x04;
            sdatestructure.WeekDay = RTC_WEEKDAY_WEDNESDAY;

            if(HAL_RTC_SetDate(&hrtc,&sdatestructure,RTC_FORMAT_BCD) != HAL_OK)
            {
                  /* Initialization Error */
                  Error_Handler();
            }

            /*##-2- Configure the Time #################################################*/
            /* Set Time: 12:00:00 */
            stimestructure.Hours = 0x12;
            stimestructure.Minutes = 0x00;
            stimestructure.Seconds = 0x00;
            stimestructure.TimeFormat = RTC_HOURFORMAT12_AM;
            stimestructure.DayLightSaving = RTC_DAYLIGHTSAVING_NONE ;
            stimestructure.StoreOperation = RTC_STOREOPERATION_RESET;

            if (HAL_RTC_SetTime(&hrtc, &stimestructure, RTC_FORMAT_BCD) != HAL_OK)
            {
                  /* Initialization Error */
                  Error_Handler();
            }

            /*##-3- Writes a data in a RTC Backup data Register1 #######################*/
            HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2); 
  }

}

void HAL_RTC_MspInit(RTC_HandleTypeDef* rtcHandle)
{

  if(rtcHandle->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspInit 0 */

  /* USER CODE END RTC_MspInit 0 */
    /* RTC clock enable */
    __HAL_RCC_RTC_ENABLE();
  /* USER CODE BEGIN RTC_MspInit 1 */

  /* USER CODE END RTC_MspInit 1 */
  }
}

void HAL_RTC_MspDeInit(RTC_HandleTypeDef* rtcHandle)
{

  if(rtcHandle->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspDeInit 0 */

  /* USER CODE END RTC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_RTC_DISABLE();
  /* USER CODE BEGIN RTC_MspDeInit 1 */

  /* USER CODE END RTC_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
