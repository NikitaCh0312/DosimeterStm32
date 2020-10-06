#include "Tasks/ButtonsTask.h"
#include "Tasks/DisplayTask.h"
#include "Tasks/EthernetTask.h"
#include "Tasks/RFIDTask.h"
#include "Tasks/MainLogicTask.h"


#include "modules/Kernel.h"

#include "RTOS/Thread.h"


ButtonsTask * buttonsTask = new ButtonsTask((char*)"ButtonsTask", configMINIMAL_STACK_SIZE * 2, 1);
DisplayTask * displayTask = new DisplayTask((char*)"DisplayTask", configMINIMAL_STACK_SIZE * 2, 1);
EthernetTask * ethernetTask = new EthernetTask((char*)"EthernetTask", configMINIMAL_STACK_SIZE * 2, 1);


void startup()
{
    Kernel::get_instance()->init();
    RTOS::Thread::start_scheduler();
}