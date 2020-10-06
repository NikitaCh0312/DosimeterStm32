#include "Tasks/ButtonsTask.h"
#include "Tasks/DisplayTask.h"
#include "Tasks/EthernetTask.h"
#include "Tasks/RFIDTask.h"
#include "Tasks/MainLogicTask.h"


#include "modules/Kernel.h"

void startup()
{
    Kernel::get_instance()->init();
}