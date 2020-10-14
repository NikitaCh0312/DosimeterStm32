#ifndef LCD_H_
#define LCD_H_

#include "stdint.h"



typedef struct
{
    void (*set_rs_pin)(uint8_t state);
    void (*set_rw_pin)(uint8_t state);
    void (*set_en_pin)(uint8_t state);
    void (*set_db0_pin)(uint8_t state);
    void (*set_db1_pin)(uint8_t state);
    void (*set_db2_pin)(uint8_t state);
    void (*set_db3_pin)(uint8_t state);
    void (*set_db4_pin)(uint8_t state);
    void (*set_db5_pin)(uint8_t state);
    void (*set_db6_pin)(uint8_t state);
    void (*set_db7_pin)(uint8_t state);
    void (*delay)(uint32_t msec);
}LCD1604Drv_t;

void init_lcd1604(LCD1604Drv_t drv);

void set_cursor_position(uint8_t row, uint8_t col);

void set_text_eng(char * str);

void set_symbols(uint8_t * symbols, uint32_t quantity);

void clear_display();
#endif