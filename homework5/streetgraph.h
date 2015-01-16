#pragma once
#include <fstream>

class StreetGraph{
    int ** streetWeight;
    int n, m;

    void load(std :: ifstream & source);
    void clear();
public:
    StreetGraph(std :: ifstream & source);
    StreetGraph(const StreetGraph & rh);
    ~StreetGraph();

};
