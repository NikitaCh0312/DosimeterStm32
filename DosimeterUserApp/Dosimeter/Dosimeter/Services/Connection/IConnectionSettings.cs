namespace Dosimeter.Services.Connection;

public interface IConnectionSettings
{
    public string Ip { set; get; }
    
    public string Port { set; get; }
}