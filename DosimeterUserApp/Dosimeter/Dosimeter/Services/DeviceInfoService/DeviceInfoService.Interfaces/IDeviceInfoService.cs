using System.Threading.Tasks;

namespace Dosimeter.Services.DeviceInfoService.DeviceInfoService.Interfaces;

public interface IDeviceInfoService
{
    Task LoadDeviceInfo();
    string SerialNumber { get; }
    string Model  { get; }
    string SoftwareVersion  { get; }
}