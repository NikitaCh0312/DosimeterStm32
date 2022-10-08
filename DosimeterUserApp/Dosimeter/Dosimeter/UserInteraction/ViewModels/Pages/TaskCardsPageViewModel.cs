using System.Collections.ObjectModel;
using Dosimeter.Services.CardsManagerService.CardsManagerService.Interfaces;
using Dosimeter.Services.CardsManagerService.CardsManagerService.Models;
using Dosimeter.UserInteraction.UIServices;
using Dosimeter.UserInteraction.Views.Windows;
using Prism.Commands;
using Prism.Mvvm;

namespace Dosimeter.UserInteraction.ViewModels;

public class TaskCardsPageViewModel : BindableBase
{
    private readonly ICardsManagerService _cardsManagerService;
    private readonly IWindowService _windowService;

    public TaskCardsPageViewModel(ICardsManagerService cardsManagerService,
        IWindowService windowService)
    {
        _cardsManagerService = cardsManagerService;
        _windowService = windowService;
        Cards = new ObservableCollection<Card>();
        
        ViewLoadCommand = new DelegateCommand(OnViewLoaded);
        EditCardCommand = new DelegateCommand(OnEditCard);
        AddNewCardCommand = new DelegateCommand(OnAddNewCard);
        RemoveCardCommand = new DelegateCommand(OnRemoveCardCommand);
    }
    
    public DelegateCommand ViewLoadCommand { get; set; }

    private async void OnViewLoaded()
    {
        //await _cardsManagerService.LoadCards();
        //var cardsInfo = _cardsManagerService.CardsInfo;
        //if (cardsInfo != null)
        //    CardsQuantity = 0;
        Cards.Clear();
        CardsQuantity = 15;
        foreach (var card in _cardsManagerService.Cards)
        {
            Cards.Add(card);
        }
    }
    
    public DelegateCommand EditCardCommand { set; get; }

    private void OnEditCard()
    {
        _windowService.ShowWindow<EditCardWindow>(new EditCardWindowViewModel()
        {
            Title = "Редактирование карты заданий",
            SelectedCard = SelectedCard
        });
    }
    
    public DelegateCommand AddNewCardCommand { set; get; }

    private void OnAddNewCard()
    {
        _windowService.ShowWindow<EditCardWindow>(new EditCardWindowViewModel()
        {
            Title = "Добавление новой карты заданий",
            
        });
    }
    
    public DelegateCommand RemoveCardCommand { set; get; }

    private void OnRemoveCardCommand()
    {
        
    }
    
    private int _cardsQuantity;
    public int CardsQuantity
    {
        get => _cardsQuantity;
        set => SetProperty(ref _cardsQuantity, value); 
    }
    
    public ObservableCollection<Card> Cards { set; get; }

    private Card _selectedCard;
    public Card SelectedCard 
    {
        get => _selectedCard;
        set => SetProperty(ref _selectedCard, value); 
    }
}