using System.Collections.Generic;
using Newtonsoft.Json;

namespace Dosimeter.Services.CardsManagerService.CardsManagerService.Models;

public class Card
{
    [JsonProperty("Id")]
    public int Id { set; get; }
    
    [JsonProperty("SubstanceId")]
    public int SubstanceId { set; get; }
    
    [JsonProperty("Tasks")]
    public List<CardTask> Tasks { set; get; }
}