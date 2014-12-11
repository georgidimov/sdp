#include "InsertionSort.h"

template <class T>
InsertionSort<T> :: InsertionSort(){
;
}

template <class T>
void InsertionSort<T> :: sort(T * data, size_t count){

    T tempValue;
    size_t tempPosition;

    for(size_t i = count - 1; i >= 0; --i){
        tempValue = data[i];
        tempPosition = i - 1;

        while(tempPosition >= 0 && data[tempPosition] > tempValue){
            std :: swap(tempValue, data[tempPosition]);
            --tempPosition;
        }
    }
}
