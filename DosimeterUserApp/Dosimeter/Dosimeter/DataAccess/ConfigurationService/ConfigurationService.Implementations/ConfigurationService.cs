using System.Net.Http;
using Dosimeter.DataAccess.ConfigurationService.ConfigurationService.Interfaces;

namespace Dosimeter.DataAccess.ConfigurationService.ConfigurationService.Implementations;

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