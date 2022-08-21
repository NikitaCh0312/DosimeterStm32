using System.Threading.Tasks;

namespace Dosimeter.Services.ConfigurationService.ConfigurationService.Interfaces;

public interface IConfigurationService
{
    Task LoadConfiguration();
    string SerialNumber { get; }
    string Model  { get; }
    string SoftwareVersion  { get; }
}