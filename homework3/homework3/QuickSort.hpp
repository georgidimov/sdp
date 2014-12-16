#pragma once
#include <ExtendedSorter.hpp>

template <class T>
class QuickSort : public ExtendedSorter<T>{
private:
    size_t PartitionElement(T * data, size_t size);

    virtual void applySorting(T * data, size_t size);
public:
    QuickSort();
    ~QuickSort();

    virtual void sort(T * data, size_t size);
    virtual unsigned long long getSortTime() const;
};

template <class T>
QuickSort<T> :: QuickSort(){
    ;
}

template <class T>
QuickSort<T> :: ~QuickSort(){
    ;
}

template <class T>
size_t QuickSort<T> :: PartitionElement(T * data, size_t size){
    if(size <= 1){
        return 0 ;
    }

    if(size == 2){
        if(data[0] > data[1]){
            ExtendedSorter<T> :: swap(data[0], data[1]);
        }

        return 0;
    }

    //define median
    size_t first = 0;
    size_t last = size - 1;
    size_t medianIndex = size / 2;

    if(data[first] > data[last]){
       ExtendedSorter<T> :: swap(data[first], data[last]);
    }

    if(data[medianIndex] > data[last]){
        ExtendedSorter<T> :: swap(data[last], data[medianIndex]);
    }

    if(data[first] > data[medianIndex]){
        ExtendedSorter<T> :: swap(data[first], data[medianIndex]);
    }

    --last;
    ExtendedSorter<T> ::  swap(data[medianIndex], data[last]);

    T middle = data[last];

    while(true)
    {

        while(data[++first] < middle)
            ;

        while(data[--last] > middle)
        {
            if(first == last)
                break;
        }

        if(first >= last)
            break;
       ExtendedSorter<T> :: swap(data[first], data[last]);


    }

    ExtendedSorter<T> :: swap(data[first], middle);

    return first;
}

template <class T>
void QuickSort<T> :: applySorting(T *data, size_t size){
    if(size < 2){
        return;
    }

    size_t medianIndex = PartitionElement(data, size);

    sort(data, medianIndex);
    sort(data + medianIndex + 1, size - medianIndex - 1);
}

template <class T>
void QuickSort<T> :: sort(T * data, size_t size){
    ExtendedSorter<T> :: sort(data, size);
}

template <class T>
unsigned long long QuickSort<T> :: getSortTime() const{
   return ExtendedSorter<T> :: getSortTime();
}
