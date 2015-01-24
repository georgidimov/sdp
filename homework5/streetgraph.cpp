#include "streetgraph.h"

StreetGraph :: StreetGraph(std::ifstream & source){
    junctions = NULL;
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
    initArray();
    //std :: cout << n << ' ' << m << ' ' << waterPermeability <<  std :: endl;

    //read matrix content
    for(size_t i = 0; i < n; ++i){
        for(size_t j = 0; j < m; ++j){
            source >> junctions[i][j].height;
            junctions[i][j].currentWaterVolume = waterPermeability;
            junctions[i][j].newWaterVolume = waterPermeability;
        }
    }
    tick();
    //print();
}

void StreetGraph :: initArray(){
    junctions = new Junction * [n];

    for(size_t i = 0; i < n; ++i){
        junctions[i] = new Junction [m];
    }

}

int StreetGraph :: calculateWaterVolume(size_t junctionI, size_t junctionJ) const{
    //int waterToRemove = junctions[i][j].currentWaterVolume;


    junctionI = 1;
    junctionJ = 4;

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

    std :: cout << junctions[junctionI][junctionJ].height << std :: endl;

    int waterToRemove = 0;
    int waterToAdd = 0;

    //check all neighbours if will add or remove water
    for(size_t i = 0; i < neighboursCount; ++i){
        if(isValidPosition(neighbours[i][0], neighbours[i][1])){
            if(junctions[ neighbours[i][0] ][ neighbours[i][1] ].height > junctions[junctionI][junctionJ].height){
            waterToAdd += waterPermeability;
            }else{
                waterToRemove += waterPermeability;
            }
        }
    }

    std :: cout << junctions[junctionI][junctionJ].height << std :: endl;
    if(junctionI == 0 || junctionI == n - 1){   //is vertical border
        //std :: cout << '(' << junctions[i][j].height << ", " << i << ", " << j << ") ";
        waterToRemove += 2 * waterPermeability;
    }

    if(junctionJ == 0 || junctionJ == m - 1){   //is horizontal border
        //std :: cout << '(' << junctions[i][j].height << ", " << i << ", " << j << ") ";
        waterToRemove += 2 * waterPermeability;
    }

    std :: cout << "w t r - " << waterToRemove << std :: endl << "w t a + " << waterToAdd;

 /*
    int neighbourI, neighbourJ;

    //left junction
    neighbourI = i;
    neighbourJ = j - 1;

    //down junction
    neighbourI = i - 1;
    neighbourJ = j;

    //right junction
    neighbourI = i;
    neighbourJ = j + 1;

    //up junction
    neighbourI = i + 1;
    neighbourJ = j;
*/

    for(size_t k = 0; k < neighboursCount; ++k){
        delete [] neighbours[k];
    }

    delete [] neighbours;
    neighbours = NULL;
    return 0;
}

void StreetGraph :: tick(){
    for(size_t i = 0; i < n; ++i){
        for(size_t j = 0; j < m; ++j){
            //std :: cout << "i = " << i << " j = " << j << std :: endl;
            calculateWaterVolume(i, j);
            return;
        }
    }
}

bool StreetGraph :: isValidPosition(int i, int j) const{
    if(i >= 0 && i < (int)n && j >= 0 && j < (int)m){
        return true;
    }

    return false;
}

void StreetGraph :: clear(){
    for(size_t i = 0; i < n; ++i){
        delete [] junctions[i];
    }

    delete [] junctions;

    junctions = NULL;
}
