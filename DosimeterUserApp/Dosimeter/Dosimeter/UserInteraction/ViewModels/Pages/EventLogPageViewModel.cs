using Dosimeter.Services.EventLog.EventLog.Interfaces;
using Prism.Commands;
using Prism.Mvvm;

namespace Dosimeter.UserInteraction.ViewModels;

public class EventLogPageViewModel:BindableBase
{
    private readonly IEventLogService _eventLogService;
    
    public EventLogPageViewModel(IEventLogService eventLogService)
    {
        _eventLogService = eventLogService;
        ViewLoadCommand = new DelegateCommand(OnViewLoaded);
    }
    
    public DelegateCommand ViewLoadCommand { get; set; }

    private void OnViewLoaded()
    {
        
    }
}