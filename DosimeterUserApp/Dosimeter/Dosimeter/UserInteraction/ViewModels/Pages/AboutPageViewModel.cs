using Dosimeter.DataAccess.ConfigurationService.ConfigurationService.Interfaces;
using Prism.Mvvm;

namespace Dosimeter.UserInteraction.ViewModels;

public class AboutPageViewModel : BindableBase
{
    private readonly IConfigurationService _configurationService;
    
    public AboutPageViewModel(IConfigurationService configurationService)
    {
        _configurationService = configurationService;
        SoftwareVersion = _configurationService.GetSoftwareVersion();
        HardwareVersion = _configurationService.GetHardwareVersion();
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