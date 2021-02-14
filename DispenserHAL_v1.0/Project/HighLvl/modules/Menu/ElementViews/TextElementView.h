#ifndef TEXT_ELEMENT_VIEW_H_
#define TEXT_ELEMENT_VIEW_H_

#include "stddef.h"
#include "string.h"
#include "stdint.h"

#include "LCD/LCD.h"
#include "modules/Menu/ElementViews/IElementView.h"

#define TEXT_ELEMENT_MAX_VALUE_LENGTH 10

class TextElementView:IElementView
{
public:
    TextElementView(LcdPosition_t position,
                    char * value):IElementView(position)
    {
        _valueLength = strlen(value);
        if ( > TEXT_ELEMENT_MAX_VALUE_LENGTH)
            strcpy(_value, "error");
        
        strcpy(_value, value);
    }
    virtual ~TextElementView(){}
    
    void Draw()
    {
        set_cursor_position(position.row, position.column);
        set_text_eng((char*)_value);
    }
    
    void Hide()
    {
        set_cursor_position(position.row, position.column);
        set_symbols(_viewLength, ' ');
    }
    
private:
    
    char _value[TEXT_ELEMENT_MAX_VALUE_LENGTH];
    
    uint32_t _valueLength;

};


#endif