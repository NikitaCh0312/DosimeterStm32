using System;
using System.Collections.Generic;
using System.Windows;
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
        IsEdittingActive = true;
        SelectedCard = card ?? new Card(){ Tasks = new List<CardTask>()};
        ApplyCardCommand = new DelegateCommand<object>(OnApplyCardCommand, CanExecuteCommand);
    }
    
    public event EventHandler DataUpdatedEvent;
    
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

    private bool _isEdittingActive;
    public bool IsEdittingActive
    {
        get => _isEdittingActive;
        set => SetProperty(ref _isEdittingActive, value); 
    }
    
    public DelegateCommand<object> ApplyCardCommand { private set; get; }

    private async void OnApplyCardCommand(object obj)
    {
        IsEdittingActive = false;
        await _cardsManagerService.AddOrUpdateCard(SelectedCard);
        DataUpdatedEvent?.Invoke(this, EventArgs.Empty);
        IsEdittingActive = true;
        Window window = (Window)obj;
        window.Close();
        DataUpdatedEvent = null;
    }

    private bool CanExecuteCommand(object obj)
    {
        return true;
    }
}