using System.Collections.Generic;
using System.Threading.Tasks;
using Dosimeter.Services.EventLog.EventLog.Models;

namespace Dosimeter.Services.EventLog.EventLog.Interfaces;

public interface IEventLogService
{
    Task<EventLogInfo> GetInfo();
    
    Task<List<EventLogRecord>> GetRecords(int startRecordNum, int endRecordNum);

    Task Clear();
}