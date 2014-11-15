#include "market.h"

Market :: Market(int NumberOfAllCashDecks){
    cashCount = NumberOfAllCashDecks;

    cashes = new Queue<Client *> [cashCount];

    openCashes = new bool [cashCount];

    //open first cash and close everyone else
    openCashes[0] = true;
    for(size_t i = 1; i < cashCount; ++i){
        openCashes[i] = false;
    }

    expressCashGoodsLimit = 3;
    IDs = 0;
}

Market :: ~Market(){
    delete []cashes;
    cashes = NULL;

    delete [] openCashes;
    openCashes = NULL;
}

size_t Market :: shortestQueue() const{
    int shortestQueueIndex = 0;
    int clientsCount = -1;

    for(size_t i = 0; i < cashCount; ++i){
        if(openCashes[i] && (int)cashes[i].getSize() < clientsCount){
            clientsCount = cashes[i].getSize();
            shortestQueueIndex = i;
        }
    }
    return shortestQueueIndex;
}

size_t Market :: openCash(){
    for(size_t i = 0; i < cashCount; ++i){
        if(!openCashes[i]){
            openCashes[i] = true;
            return i;
        }
    }

    return -1;
}

void Market :: manageQueues(){
    size_t currentCashSize;
    for(size_t i = 0; i < cashCount; ++i){
        if(openCashes[i]){
            currentCashSize = cashes[i].getSize();

            if(currentCashSize > cashCount){
                //open cash
                //split this cash
            }else if(currentCashSize > cashCount / 8){ ///check again
                //manage longest cash
            }else if(currentCashSize < cashCount / 10){
                //reorder clients
                //close this cash
            }
        }
    }
}

void Market :: AddClient(Client * clients, int number){
    for(int i = 0; i < number; ++i){
        if(clients[i].numberOfGoods != 0){  //the client has goods
            //check conditions for express cash
            if(clients[i].numberOfGoods <= expressCashGoodsLimit &&
               expressCash.getSize() <  2 * cashCount){

                expressCash.enqueue(&clients[i]);
            }else{  //go to normal cash
                cashes[ shortestQueue() ].enqueue(&clients[i]);
            }
        }

        clients[i].ID = IDs;
        IDs++;


        /*
        for(size_t i = 0; i < cashCount; ++i){
            std :: cout << i << " => " << (openCashes[i] ? "opened" : "closed") << std :: endl;
        }
        */
    }
}



