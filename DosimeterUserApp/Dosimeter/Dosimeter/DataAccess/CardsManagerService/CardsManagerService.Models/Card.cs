using System.Collections.Generic;

namespace Dosimeter.DataAccess.CardsManagerService.CardsManagerService.Models;

public class Card
{
    public int Id { set; get; }
    public int SubstanceId { set; get; }
    public List<CardTask> Tasks { set; get; }
}