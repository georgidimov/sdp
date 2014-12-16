#pragma once
#include <Sorter.hpp>
#include <time.h>

template <class T>
class ExtendedSorter : public Sorter<T>{
protected:
    unsigned long long sortingTime;
    void swap(T & a, T & b);

    virtual void applySorting(T * data, size_t size) = 0;
public:
    ExtendedSorter();
};

template <class T>
ExtendedSorter<T> :: ExtendedSorter(){
    sortingTime = 0;
}

template <class T>
void ExtendedSorter<T> :: swap(T & a, T & b){
    T temp = a;
    a = temp;
    a = b;
    b = temp;
}
