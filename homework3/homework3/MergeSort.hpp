#pragma once
#include <Sorter.hpp>


template <class T>
class MergeSort : public Sorter<T>{
    T * result;

    void swap(T & a, T & b) const;
    void merge(T * a, size_t aSize, T * b, size_t bSize);
public:
    MergeSort();
    ~MergeSort();

    virtual void sort(T * array, size_t size);
    virtual unsigned long long getSortTime() const;

    void print() const;
};

template <class T>
MergeSort<T> :: MergeSort(){
    result = NULL;
}

template <class T>
MergeSort<T> :: ~MergeSort(){
    delete [] result;
}

template <class T>
void MergeSort<T> :: swap(T & a, T & b) const{
    T temp = a;
    a = temp;
    a = b;
    b = temp;
}

template <class T>
void MergeSort<T> :: merge(T * a, size_t aSize, T * b, size_t bSize){
    size_t aCounter = 0;
    size_t bCounter = 0;
    size_t resultCounter = 0;

    while(aCounter < aSize && bCounter < bSize) {
        if(a[aCounter] <= b[bCounter]){
            result[resultCounter] = a[aCounter];
            ++aCounter;
        }else{
            result[resultCounter] = b[bCounter];
            ++bCounter;
        }

        ++resultCounter;
    }

    while(aCounter < aSize){
        result[resultCounter] = a[aCounter];

        ++aCounter;
        ++resultCounter;
    }

    while(bCounter < bSize){
        result[resultCounter] = b[bCounter];

        ++bCounter;
        ++resultCounter;
    }

    for(size_t i = 0; i < resultCounter; ++i){
        a[i] = result[i];
    }
}

template <class T>
void MergeSort<T> :: sort(T * array, size_t size){
    if(result == NULL){
        result = new int[size];

    }

    if(size == 1){
        return;
    }

    if(size == 2){
        if(array[0] > array[1]){
            swap(array[0], array[1]);
        }
        return;
    }

    size_t newSize = size / 2;

    sort(array, newSize);
    sort(array + newSize, size - newSize);
    merge(array, newSize, array + newSize, size - newSize);

}

template <class T>
unsigned long long MergeSort<T> :: getSortTime() const{
    return 0;
}

template <class T>
void MergeSort<T> :: print() const{
    for(size_t i = 0; i < 8; ++i){
        std :: cout << result[i] << ' ';
    }
}
