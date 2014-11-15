#include "market.h"

Market :: Market(int NumberOfAllCashDecks){
    cashNumers = NumberOfAllCashDecks;

    cashes = new Queue<Client *> [cashNumers];

    openCashes = new bool [cashNumers];

    for(size_t i = 0; i < openCashes; ++i){
        openCashes[i] = false;
    }
}

Market :: ~Market(){
    delete []cashes;
    cashes = NULL;

    delete [] openCashes;
    openCashes = NULL;
}

//addClient



