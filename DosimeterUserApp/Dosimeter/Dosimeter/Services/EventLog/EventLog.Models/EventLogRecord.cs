using System;

namespace Dosimeter.Services.EventLog.EventLog.Models;

public class EventLogRecord
{
    public int Id { set; get; }
    
    public int EventId { set; get; }
    
    public string Description { set; get; }
    
    public DateTime DateTime { set; get; }
    
    public int ExtraInfo { set; get; }
}