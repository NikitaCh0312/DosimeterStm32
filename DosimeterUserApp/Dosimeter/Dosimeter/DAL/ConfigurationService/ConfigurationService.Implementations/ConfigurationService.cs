using System.Net.Http;
using Dosimeter.DAL.ConfigurationService.ConfigurationService.Interfaces;

namespace Dosimeter.DAL.ConfigurationService.ConfigurationService.Implementations;

public class ConfigurationService:IConfigurationService
{
    private readonly HttpClient _httpClient;
    
    public ConfigurationService()
    {
        _httpClient = new HttpClient();
    }
    
    public string GetSoftwareVersion()
    {
        return "2.0.1";
    }

    public string GetHardwareVersion()
    {
        return "1.0.0";
    }
}