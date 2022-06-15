#include "LCD_Init.h"
#include "LCD.h"
#include "main.h"

static void set_rs_pin(uint8_t state)
{
    if (state)
        HAL_GPIO_WritePin(DISPLAY_RS_GPIO_Port, DISPLAY_RS_Pin, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(DISPLAY_RS_GPIO_Port, DISPLAY_RS_Pin, GPIO_PIN_RESET);
}
static void set_rw_pin(uint8_t state)
{

}
static void set_en_pin(uint8_t state)
{
    if (state)
        HAL_GPIO_WritePin(DISPLAY_ES_GPIO_Port, DISPLAY_ES_Pin, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(DISPLAY_ES_GPIO_Port, DISPLAY_ES_Pin, GPIO_PIN_RESET);
}
static void set_db0_pin(uint8_t state)
{

}
static void set_db1_pin(uint8_t state)
{

}
static void set_db2_pin(uint8_t state)
{

}
static void set_db3_pin(uint8_t state)
{

}
static void set_db4_pin(uint8_t state)
{
    if (state)
        HAL_GPIO_WritePin(DISPLAY_D4_GPIO_Port, DISPLAY_D4_Pin, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(DISPLAY_D4_GPIO_Port, DISPLAY_D4_Pin, GPIO_PIN_RESET);
}
static void set_db5_pin(uint8_t state)
{
    if (state)
        HAL_GPIO_WritePin(DISPLAY_D5_GPIO_Port, DISPLAY_D5_Pin, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(DISPLAY_D5_GPIO_Port, DISPLAY_D5_Pin, GPIO_PIN_RESET);
}
static void set_db6_pin(uint8_t state)
{
    if (state)
        HAL_GPIO_WritePin(DISPLAY_D6_GPIO_Port, DISPLAY_D6_Pin, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(DISPLAY_D6_GPIO_Port, DISPLAY_D6_Pin, GPIO_PIN_RESET);
}
static void set_db7_pin(uint8_t state)
{
    if (state)
        HAL_GPIO_WritePin(DISPLAY_D7_GPIO_Port, DISPLAY_D7_Pin, GPIO_PIN_SET);
    else
        HAL_GPIO_WritePin(DISPLAY_D7_GPIO_Port, DISPLAY_D7_Pin, GPIO_PIN_RESET);
}
static void delay(uint32_t msec)
{
    for (int i = 0; i < 30 * msec; i++);
    //HAL_Delay(1);
}


void LCD_Init()
{
    LCD1604Drv_t drv;
    drv.set_rs_pin = &set_rs_pin;
    drv.set_rw_pin = &set_rw_pin;
    drv.set_en_pin = &set_en_pin;
    drv.set_db0_pin = &set_db0_pin;
    drv.set_db1_pin = &set_db1_pin;
    drv.set_db2_pin = &set_db2_pin;
    drv.set_db3_pin = &set_db3_pin;
    drv.set_db4_pin = &set_db4_pin;
    drv.set_db5_pin = &set_db5_pin;
    drv.set_db6_pin = &set_db6_pin;
    drv.set_db7_pin = &set_db7_pin;
    drv.delay = &delay;
      
    init_lcd1604(drv);
}