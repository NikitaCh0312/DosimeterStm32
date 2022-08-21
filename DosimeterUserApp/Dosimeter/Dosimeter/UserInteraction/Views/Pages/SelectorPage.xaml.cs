using System.Windows;
using System.Windows.Controls;

namespace Dosimeter.UserInteraction.Views;

public partial class SelectorPage : UserControl
{
    private MainWindow _window;
    
    public SelectorPage()
    {
        InitializeComponent();
    }

    private void LoadWindow()
    {
        _window ??= Window.GetWindow(App.Current.MainWindow) as MainWindow;
    }
    
    private void AboutPageClicked(object sender, RoutedEventArgs e)
    {
        LoadWindow();
        _window.ExecutePage(PageType.About);
    }
    
    private void ConfigurationPageClicked(object sender, RoutedEventArgs e)
    {
        LoadWindow();
        _window.ExecutePage(PageType.Configuration);
    }
    
    private void EventLogPageClicked(object sender, RoutedEventArgs e)
    {
        LoadWindow();
        _window.ExecutePage(PageType.EventLog);
    }
    
    private void TaskCardsPageClicked(object sender, RoutedEventArgs e)
    {
        LoadWindow();
        _window.ExecutePage(PageType.TaskCards);
    }
}