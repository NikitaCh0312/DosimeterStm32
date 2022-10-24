using System;
using Newtonsoft.Json;

namespace Dosimeter.Services.EventLog.EventLog.Models;

public class EventLogItem
{
    [JsonProperty("num")]
    public int Id { set; get; }
    
    [JsonProperty("id")]
    public int EventId { set; get; }
    
    [JsonProperty("dt")]
    public string DateTime { set; get; }
    
    [JsonProperty("ex")]
    public int ExtraInfo { set; get; }
}