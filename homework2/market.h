#pragma once
#include <queue.hpp>
#include <marketState.h>
#include <client.h>
#include <clientState.h>
#include <list.hpp>

class Market{
    size_t cashCount;  // or N

    List<Queue<Client *> * > cashes;
    bool * openCashes;

    Queue<Client *> expressCash;

    int expressCashGoodsLimit;

    size_t shortestQueue() const;

    void manageQueues();
    int openCash();

    int IDs; //FIXME
public:
    Market(int NumberOfAllCashDecks);
    ~Market();

    void AddClient(Client * clients, int number);
    MarketState getMarketState() const;
    ClientState getClientState(int ID);

};

