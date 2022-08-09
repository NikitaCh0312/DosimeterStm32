using System;
using System.Windows.Threading;
using Prism.Mvvm;

namespace Dosimeter.UserInteraction.ViewModels
{
    public class MainWindowViewModel : BindableBase
    {
        private DispatcherTimer _timer;
        
        private string _title = "Дозатор растворов";
        public string Title
        {
            get => _title;
            set => SetProperty(ref _title, value); 
        }

        private string _time;
        public string Time
        {
            get => _time;
            set => SetProperty(ref _time, value); 
        }
        
        private string _weekDay;
        public string WeekDay
        {
            get => _weekDay;
            set => SetProperty(ref _weekDay, value); 
        }
        
        private string _date;
        public string Date
        {
            get => _date;
            set => SetProperty(ref _date, value); 
        }
        
        public MainWindowViewModel()
        {
            _timer = new DispatcherTimer();
            _timer.Interval = TimeSpan.FromSeconds(1);
            _timer.Tick += _onTimerTick;
            _timer.Start();
        }
        
        private void _onTimerTick(object sender, EventArgs e)
        {
            var dateTime = DateTime.Now;
            Time = TimeOnly.FromDateTime(dateTime).ToString("hh:mm:ss");
            Date = DateOnly.FromDateTime(dateTime).ToString();
            WeekDay = dateTime.DayOfWeek.ToString();
        }
    }
}
