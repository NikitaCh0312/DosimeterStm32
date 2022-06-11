#include "PumpInit.h"
#include "main.h"
#include "tim.h"

A4988Driver_t pumpDriver = {0};
A4988Conf_t A4988Conf;

uint32_t numSteps;      // stores the number of steps
PUMP_STATUS_t status;   // status work pump

A4988Conf_t getA4988Conf()
{
  return A4988Conf;
}

A4988Driver_t* getPumpDriver()
{
  return &pumpDriver;
}

void setStatus (PUMP_STATUS_t _status)
{
  status = _status;
}

PUMP_STATUS_t getStatus ()
{
  return status;
}

static void stopTimPWM(void)
{
   HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_1);
}

static void startTimPWM(void)
{
  __HAL_TIM_SET_COUNTER(&htim2, 0);     // clear cnt
  HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_1);
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

static void setStepCnt(uint32_t steps)
{
  numSteps = steps;
}

static uint32_t getStepCnt()
{
  return numSteps;
}

static void setStepPeroid(uint32_t stepsUs)
{

  stepsUs/=2;
  
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 120;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = stepsUs;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  HAL_TIM_PWM_Init(&htim2);
  
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig);
  
  sConfigOC.OCMode = TIM_OCMODE_PWM2;
  sConfigOC.Pulse = stepsUs/2;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_LOW;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
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
    pumpDriver.stopTimPWM = &stopTimPWM;
    pumpDriver.startTimPWM = &startTimPWM;
    pumpDriver.setStepCnt = & setStepCnt;
    pumpDriver.getStepCnt = &getStepCnt;
    pumpDriver.setStepPeroid = &setStepPeroid;
    pumpDriver.getStatus = &getStatus;
    pumpDriver.setStatus = &setStatus;
    
    A4988Conf.resolution = FULL_STEP_RESOLUTION_TYPE;
    
    //enablePump(&pumpDriver, A4988Conf); // todo
    //HAL_Delay(100);
    
    //startTimPWM();
}
