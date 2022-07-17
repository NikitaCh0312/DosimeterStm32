#ifndef STRING_RESOURCES_H_
#define STRING_RESOURCES_H_

#include "stddef.h"
#include "stdint.h"

class StringResources
{
public:
    virtual ~StringResources(){}
    StringResources * GetInstance()
    {
        if (_instance == NULL)
            _instance = new StringResources();
        return _instance;
    }
    
    //Device preparing
    static uint8_t DevicePreparing[20];
    static uint8_t PleaseWait[20];
    static uint8_t Error[20];
    static uint8_t VoltageError[20];
    
    //attach to reader
    static uint8_t Attach_RFID_Card_1str[20];
    //identification card
    static uint8_t Attach_RFID_Card_2str[20];
    
    static uint8_t TaskExecution_1str[20];
    static uint8_t TaskExecution_2str[20];

    static uint8_t TaskExecuted_1str[20];
    static uint8_t TaskExecuted_2str[20];
    
    static uint8_t StringResources::TaskCancelTask_1str[20];
    static uint8_t StringResources::TaskErrorPreasure_1str[20];
    static uint8_t StringResources::TaskErrorPreasure_2str[20];
    static uint8_t StringResources::TaskErrorAvalibilitySubstance_1str[20];
    static uint8_t StringResources::TaskErrorAvalibilitySubstance_2str[20];
    
    static uint8_t TaskErrorExecuted_1str[20];
    static uint8_t TaskErrorExecuted_2str[20];
    
    //Attention! Card is not binded to this device
    static uint8_t Attention[20];
    static uint8_t CardIsNotBinded[20];
    static uint8_t ToThisDevice[20];
    
    //All tasks quantty
    static uint8_t TasksQuantity[20];
    //Current task
    static uint8_t CurrentTask[20];
    //Solution volume
    static uint8_t SolutionVolume[20];
    //Solution Concentration
    static uint8_t SolutionConcentration[20];
    
    //Menu
    static uint8_t Menu[20];
    //DateTime
    static uint8_t DateTime[20];
    static uint8_t Time[20];
    static uint8_t Date[20];
    //Network
    static uint8_t Network[20];
    
    static uint8_t ManualDosation[20];
    static uint8_t PressEnter[20];
    static uint8_t ToStart[20];
    static uint8_t ManualDosationMode[20];
    static uint8_t Select[20];
    static uint8_t Volume[20];
    static uint8_t Concentration[20];
    static uint8_t SelectedParams[20];
    
    //SubstanceService
    static uint8_t SubstanceService[20];    
private:
    StringResources(){}
    static StringResources * _instance;
        
};

#endif