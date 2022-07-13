#include "main.h"

#include "Tasks/ButtonsTask.h"
#include "Tasks/DisplayTask.h"
#include "Tasks/EthernetTask.h"
#include "Tasks/RFIDTask.h"
#include "Tasks/MainLogicTask.h"
#include "Tasks/DebugTask.h"

#include "modules/Menu/MenuFactory.h"
#include "modules/Json/JsonSerializer.h"

#include "DeviceStates/Dosimeter.hpp"
#include "DeviceStates/States/WaitingUserActionState.hpp"
#include "DeviceStates/States/TaskSelectionState.hpp"
#include "DeviceStates/States/TaskExecutionState.hpp"
#include "DeviceStates/States/MenuState.hpp"
#include "DeviceStates/States/StartupState.hpp"
#include "DeviceStates/[Interfaces]/IDeviceStatesFactory.hpp"
#include "DeviceStates/DeviceStatesFactory.hpp"
#include "modules/Configuration.h"

#include "modules/api/ApiController.h"
#include "modules/api/RequestHandlers/[Interfaces]/IRequestHandlerFactory.hpp"
#include "modules/api/RequestHandlers//RequestHandlerFactory.hpp"
#include "modules/ModulesLocator.h"

#include "ComponentsInit.h"

#include "RTOS/Thread.h"

#include "rtos_lib.h"


uint32_t global_timer = 0;
static void tick_hook(void)
{
    global_timer++;
}
static void malloc_failed_hook()
{
    while(1);
}
static void stack_overflow_hook(void * tsk_handle, char * tsk_name)
{
    while(1);
}
static void iddle_hook()
{
    while(1);
}
void stack_over_flow_hook(void * tsk_handle, char * tsk_name)
{
    while(1);
}




ButtonsTask * buttonsTask = new ButtonsTask((char*)"ButtonsTask", configMINIMAL_STACK_SIZE * 2, 1);
//DisplayTask * displayTask = new DisplayTask((char*)"DisplayTask", configMINIMAL_STACK_SIZE * 2, 1);
EthernetTask * ethernetTask = new EthernetTask((char*)"EthernetTask", configMINIMAL_STACK_SIZE * 2, 1);
MainLogicTask * mainLogicTask = new MainLogicTask((char*)"MainLogicTask", configMINIMAL_STACK_SIZE * 2, 1);
RfidTask * rfidTask = new RfidTask((char*)"RfidTask", configMINIMAL_STACK_SIZE * 2, 1);
DebugTask * debugTask = new DebugTask((char*)"DebugTask", configMINIMAL_STACK_SIZE * 2, 1);

Menu * menu = MenuFactory::CreateMenu();

Dosimeter * Dosimeter::_instance = new Dosimeter();

WaitingUserActionState * WaitingUserActionState::_instance = new WaitingUserActionState();
TaskSelectionState * TaskSelectionState::_instance = new TaskSelectionState();
TaskExecutionState * TaskExecutionState::_instance = new TaskExecutionState();
MenuState * MenuState::_instance = new MenuState();
StartupState * StartupState::_instance = new StartupState();
ManualDosationState * ManualDosationState::_instance = new ManualDosationState();
SubstanceServiceState * SubstanceServiceState::_instance = new SubstanceServiceState();

DeviceStatesFactory * DeviceStatesFactory::_instance = new DeviceStatesFactory();
Configuration * Configuration::_instance = new Configuration();


ModulesLocator * ModulesLocator::_instance = new ModulesLocator();
CardsManager * CardsManager::_instance = new CardsManager();


JsonSerializer * JsonSerializer::_instance = new JsonSerializer();

ElementSelector * ElementSelector::_instance = new ElementSelector();


ApiController * ApiController::_instance = new ApiController();
IRequestHandlerFactory * requestHandlerFactory = new RequestHandlerFactory();

static void ConfigureApi()
{
    ApiController * apiController = ApiController::GetInstance();
    apiController->RegisterHandler("description", requestHandlerFactory->CreateDescriptionRequestHandler());
    apiController->RegisterHandler("event_log", requestHandlerFactory->CreateEventLogRequestHandler());
    apiController->RegisterHandler("network", requestHandlerFactory->CreateNetworkRequestHandler());
    apiController->RegisterHandler("get_cards", requestHandlerFactory->CreateCardsListRequestHandler());
    apiController->RegisterHandler("add_card", requestHandlerFactory->CreateAddCardRequestHandler());
}


void startup()
{
    //low level initialization
    boardInit();

    //set RTOS functions
    pfn_tick_hook_function = &tick_hook;
    pfn_malloc_failed_hook = &malloc_failed_hook;
    pfn_idle_hook = &iddle_hook;
    pfn_stack_over_flow_hook = &stack_overflow_hook;
    
    
    //initializing dosimeter states
    Dosimeter * dosimeter = Dosimeter::GetInstance();
    
    WaitingUserActionState * waitingUserActionState = WaitingUserActionState::GetInstance();
    TaskSelectionState * taskSelectionState = TaskSelectionState::GetInstance();
    TaskExecutionState * taskExecutionState = TaskExecutionState::GetInstance();
    MenuState * menuState = MenuState::GetInstance();
    menuState->SetMenu(menu);
    StartupState * startupState = StartupState::GetInstance();
    
    waitingUserActionState->SetContext(dosimeter);
    taskSelectionState->SetContext(dosimeter);
    taskExecutionState->SetContext(dosimeter);
    menuState->SetContext(dosimeter);
    startupState->SetContext(dosimeter);
    
    IDeviceStatesFactory * factory = DeviceStatesFactory::GetInstance();
    waitingUserActionState->SetDeviceStatesFactory(factory);
    taskSelectionState->SetDeviceStatesFactory(factory);
    taskExecutionState->SetDeviceStatesFactory(factory);
    menuState->SetDeviceStatesFactory(factory);
    startupState->SetDeviceStatesFactory(factory);
    
    //set first state
    dosimeter->SetState((IDeviceState*)startupState);
    
    ConfigureApi();
    
    //modules init
    ModulesLocator* locator = ModulesLocator::GetInstance();
    
    //start RTOS
    RTOS::Thread::start_scheduler();
}

