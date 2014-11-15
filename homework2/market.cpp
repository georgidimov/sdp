#include "market.h"

Market :: Market(int NumberOfAllCashDecks){
    cashCount = NumberOfAllCashDecks;

    cashes = new Queue<Client *> [cashCount];

    openCashes = new bool [cashCount];

    //open first cash and close everyone else
    openCashes[0] = true;
    for(int i = 1; i < cashCount; ++i){
        openCashes[i] = true;
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

    for(int i = 0; i < cashCount; ++i){
        if(openCashes[i] && (int)cashes[i].getSize() < clientsCount){
            clientsCount = cashes[i].getSize();
            shortestQueueIndex = i;
        }
    }
    return shortestQueueIndex;
}

void Market :: manageQueues(){

}

void Market :: AddClient(Client * clients, int number){
    for(int i = 0; i < number; ++i){
        if(clients[i].numberOfGoods != 0){  //the client has goods
            //check conditions for express cash
            if(clients[i].numberOfGoods <= expressCashGoodsLimit &&
               (int)expressCash.getSize() <  2 * cashCount){

                expressCash.enqueue(&clients[i]);
            }else{  //go to normal cash
                cashes[ shortestQueue() ].enqueue(&clients[i]);
            }
        }

        clients[i].ID = IDs;
        IDs++;
    }
}



