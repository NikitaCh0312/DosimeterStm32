using System;
using System.Collections.ObjectModel;
using Dosimeter.Services.EventLog.EventLog.Interfaces;
using Dosimeter.Services.EventLog.EventLog.Models;
using Prism.Commands;
using Prism.Mvvm;

namespace Dosimeter.UserInteraction.ViewModels;

public class EventLogPageViewModel:BindableBase
{
    private readonly IEventLogService _eventLogService;
    
    public EventLogPageViewModel(IEventLogService eventLogService)
    {
        _eventLogService = eventLogService;
        ViewLoadCommand = new DelegateCommand(OnViewLoaded);
        NextRecordsListCommand = new DelegateCommand(OnNextRecordCommandHandler);
        PreviousRecordsListCommand = new DelegateCommand(OnPreviousRecordCommandHandler);
        Records = new ObservableCollection<EventLogRecord>();
        for (int i = 0; i < 100; i++)
        {
            Records.Add(new EventLogRecord()
            {
                Id = i,
                EventId = i,
                DateTime = DateTime.Now,
                Description = "device starting device starting device starting",
                ExtraInfo = i * 10,
            });
        }
    }
    
    public DelegateCommand ViewLoadCommand { get; set; }

    private void OnViewLoaded()
    {
        IsDataLoaded = true;
    }
    
    public DelegateCommand NextRecordsListCommand { get; set; }

    private void OnNextRecordCommandHandler()
    {
        
    }
    
    public DelegateCommand PreviousRecordsListCommand { get; set; }
    private void OnPreviousRecordCommandHandler()
    {
        
    }
    
    private bool _isDataLoaded;
    public bool IsDataLoaded
    {
        get => _isDataLoaded;
        set => SetProperty(ref _isDataLoaded, value); 
    }
    
    public ObservableCollection<EventLogRecord> Records { set; get; }
    
    private int _displayRecordsNumber;
    public int DisplayRecordsNumber
    {
        get => _displayRecordsNumber;
        set
        {
            SetProperty(ref _displayRecordsNumber, value);   
        } 
    }
    
    private int _startRecordNumber;
    public int StartRecordNumber
    {
        get => _startRecordNumber;
        set
        {
            SetProperty(ref _startRecordNumber, value);
        }
    }
    
    private int _endRecordNumber;
    public int EndRecordNumber
    {
        get => _endRecordNumber;
        set
        {
            SetProperty(ref _endRecordNumber, value);
        }
    }
}