#pragma once
#include <iostream>
#include <assert.h>
#include <time.h>

template<typename T>
class Sorter {
protected:
    unsigned long long sortingTime;
public:
    Sorter();
    virtual void sort(T * data, size_t count) = 0;
    virtual unsigned long long getSortTime() const = 0;
};

template <class T>
Sorter<T> :: Sorter(){
    sortingTime = 0;
}

template <class T>
unsigned long long Sorter<T> :: getSortTime() const{
    time_t timeBeforeSort;
    time(&timeBeforeSort);

    return timeBeforeSort;
}
