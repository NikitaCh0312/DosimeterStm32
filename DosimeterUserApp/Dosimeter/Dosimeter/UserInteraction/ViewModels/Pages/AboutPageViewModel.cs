using Dosimeter.Services.DeviceInfoService.DeviceInfoService.Interfaces;
using Prism.Commands;
using Prism.Mvvm;

namespace Dosimeter.UserInteraction.ViewModels;

public class AboutPageViewModel : BindableBase
{
    private readonly IDeviceInfoService _deviceInfoService;
    
    public AboutPageViewModel(IDeviceInfoService deviceInfoService)
    {
        _deviceInfoService = deviceInfoService;
        
        ViewLoadCommand = new DelegateCommand(OnViewLoaded);
    }
    
    public DelegateCommand ViewLoadCommand { get; set; }
    private async void OnViewLoaded()
    {
        await _deviceInfoService.LoadDeviceInfo();
        SoftwareVersion = _deviceInfoService.SoftwareVersion ?? "undefined";
        Model = _deviceInfoService.Model ?? "undefined";
        SerialNumber = _deviceInfoService.SerialNumber ?? "undefined";
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