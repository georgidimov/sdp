#include "market.h"

Market :: Market(int NumberOfAllCashDecks){
    cashNumers = NumberOfAllCashDecks;

    cashes = new Queue<Client *> [cashNumers];
}

Market :: ~Market(){
    delete []cashes;
    cashes = NULL;
}

//addClient



