using System.Windows;
using System.Windows.Controls;
using MahApps.Metro.IconPacks;

namespace Dosimeter.UserInteraction.Views.UserControls;

public partial class ElementSelector : UserControl
{
    public ElementSelector()
    {
        InitializeComponent();
    }

    public string Title
    {
        get { return (string)GetValue(TitleProperty); }
        set { SetValue(TitleProperty, value) ;}
    }
    public static readonly DependencyProperty TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(ElementSelector));
    
    public PackIconMaterialKind Icon
    {
        get { return (PackIconMaterialKind)GetValue(IconProperty); }
        set { SetValue(IconProperty, value) ;}
    }
    public static readonly DependencyProperty IconProperty = DependencyProperty.Register("Icon", typeof(string), typeof(ElementSelector));

    public bool IsActive
    {
        get { return (bool)GetValue(IsActiveProperty); }
        set { SetValue(IsActiveProperty, value) ;}
    }
    public static readonly DependencyProperty IsActiveProperty = DependencyProperty.Register("IsActive", typeof(string), typeof(ElementSelector));

    public event RoutedEventHandler ElementSelectorClick
    {
        add { AddHandler(ElementClickEvent, value); }
        remove { RemoveHandler(ElementClickEvent, value);}
    }
    public static readonly RoutedEvent ElementClickEvent =
        EventManager.RegisterRoutedEvent("ElementClick", RoutingStrategy.Bubble, typeof(RoutedEventHandler),
            typeof(ElementSelector));

    void Button_Click(object sender, RoutedEventArgs e) => RaiseEvent(new RoutedEventArgs(ElementClickEvent));
}