﻿using System;
using System.IO;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Dosimeter.Services.ConfigurationService.ConfigurationService.Interfaces;
using Dosimeter.Services.ConfigurationService.ConfigurationService.Models;
using Newtonsoft.Json;

namespace Dosimeter.Services.ConfigurationService.ConfigurationService.Implementations;

public class ConfigurationService: IConfigurationService
{
    private readonly HttpClient _httpClient;
    private const string _requestTemplate = @"http://{0}:{1}/api/{2}";
    
    public ConfigurationService()
    {
        _httpClient = new HttpClient();
        _httpClient.Timeout =TimeSpan.FromSeconds(2);
    }
    public async Task<Configuration> Get()
    {
        try
        {
            var request = CreateRequest("192.168.0.55", "666", "get_config");
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

    public Task Set(Configuration configuration)
    {
        return Task.CompletedTask;
    }
    
    private string CreateRequest(string ip, string port, string uri, string query = null)
    {
        StringBuilder requestBuilder = new StringBuilder();
        return requestBuilder.Append(String.Format(_requestTemplate, ip, port, uri)).Append(query).ToString();
    }
}