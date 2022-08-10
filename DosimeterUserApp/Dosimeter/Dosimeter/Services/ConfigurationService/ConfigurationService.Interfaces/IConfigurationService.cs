using System.Threading.Tasks;

namespace Dosimeter.Services.ConfigurationService.ConfigurationService.Interfaces;

public interface IConfigurationService
{
    Task LoadConfiguration();
    string SoftwareVersion { get; }
    string HardwareVersion { get; }
}