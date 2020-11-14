#include "WaitingUserActionState.h"
#include "MenuState.h"
#include "LCD/LCD.h"
#include "Dosimeter.h"
void WaitingUserActionState::Handle(UserAction_t action)
{
    static uint32_t stageTimer;
    
    if (_stage == WAITING_STAGE)
    {
        set_cursor_position(0, 3);
        set_text_eng("ip:192.168.0.10");
        set_cursor_position(1, 3);
        set_text_eng("port: 667");
        set_cursor_position(2, 3);
        set_text_eng("Attach card      ");    
        
        //ожидание карты пользователя
        if (action.rfidEvent.event != NEW_CARD_DETECTED_EVENT)
            return;
        uint32_t cardId = action.rfidEvent.rfidCard.CardId;
        //вытянуть из памяти карту по ее ID
        //проверка карты
        if (cardId == 908904)
        {
            //если карта КРД, то переключение состояния в меню
            MenuState * menuState = MenuState::GetInstance();
            menuState->InitMenuState();
            _context->SetState((IDeviceState*)menuState);
            return;
        }
        else 
        {
            stageTimer = global_timer;
            _stage = CARD_NOT_REGISTERED_STAGE;
        }
        return;
    }

    
    if (_stage == CARD_NOT_REGISTERED_STAGE)
    { 
        set_cursor_position(2, 3);
        set_text_eng("Card not detected"); 
        
        if (global_timer - stageTimer > 5000)
            _stage = WAITING_STAGE;
        
        return;
    }
}