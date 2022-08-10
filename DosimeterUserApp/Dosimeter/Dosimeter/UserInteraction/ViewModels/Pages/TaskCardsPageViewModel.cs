using System.Collections.ObjectModel;
using Dosimeter.Services.CardsManagerService.CardsManagerService.Interfaces;
using Dosimeter.Services.CardsManagerService.CardsManagerService.Models;
using Prism.Commands;
using Prism.Mvvm;

namespace Dosimeter.UserInteraction.ViewModels;

public class TaskCardsPageViewModel : BindableBase
{
    private readonly ICardsManagerService _cardsManagerService;

    private ObservableCollection<Card> _cards;
    private int _cardsQuantity;

    public TaskCardsPageViewModel(ICardsManagerService cardsManagerService)
    {
        _cardsManagerService = cardsManagerService;

        _cards = new ObservableCollection<Card>();
        
        ViewLoadCommand = new DelegateCommand(OnViewLoaded);
    }
    
    public DelegateCommand ViewLoadCommand { get; set; }

    private async void OnViewLoaded()
    {
        await _cardsManagerService.LoadCards();
        _cardsQuantity = _cardsManagerService.CardsInfo.CardsQuantity;
    }
}