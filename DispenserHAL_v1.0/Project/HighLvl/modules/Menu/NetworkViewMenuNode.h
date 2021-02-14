#ifndef NETWORK_VIEW_MENU_NODE_H_
#define NETWORK_VIEW_MENU_NODE_H_

#include "stddef.h"
#include "string.h"
#include "stdio.h"

#include "LCD/LCD.h"

#include "ViewMenuNode.h"
#include "Menu.h"
#include "modules/Configuration.h"

extern uint32_t global_timer;

typedef enum
{
    VIEW_ELEMENT_STATE,
    EDIT_ELEMENT_STATE,
}ELEMENT_VIEW_STATE_t;

struct ElementView_t
{
    struct ElementView_t * next;
    struct ElementView_t * prev;
    uint8_t x;
    uint8_t y;
    uint8_t value;
    ELEMENT_VIEW_STATE_t state;
};


class NetworkViewMenuNode: public ViewMenuNode
{
public:
    NetworkViewMenuNode(Menu * menuCtx,
                        char * name): ViewMenuNode(menuCtx, name)
    {
        IP_Addr = Configuration::GetInstance()->GetIpAddr();
        IP_Mask = Configuration::GetInstance()->GetIpMask();
        
        _isInited = 0;
        _needUpdatePrevious = 0;
        blinkingTimer = 0;
        configureViewElements(IP_Addr, IP_Mask);
    }
    virtual ~NetworkViewMenuNode(){}
    
    void Draw()
    {
        if (_isInited == 0)
        {
            configureViewElements(IP_Addr, IP_Mask);
            
            static char debugAddt[40];
            sprintf(debugAddt, "IP:  %03d.%03d.%03d.%03d", IP_Addr.addr_1,IP_Addr.addr_2,IP_Addr.addr_3,IP_Addr.addr_4); 
            sprintf(_ip_mask_str, "MASK:%03d.%03d.%03d.%03d", IP_Mask.msk_1,IP_Mask.msk_2,IP_Mask.msk_3,IP_Mask.msk_4);
            
            set_cursor_position(0, 0);
            set_text_eng((char*)"NETWORK SETTINGS    ");
            set_cursor_position(1, 0);
            set_text_eng(debugAddt);
            set_cursor_position(2, 0);
            set_text_eng(_ip_mask_str);
            _prevSelectedElementView = NULL;
            _selectedElementView = &_addr1;
            _isInited = 1;
        }
        
        DrawSelectedElement();
        DrawPreviousSelectedElement();
    }
    
    void Cancel()
    {
        _isInited = 0;
        _context->SetCurrentNode(_parent);

    }
    void Enter()
    {
        if (_selectedElementView == &_ok)
        {
            //...
            Cancel();
            return;
        }
        
         if (_selectedElementView->state == VIEW_ELEMENT_STATE) _selectedElementView->state = EDIT_ELEMENT_STATE;
         else if (_selectedElementView->state == EDIT_ELEMENT_STATE) _selectedElementView->state = VIEW_ELEMENT_STATE;

    }
    void Up()
    {
        if (_selectedElementView->state == VIEW_ELEMENT_STATE)
        {
            _prevSelectedElementView = _selectedElementView;
            _selectedElementView = _selectedElementView->next;
            _needUpdatePrevious = 1;
        }
        if (_selectedElementView->state == EDIT_ELEMENT_STATE)
            _selectedElementView->value++;
         
    }
    void Down()
    {
         if (_selectedElementView->state == VIEW_ELEMENT_STATE)
         {
             _prevSelectedElementView = _selectedElementView;
            _selectedElementView = _selectedElementView->prev;
            _needUpdatePrevious = 1;
         }
         if (_selectedElementView->state == EDIT_ELEMENT_STATE)
            _selectedElementView->value--;         
    }
private:
    char _ip_addr_str[20];
    char _ip_mask_str[20];
    
    IP_ADDR_t IP_Addr;
    IP_MASK_t IP_Mask;
    
    const uint32_t VIEW_BLINK_TIME = 500;
    const uint32_t EDIT_BLINK_TIME = 200;
    
    int _isInited;
    int _needUpdatePrevious;
    int _blinkFlag;
    uint32_t blinkingTimer;
    
