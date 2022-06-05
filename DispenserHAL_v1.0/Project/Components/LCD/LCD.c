#include "LCD.h"

#include "string.h"
#include "FontRusConverter.h"

#define USE_4_BIT_MODE
static LCD1604Drv_t driver;


static void pulse_lcd()
{
    driver.set_en_pin(0);
    driver.delay(300);
    driver.set_en_pin(1);
    driver.delay(300);
    driver.set_en_pin(0);
}

#ifdef USE_4_BIT_MODE
static void send_byte(uint8_t byte, uint8_t is_data)
{
    //rs pin
    if (is_data == 1)
        driver.set_rs_pin(1);
    else
        driver.set_rs_pin(0);
    
    
    //data bits
    if ( (byte & 0x10) != 0x00 )
        driver.set_db4_pin(1);
    else
        driver.set_db4_pin(0);
        
    if ( (byte & 0x20) != 0x00 )
        driver.set_db5_pin(1);
    else
        driver.set_db5_pin(0);
        
    if ( (byte & 0x40) != 0x00 )
        driver.set_db6_pin(1);
    else
        driver.set_db6_pin(0);
        
    if ( (byte & 0x80) != 0x00 )
        driver.set_db7_pin(1);
    else
        driver.set_db7_pin(0);
    
    //strobe en pin
    pulse_lcd();
    
    uint8_t byte_to_send = ( (byte & 0x0F) << 4 );
    if ( (byte_to_send & 0x10) != 0x00 )
        driver.set_db4_pin(1);
    else
        driver.set_db4_pin(0);
        
    if ( (byte_to_send & 0x20) != 0x00 )
        driver.set_db5_pin(1);
    else
        driver.set_db5_pin(0);
        
    if ( (byte_to_send & 0x40) != 0x00 )
        driver.set_db6_pin(1);
    else
        driver.set_db6_pin(0);
        
    if ( (byte_to_send & 0x80) != 0x00 )
        driver.set_db7_pin(1);
    else
        driver.set_db7_pin(0);
    //strobe en pin
    pulse_lcd();
}
#else
static void send_byte(uint8_t byte, uint8_t is_data)
{
    //rs pin
    if (is_data == 1)
        driver.set_rs_pin(1);
    else
        driver.set_rs_pin(0);
    
    
    //data bits
    if ( (byte & 0x01) != 0x00 )
        driver.set_db0_pin(1);
    else
        driver.set_db0_pin(0);
    
    if ( (byte & 0x02) != 0x00 )
        driver.set_db1_pin(1);
    else
        driver.set_db1_pin(0);
    
    if ( (byte & 0x04) != 0x00 )
        driver.set_db2_pin(1);
    else
        driver.set_db2_pin(0);
    
    if ( (byte & 0x08) != 0x00 )
        driver.set_db3_pin(1);
    else
        driver.set_db3_pin(0);
    
    if ( (byte & 0x10) != 0x00 )
        driver.set_db4_pin(1);
    else
        driver.set_db4_pin(0);
        
    if ( (byte & 0x20) != 0x00 )
        driver.set_db5_pin(1);
    else
        driver.set_db5_pin(0);
        
    if ( (byte & 0x40) != 0x00 )
        driver.set_db6_pin(1);
    else
        driver.set_db6_pin(0);
        
    if ( (byte & 0x80) != 0x00 )
        driver.set_db7_pin(1);
    else
        driver.set_db7_pin(0);
    
    //strobe en pin
    pulse_lcd();
}
#endif

void init_lcd1604(LCD1604Drv_t drv)
{
    driver = drv;
    driver.set_rw_pin(0);
    
    driver.set_db0_pin(0);
    driver.set_db1_pin(0);
    driver.set_db2_pin(0);
    driver.set_db3_pin(0);
    driver.set_db4_pin(0);
    driver.set_db5_pin(0);
    driver.set_db6_pin(0);
    driver.set_db7_pin(0);
    
    driver.delay(1000);
#ifdef USE_4_BIT_MODE
    send_byte(0x33, 0);
    driver.delay(10);
    send_byte(0x32, 0);
    driver.delay(10);
    
    //интерфейс - 4бита, размер символа 5х8
    send_byte(0x28, 0);
    //отключаем положение курсора
    send_byte(0x0C, 0);
    //инкремент адреса DDRAM, сдвиг дисплея выключен
    send_byte(0x06, 0);
    //очистка дисплея
    send_byte(0x01, 0);
#else
    //8 bit
    send_byte(0x38, 0);
    send_byte(0x0F, 0);
    send_byte(0x06, 0);
#endif
    
    driver.delay(100);
}

void set_cursor_position(uint8_t row, uint8_t col)
{
   if (row > 3 || col > 19)
       return;
   uint8_t lineOffsets[4] = { 0x00, 0x40, 0x14, 0x54 };
   uint8_t address;
   address = lineOffsets[row] + col;
   send_byte(0x80 | address, 0);
}

void set_text_eng(char * str)
{
    uint32_t bytes = strlen(str);
    for ( uint32_t i = 0; i < bytes; i++ )
    {
        send_byte ( str[i], 1 );
    }
}

void set_text_rus(char * str)
{
    uint8_t rusSymbol;
    uint32_t bytes = strlen(str);
    for ( uint32_t i = 0; i < bytes; i++ )
    {
        bool result = TryGetLcdSymbol(str[i], &rusSymbol);
        if (result)
          send_byte ( rusSymbol, 1 );
        else
          send_byte ( str[i], 1 );
    }
}

void set_symbols(uint8_t * symbols, uint32_t quantity)
{
    for ( uint32_t i = 0; i < quantity; i++ )
    {
        send_byte ( symbols[i], 1 );
    }
}

void clear_display()
{
    send_byte(0x01, 0);
}