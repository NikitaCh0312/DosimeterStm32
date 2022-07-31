#ifndef EVENT_JOURNAL_H_
#define EVENT_JOURNAL_H_

//12 bytes
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
    uint32_t StartEventId;
    uint32_t LastEventId;
    uint32_t MemoryUsage;
    uint32_t EventsQuantity;
}EventJournalInfo_t;

class EventJournal
{
public:
    EventJournal()
    {

    }
    virtual ~EventJournal(){}
    
    void WrteEvent(uint8_t eventId, uint32_t extraInfo)
    {
        EventJournalItem_t item;
        RtcDateTime_t dateTime;
        
        RtcGetDateTime(&dateTime);
        
        item.Year = dateTime.Year;
        item.Month = dateTime.Month;
        item.Day = dateTime.Day;
        item.Hours = dateTime.Hours;
        item.Minutes = dateTime.Minutes;
        item.Seconds = dateTime.Seconds;
        item.EventId = eventId;
        item.ExtraInfo = extraInfo;
        WriteEventItem(item);
    }

    int GetAllEventsQuaintity()
    {
      
    }
    
    EventJournalInfo_t GetEventJournalInfo()
    {
        EventJournalInfo_t info;
        return info;
    }
    
    EventJournalItem_t GetEvent(int eventId)
    {
        EventJournalItem_t item;
        item.Year = 2022;
        item.Month = 7;
        item.Day = 31;
        item.Hours = 19;
        item.Minutes = 18;
        item.Seconds = 25;
        item.EventId = 10;
        item.ExtraInfo = 12;
        return item;
    }
    
private:
    void WriteEventItem(EventJournalItem_t event)
    {
      
    }
};

#endif