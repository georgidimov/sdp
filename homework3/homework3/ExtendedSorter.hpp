#pragma once
#include <Sorter.hpp>
#include <time.h>

template <class T>
class ExtendedSorter : public Sorter<T>{
protected:
    unsigned long long sortingTime;
    void swap(T & a, T & b) const;

    virtual void sort(T * data, size_t count);
    virtual void applySorting(T * data, size_t size) = 0;
    virtual unsigned long long getSortTime() const = 0;
public:
    ExtendedSorter();
    ~ExtendedSorter();
};

template <class T>
ExtendedSorter<T> :: ExtendedSorter(){
    sortingTime = 0;
}

template <class T>
void ExtendedSorter<T> :: swap(T & a, T & b) const{
    T temp = a;
    a = temp;
    a = b;
    b = temp;
}

template <class T>
void ExtendedSorter<T> :: sort(T * data, size_t size){
    clock_t timeBeforeSorting  = clock();
    applySorting(data, size);

    clock_t timeAfterSorting = clock();

    sortingTime = timeAfterSorting - timeBeforeSorting;
}

template <class T>
unsigned long long ExtendedSorter<T> :: getSortTime() const{
    return sortingTime;
}
