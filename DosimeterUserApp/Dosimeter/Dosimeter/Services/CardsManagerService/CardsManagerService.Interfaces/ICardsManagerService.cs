using System.Collections.Generic;
using System.Threading.Tasks;
using Dosimeter.Services.CardsManagerService.CardsManagerService.Models;

namespace Dosimeter.Services.CardsManagerService.CardsManagerService.Interfaces;

public interface ICardsManagerService
{
    Task LoadCards();
    
    List<Card> Cards { get; }

    Task AddOrUpdateCard(Card card);
    
    Task RemoveCard(int cardId);
}