    struct ElementView_t _addr1;
    struct ElementView_t _addr2;
    struct ElementView_t _addr3;
    struct ElementView_t _addr4;
    
    struct ElementView_t _mask1;
    struct ElementView_t _mask2;
    struct ElementView_t _mask3;
    struct ElementView_t _mask4;
    
    struct ElementView_t _ok;
    
    ElementView_t * _selectedElementView;
    ElementView_t * _prevSelectedElementView;
    
    void configureViewElements(IP_ADDR_t ip_addr, IP_MASK_t ip_mask)
    {
        _addr1.prev = &_ok;
        _addr1.next = &_addr2;
        _addr1.x = 5;
        _addr1.y = 1;
        _addr1.value = ip_addr.addr_1;
        _addr1.state = VIEW_ELEMENT_STATE;
        
        _addr2.prev = &_addr1;
        _addr2.next = &_addr3;
        _addr2.x = 9;
        _addr2.y = 1;
        _addr2.value = ip_addr.addr_2;
        _addr2.state = VIEW_ELEMENT_STATE;
        
        _addr3.prev = &_addr2;
        _addr3.next = &_addr4;
        _addr3.x = 13;
        _addr3.y = 1;
        _addr3.value = ip_addr.addr_3;
        _addr3.state = VIEW_ELEMENT_STATE;
        
        _addr4.prev = &_addr3;
        _addr4.next = &_mask1;
        _addr4.x = 17;
        _addr4.y = 1;
        _addr4.value = ip_addr.addr_4;
        _addr4.state = VIEW_ELEMENT_STATE;
        
        
        _mask1.prev = &_addr4;
        _mask1.next = &_mask2;
        _mask1.x = 5;
        _mask1.y = 2;
        _mask1.value = ip_mask.msk_1;
        _mask1.state = VIEW_ELEMENT_STATE;
        
        _mask2.prev = &_mask1;
        _mask2.next = &_mask3;
        _mask2.x = 9;
        _mask2.y = 2;
        _mask2.value = ip_mask.msk_2;
        _mask2.state = VIEW_ELEMENT_STATE;
        
        _mask3.prev = &_mask2;
        _mask3.next = &_mask4;
        _mask3.x = 13;
        _mask3.y = 2;
        _mask3.value = ip_mask.msk_3;
        _mask3.state = VIEW_ELEMENT_STATE;
        
        _mask4.prev = &_mask3;
        _mask4.next = &_ok;
        _mask4.x = 17;
        _mask4.y = 2;
        _mask4.value = ip_mask.msk_4;
        _mask4.state = VIEW_ELEMENT_STATE;
        
        _ok.prev = &_mask4;
        _ok.next = &_addr1;
        _ok.x = 15;
        _ok.y = 3;
        _ok.value = ip_mask.msk_4;
        _ok.state = VIEW_ELEMENT_STATE;
    }
    
    void DrawSelectedElement()
    {
        uint32_t blinkTime = VIEW_BLINK_TIME;
        if (_selectedElementView->state == EDIT_ELEMENT_STATE)
            blinkTime = EDIT_BLINK_TIME;
        if (global_timer - blinkingTimer > blinkTime)
        {
            blinkingTimer = global_timer;            
            if (_blinkFlag)
            {
                _blinkFlag = 0;
                DrawElementView(_selectedElementView);
            }
            else
            {
                _blinkFlag = 1;
                set_cursor_position(_selectedElementView->y, _selectedElementView->x);
                set_text_eng((char*)"   ");
            }
        }
    }
    
    void DrawPreviousSelectedElement()
    {
        if (_needUpdatePrevious)
        {
            if (!isOkElement(_prevSelectedElementView))
                DrawElementView(_prevSelectedElementView);
            _needUpdatePrevious = 0;
        }
    }

    void DrawElementView(ElementView_t * element)
    {
        set_cursor_position(element->y, element->x);
        char value[5];
        if (isOkElement(element))
            strcpy(value, "OK");
         else
            sprintf(value, "%03d", element->value);
        set_text_eng((char*)value);
    }
    
    int isOkElement(ElementView_t * element)
    {
        if (_selectedElementView == &_ok)
            return 1;
        return 0;
    }
    
};


#endif