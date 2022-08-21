using Newtonsoft.Json;

namespace Dosimeter.Services.ConfigurationService.ConfigurationService.Models;

public class Configuration
{
    [JsonProperty("IpAddress")]
    public string Ip { set; get; }
    
    [JsonProperty("Port")]
    public int? Port { set; get; }
    
    [JsonProperty("Mask")]
    public string Mask { set; get; }
    
    [JsonProperty("Date")]
    public string Date { set; get; }
    
    [JsonProperty("Time")]
    public string Time { set; get; }
}