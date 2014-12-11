#pragma once
#include <iostream>
#include <Sorter.h>

template <class T>
class InsertionSort : public Sorter<T>{
public:
    InsertionSort();
    virtual void sort(T *data, size_t count);
};
