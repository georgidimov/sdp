#include <QCoreApplication>
#include <iostream>
#include <queue.hpp>
#include <market.h>
int main(){
    Market market(5);
    size_t gubiesCount = 12;
    Client * gubies = new Client[gubiesCount];
    for(size_t i = 0; i < gubiesCount - 1; ++i){
        gubies[i].creditCard = false;
        gubies[i].ID = -1;
        gubies[i].numberOfGoods = 5;
    }

    gubies[gubiesCount - 1].numberOfGoods = 2;
    gubies[gubiesCount - 2].numberOfGoods = 2;
    gubies[gubiesCount - 3].numberOfGoods = 2;

    market.AddClient(gubies, gubiesCount);

    /*
    Queue<int> * qs = new Queue<int> [5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < i + 1; ++j){
            qs[i].enqueue(j);
        }
    }

    int shortestQueueIndex = 0;
    size_t clientsCount = 0;

    for(int i = 0; i < 5; ++i){
        if(qs[i].getSize() < clientsCount){
            clientsCount = qs[i].getSize();
            shortestQueueIndex = i;
        }
    }

    qs[1].dequeue();
    std :: cout << qs[0].getSize() << " " << qs[1].getSize() << std :: endl;

    std :: cout << shortestQueueIndex;

    delete [] qs;
    */
}
