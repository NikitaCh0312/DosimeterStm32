using System;
using System.IO;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Dosimeter.Services.Connection;
using Dosimeter.Services.DeviceInfoService.DeviceInfoService.Interfaces;
using Dosimeter.Services.DeviceInfoService.DeviceInfoService.Models;
using Newtonsoft.Json;

namespace Dosimeter.Services.DeviceInfoService.DeviceInfoService.Implementations;

public class DeviceInfoService:IDeviceInfoService
{
    private const string _requestTemplate = @"http://{0}:{1}/api/{2}";
    private readonly HttpClient _httpClient;
    private readonly IConnectionSettings _connectionSettings;

    private DeviceInfo _deviceInfo;
    
    public DeviceInfoService(IConnectionSettings connectionSettings)
    {
        _httpClient = new HttpClient();
        _httpClient.Timeout = TimeSpan.FromSeconds(1);
        _connectionSettings = connectionSettings;
    }

    public async Task LoadDeviceInfo()
    {
        try
        {
            await using var stream = await _httpClient.GetStreamAsync( CreateRequest(_connectionSettings.Ip, _connectionSettings.Port, "description"));
            using var reader = new StreamReader(stream);
            using JsonReader jsonReader = new JsonTextReader(reader);
            JsonSerializer serializer = new JsonSerializer();
            _deviceInfo = serializer.Deserialize<DeviceInfo>(jsonReader);
        }
        catch (Exception e)
        {
            // ignored
            _deviceInfo = null;
        }
    }

    public string SerialNumber => _deviceInfo?.SerialNumber;
    public string Model => _deviceInfo?.Model;
    public string SoftwareVersion => _deviceInfo?.SoftwareVersion;
    
    private string CreateRequest(string ip, string port, string uri, string query = null)
    {
        StringBuilder requestBuilder = new StringBuilder();
        return requestBuilder.Append(String.Format(_requestTemplate, ip, port, uri)).Append(query).ToString();
    }
}