/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON1_Pin GPIO_PIN_0
#define BUTTON1_GPIO_Port GPIOC
#define BUTTON2_Pin GPIO_PIN_1
#define BUTTON2_GPIO_Port GPIOC
#define BUTTON3_Pin GPIO_PIN_2
#define BUTTON3_GPIO_Port GPIOC
#define BUTTON4_Pin GPIO_PIN_3
#define BUTTON4_GPIO_Port GPIOC
#define STEPPER_SW_STEP_Pin GPIO_PIN_0
#define STEPPER_SW_STEP_GPIO_Port GPIOA
#define STEPPER_MS1_Pin GPIO_PIN_1
#define STEPPER_MS1_GPIO_Port GPIOA
#define STEPPER_MS2_Pin GPIO_PIN_2
#define STEPPER_MS2_GPIO_Port GPIOA
#define STEPPER_MS3_Pin GPIO_PIN_3
#define STEPPER_MS3_GPIO_Port GPIOA
#define W55_SCK_SPI_Pin GPIO_PIN_5
#define W55_SCK_SPI_GPIO_Port GPIOA
#define W55_MISO_SPI_Pin GPIO_PIN_6
#define W55_MISO_SPI_GPIO_Port GPIOA
#define W55_MOSI_SPI_Pin GPIO_PIN_7
#define W55_MOSI_SPI_GPIO_Port GPIOA
#define W55_CS_SPI_Pin GPIO_PIN_4
#define W55_CS_SPI_GPIO_Port GPIOC
#define STEPPER_SW_ENABLE_Pin GPIO_PIN_1
#define STEPPER_SW_ENABLE_GPIO_Port GPIOB
#define DISPLAY_D4_Pin GPIO_PIN_10
#define DISPLAY_D4_GPIO_Port GPIOB
#define DISPLAY_D5_Pin GPIO_PIN_11
#define DISPLAY_D5_GPIO_Port GPIOB
#define DISPLAY_D6_Pin GPIO_PIN_12
#define DISPLAY_D6_GPIO_Port GPIOB
#define DISPLAY_D7_Pin GPIO_PIN_13
#define DISPLAY_D7_GPIO_Port GPIOB
#define DISPLAY_RS_Pin GPIO_PIN_14
#define DISPLAY_RS_GPIO_Port GPIOB
#define DISPLAY_ES_Pin GPIO_PIN_15
#define DISPLAY_ES_GPIO_Port GPIOB
#define RFID_DATA0_Pin GPIO_PIN_6
#define RFID_DATA0_GPIO_Port GPIOC
#define RFID_DATA0_EXTI_IRQn EXTI9_5_IRQn
#define RFID_DATA1_Pin GPIO_PIN_7
#define RFID_DATA1_GPIO_Port GPIOC
#define RFID_DATA1_EXTI_IRQn EXTI9_5_IRQn
#define VALVE_Pin GPIO_PIN_8
#define VALVE_GPIO_Port GPIOC
#define SENSOR_DMRV_Pin GPIO_PIN_9
#define SENSOR_DMRV_GPIO_Port GPIOC
#define SENSOR_DMRV_EXTI_IRQn EXTI9_5_IRQn
#define SENSOR_DMRK_Pin GPIO_PIN_8
#define SENSOR_DMRK_GPIO_Port GPIOA
#define SENSOR_DMRK_EXTI_IRQn EXTI9_5_IRQn
#define SNSOR_LEVEL_Pin GPIO_PIN_9
#define SNSOR_LEVEL_GPIO_Port GPIOA
#define FLASH_SCK_SPI_Pin GPIO_PIN_10
#define FLASH_SCK_SPI_GPIO_Port GPIOC
#define FLASH_MISO_SPI_Pin GPIO_PIN_11
#define FLASH_MISO_SPI_GPIO_Port GPIOC
#define FLASH_MOSI_SPI_Pin GPIO_PIN_12
#define FLASH_MOSI_SPI_GPIO_Port GPIOC
#define FLASH_CS_SPI_Pin GPIO_PIN_2
#define FLASH_CS_SPI_GPIO_Port GPIOD
#define STEPPER_DIR_Pin GPIO_PIN_9
#define STEPPER_DIR_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
