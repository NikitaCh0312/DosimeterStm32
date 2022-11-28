#ifndef EVENT_JOURNAL_STORAGE_H_
#define EVENT_JOURNAL_STORAGE_H_

#include "Components/Flash/W25Q256.h"
#include "modules/Storage/Crc16.h"
#include "modules/Storage/BaseStorage.h"


#define EVENT_JOURNAL_START_SECTOR 15
#define EVENT_JOURNAL_END_SECTOR 1023

extern w25qxx_t w25qxx;

//16bytes = 4words
typedef struct
{
    uint32_t ExtraInfo;
    uint32_t Year;
    uint8_t Month;
    uint8_t Day;
    uint8_t Hours;
    uint8_t Minutes;
    uint8_t Seconds;
    uint8_t EventId;
    uint16_t Crc;
}EventJournalRecord_t;

typedef enum
{
    Event_0R1 = 0,      // device configuration is OK 
    Event_2R1,          // pwr voltage is bad
    Event_2R2,          // substance is no in tank  
    Event_2R3,          // insufficient water pressure in the pipeline
    
    Event_3R1,          // the "xxxx" card has been identified, not attached to this Device
    Event_3R2,          // the inactive "xxxx" card has been identified:x"
    Event_3R3,          // the extended access card "xxx"
    Event_3R4,          // has been identified - the current task card 
    Event_3R5,          // has been identified - work with the "xxxx" card has been terminated due to a failure
    Event_3R6,          // work with the "xxxx" card has been completed successfully: all tasks have been completed 
    Event_3R7,          // work with the 270F card has been completed successfully: tasks 'n'
    Event_3R8,          // task 'n' cancelled during execution
    Event_3R9,          // task card "xxxx" cancelled. In total, 'n' tasks have not been completed
    
    Event_4R1,          //system date successfully updated
    Event_4R2,          //network connection settings changed successfully
    Event_4R3,          //forced release of solution started 
    Event_4R4,          //forced release of solution completed successfully
    Event_4R5,          //forced release of solution interrupted
    Event_4R6,          //the procedure for cleaning the SCP from the drug has been started
    Event_4R7,          //the procedure for cleaning the SCP from the drug has been completed successfully
    Event_4R8,          //the procedure for cleaning the SCP from the drug has been interrupted without consequences
    Event_4R9,          //the procedure for washing the SCP has been started
    Event_4R10,         //the procedure for flushing the SCP was completed successfully
    Event_4R11,         //the procedure for refueling the fresh drug was canceled
    Event_4R12,         //the procedure for refueling the fresh drug was performed successfully
    Event_4R13,         //the procedure for selecting the current drug was performed successfully

    Event_5R7,          //received a request to lock the Device
    Event_5R8,          //the lock was completed successfully
    Event_5R12,         //UT sent a new time. Correction of the system time was carried out successfully
    Event_5R19          //received a request to send the first block
}EventID_List_t;


class EventJournalStorage : BaseStorage
{
public:
    void Init()
    {
        _recordSizeBytes = sizeof(EventJournalRecord_t);
        _maxRecordsNumber = ((EVENT_JOURNAL_END_SECTOR - EVENT_JOURNAL_START_SECTOR) * w25qxx.SectorSize)/_recordSizeBytes;
        _activeRecordNumber = SearchActiveRecNumb(0, _maxRecordsNumber);
        
        
        EventJournalRecord_t record;
        int changer = 3;
        record.ExtraInfo = 1 + changer;
        record.Year = 2022;
        record.Month = 12;
        record.Day = 14;
        record.Hours = 15;
        record.Minutes = 20;
        record.Seconds = 45;
        record.EventId = 22;
        record.Crc = 9 + changer;
//        TryAddRecord(&record);
        
//        for(int i = 0; i < 10; i++)
//          TryAddRecord(&record);
//        
//        SearchActiveRecNumb();
//        uint32_t count = GetRecordsCount();
//        
//        EventJournalRecord_t rec1 = TryGetRecord(0);
//        EventJournalRecord_t rec2 = TryGetRecord(1);
//        EventJournalRecord_t rec3 = TryGetRecord(2);
//        
//        CleanJournal();
    }
    
