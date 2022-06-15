#ifndef TIMEDATE_VIEW_MENU_NODE_H_
#define TIMEDATE_VIEW_MENU_NODE_H_

#include "stddef.h"
#include "string.h"

#include "LCD/LCD.h"

#include "ViewMenuNode.h"
#include "Menu.h"
#include "modules/Configuration.h"
#include "modules/Menu/ElementViews/ElementSelector.h"
#include "modules/Menu/ElementViews/IElementView.h"
#include "modules/Menu/ElementViews/NumberElementView.h"
#include "modules/Menu/ElementViews/TextElementView.h"
#include "RTC/RTC_drv.h"


class TimeDateViewMenuNode: public ViewMenuNode
{
public:
    TimeDateViewMenuNode(Menu * menuCtx,
                         char * name) : ViewMenuNode(menuCtx, name)
    {
        _elementSelector = ElementSelector::GetInstance();
        _elementSelector->SetBlinkPeriod(VIEW_BLINK_TIME);
        _selectedElement = NULL;
        _viewState = VIEW_ELEMENT_STATE;
    }
    virtual ~TimeDateViewMenuNode(){}
    
    void Draw()
    {
        if (!_isInited)
        {
            configureViewElements();
            
            clear_display();
            set_cursor_position(0, 0);
            set_text_eng((char*)"SYSTEM TIME");
            set_cursor_position(1, 0);
            set_text_eng((char*)"TIME:00:00:00       ");
            set_cursor_position(2, 0);
            set_text_eng((char*)"DATE:00.00.2000     ");
            _seconds.Draw();
            _minutes.Draw();
            _hours.Draw();
            _day.Draw();
            _month.Draw();
            _year.Draw();
            _ok.Draw();
            _selectedElement = &_hours;
            _elementSelector->SetSelectedElement(_selectedElement);
            _elementSelector->SetBlinkPeriod(VIEW_BLINK_TIME);
            _isInited = true;
        }
        _elementSelector->DrawSelectedElement();
    }
        
    void Cancel()
    {
        _context->SetCurrentNode(_parent);
        _isInited = false;
        _elementSelector->SetBlinkPeriod(VIEW_BLINK_TIME);
        _selectedElement = NULL;
        _viewState = VIEW_ELEMENT_STATE;
        _elementSelector->Clean();
    }
    
    void Enter()
    {
        if (isOkElement())
        {
            RtcDateTime_t dateTime;
            dateTime.Day = 255;//_day.GetValue();
            dateTime.Month = 255;//_month.GetValue();
            dateTime.Year = 255;//_year.GetValue();
            dateTime.Hours = _hours.GetValue();
            dateTime.Minutes = _minutes.GetValue();
            dateTime.Seconds = _seconds.GetValue();
            RtcSetDateTime(&dateTime);
            Cancel();
            return;
        }
        
         if (_viewState == VIEW_ELEMENT_STATE)
         {
             _viewState = EDIT_ELEMENT_STATE;
             _elementSelector->SetBlinkPeriod(EDIT_BLINK_TIME);
         }
         else if (_viewState == EDIT_ELEMENT_STATE)
         {
             _viewState = VIEW_ELEMENT_STATE;
             _elementSelector->SetBlinkPeriod(VIEW_BLINK_TIME);
         }
    }
    
    void Up()
    {
         if (_viewState == VIEW_ELEMENT_STATE)
         {
            _selectedElement = _selectedElement->GetNext();
            _elementSelector->SetSelectedElement(_selectedElement);
         }
         
         if (isOkElement())
             return;
         
         if (_viewState == EDIT_ELEMENT_STATE)
            ((NumberElementView*)_selectedElement)->IncreaseValue();
    }
    
    void Down()
    {
         if (_viewState == VIEW_ELEMENT_STATE)
         {
            _selectedElement = _selectedElement->GetPrevious();
            _elementSelector->SetSelectedElement(_selectedElement);
         }
         
         if (isOkElement())
             return;
         
         if (_viewState == EDIT_ELEMENT_STATE)
            ((NumberElementView*)_selectedElement)->DecreaseValue();         
    }
    
private:
    
    ElementSelector * _elementSelector;
    
    const uint32_t VIEW_BLINK_TIME = 500;
    const uint32_t EDIT_BLINK_TIME = 200;
    
    const uint32_t TIME_DISPLAY_ROW = 1;
    const uint32_t DATE_DISPLAY_ROW = 2;
    
    const uint32_t FIRST_DISPLAY_COLUMN = 5;
    const uint32_t SECOND_DISPLAY_COLUMN = 8;
    const uint32_t THIRD_DISPLAY_COLUMN = 11;
    
    ELEMENT_VIEW_STATE_t _viewState;
    
    NumberElementView _hours = NumberElementView(TIME_DISPLAY_ROW,
                                                 FIRST_DISPLAY_COLUMN,
                                                 0, 2);
    NumberElementView _minutes = NumberElementView(TIME_DISPLAY_ROW,
                                                   SECOND_DISPLAY_COLUMN,
                                                   0, 2);
    NumberElementView _seconds = NumberElementView(TIME_DISPLAY_ROW,
                                                   THIRD_DISPLAY_COLUMN,
                                                   0, 2);

    NumberElementView _day = NumberElementView(DATE_DISPLAY_ROW,
                                               FIRST_DISPLAY_COLUMN,
                                               0, 2);
    NumberElementView _month = NumberElementView(DATE_DISPLAY_ROW,
                                                 SECOND_DISPLAY_COLUMN,
                                                 0, 2);
    NumberElementView _year = NumberElementView(DATE_DISPLAY_ROW,
                                                THIRD_DISPLAY_COLUMN,
                                                0, 4);

    TextElementView _ok = TextElementView(3, 9, "OK");
    
    IElementView * _selectedElement;
    
    void configureViewElements()
    {
        _hours.SetPrevious(&_ok);
        _hours.SetNext(&_minutes);
        _minutes.SetPrevious(&_hours);
        _minutes.SetNext(&_seconds);
        _seconds.SetPrevious(&_minutes);
        _seconds.SetNext(&_day);

        _day.SetPrevious(&_hours);
        _day.SetNext(&_month);
        _month.SetPrevious(&_day);
        _month.SetNext(&_year);
        _year.SetPrevious(&_month);
        _year.SetNext(&_ok);
        
        _ok.SetPrevious(&_year);
        _ok.SetNext(&_hours);
        
        _hours.SetValue(15);
        _minutes.SetValue(12);
        _seconds.SetValue(25);

        _day.SetValue(3);
        _month.SetValue(2);
        _year.SetValue(2021);
    }
    
    bool isOkElement()
    {
        if (_selectedElement == &_ok)
            return true;
        return false;
    }
};


#endif