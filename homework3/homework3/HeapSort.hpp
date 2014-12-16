#pragma once
#include <ExtendedSorter.hpp>


template <class T>
class HeapSort : public ExtendedSorter<T>{
    void siftDown(T * data, size_t startPosition, size_t size) const;
    virtual void applySorting(T * data, size_t size);
public:
    HeapSort();
    ~HeapSort();

    virtual void sort(T * data, size_t size);
    virtual unsigned long long getSortTime() const;
};

template <class T>
HeapSort<T> :: HeapSort(){
    ;
}

template <class T>
HeapSort<T> :: ~HeapSort(){
    ;
}

template <class T>
void HeapSort<T> :: siftDown(T * data, size_t startPosition, size_t size) const{
    T valueAtTheBeginning = data[startPosition];

    size_t childPosition = startPosition * 2 + 1;

    while(childPosition < size){
        //check rigth child if is with greater value get this position
        if(data[childPosition] < data[childPosition + 1] && childPosition + 1 < size){
            ++childPosition;
        }

        //check if the tree is ordered
        if(valueAtTheBeginning > data[childPosition]){
            return;
        }

        if(data[startPosition] < data[childPosition]){
            ExtendedSorter<T> :: swap(data[startPosition], data[childPosition]);
        }

        //jump to next node
        startPosition *= 2;
        startPosition += 1;

        childPosition = startPosition * 2 + 1;
    }
}

template <class T>
void HeapSort<T> :: applySorting(T * data, size_t size){
    size_t currentPosition = size / 2;

    while(currentPosition > 0){
        --currentPosition;

        siftDown(data, currentPosition, size);
    }

    currentPosition = size;

    while(currentPosition > 0){
        --currentPosition;

        ExtendedSorter<T> :: swap(data[0], data[currentPosition]);
        siftDown(data, 0, currentPosition);
    }
}

template <class T>
void HeapSort<T> :: sort(T * data, size_t size){
    ExtendedSorter<T> :: sort(data, size);
}

template <class T>
unsigned long long HeapSort<T> :: getSortTime() const{
    return ExtendedSorter<T> :: getSortTime();
}
