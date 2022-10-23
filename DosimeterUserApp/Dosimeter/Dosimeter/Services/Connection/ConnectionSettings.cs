namespace Dosimeter.Services.Connection;

public class ConnectionSettings : IConnectionSettings
{
    public ConnectionSettings()
    {
        Ip = "192.168.0.55";
        Port = "666";
    }
    
    public string Ip { get; set; }
    
    public string Port { get; set; }
}