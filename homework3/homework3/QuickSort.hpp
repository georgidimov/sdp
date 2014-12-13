#pragma once
#include <Sorter.hpp>

template <class T>
class QuickSort : public Sorter<T>{
private:
    void swap(T & a, T & b);
public:
    QuickSort();

    virtual void sort(T *data, size_t size);
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
void QuickSort<T> :: sort(T * data, size_t size){
    for(size_t i = 0; i < size; ++i){
        std :: cout << data[i] << ' ';
    }
    std :: cout << std :: endl;


    if(size <= 1){
        return;
    }

    if(size == 2){
        if(data[0] > data[1]){
            swap(data[0], data[1]);
        }

        return;
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

    T median = data[medianIndex];

    --last;
    ++first;

    while(first < last){
        if(data[last] < median){
            while(data[first] < median){
                if(first == last){
                    break;
                }

                ++first;
            }

            if(first != last){
                if(data[first] == median){
                    medianIndex = last;
                }else if(data[last] == median){
                    medianIndex = first;
                }

                swap(data[first], data[last]);
                ++first;
            }
        }

        --last;

        if(first == last && first < medianIndex && data[first] > median){
            swap(data[first], data[medianIndex]);
            medianIndex = first;
        }else if(first == last && first > medianIndex && data[first] < median){
            swap(data[first], data[medianIndex]);
            medianIndex = first;
        }
    }

    sort(data, medianIndex);
    sort(data + medianIndex + 1, size - medianIndex - 1);
}

template <class T>
unsigned long long QuickSort<T> :: getSortTime() const{
   return 0;
}
