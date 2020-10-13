#include "main.h"

#include "Tasks/ButtonsTask.h"
#include "Tasks/DisplayTask.h"
#include "Tasks/EthernetTask.h"
#include "Tasks/RFIDTask.h"
#include "Tasks/MainLogicTask.h"

#include "BoardInit.h"

#include "modules/Kernel.h"

#include "RTOS/Thread.h"

#include "rtos_lib.h"

ButtonsTask * buttonsTask = new ButtonsTask((char*)"ButtonsTask", configMINIMAL_STACK_SIZE * 2, 1);
DisplayTask * displayTask = new DisplayTask((char*)"DisplayTask", configMINIMAL_STACK_SIZE * 2, 1);
EthernetTask * ethernetTask = new EthernetTask((char*)"EthernetTask", configMINIMAL_STACK_SIZE * 2, 1);
MainLogicTask * mainLogicTask = new MainLogicTask((char*)"MainLogicTask", configMINIMAL_STACK_SIZE * 2, 1);
RfidTask * rfidTask = new RfidTask((char*)"RfidTask", configMINIMAL_STACK_SIZE * 2, 1);


uint32_t global_timer = 0;
static void tick_hook(void)
{
    global_timer++;
}
static void malloc_failed_hook()
{
    while(1);
}
static void stack_overflow_hook(void * tsk_handle, char * tsk_name)
{
    while(1);
}
static void iddle_hook()
{
    while(1);
}
void stack_over_flow_hook(void * tsk_handle, char * tsk_name)
{
    while(1);
}


//#include "LCD/LCD_Init.h"
//#include "LCD/LCD.h"
void startup()
{
    //low level initialization
    boardInit();
    //LCD_Init();


    pfn_tick_hook_function = &tick_hook;
    pfn_malloc_failed_hook = &malloc_failed_hook;
    pfn_idle_hook = &iddle_hook;
    pfn_stack_over_flow_hook = &stack_overflow_hook;
    
    Kernel::get_instance()->init();
    RTOS::Thread::start_scheduler();
}