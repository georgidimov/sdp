#pragma once
#include <iostream>

template<typename T>
class Sorter {
public:
    virtual void sort(T * data, size_t count) = 0;
    virtual unsigned long long getSortTime() const = 0;
};


template <class T>
unsigned long long Sorter<T> :: getSortTime() const{
    time_t timeBeforeSort;
    time(&timeBeforeSort);

    return timeBeforeSort;
}
