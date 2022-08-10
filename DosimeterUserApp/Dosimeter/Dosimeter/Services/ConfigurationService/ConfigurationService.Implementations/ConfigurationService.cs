using System;
using System.IO;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Dosimeter.Services.ConfigurationService.ConfigurationService.Interfaces;
using Dosimeter.Services.ConfigurationService.ConfigurationService.Models;
using Newtonsoft.Json;

namespace Dosimeter.Services.ConfigurationService.ConfigurationService.Implementations;

public class ConfigurationService:IConfigurationService
{
    private const string _requestTemplate = @"http://{0}:{1}/api/{2}";
    private readonly HttpClient _httpClient;

    private Configuration _configuration;
    
    public ConfigurationService()
    {
        _httpClient = new HttpClient();
    }

    public async Task LoadConfiguration()
    {
        try
        {
            await using var stream = await _httpClient.GetStreamAsync( CreateRequest("192.168.0.55", "666", "get_configuration"));
            using var reader = new StreamReader(stream);
            using JsonReader jsonReader = new JsonTextReader(reader);
            JsonSerializer serializer = new JsonSerializer();
            _configuration = serializer.Deserialize<Configuration>(jsonReader);
        }
        catch (Exception e)
        {
            // ignored
        }
    }
    
    public string SoftwareVersion => "2.0.1";
    public string HardwareVersion => "1.0.0";
    
    private string CreateRequest(string ip, string port, string uri, string query = null)
    {
        StringBuilder requestBuilder = new StringBuilder();
        return requestBuilder.Append(String.Format(_requestTemplate, ip, port, uri)).Append(query).ToString();
    }
}