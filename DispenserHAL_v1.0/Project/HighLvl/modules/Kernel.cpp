#include "Kernel.h"

#include "RTOS/Thread.h"
#include "RTOS/RTOSManager.h"

Kernel* Kernel::instance = NULL;


RTOS::ThreadHandle debugThread;
RTOS::ThreadHandle buttonsThread;
RTOS::ThreadHandle displayThread;
RTOS::ThreadHandle mainLogicThread;


void debugFunc(void * pvParameters)
{
    Kernel::get_instance()->debugTaskRun();
}


void Kernel::init()
{
    int rc = 0;
    rc = RTOS::Thread::create_thread(debugFunc, &debugThread, 2, 1); 
    if (rc != 0){
      while(1);
    }
    
    RTOS::Thread::start_thread(&debugThread);
    
    //запуск RTOS
    RTOS::Thread::start_scheduler();
}



void Kernel::debugTaskRun()
{
    while(1)
    {
        
    }
}