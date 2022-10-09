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
        _cards.Add(new Card()
        {
            Id = 90000,
            SubstanceId = 30000,
            Tasks = new List<CardTask>()
            {
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
            }
        });
        _cards.Add(new Card()
        {
            Id = 90001,
            SubstanceId = 30001,
            Tasks = new List<CardTask>()
            {
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
            }
        });
        _cards.Add(new Card()
        {
            Id = 90002,
            SubstanceId = 30002,
            Tasks = new List<CardTask>()
            {
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
                new CardTask()
                {
                    Id = 1,
                    Concentration = 0.05f,
                    Volume = 5
                },
            }
        });
    }

    public async Task LoadCards()
    {
        _cardsInfo = await LoadCardsInfo();
        if (_cardsInfo == null)
            return;
        
        foreach (var cardId in _cardsInfo.CardIds)
        {
            _cards.Add(await LoadCard(cardId));
        }
    }
    
    public List<Card> Cards => _cards;

    public async Task AddOrUpdateCard(Card card)
    {
        var query = CreateCardQuery(card);
        if (Cards.Contains(card))
        {
            var response = await _httpClient.GetAsync( CreateRequest("192.168.0.55", "666", "update_card", query));
            return;
        }
        await _httpClient.GetAsync( CreateRequest("192.168.0.55", "666", "add_card", query));
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
            await using var stream = await _httpClient.GetStreamAsync( CreateRequest("192.168.0.55", "666", "get_card", $"?card_id={cardId}"));
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
        return null;
    }
}