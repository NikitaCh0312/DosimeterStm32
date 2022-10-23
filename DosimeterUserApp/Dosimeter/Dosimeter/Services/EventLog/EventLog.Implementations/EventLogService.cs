using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Dosimeter.Services.Connection;
using Dosimeter.Services.EventLog.EventLog.Interfaces;
using Dosimeter.Services.EventLog.EventLog.Models;
using Newtonsoft.Json;

namespace Dosimeter.Services.EventLog.EventLog.Implementations;

public class EventLogService:IEventLogService
{
    private readonly HttpClient _httpClient;
    private const string _requestTemplate = @"http://{0}:{1}/api/{2}";
    private readonly IConnectionSettings _connectionSettings;

    public EventLogService(IConnectionSettings connectionSettings)
    {
        _httpClient = new HttpClient();
        _httpClient.Timeout = TimeSpan.FromSeconds(3);
        _connectionSettings = connectionSettings;
    }

    public async Task<EventLogInfo> GetInfo()
    {
        try
        {
            var request = CreateRequest(_connectionSettings.Ip, _connectionSettings.Port, "event_log_info");
            await using var stream = await _httpClient.GetStreamAsync(request);
            using var reader = new StreamReader(stream);
            using JsonReader jsonReader = new JsonTextReader(reader);
            JsonSerializer serializer = new JsonSerializer();
            return serializer.Deserialize<EventLogInfo>(jsonReader);
        }
        catch (Exception e)
        {
            return null;
        }
    }
    
    public async Task<List<EventLogRecord>> GetRecords(int startRecordNum, int endRecordNum)
    {
        try
        {
            List<EventLogRecord> records = new List<EventLogRecord>();
            for (int i = startRecordNum; i <= endRecordNum; i++)
            {
                var record = Convert(await GetEventLogRecord(i));
                records.Add(record);
            }
            return records;
        }
        catch (Exception e)
        {
            return null;
        }

    }

    public async Task Clear()
    {
        try
        {
            var request = CreateRequest(_connectionSettings.Ip, _connectionSettings.Port, "clear_event_log");
            await using var stream = await _httpClient.GetStreamAsync(request);
        }
        catch (Exception e)
        {
            
        }
    }

    private async Task<EventLogItem> GetEventLogRecord(int recordNum)
    {
        var request = CreateRequest(_connectionSettings.Ip, _connectionSettings.Port, "get_event_log", $"?event_number={recordNum}");
        await using var stream = await _httpClient.GetStreamAsync(request);
        using var reader = new StreamReader(stream);
        using JsonReader jsonReader = new JsonTextReader(reader);
        JsonSerializer serializer = new JsonSerializer();
        return serializer.Deserialize<EventLogItem>(jsonReader);
    }

    private EventLogRecord Convert(EventLogItem item)
    {
        return new EventLogRecord()
        {
            Id = item.Id,
            EventId = item.EventId,
            DateTime = item.DateTime,
            Description = "add event description here",
            ExtraInfo = item.ExtraInfo
        };
    }
    
    private string CreateRequest(string ip, string port, string uri, string query = null)
    {
        StringBuilder requestBuilder = new StringBuilder();
        return requestBuilder.Append(String.Format(_requestTemplate, ip, port, uri)).Append(query).ToString();
    }
}