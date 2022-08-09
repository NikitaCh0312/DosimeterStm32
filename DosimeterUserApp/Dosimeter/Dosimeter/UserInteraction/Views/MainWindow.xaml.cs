using System.Windows;
using System.Windows.Input;


namespace Dosimeter.UserInteraction.Views
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private SelectorPage _selectorPage;
        private AboutPage _aboutPage;
        private EventLogPage _eventLogPage;
        private StoragePage _storagePage;
        private TaskCardsPage _taskCardsPage;
        
        public MainWindow()
        {
            InitializeComponent();
            _selectorPage = new SelectorPage();
            _aboutPage = new AboutPage();
            _eventLogPage = new EventLogPage();
            _storagePage = new StoragePage();
            _taskCardsPage = new TaskCardsPage();
        }

        private void UIElement_OnMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            
        }

        private void UIElement_OnMouseDown(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left)
                this.DragMove();
        }

        private void BackButton_OnClick(object sender, RoutedEventArgs e)
        {
            BackButton.Visibility = Visibility.Collapsed;
            container.Content = _selectorPage;
        }

        public void ExecutePage(PageType page)
        {
            BackButton.Visibility = Visibility.Visible;
            switch (page)
            {
                case PageType.Selector:
                    container.Content = _selectorPage;
                    break;
                case PageType.About:
                    container.Content = _aboutPage;
                    break;
                case PageType.Storage:
                    container.Content = _storagePage;
                    break;
                case PageType.EventLog:
                    container.Content = _eventLogPage;
                    break;
                case PageType.TaskCards:
                    container.Content = _taskCardsPage;
                    break;
            }
        }

        private void ButtonBase_OnClick(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }
}
