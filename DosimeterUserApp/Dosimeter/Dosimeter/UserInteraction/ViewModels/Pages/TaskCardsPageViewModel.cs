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

        IsDataLoaded = false;
        
        ViewLoadCommand = new DelegateCommand(OnViewLoaded);
        EditCardCommand = new DelegateCommand(OnEditCard);
        AddNewCardCommand = new DelegateCommand(OnAddNewCard);
        RemoveCardCommand = new DelegateCommand(OnRemoveCardCommand);
    }
    
    public DelegateCommand ViewLoadCommand { get; set; }

    private async void OnViewLoaded()
    {
        IsDataLoaded = false;
        Cards.Clear();
        await _cardsManagerService.LoadCards();
        CardsQuantity = _cardsManagerService.Cards.Count;
        foreach (var card in _cardsManagerService.Cards)
        {
            Cards.Add(card);
        }
        
        IsDataLoaded = true;
    }
    
    public DelegateCommand EditCardCommand { set; get; }

    private void OnEditCard()
    {
        if (SelectedCard == null)
        {
            _windowService.ShowMessageBox("Выберите карту");
            return;
        }

        _windowService.ShowWindow<EditCardWindow>(new EditCardWindowViewModel(_cardsManagerService, SelectedCard)
        {
            Title = "Редактирование карты заданий"
        });
    }
    
    public DelegateCommand AddNewCardCommand { set; get; }

    private void OnAddNewCard()
    {
        _windowService.ShowWindow<EditCardWindow>(new EditCardWindowViewModel(_cardsManagerService, null)
        {
            Title = "Добавление новой карты заданий",
        });
    }
    
    public DelegateCommand RemoveCardCommand { set; get; }

    private void OnRemoveCardCommand()
    {
        if (SelectedCard == null)
        {
            _windowService.ShowMessageBox("Выберите карту");
            return;
        }
    }
    
    private bool _isDataLoaded;
    public bool IsDataLoaded
    {
        get => _isDataLoaded;
        set => SetProperty(ref _isDataLoaded, value); 
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