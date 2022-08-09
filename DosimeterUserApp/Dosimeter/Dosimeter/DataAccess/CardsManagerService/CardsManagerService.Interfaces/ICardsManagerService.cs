using System.Collections.Generic;
using Dosimeter.DataAccess.CardsManagerService.CardsManagerService.Models;

namespace Dosimeter.DataAccess.CardsManagerService.CardsManagerService.Interfaces;

public interface ICardsManagerService
{
    List<Card> GetCards();
    void AddCard(Card card);
}