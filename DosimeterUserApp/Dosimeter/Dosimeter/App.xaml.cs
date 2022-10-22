using Prism.DryIoc;
using Prism.Ioc;
using System.Windows;
using Dosimeter.DataAccess.CardsManagerService.CardsManagerService.Implementations;
using Dosimeter.Services.CardsManagerService.CardsManagerService.Interfaces;
using Dosimeter.Services.ConfigurationService.ConfigurationService.Implementations;
using Dosimeter.Services.ConfigurationService.ConfigurationService.Interfaces;
using Dosimeter.Services.DeviceInfoService.DeviceInfoService.Implementations;
using Dosimeter.Services.DeviceInfoService.DeviceInfoService.Interfaces;
using Dosimeter.Services.EventLog.EventLog.Implementations;
using Dosimeter.Services.EventLog.EventLog.Interfaces;
using Dosimeter.UserInteraction.UIServices;
using Dosimeter.UserInteraction.Views;

namespace Dosimeter
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App: PrismApplication
    {
        protected override Window CreateShell()
        {
            return Container.Resolve<MainWindow>();
        }

        protected override void RegisterTypes(IContainerRegistry containerRegistry)
        {
            containerRegistry.Register<IDeviceInfoService, DeviceInfoService>();
            containerRegistry.Register<ICardsManagerService, CardsManagerService>();
            containerRegistry.Register<IConfigurationService, ConfigurationService>();
            containerRegistry.Register<IEventLogService, EventLogService>();
            containerRegistry.Register<IWindowService, WindowService>();
        }
    }
}
