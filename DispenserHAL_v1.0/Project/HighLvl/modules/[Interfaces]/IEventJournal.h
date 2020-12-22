#ifndef IEVENT_JOURNAL_H_
#define IEVENT_JOURNAL_H_


typedef struct
{
    uint8_t Year;
    uint8_t Month;
    uint8_t Day;
    uint8_t Hour;
    
    uint8_t Minute;
    uint8_t Second;
    uint8_t reserved;
    uint8_t reserved;
    
    uint32_t EventCode;
    uint32_t EventData;
}EventRecord_t;

class IEventJournal
{
public:
    IEventJournal(){}
    virtual ~IEventJournal(){}
    
    virtual int WriteRecord(EventRecord_t record) = 0;
    
    virtual uint32_t GetRecordsQuantity() = 0;
    
    virtual EventRecord_t GetRecord(uint32_t recordNum) = 0;
};


#endif