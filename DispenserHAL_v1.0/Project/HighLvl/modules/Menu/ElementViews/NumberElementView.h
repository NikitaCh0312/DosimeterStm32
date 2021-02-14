#ifndef NUMBER_ELEMENT_VIEW_H_
#define NUMBER_ELEMENT_VIEW_H_

#include "stddef.h"
#include "string.h"

#include "LCD/LCD.h"
#include "modules/Menu/ElementViews/IElementView.h"

#define NUMBER_ELEMENT_MAX_VALUE_LENGTH 10
#define NUMBER_ELEMENT_DEFAULT_VALUE_LENGTH 3

class NumberElementView:IElementView
{
public:
    NumberElementView(LcdPosition_t position,
                      uint32_t value,
                      uint32_t viewLength):IElementView(position)
    {
        _value = value;
        if (viewLength > NUMBER_ELEMENT_MAX_VALUE_LENGTH)
            _viewLength = NUMBER_ELEMENT_DEFAULT_VALUE_LENGTH;
        else
            _viewLength = viewLength;
        CreateFormatter();
    }
    virtual ~NumberElementView(){}
    
    void Draw()
    {
        set_cursor_position(position.row, position.column);
        char value[_viewLength + 1];
        sprintf(value, formatter, _value);
        set_text_eng((char*)value);
    }
    
    void Hide()
    {
        set_cursor_position(position.row, position.column);
        set_symbols(_viewLength, ' ');
    }
    
private:

    uint32_t _value;
    
    uint32_t _viewLength;
    
    char formatter[5];
    
    void CreateFormatter()
    {
        strcpy(formatter, "\"%0");
        char length[5];
        sprintf(length, "%d", _viewLength);
        strcat(formatter, length);
        strcat(formatter,"d");
    }
};


#endif