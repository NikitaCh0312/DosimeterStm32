using Newtonsoft.Json;

namespace Dosimeter.Services.CardsManagerService.CardsManagerService.Models;

public class CardTask
{
    [JsonProperty("Id")]
    public int Id { set; get; }
    
    [JsonProperty("V")]
    public float Volume { set; get; }
    
    [JsonProperty("C")]
    public float Concentration { set; get; }
}