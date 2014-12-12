#pragma once
#include <iostream>
#include <Sorter.h>

template<typename T>
class SortTester {
public:
    SortTester(Sorter<T> ** sorters, int count);
    void getSummary(std::ostream & out);
};


template <class T>
SortTester<T> :: SortTester(Sorter<T> ** sorters, int count){
    ;
}

