using System;
using System.Globalization;
using System.Windows.Data;

namespace Dosimeter.UserInteraction.Views.Converters;

public class BoolToBoolInvertedConverter : IValueConverter
{
    public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
    {
        var val = value != null && (bool)value;
        return !val;
    }

    public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
    {
        throw new NotImplementedException();
    }
}