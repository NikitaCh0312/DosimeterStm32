using System;
using System.Collections.Generic;
using System.IO;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Dosimeter.Services.CardsManagerService.CardsManagerService.Interfaces;
using Dosimeter.Services.CardsManagerService.CardsManagerService.Models;
using Newtonsoft.Json;

namespace Dosimeter.DataAccess.CardsManagerService.CardsManagerService.Implementations;

public class CardsManagerService: ICardsManagerService
{
    private const int REQUEST_TIMEOUT_SEC = 2;
    private readonly HttpClient _httpClient;

    private const string _requestTemplate = @"http://{0}:{1}/api/{2}";
    
    private List<Card> _cards;
    private CardsInfo _cardsInfo;
    
    public CardsManagerService()
    {
        _httpClient = new HttpClient();
        _httpClient.Timeout = TimeSpan.FromSeconds(REQUEST_TIMEOUT_SEC);
        _cards = new List<Card>();
    }

    public async Task LoadCards()
    {
        _cardsInfo = await LoadCardsInfo();
        foreach (var cardId in _cardsInfo.CardIds)
        {
            _cards.Add(await LoadCard(cardId));
        }
    }

    public CardsInfo CardsInfo => _cardsInfo;
    
    public List<Card> Cards => _cards;

    public Task AddCard(Card card)
    {
        return Task.CompletedTask;
    }

    public Task RemoveCard(int cardId)
    {
        return Task.CompletedTask;
    }
    private async Task<CardsInfo> LoadCardsInfo()
    {
        try
        {
            await using var stream = await _httpClient.GetStreamAsync( CreateRequest("192.168.0.55", "666", "get_cards_info"));
            using var reader = new StreamReader(stream);
            using JsonReader jsonReader = new JsonTextReader(reader);
            JsonSerializer serializer = new JsonSerializer();
            return serializer.Deserialize<CardsInfo>(jsonReader);
        }
        catch (Exception exc)
        {
            return null;
        }
    }

    private async Task<Card> LoadCard(int cardId)
    {
        try
        {
            await using var stream = await _httpClient.GetStreamAsync( CreateRequest("192.168.0.55", "666", "get_card"));
            using var reader = new StreamReader(stream);
            using JsonReader jsonReader = new JsonTextReader(reader);
            JsonSerializer serializer = new JsonSerializer();
            return serializer.Deserialize<Card>(jsonReader);
        }
        catch (Exception e)
        {
            return null;
        }
    }

    private string CreateRequest(string ip, string port, string uri, string query = null)
    {
        StringBuilder requestBuilder = new StringBuilder();
        return requestBuilder.Append(String.Format(_requestTemplate, ip, port, uri)).Append(query).ToString();
    }
}