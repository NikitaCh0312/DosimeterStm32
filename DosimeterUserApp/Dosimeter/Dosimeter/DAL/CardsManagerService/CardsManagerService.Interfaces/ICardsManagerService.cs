using System.Collections.Generic;
using Dosimeter.DAL.CardsManagerService.CardsManagerService.Models;

namespace Dosimeter.DAL.CardsManagerService.CardsManagerService.Interfaces;

public interface ICardsManagerService
{
    List<Card> GetCards();
    void AddCard(Card card);
}