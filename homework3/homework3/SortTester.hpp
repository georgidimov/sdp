#pragma once
#include <Sorter.hpp>

template<typename T>
class SortTester {
public:
    SortTester(){};
    virtual void getSummary(std::ostream & out) = 0;
};
