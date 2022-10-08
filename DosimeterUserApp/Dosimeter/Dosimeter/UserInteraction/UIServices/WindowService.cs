using System.Windows;

namespace Dosimeter.UserInteraction.UIServices;

public class WindowService:IWindowService
{
    public void ShowWindow<T>(object dataContext) where T : Window, new()
    {
        Window window = new T();
        window.DataContext = dataContext;
        window.Owner = Application.Current.MainWindow;
        window.Show();
    }

    public void ShowMessageBox(string message)
    {
        MessageBox.Show(message);
    }
}