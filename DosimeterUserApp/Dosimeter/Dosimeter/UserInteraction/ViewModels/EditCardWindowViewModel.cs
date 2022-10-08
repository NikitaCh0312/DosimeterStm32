using Dosimeter.Services.CardsManagerService.CardsManagerService.Models;
using Prism.Mvvm;

namespace Dosimeter.UserInteraction.ViewModels;

public class EditCardWindowViewModel : BindableBase
{
    public EditCardWindowViewModel()
    {

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
    

}