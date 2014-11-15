#pragma once
#include <queue.hpp>
#include <marketState.h>
#include <client.h>
#include <clientState.h>

class Market{
    int cashNumers;
    Queue<Client *> * cashes;
public:
    Market(int NumberOfAllCashDecks);
    ~Market();

    void AddClient(Client * clients, int number);
    MarketState getMarketState() const;
    ClientState getClientState(int ID);
};

