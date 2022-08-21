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
        SoftwareVersion = _configurationService.SoftwareVersion ?? "undefined";
        Model = _configurationService.Model ?? "undefined";
        SerialNumber = _configurationService.SerialNumber ?? "undefined";
    }
    
    private string _softwareVersion = "";
    public string SoftwareVersion
    {
        get => _softwareVersion;
        set => SetProperty(ref _softwareVersion, value); 
    }

    private string _model = "";
    public string Model
    {
        get => _model;
        set => SetProperty(ref _model, value); 
    }
    
    private string _serialNumber = "";
    public string SerialNumber
    {
        get => _serialNumber;
        set => SetProperty(ref _serialNumber, value); 
    }
}