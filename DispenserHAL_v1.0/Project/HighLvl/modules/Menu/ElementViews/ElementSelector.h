#ifndef ELEMENT_SELECTOR_H_
#define ELEMENT_SELECTOR_H_

#include "stddef.h"
#include "string.h"
#include "stdint.h"

#include "LCD/LCD.h"
#include "modules/Menu/ElementViews/IElementView.h"

#define TEXT_ELEMENT_MAX_VALUE_LENGTH 10

extern uint32_t global_timer;

class ElementSelector
{
public:
    static ElementSelector * GetInstance()
    {
        if (_instance == NULL)
            _instance = new ElementSelector();
        return _instance;
    }
    virtual ~ElementSelector(){}
    
    void DrawSelectedElement()
    {
        if (_selectedElement != NULL && global_timer - _blinkingTimer > _blinkPeriod)
        {
            _blinkingTimer = global_timer;
            if (_blinkState)
            {
                _blinkState = false;
                _selectedElement->Draw();
            }
            else
            {
                _blinkState = true;
                _selectedElement->Hide();
            }
        }

        if (_needUpdatePrevious && _previousSelectedElement != NULL)
            _previousSelectedElement->Draw();
    }
    
    void SetSelectedElement(IElementView * selectedElement)
    {
        _previousSelectedElement = _selectedElement;
        _selectedElement = selectedElement;
        _needUpdatePrevious = true;
    }

    void SetBlinkPeriod(uint32_t period)
    {
        _blinkPeriod = period;
    }
    
private:
    static ElementSelector * _instance;
    ElementSelector()
    {
        _selectedElement = NULL;
        _previousSelectedElement = NULL;
        _needUpdatePrevious = false;
    }
    
    IElementView * _selectedElement;
    
    IElementView * _previousSelectedElement;
    
    bool _needUpdatePrevious;
    
    bool _blinkState;
    
    uint32_t _blinkingTimer;    
    
    uint32_t _blinkPeriod;
};


#endif