#include "PumpInit.h"
#include "main.h"
#include "tim.h"

A4988Driver_t pumpDriver;


static void setPwmFrequencyHz(uint32_t frequency)
{
    if (frequency == 0)
        HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
    else
    {
        TIM_OC_InitTypeDef sConfigOC = {0};
        sConfigOC.OCMode = TIM_OCMODE_PWM1;
        sConfigOC.Pulse = 500;
        sConfigOC.OCPolarity = TIM_OCPOLARITY_LOW;
        sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
        HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
        HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    }
}
static void setDirPin(uint32_t state)
{
    if (state == 1)
        HAL_GPIO_WritePin(STEPPER_DIR_GPIO_Port, STEPPER_DIR_Pin,
                          GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(STEPPER_DIR_GPIO_Port, STEPPER_DIR_Pin,
                          GPIO_PIN_RESET);
}
static void setMs1Pin(uint32_t state)
{
    if (state == 1)
        HAL_GPIO_WritePin(STEPPER_MS1_GPIO_Port, STEPPER_MS1_Pin,
                          GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(STEPPER_MS1_GPIO_Port, STEPPER_MS1_Pin,
                          GPIO_PIN_RESET);
}
static void setMs2Pin(uint32_t state)
{
    if (state == 1)
        HAL_GPIO_WritePin(STEPPER_MS2_GPIO_Port, STEPPER_MS2_Pin,
                          GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(STEPPER_MS2_GPIO_Port, STEPPER_MS2_Pin,
                          GPIO_PIN_RESET);
}
static void setMs3Pin(uint32_t state)
{
    if (state == 1)
        HAL_GPIO_WritePin(STEPPER_MS3_GPIO_Port, STEPPER_MS3_Pin,
                          GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(STEPPER_MS3_GPIO_Port, STEPPER_MS3_Pin,
                          GPIO_PIN_RESET);
}
static void setEnablePin(uint32_t state)
{
    if (state == 1)
        HAL_GPIO_WritePin(STEPPER_SW_ENABLE_GPIO_Port, STEPPER_SW_ENABLE_Pin,
                          GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(STEPPER_SW_ENABLE_GPIO_Port, STEPPER_SW_ENABLE_Pin,
                          GPIO_PIN_RESET);
}
static void delay_msec(uint32_t msec)
{
    HAL_Delay(msec);
}

void initPumpDriver()
{
    pumpDriver.setDirPin = &setDirPin;
    pumpDriver.setEnablePin = &setEnablePin;
    pumpDriver.setMs1Pin = &setMs1Pin;
    pumpDriver.setMs2Pin = &setMs2Pin;
    pumpDriver.setMs3Pin = &setMs3Pin;
    pumpDriver.delay_msec = &delay_msec;
    pumpDriver.setPwmFrequencyHz = &setPwmFrequencyHz;
    
    A4988Conf_t A4988Conf;
    A4988Conf.resolution = QUARTER_STEP_RESOLUTION_TYPE;
    initPump(&pumpDriver, A4988Conf);
    HAL_Delay(100);
}