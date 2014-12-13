#pragma once
#include <Sorter.hpp>


template <class T>
class HeapSort : public Sorter<T>{
    void siftDown(T * array, size_T startPosition, size_t endPosition) const;
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
void HeapSort<T> :: siftDown(T * array, size_T startPosition, size_t endPosition) const{
    ;
}


template <class T>
void HeapSort<T> :: sort(T * data, size_t count){

}

template <class T>
unsigned long long HeapSort<T> :: getSortTime() const{
    return 0;
}
