#include "streetgraph.h"

StreetGraph :: StreetGraph(std::ifstream & source){
    junctionsHeight = NULL;
    sortedJunctions = NULL;
    sortedJunctionsLimit = 0;

    load(source);
}

StreetGraph :: StreetGraph(const StreetGraph & rh){
    ///ADD IMPLEMENTATION
}

StreetGraph :: ~StreetGraph(){
    clear();
}

void StreetGraph :: load(std::ifstream & source){
    source.clear();
    source.seekg(0);

    //read matrix size
    source >> n;
    source >> m;
    source >> waterPermeability;

    //initialize needed matrix
    initArrays();

    Junction tempJunction;

    //read matrix content and sort junctions in sortedJunction array
    for(size_t i = 0; i < n; ++i){
        for(size_t j = 0; j < m; ++j){
            source >> junctionsHeight[i][j];

            tempJunction.height = junctionsHeight[i][j];
            tempJunction.waterVolume = 0;
            tempJunction.position.i = i;
            tempJunction.position.j = j;

            insertNewJunction(tempJunction);
        }
    }

}

void StreetGraph :: insertNewJunction(Junction junction){
    //use insertion sort and find the rigth place for junction
    Junction tempValue = junction;
    size_t tempPosition = sortedJunctionsLimit;

    while(tempPosition > 0 && tempValue.height > sortedJunctions[tempPosition - 1].height){
        sortedJunctions[tempPosition] = sortedJunctions[tempPosition - 1];
        --tempPosition;
    }

    sortedJunctions[tempPosition] = tempValue;

    ++sortedJunctionsLimit;
}

void StreetGraph :: initArrays(){
    //initialize needed matrix and array
    junctionsHeight = new int * [n];

    for(size_t i = 0; i < n; ++i){
        junctionsHeight[i] = new int[m];
    }

    sortedJunctions = new Junction[n * m];
}

void StreetGraph :: clear(){
    //delete used matrix and array
    for(size_t i = 0; i < n; ++i){
        delete [] junctionsHeight[i];
    }

    delete [] junctionsHeight;

    junctionsHeight = NULL;

    delete [] sortedJunctions;
    sortedJunctions = NULL;
}

int StreetGraph :: calculateWaterVolume(size_t junctionI, size_t junctionJ) const{
    size_t neighboursCount = 4;
    size_t coordinatesCount = 2;

    int ** neighbours = new int * [neighboursCount];

    for(size_t k = 0; k < neighboursCount; ++k){
        neighbours[k] = new int [coordinatesCount];
    }

    //left junction
    neighbours[0][0] = junctionI;
    neighbours[0][1] = junctionJ - 1;

    //down junction
    neighbours[1][0] = junctionI + 1;
    neighbours[1][1] = junctionJ;

    //rigth junction
    neighbours[2][0] = junctionI;
    neighbours[2][1] = junctionJ + 1;

    //up junction
    neighbours[3][0] = junctionI - 1;
    neighbours[3][1] = junctionJ;

    double waterToRemove = 0;
    double waterToAdd = 0;

    //check all neighbours if will add or remove water
    for(size_t i = 0; i < neighboursCount; ++i){
        if(isValidPosition(neighbours[i][0], neighbours[i][1])){
            if(junctionsHeight[ neighbours[i][0] ][ neighbours[i][1] ] > junctionsHeight[junctionI][junctionJ]){
                waterToAdd += waterPermeability;
            }else{
                waterToRemove += waterPermeability;
            }
        }
    }

    //check if is vertical border
    if(junctionI == 0 || junctionI == n - 1){
        waterToRemove += 2 * waterPermeability;
    }

    //is horizontal border
    if(junctionJ == 0 || junctionJ == m - 1){
        waterToRemove += 2 * waterPermeability;
    }

    std :: cout << "w t r - " << waterToRemove << std :: endl << "w t a + " << waterToAdd;

    //free used matrix
    for(size_t k = 0; k < neighboursCount; ++k){
        delete [] neighbours[k];
    }

    delete [] neighbours;
    neighbours = NULL;

    return 0;
}

void StreetGraph :: tick(){
    std :: cout << junctionsHeight[0][0] << std :: endl;
    calculateWaterVolume(0, 0);
    //for(size_t i = 0; i < n; ++i){
    //    for(size_t j = 0; j < m; ++j){
            //std :: cout << "i = " << i << " j = " << j << std :: endl;
            //calculateWaterVolume(i, j);
            //return;
    //    }
    //}
}

bool StreetGraph :: isValidPosition(int i, int j) const{
    if(i >= 0 && i < (int)n && j >= 0 && j < (int)m){
        return true;
    }

    return false;
}


