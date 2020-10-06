#include "stddef.h"
#include "rtos_lib.h"

void(*pfn_tick_hook_function)(void) = NULL;
void(*pfn_malloc_failed_hook)(void) = NULL;
void(*pfn_idle_hook)(void) = NULL;
void(*pfn_stack_over_flow_hook)(void * tsk_handle, char * tsk_name) = NULL;

void vApplicationTickHook()
{
    if (pfn_tick_hook_function != NULL)
      pfn_tick_hook_function();
}
void vApplicationMallocFailedHook()
{
    while(1)
    {
        if (pfn_malloc_failed_hook != NULL)
            pfn_malloc_failed_hook();
    }
}
void vApplicationIdleHook( void )
{
    while(1)
    {
        if (pfn_idle_hook != NULL)
            pfn_idle_hook();        
    }
}

void vApplicationStackOverflowHook(  void *  pxCurrentTCB, char * tsk_name )
{
    while(1)
    {
        if (pfn_stack_over_flow_hook != NULL)
            pfn_stack_over_flow_hook(pxCurrentTCB, tsk_name);
    }
}