#include "streetgraph.h"

StreetGraph :: StreetGraph(std::ifstream & source){
    streetWeight = NULL;
    load(source);
}

StreetGraph :: StreetGraph(const StreetGraph & rh){
    ///ADD IMPLEMENTATION
}

StreetGraph :: ~StreetGraph(){
    clear();

}

void StreetGraph :: load(std::ifstream & source){
    ///ADD IMPLENTATION
}

void StreetGraph :: clear(){
    for(int i = 0; i < n; ++i){
        delete [] streetWeight[i];
    }

    delete [] streetWeight;

    streetWeight = NULL;
}
