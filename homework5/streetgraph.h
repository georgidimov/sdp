#pragma once
#include <iostream>
#include <fstream>

struct Junction{
    int height;
    int currentWaterVolume;
    int newWaterVolume;
};

class StreetGraph{
public:
    StreetGraph(std :: ifstream & source);
    StreetGraph(const StreetGraph & rh);
    ~StreetGraph();

private:
    Junction ** junctions;
    size_t n, m, waterPermeability;

    void load(std :: ifstream & source);
    void initArray();
    void clear();

    int calculateWaterVolume(size_t i, size_t j) const;
    void tick();

    bool isValidPosition(int i, int j) const;

    //remove me
    void print() const{
        for(size_t i = 0; i < n; ++i){
            for(size_t j = 0; j < m; ++j){
                std :: cout << '('  << junctions[i][j].height << ", " <<  junctions[i][j].currentWaterVolume << "), ";
            }
            std :: cout << std :: endl;
        }
    }

};
