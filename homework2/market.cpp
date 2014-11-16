#include "market.h"

Market :: Market(int NumberOfAllCashDecks){
    cashCount = NumberOfAllCashDecks;

    for(size_t i = 0; i < cashCount; ++i){
        cashes.addAt(cashes.getSize(), new Queue<Client *>);
    }

    openCashes = new bool [cashCount];

    //open first cash and close everyone else
    openCashes[0] = true;
    openCashesCount = 1;

    for(size_t i = 1; i < cashCount; ++i){
        openCashes[i] = false;
    }

    expressCashGoodsLimit = 3;
    IDs = 1;

}

Market :: ~Market(){
    for(size_t i = 0; i < cashCount; ++i){
        delete cashes.getAt(i);
    }

    delete [] openCashes;
    openCashes = NULL;
}

size_t Market :: shortestQueue() const{
    int shortestQueueIndex;
    int clientsCount;

    //find first open cash
    for(size_t i = 0; i < cashCount; ++i){
        if(openCashes[i]){
            shortestQueueIndex = i;
            clientsCount = cashes[i]->getSize();
        }
    }

    for(size_t i = 0; i < cashCount; ++i){
        if(openCashes[i] && (int)cashes[i]->getSize() < clientsCount){
            clientsCount = cashes[i]->getSize();
            shortestQueueIndex = i;
        }
    }
    return shortestQueueIndex;
}

int Market :: openCash(){
    for(size_t i = 0; i < cashCount; ++i){
        if(!openCashes[i]){
            openCashes[i] = true;
            ++openCashesCount;
            return (int)i;
        }
    }

    return -1;
}

void Market :: closeCash(size_t index){
    if(openCashesCount == 1)
        return;

    openCashes[index] = false;
    Client * tempClient;

    while( cashes[index]->getSize() ){
        tempClient = cashes[index]->dequeue();
        tempClient->ID = 0;
        addClientToQueue(tempClient);
    }

    --openCashesCount;
}


bool Market::bigDifference(int & index) const{
    for(size_t i = 0; i < cashCount; ++i){
        for(size_t j = 0; j < cashCount; ++j){
            if(openCashes[i] && openCashes[j]){
                if( abs(cashes[i]->getSize() -  cashes[j]->getSize()) > (int)cashCount / 8){
                    index = cashes[i]->getSize() > cashes[j]->getSize() ? i : j;
                    return true;
                }
            }
        }
    }

    return false;
}
void Market :: manageQueues(){
    size_t currentCashCount;
    int bigDifferenceCash = -1;
    for(size_t i = 0; i < cashCount; ++i){
        if(openCashes[i]){
            currentCashCount = cashes[i]->getSize();
            if(currentCashCount > cashCount){ /// > N

                int newCashIndex = openCash();

                if(newCashIndex > 0){
                    cashes[i]->split(*cashes[newCashIndex]);
                    return;
                }

            }else if(bigDifference(bigDifferenceCash)){ ///N/8
                int size = cashes[bigDifferenceCash]->getSize();

                for(;size >= 0; size--){
                    addClientToQueue(cashes[bigDifferenceCash]->dequeue());
                }
            }
            else if(currentCashCount < cashCount / 10){
                closeCash(i);
                return;
            }

        }
    }
}

void Market :: addClientToQueue(Client * client){
    if(client->numberOfGoods != 0){  //the client has goods
        //check conditions for express cash
        if(client->numberOfGoods <= expressCashGoodsLimit &&
           expressCash.getSize() <  2 * cashCount){

            expressCash.enqueue(client);
        }else{  //go to normal cash
            cashes[ shortestQueue() ]->enqueue(client);
        }
    }

    client->ID = IDs;
    IDs++;

}

void Market :: addClientsToQueue(Client * clients, int number){
    for(int i = 0; i < number; ++i){
        addClientToQueue(&clients[i]);
    }
}


void Market :: checkClient(Queue<Client *> * cash){
    Client * firstOnQueue = cash->peek();

    if(!firstOnQueue->creditCard){
        firstOnQueue->ID *= -1;
        cash->dequeue();
    }else{
        firstOnQueue->creditCard = false;
    }
}

void Market :: processClients(){
    for(size_t i = 0; i < cashCount; ++i){
        if(cashes[i] && cashes[i]->getSize()){ ///Remove getSize
            checkClient(cashes[i]);
        }
    }

    if(expressCash.getSize() > 0){
        checkClient(&expressCash);
    }
}

void Market :: AddClient(Client * clients, int number){
    processClients();
    manageQueues();
    addClientsToQueue(clients, number);


/*
    for(size_t i = 0; i < cashCount; ++i){
        std :: cout << i << " size: " << cashes[i]->getSize() << " => " <<
                       (openCashes[i] ? "opened" : "closed") << std :: endl;
    }

    std :: cout << std :: endl << "express cash now: " << std :: endl
                << "size: " << expressCash.getSize() << " => " << "opened" << std :: endl;
*/
}

MarketState Market :: getMarketState() const{
    MarketState result;

    result.numberOfCashDesk = openCashesCount;
    result.numberOfClientsAtExpressCashDeck = expressCash.getSize();

    result.numberOfClientsAtCashDecsk = new int [openCashesCount];

    int counter = 0;
    for(size_t i = 0; i < cashCount; ++i){
        if(openCashes[i]){
            result.numberOfClientsAtCashDecsk [counter] = cashes[i]->getSize();
            ++counter;
        }
    }

    return result;
}

ClientState Market :: getClientState(int ID){
    Client * tempClient = NULL;
    Client * trueClient = NULL;
    size_t queueIndex = -1;
    size_t positionOnQueue = 0;

    size_t currentCashSize = 0;
    for(size_t i = 0; i < cashCount; ++i){
        if(openCashes[i]){
            currentCashSize = cashes[i]->getSize();

            for(size_t j = 0; j < currentCashSize; ++j){
                tempClient = cashes[i]->dequeue();
                cashes[i]->enqueue(tempClient);

                if(tempClient->ID == ID){
                    trueClient= tempClient;
                    queueIndex = i;
                    positionOnQueue = j;
                }
            }
        }
    }

    ClientState result;
    result.CashDeskPosition = queueIndex;
    result.QueuePosition = positionOnQueue;
    result.client = trueClient;

    return result;
}


