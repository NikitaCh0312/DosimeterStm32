#ifndef EVENT_JOURNAL_H_
#define EVENT_JOURNAL_H_

#include "Components/RTC/RTC_drv.h"
#include "modules/Storage/EventJournalStorage.h"

typedef struct
{
    uint32_t Id;
    uint32_t Year;
    uint8_t Month;
    uint8_t Day;
    uint8_t Hours;
    uint8_t Minutes;
    uint8_t Seconds;
    uint8_t EventId;
    uint32_t ExtraInfo;
}EventJournalItem_t;

typedef struct
{
    uint32_t MaxEventQuantity;
    uint32_t EventsQuantity;
}EventJournalInfo_t;

class EventJournal
{
public:
    EventJournal()
    {
        _storage = new EventJournalStorage();
    }
    virtual ~EventJournal(){}
    
    void Init()
    {
        _storage->Init();
    }
    
    void WrteEvent(uint8_t eventId, uint32_t extraInfo)
    {
        EventJournalRecord_t record;
        RtcDateTime_t dateTime;
        
        RtcGetDateTime(&dateTime);
        
        record.Year = dateTime.Year;
        record.Month = dateTime.Month;
        record.Day = dateTime.Day;
        record.Hours = dateTime.Hours;
        record.Minutes = dateTime.Minutes;
        record.Seconds = dateTime.Seconds;
        record.EventId = eventId;
        record.ExtraInfo = extraInfo;
        
        _storage->TryAddRecord(&record);
    }
    
    EventJournalInfo_t GetEventJournalInfo()
    {
        EventJournalInfo_t info;
        info.EventsQuantity = _storage->GetRecordsCount();
        info.MaxEventQuantity = _storage->GetMaxRecordsCount();
        return info;
    }
    
    EventJournalItem_t GetEvent(int number)
    {
        EventJournalItem_t item;
        
        EventJournalRecord_t record = _storage->TryGetRecord(number);
        
        item.Id = number;
        item.Year = record.Year;
        item.Month = record.Month;
        item.Day = record.Day;
        item.Hours = record.Hours;
        item.Minutes = record.Minutes;
        item.Seconds = record.Seconds;
        item.EventId = record.EventId;
        item.ExtraInfo = record.ExtraInfo;
        
        return item;
    }
    
    void ClearJournal()
    {
        _storage->CleanJournal();
    }
private:
    
    EventJournalStorage* _storage;
};

#endif