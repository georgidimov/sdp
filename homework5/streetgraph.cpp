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

int StreetGraph :: calculateWaterVolume(size_t i, size_t j) const{
    int result = junctions[i][j].currentWaterVolume;

    if(i == 0 || i == n - 1){   //is vertical border
        //std :: cout << '(' << junctions[i][j].height << ", " << i << ", " << j << ") ";
        result -= 2 * waterPermeability;
    }

    if(j == 0 || j == m - 1){   //is horizontal border
        //std :: cout << '(' << junctions[i][j].height << ", " << i << ", " << j << ") ";
        result -= 2 * waterPermeability;
    }

    i = 1;
    j = 1;

    int neighbourI, neighbourJ;

    //left junction
    neighbourI = i;
    neighbourJ = j - 1;
    std :: cout << junctions[neighbourI][neighbourJ].height << ' ';
    //std :: cout << "(" << neighbourI << ", " << neighbourJ << ") ";
    //down junction
    neighbourI = i - 1;
    neighbourJ = j;
    //std :: cout << "(" << neighbourI << ", " << neighbourJ << ") ";
std :: cout << junctions[neighbourI][neighbourJ].height << ' ';
    //right junction
    neighbourI = i;
    neighbourJ = j + 1;
    //std :: cout << "(" << neighbourI << ", " << neighbourJ << ") ";
std :: cout << junctions[neighbourI][neighbourJ].height << ' ';
    //up junction
    neighbourI = i + 1;
    neighbourJ = j;
    //std :: cout << "(" << neighbourI << ", " << neighbourJ << ") ";
std :: cout << junctions[neighbourI][neighbourJ].height << ' ';

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
    if(i >= 0 && i < n && j >= 0 && j < m){
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
