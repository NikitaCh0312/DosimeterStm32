using System;
using System.Collections.Generic;
using System.Net.Http;
using Dosimeter.DAL.CardsManagerService.CardsManagerService.Interfaces;
using Dosimeter.DAL.CardsManagerService.CardsManagerService.Models;

namespace Dosimeter.DAL.CardsManagerService.CardsManagerService.Implementations;

public class CardsManagerService: ICardsManagerService
{
    private const int REQUEST_TIMEOUT_SEC = 5;
    private readonly HttpClient _httpClient;

    private List<Card> _cards;
    
    public CardsManagerService()
    {
        _httpClient = new HttpClient();
        _httpClient.Timeout = TimeSpan.FromSeconds(REQUEST_TIMEOUT_SEC);
        _cards = new List<Card>();
    }
        
    public List<Card> GetCards()
    {
        return _cards;
    }

    public void AddCard(Card card)
    {
        
    }
}