using System;
using System.IO;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Dosimeter.Services.ConfigurationService.ConfigurationService.Interfaces;
using Dosimeter.Services.ConfigurationService.ConfigurationService.Models;
using Dosimeter.Services.Connection;
using Newtonsoft.Json;

namespace Dosimeter.Services.ConfigurationService.ConfigurationService.Implementations;

public class ConfigurationService: IConfigurationService
{
    private readonly HttpClient _httpClient;
    private const string _requestTemplate = @"http://{0}:{1}/api/{2}";
    private readonly IConnectionSettings _connectionSettings;
    
    public ConfigurationService(IConnectionSettings connectionSettings)
    {
        _httpClient = new HttpClient();
        _httpClient.Timeout = TimeSpan.FromSeconds(5);
        _connectionSettings = connectionSettings;
    }
    public async Task<Configuration> Get()
    {
        try
        {
            var request = CreateRequest(_connectionSettings.Ip, _connectionSettings.Port, "get_config");
            await using var stream = await _httpClient.GetStreamAsync(request);
            using var reader = new StreamReader(stream);
            using JsonReader jsonReader = new JsonTextReader(reader);
            JsonSerializer serializer = new JsonSerializer();
            return serializer.Deserialize<Configuration>(jsonReader);
        }
        catch (Exception e)
        {
            return null;
        }
    }

    public async Task Set(Configuration configuration)
    {
        try
        {
            var request = CreateRequest(_connectionSettings.Ip, _connectionSettings.Port, "set_config", "?ip=192.168.36.77&mask=255.255.255.0&port=666&date=" + configuration.Date + "&time="+ configuration.Time);
            var stream = await _httpClient.PostAsync(request, null);
        }
        catch (Exception e)
        {
            
        }

    }
    
    private string CreateRequest(string ip, string port, string uri, string query = null)
    {
        StringBuilder requestBuilder = new StringBuilder();
        return requestBuilder.Append(String.Format(_requestTemplate, ip, port, uri)).Append(query).ToString();
    }
}