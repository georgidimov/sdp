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
        if(openCashes[i] && cashes[i].getSize() < clientsCount){
            clientsCount = cashes[i].getSize();
            shortestQueueIndex = i;
        }
    }

    for(size_t i = 0; i < cashCount; ++i){
        std :: cout << i << " => "  << cashes[i].getSize() << std :: endl;
    }

    std :: cout << std :: endl << "shortest queue is << " << shortestQueueIndex << std :: endl;
    return shortestQueueIndex;
}

void Market :: AddClient(Client * clients, int number){
    for(int i = 0; i < number; ++i){
        //check conditions for express cash
        if(clients[i].numberOfGoods <= expressCashGoodsLimit &&
           (int)expressCash.getSize() <  2 * cashCount){

            expressCash.enqueue(&clients[i]);
        }else{  //go to normal cash
            //std :: cout << "shortest queue is " << shortestQueue() << std :: endl;
            cashes[ shortestQueue() ].enqueue(&clients[i]);
        }
    }

    for(size_t i = 0; i < cashCount; ++i){
       // std :: cout << i << " => "  << cashes[i].getSize() << std :: endl;
    }
}



