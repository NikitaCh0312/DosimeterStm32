using Newtonsoft.Json;

namespace Dosimeter.Services.DeviceInfoService.DeviceInfoService.Models;

public class DeviceInfo
{
    [JsonProperty("serial_number")]
    public string SerialNumber { set; get; }
    [JsonProperty("model")]
    public string Model { set; get; }
    [JsonProperty("firmware")]
    public string SoftwareVersion { set; get; }
}