#pragma once
#include <ExtendedSorter.hpp>


template <class T>
class MergeSort : public ExtendedSorter<T>{
    void merge(T * a, size_t aSize, T * b, size_t bSize, T * buffer);
    void applySorting(T * data, size_t size);
public:
    MergeSort();
    ~MergeSort();

    virtual void sort(T * array, size_t size);
    void sortIteration(T * array, T * buffer, size_t size);

    virtual unsigned long long getSortTime() const;
};

template <class T>
MergeSort<T> :: MergeSort(){
    ;
}

template <class T>
MergeSort<T> :: ~MergeSort(){
    ;
}


template <class T>
void MergeSort<T> :: sortIteration(T * array, T * buffer, size_t size){
    if(size == 1){
        return;
    }

    if(size == 2){
        if(array[0] > array[1]){
            ExtendedSorter<T> :: swap(array[0], array[1]);
        }

        return;
    }

    size_t newSize = size / 2;

    sortIteration(array, buffer, newSize);
    sortIteration(array + newSize, buffer, size - newSize);
    merge(array, newSize, array + newSize, size - newSize, buffer);
}

template <class T>
void MergeSort<T> :: merge(T * a, size_t aSize, T * b, size_t bSize, T * buffer){
    size_t aCounter = 0;
    size_t bCounter = 0;
    size_t resultCounter = 0;

    while(aCounter < aSize && bCounter < bSize) {
        if(a[aCounter] <= b[bCounter]){
            buffer[resultCounter] = a[aCounter];
            ++aCounter;
        }else{
            buffer[resultCounter] = b[bCounter];
            ++bCounter;
        }

        ++resultCounter;
    }

    while(aCounter < aSize){
        buffer[resultCounter] = a[aCounter];
        ++aCounter;
        ++resultCounter;
    }

    while(bCounter < bSize){
        buffer[resultCounter] = b[bCounter];
        ++bCounter;
        ++resultCounter;
    }

    for(size_t i = 0; i < resultCounter; ++i){
        a[i] = buffer[i];
    }
}

template <class T>
void MergeSort<T> :: applySorting(T * data, size_t size){
    T * buffer = new T[size];

    sortIteration(data, buffer, size);

    delete [] buffer;
}

template <class T>
void MergeSort<T> :: sort(T * array, size_t size){
    ExtendedSorter<T> :: sort(array, size);
}

template <class T>
unsigned long long MergeSort<T> :: getSortTime() const{
    return ExtendedSorter<T> :: getSortTime();
}

