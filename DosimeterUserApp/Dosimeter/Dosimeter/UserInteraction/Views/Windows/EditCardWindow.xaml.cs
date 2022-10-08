using System.Windows;
using System.Windows.Input;

namespace Dosimeter.UserInteraction.Views.Windows;

public partial class EditCardWindow : Window
{
    public EditCardWindow()
    {
        InitializeComponent();
    }

    private void ButtonClose_OnClick(object sender, RoutedEventArgs e)
    {
        this.Close();
    }
    
    private void UIElement_OnMouseDown(object sender, MouseButtonEventArgs e)
    {
        if (e.ChangedButton == MouseButton.Left)
            this.DragMove();
    }
}