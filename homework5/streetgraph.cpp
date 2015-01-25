#include "streetgraph.h"

StreetGraph :: StreetGraph(std::ifstream & source){
    junctions = NULL;

    simulations = NULL;
    simulationsCount = 0;
    currentSimulation = 0;

    sortedJunctions = NULL;
    sortedJunctionsCount = 0;

    load(source);
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
    initializeJunctionArrays();

    //read matrix content and sort junctions in sortedJunction array
    for(size_t i = 0; i < n; ++i){
        for(size_t j = 0; j < m; ++j){
            source >> junctions[i][j].height;
            junctions[i][j].waterVolume = 0;
            junctions[i][j].position.i = i;
            junctions[i][j].position.j = j;
            junctions[i][j].visited = false;

            insertNewJunction(junctions[i][j].position, junctions[i][j].height);
        }
    }

    //read simulation`s information
    source >> simulationsCount;

    initializeSimulationArray();

    for(size_t i = 0; i < simulationsCount; ++i){
        source >> simulations[i].K;
        source >> simulations[i].T;
    }
}

void StreetGraph :: insertNewJunction(Coordinate junctionPosition, int junctionHeight){
    //use insertion sort and find the rigth place for junction
    size_t tempPosition = sortedJunctionsCount;

    while(tempPosition > 0 &&
          junctionHeight > junctions[ sortedJunctions[tempPosition -1].i ][ sortedJunctions[tempPosition - 1].j ].height){

        sortedJunctions[tempPosition] = sortedJunctions[tempPosition - 1];
        --tempPosition;
    }

    sortedJunctions[tempPosition] = junctionPosition;

    ++sortedJunctionsCount;
}

void StreetGraph :: initializeJunctionArrays(){
    //initialize needed matrix and array
    junctions = new Junction * [n];

    for(size_t i = 0; i < n; ++i){
        junctions[i] = new Junction [m];
    }

    sortedJunctions = new Coordinate[n * m];
}

void StreetGraph :: initializeSimulationArray(){
    simulations = new Simulation[simulationsCount];
}

void StreetGraph :: clear(){
    //delete arrays used for junctions
    for(size_t i = 0; i < n; ++i){
        delete [] junctions[i];
    }

    delete [] junctions;

    junctions = NULL;

    delete [] sortedJunctions;
    sortedJunctions = NULL;

    //delete array used for simulations
    delete [] simulations;
    simulations = NULL;
}

double StreetGraph::calculateWaterVolume(Junction & junction){
    size_t neighboursCount = 4;

    Coordinate * neighbours = new Coordinate [neighboursCount];


    //left junction
    neighbours[0].i = junction.position.i;
    neighbours[0].j = junction.position.j - 1;

    //down junction
    neighbours[1].i = junction.position.i + 1;
    neighbours[1].j = junction.position.j;

    //rigth junction
    neighbours[2].i = junction.position.i;
    neighbours[2].j = junction.position.j + 1;

    //up junction
    neighbours[3].i = junction.position.i - 1;
    neighbours[3].j = junction.position.j;

    double waterForTheNeighbours = 0;
    double waterForTheRiver = 0;
    double waterToAdd = 0;

    //check all neighbours if will add or remove water
    for(size_t i = 0; i < neighboursCount; ++i){
        if(isValidPosition(neighbours[i])){
            if(junctions[ neighbours[i].i ][ neighbours[i].j ].height > junction.height){
                junctions[ neighbours[i].i ][ neighbours[i].j ].waterVolume -= waterPermeability;
                waterToAdd += waterPermeability;
            }else{
                waterForTheNeighbours += waterPermeability;
            }
        }else if(isBorder(neighbours[i])){  //if is border
            waterForTheRiver += 2 * waterPermeability;
        }
    }

    //add water to the junction
    junction.waterVolume += waterToAdd;

    if(waterForTheNeighbours + waterForTheRiver < junction.waterVolume){
        for(size_t i = 0; i < neighboursCount; ++i){
            if(isValidPosition(neighbours[i]) && junctions[ neighbours[i].i ][ neighbours[i].j ].height < junction.height){
                junctions[ neighbours[i].i ][ neighbours[i].j ].waterVolume += waterPermeability;
                junction.waterVolume -= waterPermeability;
            }else if(isBorder(neighbours[i])){ //if is border
                junction.waterVolume -= 2 * waterPermeability;
            }
        }
    }else{
        if(junction.waterVolume > waterForTheRiver){
            for(size_t i = 0; i < neighboursCount; ++i){
                if(isValidPosition(neighbours[i]) && junctions[ neighbours[i].i ][ neighbours[i].j ].height < junction.height){
                    junctions[ neighbours[i].i ][ neighbours[i].j ].waterVolume += waterPermeability;
                    junction.waterVolume -= waterPermeability;
                }
            }
        }else{
            double waterForEveryNeighbour = junction.waterVolume / neighboursCount;

            for(size_t i = 0; i < neighboursCount; ++i){
                if(isValidPosition(neighbours[i]) && junctions[ neighbours[i].i ][ neighbours[i].j ].height < junction.height){
                    junctions[ neighbours[i].i ][ neighbours[i].j ].waterVolume += waterForEveryNeighbour;
                    junction.waterVolume -= waterForEveryNeighbour;
                }else if(isBorder(neighbours[i])){  //if is border
                    junction.waterVolume -= 2 * waterForEveryNeighbour;
                }
            }
        }

        junction.waterVolume = 0;

    }

    //free used matrix
    delete [] neighbours;
    neighbours = NULL;

    junction.visited = true;

    return junction.waterVolume;
}

void StreetGraph :: simulate(){
    for(size_t i = 0; i < n; ++i){
        for(size_t j = 0; j < m; ++j){
            junctions[i][j].waterVolume = simulations[currentSimulation].K;
        }
    }

    double waterVolumeBefore = 0;
    double waterVolumeAfter = 0;

    while(simulations[currentSimulation].T--){
        for(size_t i = 0; i < sortedJunctionsCount; ++i){
            waterVolumeAfter += calculateWaterVolume(junctions[ sortedJunctions[i].i ][sortedJunctions[i].j]);
        }

        //refresh visited status
        for(size_t i = 0; i < n; ++i){
            for(size_t j = 0; j < m; ++j){
                junctions[i][j].visited = false;
            }
        }

        if(waterVolumeAfter == waterVolumeBefore){
            std :: cout << simulations[currentSimulation].T;
            break;
        }else{
            waterVolumeBefore = waterVolumeAfter;
            waterVolumeAfter = 0;
        }
    }

    ++currentSimulation;
}

bool StreetGraph :: isValidPosition(Coordinate coordinates) const{
    if((int)coordinates.i >= 0 && (int)coordinates.i < (int)n && (int)coordinates.j >= 0 &&
            (int)coordinates.j < (int)m && junctions[coordinates.i][coordinates.j].visited == false){
        return true;
    }

    return false;
}

bool StreetGraph :: isBorder(Coordinate coordinates) const{
    if((int)coordinates.i >= 0 && (int)coordinates.i < (int)n && (int)coordinates.j >= 0 && (int)coordinates.j < (int)m){
        return false;
    }

    return true;
}


void StreetGraph :: print() const{
    std :: cout << std :: endl;
    for(size_t i = 0; i < n; ++i){
        for(size_t j = 0; j < m; ++j){
            std :: cout << '(' << junctions[i][j].height << ", " <<  junctions[i][j].waterVolume << "), ";
        }
        std :: cout << std :: endl;
    }
}
