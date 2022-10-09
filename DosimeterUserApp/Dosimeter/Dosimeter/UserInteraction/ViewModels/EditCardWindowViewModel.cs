using System.Collections.Generic;
using Dosimeter.Services.CardsManagerService.CardsManagerService.Interfaces;
using Dosimeter.Services.CardsManagerService.CardsManagerService.Models;
using Prism.Commands;
using Prism.Mvvm;

namespace Dosimeter.UserInteraction.ViewModels;

public class EditCardWindowViewModel : BindableBase
{
    private readonly ICardsManagerService _cardsManagerService;
    
    public EditCardWindowViewModel(ICardsManagerService cardsManagerService, Card card)
    {
        _cardsManagerService = cardsManagerService;
        SelectedCard = card ?? new Card(){ Tasks = new List<CardTask>()};
        ApplyCardCommand = new DelegateCommand(OnApplyCardCommand);
    }
    
    private string _title;
    public string Title
    {
        get => _title;
        set => SetProperty(ref _title, value); 
    }
    
    private Card _selectedCard;
    public Card SelectedCard
    {
        get => _selectedCard;
        set => SetProperty(ref _selectedCard, value); 
    }
    
    public DelegateCommand ApplyCardCommand { set; get; }

    private void OnApplyCardCommand()
    {
        _cardsManagerService.AddOrUpdateCard(SelectedCard);
    }
}