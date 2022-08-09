namespace Dosimeter.DAL.ConfigurationService.ConfigurationService.Interfaces;

public interface IConfigurationService
{
    string GetSoftwareVersion();
    string GetHardwareVersion();
}