    EventJournalRecord_t TryGetRecord(uint32_t recordId)
    {
        EventJournalRecord_t record;
        uint32_t recordAddress = RecordNumberToAddress(recordId);
        W25qxx_ReadBytes((uint8_t*)&record, recordAddress, _recordSizeBytes);
        return record;
    }
    
    void TryAddRecord(EventJournalRecord_t* record)
    {
        if (_activeRecordNumber >= _maxRecordsNumber - 1)
          return;
        
        record->Crc = 0x77;
        
        uint32_t activeAddress = RecordNumberToAddress(_activeRecordNumber);
        uint32_t pageNumber = AddressToPage(activeAddress);
        uint32_t addressOffset = OffsetFromPageStartAddress(activeAddress);
        W25qxx_WritePage((uint8_t*)record, pageNumber, addressOffset, _recordSizeBytes);
        _activeRecordNumber++;
    }
    
    uint32_t GetRecordsCount()
    {
        return _activeRecordNumber;
    }
    
    uint32_t GetMaxRecordsCount()
    {
        return _maxRecordsNumber;
    }
    
    void CleanJournal()
    {
        uint32_t currentAddress = RecordNumberToAddress(_activeRecordNumber);
        uint32_t currentSector = (currentAddress/w25qxx.SectorSize);
        
        for (int i = EVENT_JOURNAL_START_SECTOR; i <= currentSector; i++)
        {
            W25qxx_EraseSector(i);
        }
        
        _activeRecordNumber = 0;
    }
    
    void CleanJournalFull()
    {
        for (int i = EVENT_JOURNAL_START_SECTOR; i <= EVENT_JOURNAL_END_SECTOR; i++)
        {
            W25qxx_EraseSector(i);
        }
        _activeRecordNumber = 0;
    }
    
private:
    
    uint32_t _activeRecordNumber;
    uint32_t _recordSizeBytes;
    uint32_t _maxRecordsNumber;
    
    uint32_t RecordNumberToAddress(uint32_t number)
    {
        uint32_t startAddress = EVENT_JOURNAL_START_SECTOR * w25qxx.SectorSize;
        startAddress += _recordSizeBytes * number;
        return startAddress;
    }
    
    //calclates number of page to which address owns
    uint32_t AddressToPage(uint32_t address)
    {
        return address/w25qxx.PageSize;
    }
    
    //calcuates offset from page start address
    uint32_t OffsetFromPageStartAddress(uint32_t address)
    {
        return address%w25qxx.PageSize;
    }
    
    
    bool IsEraseEventJournal(const EventJournalRecord_t *rec)
    {
      if(rec->ExtraInfo == UINT32_MAX &&
         rec->Year == UINT32_MAX &&
         rec->Month == UINT8_MAX &&
         rec->Day == UINT8_MAX &&
         rec->Hours == UINT8_MAX &&
         rec->Minutes == UINT8_MAX &&
         rec->Seconds == UINT8_MAX &&
         rec->EventId == UINT8_MAX &&
         rec->Crc == UINT16_MAX )
      {
        return true;
      }
      else
        return false;
    }
    
    // binary search to _activeRecordNumber in W25Q
    uint32_t SearchActiveRecNumb(int l, int h)
    {
      if(l > h)
        return UINT32_MAX;

      int mid = 0;
      bool isErase = 0;
      
      EventJournalRecord_t recRead;
      
      while(l <= h)
      {
        mid = l + (h - l) / 2;
        recRead = TryGetRecord(mid);
        
        isErase = IsEraseEventJournal(&recRead);
        
        if(isErase)
          h = mid - 1;
        else
          l = mid + 1;
      }
      
      return mid;
    }
};

#endif