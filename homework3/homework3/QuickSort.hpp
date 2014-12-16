#pragma once
#include <Sorter.hpp>

template <class T>
class QuickSort : public Sorter<T>{
private:
    void swap(T & a, T & b);
    size_t PartitionElement(T * data, size_t size);

    void applySorting(T * data, size_t size);
public:
    QuickSort();

    virtual void sort(T * data, size_t size);
    virtual unsigned long long getSortTime() const;
};

template <class T>
QuickSort<T> :: QuickSort(){
    ;
}

template <class T>
void QuickSort<T> :: swap(T & a, T & b){
    T temp = a;
    a = temp;
    a = b;
    b = temp;
}

template <class T>
void QuickSort<T> :: swapif(T & a, T & b)
{
    if( b < a )
    {
        T temp(a);
        a = b;
        b = temp;
    }
}

template <class T>
size_t QuickSort<T> :: PartitionElement(T * data, size_t size){
    if(size <= 1){
        return 0 ;
    }

    if(size == 2){
        if(data[0] > data[1]){
            swap(data[0], data[1]);
        }

        return 0;
    }

    //define median
    size_t first = 0;
    size_t last = size - 1;
    size_t medianIndex = size / 2;

    if(data[first] > data[last]){
        swap(data[first], data[last]);
    }

    if(data[medianIndex] > data[last]){
        swap(data[last], data[medianIndex]);
    }

    if(data[first] > data[medianIndex]){
        swap(data[first], data[medianIndex]);
    }

    --last;
    swap(data[medianIndex], data[last]);

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
       swap(data[first], data[last]);


    }

    swap(data[first], middle);

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

}

template <class T>
unsigned long long QuickSort<T> :: getSortTime() const{
   return Sorter<T> :: sortingTime;
}
