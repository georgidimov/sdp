#include <QCoreApplication>
#include <iostream>
#include <queue.hpp>
#include <market.h>
#include <list.hpp>
#include <marketState.h>


int main(){
    Market market(15);
    size_t gubiesCount = 10;
    Client * gubies = new Client[gubiesCount];

    for(size_t i = 0; i < gubiesCount; ++i){
        gubies[i].creditCard = true;
        gubies[i].ID = -1;
        gubies[i].numberOfGoods = 5;
    }

    gubies[0].creditCard = true;
    gubies[0].numberOfGoods = 2;
    gubies[1].creditCard = true;
    gubies[1].numberOfGoods = 1;
    //gubies[2].numberOfGoods = 2;

    market.AddClient(gubies, gubiesCount);
    /*
    for(size_t i = 0; i < gubiesCount; ++i){
        std :: cout << gubies[i].creditCard << " " << gubies[i].ID<< " "
                    << gubies[i].numberOfGoods << std :: endl;
    }*/



    delete [] gubies;
}
