#include "DeviceStates/WaitingUserActionState.h"
#include "DeviceStates/MenuState.h"
#include "DeviceStates/TaskSelectionState.h"
#include "LCD/LCD.h"
#include "Resources/StringResources.h"

#include "string.h"




void WaitingUserActionState::Handle(UserAction_t action)
{
    static uint32_t stageTimer;
    
    if (_stage == WAITING_STAGE)
    {
        set_cursor_position(0, 0);
        set_symbols(StringResources::Attach_RFID_Card_1str, 20);
        set_cursor_position(1, 0);
        set_symbols(StringResources::Attach_RFID_Card_2str, 20);
        
        //ожидание карты пользовател€
        if (action.rfidEvent.event != NEW_CARD_DETECTED_EVENT)
            return;
        uint32_t cardId = action.rfidEvent.rfidCard.CardId;
        //выт€нуть из пам€ти карту по ее ID
        //проверка карты
        
        CARD_VERIFICATION_RES_t res = CARD_IS_NOT_BINDED_RES;
        if (cardId == 908904)
            res = CARD_EXT_ACCESS_RES;
        switch (res)
        {
            case CARD_EXT_ACCESS_RES:
            {
                //если карта  –ƒ, то переключение состо€ни€ в меню
                _stage = WAITING_STAGE;
                MenuState * menuState = MenuState::GetInstance();
                menuState->InitMenuState();
                _context->SetState((IDeviceState*)menuState);
                break;
            }
            case CARD_IS_INACTIVE_RES:
            {
                //карта неактивна(не закреплено ни одного задани€)
                stageTimer = global_timer;
                _stage = CARD_IS_INACTIVE_STAGE;
                break;
            }
            case CARD_IS_NOT_BINDED_RES:
            {
                //карта не прив€зана к устройству
                stageTimer = global_timer;
                _stage = CARD_NOT_BINDED_STAGE;
                break;
            }
            case CARD_IS_ACTIVE_RES:
            {
                //карта активна
                _stage = WAITING_STAGE;
                TaskSelectionState * taskSelectionState = TaskSelectionState::GetInstance();
                taskSelectionState->SetCardId(cardId);
                _context->SetState((IDeviceState*)taskSelectionState);
                break;
            }
            default:
            {
                break;
            }
        }
    }

    
    if (_stage == CARD_NOT_BINDED_STAGE)
    { 
        set_cursor_position(0, 0);
        set_symbols(StringResources::Attention, strlen((char*)StringResources::Attention)); 
        set_cursor_position(1, 0);
        set_symbols(StringResources::CardIsNotBinded, strlen((char*)StringResources::CardIsNotBinded)); 
        set_cursor_position(2, 0);
        set_symbols(StringResources::ToThisDevice, strlen((char*)StringResources::ToThisDevice)); 
        
        if (global_timer - stageTimer > 5000)
            _stage = WAITING_STAGE;
        
        return;
    }
    
    
    if (_stage == CARD_IS_INACTIVE_STAGE)
    {
        set_cursor_position(0, 0);
        set_symbols(StringResources::Attention, strlen((char*)StringResources::Attention)); 
        set_cursor_position(1, 0);
        set_symbols(StringResources::CardIsNotBinded, strlen((char*)StringResources::CardIsNotBinded)); 
        set_cursor_position(2, 0);
        set_symbols(StringResources::ToThisDevice, strlen((char*)StringResources::ToThisDevice)); 
        
        if (global_timer - stageTimer > 5000)
            _stage = WAITING_STAGE;
        
        return;
    }
}