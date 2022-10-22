using Newtonsoft.Json;

namespace Dosimeter.Services.EventLog.EventLog.Models;

public class EventLogInfo
{
    [JsonProperty("events_number")]
    public int EventsNumber { set; get; }
    
    [JsonProperty("max_events_number")]
    public int MaxEventsNumber { set; get; }
}