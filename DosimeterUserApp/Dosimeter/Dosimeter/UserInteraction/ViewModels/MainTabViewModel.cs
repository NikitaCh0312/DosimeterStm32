using Prism.Mvvm;
using System;
using System.Collections.Generic;
using System.Text;

namespace Dosimeter.UserInteraction.ViewModels
{
    public class MainTabViewModel: BindableBase
    {
        public MainTabViewModel()
        {

        }

        private string _mainTabTitle = "Main Tab view model";
        public string MainTabTitle
        {
            get => _mainTabTitle;
            set => SetProperty(ref _mainTabTitle, value);
        }
    }
}
