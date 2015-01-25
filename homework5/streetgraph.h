#pragma once
#include <iostream>
#include <fstream>

struct Coordinate{
    size_t i;
    size_t j;
};

struct Simulation{
    double K;
    size_t T;
};

struct Junction{
    int height;
    Coordinate position;
    double waterVolume;
    bool visited;
};




class StreetGraph{
public:
    StreetGraph(std :: ifstream & source);
    ~StreetGraph();

    void print() const;
    void simulate();

private:
    Junction ** junctions;

    Simulation * simulations;
    size_t simulationsCount;
    size_t currentSimulation;

    Coordinate * sortedJunctions;
    size_t sortedJunctionsCount;

    size_t n, m, waterPermeability;

    StreetGraph(const StreetGraph & rh);
    StreetGraph & operator=(const StreetGraph & rh);

    void load(std :: ifstream & source);
    void initializeJunctionArrays();
    void initializeSimulationArray();

    void clear();

    void insertNewJunction(Coordinate junctionPosition, int junctionHeight);
    double calculateWaterVolume(Junction & junction);
    int addOrRemoveWater(size_t i, size_t j) const;

    bool isValidPosition(Coordinate coordinates) const;
    bool isBorder(Coordinate coordinates) const;
};
