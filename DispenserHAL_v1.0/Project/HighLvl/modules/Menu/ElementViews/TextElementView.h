#ifndef TEXT_ELEMENT_VIEW_H_
#define TEXT_ELEMENT_VIEW_H_

#include "stddef.h"
#include "string.h"
#include "stdint.h"

#include "LCD/LCD.h"
#include "modules/Menu/ElementViews/IElementView.h"

#define TEXT_ELEMENT_MAX_VALUE_LENGTH 10

class TextElementView:public IElementView
{
public:
    TextElementView(uint32_t row,
                    uint32_t column,
                    char * value)
    {
        _position.row = row;
        _position.column = column;
        _valueLength = strlen(value);
        if ( _valueLength > TEXT_ELEMENT_MAX_VALUE_LENGTH)
            strcpy(_value, "error");
        
        strcpy(_value, value);
    }
    
    TextElementView(LcdPosition_t position,
                    char * value):IElementView(position)
    {
        _valueLength = strlen(value);
        if ( _valueLength > TEXT_ELEMENT_MAX_VALUE_LENGTH)
            strcpy(_value, "error");
        
        strcpy(_value, value);
    }
    virtual ~TextElementView(){}
    
    void Draw()
    {
        set_cursor_position(_position.row, _position.column);
        set_text_eng((char*)_value);
    }
    
    void Hide()
    {
        set_cursor_position(_position.row, _position.column);
        for (int i = 0; i < _valueLength; i++)
          set_symbols((uint8_t*)" ", 1);
    }
    
private:
    
    char _value[TEXT_ELEMENT_MAX_VALUE_LENGTH];
    
    uint32_t _valueLength;

};


#endif