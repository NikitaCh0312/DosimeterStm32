﻿using System;
using System.Globalization;
using System.Windows;
using System.Windows.Data;

namespace Dosimeter.UserInteraction.Views.Converters;

public class BoolToVisibilityConverter: IValueConverter
{
    public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
    {
        var val = (bool)value;
        return val ? Visibility.Visible : Visibility.Hidden;
    }

    public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
    {
        throw new NotImplementedException();
    }
}