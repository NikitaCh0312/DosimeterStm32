using Dosimeter.Services.ConfigurationService.ConfigurationService.Interfaces;
using Prism.Commands;
using Prism.Mvvm;

namespace Dosimeter.UserInteraction.ViewModels;

public class AboutPageViewModel : BindableBase
{
    private readonly IConfigurationService _configurationService;
    
    public AboutPageViewModel(IConfigurationService configurationService)
    {
        _configurationService = configurationService;
        
        ViewLoadCommand = new DelegateCommand(OnViewLoaded);
    }
    
    public DelegateCommand ViewLoadCommand { get; set; }
    private async void OnViewLoaded()
    {
        await _configurationService.LoadConfiguration();
        SoftwareVersion = _configurationService.SoftwareVersion;
        HardwareVersion = _configurationService.HardwareVersion;
    }
    
    private string _softwareVersion = "";
    public string SoftwareVersion
    {
        get => _softwareVersion;
        set => SetProperty(ref _softwareVersion, value); 
    }

    private string _hardwareVersion = "";
    public string HardwareVersion
    {
        get => _hardwareVersion;
        set => SetProperty(ref _hardwareVersion, value); 
    }
}