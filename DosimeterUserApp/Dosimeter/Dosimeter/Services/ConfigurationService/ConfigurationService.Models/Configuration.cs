using Newtonsoft.Json;

namespace Dosimeter.Services.ConfigurationService.ConfigurationService.Models;

public class Configuration
{
    [JsonProperty("serial_number")]
    public string SerialNumber { set; get; }
    [JsonProperty("model")]
    public string Model { set; get; }
    [JsonProperty("firmware")]
    public string SoftwareVersion { set; get; }
}