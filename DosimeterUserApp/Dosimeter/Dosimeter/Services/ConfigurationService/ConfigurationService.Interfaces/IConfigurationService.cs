using System.Threading.Tasks;
using Dosimeter.Services.ConfigurationService.ConfigurationService.Models;

namespace Dosimeter.Services.ConfigurationService.ConfigurationService.Interfaces;

public interface IConfigurationService
{
    public Task<Configuration> Get();
    public Task Set(Configuration configuration);
}