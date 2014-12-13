#pragma once
#include <Sorter.hpp>


template <class T>
class HeapSort : public Sorter<T>{
    void swap(T & a, T & b) const;
    void siftDown(T * array, size_t startPosition, size_t size) const;
public:
    HeapSort();

    virtual void sort(T * data, size_t count);
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
void HeapSort<T> :: sort(T * data, size_t count){

}

template <class T>
unsigned long long HeapSort<T> :: getSortTime() const{
    return 0;
}
