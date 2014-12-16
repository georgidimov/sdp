#pragma once
#include <ExtendedSorter.hpp>


template <class T>
class HeapSort : public ExtendedSorter<T>{
    void swap(T & a, T & b) const;
    void siftDown(T * array, size_t startPosition, size_t size) const;
public:
    HeapSort();

    virtual void sort(T * array, size_t size);
    virtual unsigned long long getSortTime() const;
};

template <class T>
HeapSort<T> :: HeapSort(){
    ;
}

template <class T>
void HeapSort<T> :: swap(T & a, T & b) const{
    T temp = a;
    a = temp;
    a = b;
    b = temp;
}

template <class T>
void HeapSort<T> :: siftDown(T * array, size_t startPosition, size_t size) const{
    T valueAtTheBeginning = array[startPosition];

    size_t childPosition = startPosition * 2 + 1;

    while(childPosition < size){
        //check rigth child if is with greater value get this position
        if(array[childPosition] < array[childPosition + 1] && childPosition + 1 < size){
            ++childPosition;
        }

        //check if the tree is ordered
        if(valueAtTheBeginning > array[childPosition]){
            return;
        }

        if(array[startPosition] < array[childPosition]){
            swap(array[startPosition], array[childPosition]);
        }

        //jump to next node
        startPosition *= 2;
        startPosition += 1;

        childPosition = startPosition * 2 + 1;
    }
}


template <class T>
void HeapSort<T> :: sort(T * array, size_t size){
    size_t currentPosition = size / 2;

    while(currentPosition > 0){
        --currentPosition;

        siftDown(array, currentPosition, size);
    }

    currentPosition = size;

    while(currentPosition > 0){
        --currentPosition;

        swap(array[0], array[currentPosition]);
        siftDown(array, 0, currentPosition);
    }
}

template <class T>
unsigned long long HeapSort<T> :: getSortTime() const{
    return 0;
}
