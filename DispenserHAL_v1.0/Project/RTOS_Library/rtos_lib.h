#ifndef RTOS_LIBRARY_H_
#define RTOS_LIBRARY_H_

extern void(*pfn_tick_hook_function)(void);
extern void(*pfn_malloc_failed_hook)(void);
extern void(*pfn_idle_hook)(void);
extern void(*pfn_stack_over_flow_hook)(void * tsk_handle, char * tsk_name);

#endif

