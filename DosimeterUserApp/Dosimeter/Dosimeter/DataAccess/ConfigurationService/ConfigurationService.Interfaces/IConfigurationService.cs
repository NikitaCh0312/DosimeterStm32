namespace Dosimeter.DataAccess.ConfigurationService.ConfigurationService.Interfaces;

public interface IConfigurationService
{
    string GetSoftwareVersion();
    string GetHardwareVersion();
}