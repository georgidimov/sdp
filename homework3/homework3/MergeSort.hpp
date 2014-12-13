#pragma once
#include <Sorter.hpp>


template <class T>
class MergeSort : public Sorter<T>{
    void swap(T & a, T & b) const;
public:
    MergeSort();

    virtual void sort(T * array, size_t size);
    virtual unsigned long long getSortTime() const;
};

template <class T>
MergeSort<T> :: MergeSort(){
    ;
}

template <class T>
void MergeSort<T> :: swap(T & a, T & b) const{
    T temp = a;
    a = temp;
    a = b;
    b = temp;
}

template <class T>
void MergeSort<T> :: sort(T * array, size_t size){

}

template <class T>
unsigned long long MergeSort<T> :: getSortTime() const{
    return 0;
}
