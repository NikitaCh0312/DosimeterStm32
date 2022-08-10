using System.Collections.Generic;

namespace Dosimeter.Services.CardsManagerService.CardsManagerService.Models;

public class Card
{
    public int Id { set; get; }
    public int SubstanceId { set; get; }
    public List<CardTask> Tasks { set; get; }
}