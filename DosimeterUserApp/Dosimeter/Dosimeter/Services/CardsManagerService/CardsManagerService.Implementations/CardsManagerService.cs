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
    private const int REQUEST_TIMEOUT_SEC = 4;
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
        _cards.Clear();
        
        _cardsInfo = await LoadCardsInfo();
        if (_cardsInfo == null)
            return;
        
        await Task.Delay(100);
        
        foreach (var cardId in _cardsInfo.CardIds)
        {
            var card = await LoadCard(cardId);
            if (card != null)
                _cards.Add(card);
            await Task.Delay(100);
        }
    }
    
    public List<Card> Cards => _cards;

    public async Task AddOrUpdateCard(Card card)
    {
        var query = CreateCardQuery(card);
        await _httpClient.GetAsync( CreateRequest("192.168.0.55", "666", "add_or_update_card", query));
    }
    
    public async Task RemoveCard(int cardId)
    {
        try
        {
            var response = await _httpClient.GetAsync( CreateRequest("192.168.0.55", "666", "remove_card", $"?card_id={cardId}"));
        }
        catch (Exception exc)
        {
            // ignored
        }
    }
    
    private async Task<CardsInfo> LoadCardsInfo()
    {
        try
        {
            await using var stream = await _httpClient.GetStreamAsync( CreateRequest("192.168.0.55", "666", "get_cards_list"));
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
            await using var stream = await _httpClient.GetStreamAsync( CreateRequest("192.168.0.55", "666", "get_card_info", $"?card_id={cardId}"));
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

    private string CreateCardQuery(Card card)
    {
        StringBuilder builder = new StringBuilder();
        builder.Append($"?card_id={card.Id}&quantity={card.Tasks.Count}&substanceId={card.SubstanceId}");
        for (int i = 0; i < card.Tasks.Count; i++)
        {
            builder.Append($"&v{i + 1}={card.Tasks[i].Volume}&c{i + 1}={card.Tasks[i].Concentration}");
        }
        return builder.ToString();
    }
}