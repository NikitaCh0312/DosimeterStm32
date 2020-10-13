#include "DisplayTask.h"
#include "LCD/LCD.h"

void DisplayTask::Execute()
{
    set_cursor_position(0, 3);
    set_text_eng("Text string 1");
    set_cursor_position(1, 3);
    set_text_eng("Text string 2");
    set_cursor_position(2, 3);
    set_text_eng("Text string 3");
    set_cursor_position(3, 3);
    set_text_eng("Text string 4");
    while(1)
    {
        
    }
}