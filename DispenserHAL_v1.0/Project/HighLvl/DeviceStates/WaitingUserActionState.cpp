#include "DeviceStates/WaitingUserActionState.h"
#include "DeviceStates/MenuState.h"
#include "DeviceStates/TaskSelectionState.h"
#include "LCD/LCD.h"
#include "Resources/StringResources.h"
#include "modules/CardsManager.h"
#include "modules/[Interfaces]/ICardsManager.h"
#include "string.h"




void WaitingUserActionState::Handle(UserAction_t action)
{
    static uint32_t stageTimer;
    
    if (_stage == WAITING_STAGE)
    {
        set_cursor_position(0, 0);
        set_symbols(StringResources::Attach_RFID_Card_1str, strlen((char*)StringResources::Attach_RFID_Card_1str));
        set_cursor_position(1, 0);
        set_symbols(StringResources::Attach_RFID_Card_2str, strlen((char*)StringResources::Attach_RFID_Card_2str));
        
        //ожидание карты пользовател€
        if (action.rfidEvent.event != NEW_CARD_DETECTED_EVENT)
            return;
        uint32_t cardId = action.rfidEvent.rfidCard.CardId;
        //выт€нуть из пам€ти карту по ее ID
        //проверка карты
        
        CARD_STATUS_t status = CARD_IS_NOT_BINDED_STATUS;
        if (cardId == 908904)
            status = CARD_EXT_ACCESS_STATUS;
        switch (status)
        {
            case CARD_EXT_ACCESS_STATUS:
            {
                //если карта  –ƒ, то переключение состо€ни€ в меню
                _stage = WAITING_STAGE;
                MenuState * menuState = MenuState::GetInstance();
                menuState->InitMenuState();
                _context->SetState((IDeviceState*)menuState);
                clear_display();
                break;
            }
            case CARD_IS_INACTIVE_STATUS:
            {
                //карта неактивна(не закреплено ни одного задани€)
                stageTimer = global_timer;
                _stage = CARD_IS_INACTIVE_STAGE;
                clear_display();
                break;
            }
            case CARD_IS_NOT_BINDED_STATUS:
            {
                //карта не прив€зана к устройству
                stageTimer = global_timer;
                _stage = CARD_NOT_BINDED_STAGE;
                clear_display();
                break;
            }
            case CARD_IS_ACTIVE_STATUS:
            {
                //карта активна
                _stage = WAITING_STAGE;
                TaskSelectionState * taskSelectionState = TaskSelectionState::GetInstance();
                taskSelectionState->SetCardId(cardId);
                _context->SetState((IDeviceState*)taskSelectionState);
                clear_display();
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
        {
            _stage = WAITING_STAGE;
            clear_display();
        }
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
        {
            _stage = WAITING_STAGE;
            clear_display();
        }
        return;
    }
}