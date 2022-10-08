using System.Windows;

namespace Dosimeter.UserInteraction.UIServices;

public interface IWindowService
{
    void ShowWindow<T>(object dataContext) where T : Window, new();
}