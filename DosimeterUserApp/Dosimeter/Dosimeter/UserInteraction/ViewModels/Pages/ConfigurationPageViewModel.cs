using System;
using System.Windows.Documents;
using Dosimeter.Services.ConfigurationService.ConfigurationService.Interfaces;
using Dosimeter.Services.ConfigurationService.ConfigurationService.Models;
using Prism.Commands;
using Prism.Mvvm;

namespace Dosimeter.UserInteraction.ViewModels;

public class ConfigurationPageViewModel:BindableBase
{
    private readonly IConfigurationService _configurationService;
    
    public ConfigurationPageViewModel(IConfigurationService configurationService)
    {
        _configurationService = configurationService;
        ViewLoadCommand = new DelegateCommand(OnViewLoaded);
        SetConfigurationCommand = new DelegateCommand(SetConfiguration);
        IsConfigurationLoaded = false;
    }
    
    public DelegateCommand ViewLoadCommand { get; set; }
    private async void OnViewLoaded()
    {
        IsConfigurationLoaded = false;
        var config = await _configurationService.Get();
        Ip = config?.Ip ?? "not connected";
        Port = config?.Port.ToString();
        Mask = config?.Mask ?? "not connected";
        Date = DateTime.Now;
        Time = DateTime.Now;
        IsConfigurationLoaded = true;
    }
    
    public DelegateCommand SetConfigurationCommand { get; private set; }

    private async void SetConfiguration()
    {
        var config = new Configuration()
        {
            Ip = Ip,
            Port = 666,//Int32.Parse(Port),
            Mask = Mask,
            Date = Date.ToString("d"),
            Time = Time.ToString("HH:mm")
        };
        await _configurationService.Set(config);
    }
    
    private bool _isConfigurationLoaded;
    public bool IsConfigurationLoaded
    {
        get => _isConfigurationLoaded;
        set => SetProperty(ref _isConfigurationLoaded, value); 
    }
    
    private string _ip = "";
    public string Ip
    {
        get => _ip;
        set => SetProperty(ref _ip, value); 
    }
    
    private string _port;
    public string Port
    {
        get => _port;
        set => SetProperty(ref _port, value); 
    }
    
    private string _mask = "";
    public string Mask
    {
        get => _mask;
        set => SetProperty(ref _mask, value); 
    }
    
    private DateTime _date;
    public DateTime Date
    {
        get => _date;
        set => SetProperty(ref _date, value); 
    }
    
    private DateTime _time;
    public DateTime Time
    {
        get => _time;
        set => SetProperty(ref _time, value); 
    }
}