#ifndef EVENT_JOURNAL_H_
#define EVENT_JOURNAL_H_

//12 bytes
typedef struct
{
    uint32_t Year;
    uint8_t Month;
    uint8_t Day;
    uint8_t Hours;
    uint8_t Minutes;
    uint8_t Seconds;
    uint8_t EventId;
    uint32_t ExtraInfo;
}EventJournalItem_t;

class EventJournal
{
public:
    EventJournal()
    {

    }
    virtual ~EventJournal(){}
    
    void WriteEvent(EventJournalItem_t event)
    {
      
    }
    
    EventJournalItem_t GetEvent()
    {
      
    }
    
private:

};

#endif