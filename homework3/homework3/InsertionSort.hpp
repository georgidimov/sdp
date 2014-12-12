#pragma once
#include <iostream>
#include <Sorter.hpp>

template <class T>
class InsertionSort : public Sorter<T>{
public:
    InsertionSort();

    virtual void sort(T * data, size_t count);
    virtual unsigned long long getSortTime() const;
};

template <class T>
InsertionSort<T> :: InsertionSort(){
    ;
}

template <class T>
void InsertionSort<T> :: sort(T * data, size_t count){
    T tempValue;
    size_t tempPosition;

    for(size_t i = 1; i < count; ++i){
        tempValue = data[i];
        tempPosition = i;

        while(tempPosition > 0 && tempValue < data[tempPosition - 1]){
            data[tempPosition] = data[tempPosition - 1];
            --tempPosition;
        }

        data[tempPosition] = tempValue;
    }
}

template <class T>
unsigned long long InsertionSort<T> :: getSortTime() const{
    return 0;
}
