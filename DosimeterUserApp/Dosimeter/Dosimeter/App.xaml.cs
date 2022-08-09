using Prism.DryIoc;
using Prism.Ioc;
using System.Windows;
using Dosimeter.DAL.CardsManagerService.CardsManagerService.Implementations;
using Dosimeter.DAL.CardsManagerService.CardsManagerService.Interfaces;
using Dosimeter.DAL.ConfigurationService.ConfigurationService.Implementations;
using Dosimeter.DAL.ConfigurationService.ConfigurationService.Interfaces;
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
            containerRegistry.Register<IConfigurationService, ConfigurationService>();
            containerRegistry.Register<ICardsManagerService, CardsManagerService>();
        }

    }
}
