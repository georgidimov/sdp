#include "market.h"

Market :: Market(int NumberOfAllCashDecks){
    cashCount = NumberOfAllCashDecks;

    for(size_t i = 0; i < cashCount; ++i){
        cashes.addAt(cashes.getSize(), new Queue<Client *>);
    }

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
            return (int)i;
        }
    }

    return -1;
}

void Market :: manageQueues(){
    size_t currentCashCount;
    for(size_t i = 0; i < cashCount; ++i){
        if(openCashes[i]){
            currentCashCount = cashes[i]->getSize();
            if(currentCashCount > cashCount){ /// > N

                int newCashIndex = openCash();

                if(newCashIndex > 0){
                    cashes[i]->split(*cashes[newCashIndex]);
                }

            }else if(currentCashCount < cashCount / 10){
                while(!cashes[i]->isEmpty()){
                    std :: cout << " call";
                }
            }

        }
    }
}

void Market :: AddClient(Client * clients, int number){
    for(int i = 0; i < number; ++i){
        manageQueues();

        if(clients[i].numberOfGoods != 0){  //the client has goods
            //check conditions for express cash
            if(clients[i].numberOfGoods <= expressCashGoodsLimit &&
               expressCash.getSize() <  2 * cashCount){

                expressCash.enqueue(&clients[i]);
            }else{  //go to normal cash
                cashes[ shortestQueue() ]->enqueue(&clients[i]);
            }
        }

        clients[i].ID = IDs;
        IDs++;

        if( i == number -2){

        }



    }

    for(size_t i = 0; i < cashCount; ++i){
        std :: cout << i << " size: " << cashes[i]->getSize() << " => " <<
                       (openCashes[i] ? "opened" : "closed") << std :: endl;
    }

    std :: cout << std :: endl << "express cash now: " << std :: endl
                << "size: " << expressCash.getSize() << " => " << "opened" << std :: endl;
}


