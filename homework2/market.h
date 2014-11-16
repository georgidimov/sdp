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
    size_t openCashesCount;

    Queue<Client *> expressCash;

    int expressCashGoodsLimit;

    size_t shortestQueue() const;

    void manageQueues();
    int openCash();
    void closeCash(size_t index);

    int IDs; //FIXME

    void addClientsToQueue(Client * clients, int clientsCount);
    void addClientToQueue(Client * clients);
    void processClients();

    void checkClient(Queue<Client *> * cash);
public:
    Market(int NumberOfAllCashDecks);
    ~Market();

    void AddClient(Client * clients, int number);
    MarketState getMarketState() const;
    ClientState getClientState(int ID);
};

