#pragma once
#include <ExtendedSorter.hpp>

template <class T>
class ShakerSort : public ExtendedSorter<T>{
    virtual void applySorting(T * data, size_t size);
public:
    ShakerSort();
    ~ShakerSort();

    virtual void sort(T * data, size_t size);
    virtual unsigned long long getSortTime() const;
};

template <class T>
ShakerSort<T> :: ShakerSort(){
    ;
}

template <class T>
ShakerSort<T> :: ~ShakerSort(){
    ;
}


template <class T>
void ShakerSort<T> :: applySorting(T * data, size_t size){
    size_t first = 0;
    size_t last = size;


    while(first < last){
        for(size_t i = first; i < last - 1; ++i){
            if(data[i] > data[i + 1]){
                ExtendedSorter<T> :: swap(data[i], data[i + 1]);
            }
        }

        --last;

        for(size_t i = last - 1; i > first; --i){
            if(data[i] < data[i - 1]){
                ExtendedSorter<T> :: swap(data[i], data[i - 1]);
            }
        }

        ++first;
    }
}

template <class T>
void ShakerSort<T> :: sort(T * data, size_t size){
    ExtendedSorter<T> :: sort(data, size);
}

template <class T>
unsigned long long ShakerSort<T> :: getSortTime() const{
    return ExtendedSorter<T> :: getSortTime();
}

