#pragma once
#include <iostream>
#include <fstream>

struct Coordinate{
    int i;
    int j;
};

struct Junction{
    int height;
    Coordinate position;
    double waterVolume;
};



class StreetGraph{
public:
    StreetGraph(std :: ifstream & source);
    StreetGraph(const StreetGraph & rh);
    ~StreetGraph();

    //remove me
    void print() const{
        std :: cout << std :: endl;
        for(size_t i = 0; i < n; ++i){
            for(size_t j = 0; j < m; ++j){
                //std :: cout << '(' << i << ", " << j << ", " << junctions[i][j].height << ", " <<  junctions[i][j].currentWaterVolume << "), ";
                //std :: cout << '(' << i << ", " << j << ", " << junctionsHeight[i][j] << ')';
                std :: cout << junctionsHeight[i][j] << ' ';
            }
            std :: cout << std :: endl;
        }

        for(size_t i = 0; i < sortedJunctionsLimit; ++i){
            //std :: cout << sortedJunctions[i].height << ' ';
        }
    }


private:
    int ** junctionsHeight;

    Junction * sortedJunctions;
    size_t sortedJunctionsLimit;

    size_t n, m, waterPermeability;

    void load(std :: ifstream & source);
    void initArrays();
    void clear();

    void insertNewJunction(Junction junction);
    int calculateWaterVolume(size_t junctionI, size_t junctionJ) const;
    int addOrRemoveWater(size_t i, size_t j) const;
public:
    //make me private
    void tick();
private:
    bool isValidPosition(int i, int j) const;
};
