using Dosimeter.Services.Connection;
using Dosimeter.Services.EventLog.EventLog.Interfaces;

namespace Dosimeter.Services.EventLog.EventLog.Implementations;

public class EventLogService:IEventLogService
{
    private readonly IConnectionSettings _connectionSettings;

    public EventLogService(IConnectionSettings connectionSettings)
    {
        _connectionSettings = connectionSettings;
    }
}