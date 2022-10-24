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
    private readonly Dictionary<int, string> _eventIdDescription;

    public EventLogService(IConnectionSettings connectionSettings)
    {
        _httpClient = new HttpClient();
        _httpClient.Timeout = TimeSpan.FromSeconds(3);
        _eventIdDescription = new Dictionary<int, string>()
        {
            { 1, "Устройство сконфигурировано" },
            { 21, "Питающее напряжение вне установленного предела" },
            { 22, "Недостаточный уровень препарата в баке" },
            { 23, "Недостаточное давление воды в магистрали" },
            { 31, "Идентифицирована карта не закрепленная за данным устройством" },
            { 32, "Идентифицирована неактивная карта" },
            { 33, "Идентифицирована карта расширенного доступа" },
            { 34, "Идентифицирована актуальная карта заданий" },
            { 35, "Работа с картой прекращена из-за сбоя" },
            { 36, "Работа с картой завершена успешно: выполнены все задания" },
            { 37, "Работа с картой завершена успешно: отменены задания" },
            { 38, "Задание отменено во время выполнения" },
            { 39, "Карта заданий отменена" },
            { 41, "Карта заданий отменена" },
            { 42, "Карта заданий отменена" },
            { 43, "Карта заданий отменена" },
        };
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
                await Task.Delay(50);
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
        var request = CreateRequest(_connectionSettings.Ip, _connectionSettings.Port, "get_event_record", $"?event_number={recordNum}");
        await using var stream = await _httpClient.GetStreamAsync(request);
        using var reader = new StreamReader(stream);
        using JsonReader jsonReader = new JsonTextReader(reader);
        JsonSerializer serializer = new JsonSerializer();
        return serializer.Deserialize<EventLogItem>(jsonReader);
    }

    private EventLogRecord Convert(EventLogItem item)
    {
        _eventIdDescription.TryGetValue(item.EventId, out string description);
        return new EventLogRecord()
        {
            Id = item.Id,
            EventId = item.EventId,
            DateTime = DateTime.Parse(item.DateTime),
            Description = description ?? "",
            ExtraInfo = item.ExtraInfo
        };
    }
    
    private string CreateRequest(string ip, string port, string uri, string query = null)
    {
        StringBuilder requestBuilder = new StringBuilder();
        return requestBuilder.Append(String.Format(_requestTemplate, ip, port, uri)).Append(query).ToString();
    }
}