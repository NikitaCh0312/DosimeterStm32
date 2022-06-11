#ifndef NETWORK_VIEW_MENU_NODE_H_
#define NETWORK_VIEW_MENU_NODE_H_

#include "stddef.h"
#include "string.h"
#include "stdio.h"

#include "LCD/LCD.h"

#include "ViewMenuNode.h"
#include "Menu.h"
#include "modules/Configuration.h"
#include "modules/Menu/ElementViews/ElementSelector.h"
#include "modules/Menu/ElementViews/IElementView.h"
#include "modules/Menu/ElementViews/NumberElementView.h"
#include "modules/Menu/ElementViews/TextElementView.h"

extern uint32_t global_timer;

typedef enum
{
    VIEW_ELEMENT_STATE,
    EDIT_ELEMENT_STATE,
}ELEMENT_VIEW_STATE_t;

class NetworkViewMenuNode: public ViewMenuNode
{
public:
    NetworkViewMenuNode(Menu * menuCtx,
                        char * name): ViewMenuNode(menuCtx, name)
    {
        _elementSelector = ElementSelector::GetInstance();
        _elementSelector->SetBlinkPeriod(VIEW_BLINK_TIME);
        _selectedElement = NULL;
        _viewState = VIEW_ELEMENT_STATE;
    }
    
    virtual ~NetworkViewMenuNode(){}
    
    void Draw()
    {
        if (!_isInited)
        {
            configureViewElements(Configuration::GetInstance()->GetIpAddr(),
                                  Configuration::GetInstance()->GetIpMask());
            
            clear_display();
            set_cursor_position(0, 0);
            set_text_eng((char*)"NETWORK SETTINGS    ");
            set_cursor_position(1, 0);
            set_text_eng((char*)"IP:  000.000.000.000");
            set_cursor_position(2, 0);
            set_text_eng((char*)"MASK:000.000.000.000");
            _addr1.Draw();
            _addr2.Draw();
            _addr3.Draw();
            _addr4.Draw();
            _mask1.Draw();
            _mask2.Draw();
            _mask3.Draw();
            _mask4.Draw();
            _ok.Draw();
            _selectedElement = &_addr1;
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
            //...
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
    
    ELEMENT_VIEW_STATE_t _viewState;
    
    NumberElementView _addr1 = NumberElementView(1, 5, 0, 3);
    NumberElementView _addr2 = NumberElementView(1, 9, 0, 3);
    NumberElementView _addr3 = NumberElementView(1, 13, 0, 3);
    NumberElementView _addr4 = NumberElementView(1, 17, 0, 3);
    
    NumberElementView _mask1 = NumberElementView(2, 5, 0, 3);
    NumberElementView _mask2 = NumberElementView(2, 9, 0, 3);
    NumberElementView _mask3 = NumberElementView(2, 13, 0, 3);
    NumberElementView _mask4 = NumberElementView(2, 17, 0, 3);
    
    TextElementView _ok = TextElementView(3, 9, "OK");
    
    IElementView * _selectedElement;
    
    void configureViewElements(IpAddr_t ip_addr, Mask_t ip_mask)
    {
        _addr1.SetPrevious(&_ok);
        _addr1.SetNext(&_addr2);
        _addr2.SetPrevious(&_addr1);
        _addr2.SetNext(&_addr3);
        _addr3.SetPrevious(&_addr2);
        _addr3.SetNext(&_addr4);
        _addr4.SetPrevious(&_addr3);
        _addr4.SetNext(&_mask1);

        _mask1.SetPrevious(&_addr4);
        _mask1.SetNext(&_mask2);
        _mask2.SetPrevious(&_mask1);
        _mask2.SetNext(&_mask3);
        _mask3.SetPrevious(&_mask2);
        _mask3.SetNext(&_mask4);
        _mask4.SetPrevious(&_mask3);
        _mask4.SetNext(&_ok);
        
        _ok.SetPrevious(&_mask4);
        _ok.SetNext(&_addr1);
        
        _addr1.SetValue(ip_addr.addr_1);
        _addr2.SetValue(ip_addr.addr_2);
        _addr3.SetValue(ip_addr.addr_3);
        _addr4.SetValue(ip_addr.addr_4);
        
        _mask1.SetValue(ip_mask.mask_1);
        _mask2.SetValue(ip_mask.mask_2);
        _mask3.SetValue(ip_mask.mask_3);
        _mask4.SetValue(ip_mask.mask_4);
    }
    
    bool isOkElement()
    {
        if (_selectedElement == &_ok)
            return true;
        return false;
    }
};


#endif