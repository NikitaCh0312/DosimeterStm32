#include "ButtonsTask.h"
#include "Buttons\Buttons.h"

void ButtonsTask::Execute()
{
    ButtonsInit(Buttons);
    
    while(1)
    {
       scanButtonsState(Buttons); 
    }
}