#include <iostream>
#include <QCoreApplication>
#include <SortTester.hpp>
#include <InsertionSort.hpp>
#include <QuickSort.hpp>
#include <HeapSort.hpp>
#include <MergeSort.hpp>

int main(){

    //SortTester<int> sorter;
    //int array[8] = {5, 5, 3, 1, 4, 7, 3, 11};
    //size_t size = 7;
    //int array[8] = {1, 1, 1, 1, 1, 1, 1, 11};
    //size_t size = 7;
    //int array[8] = {1, 4, 1, 5, 3, 8, 7, 2};
    //int array[8] = {4, 3, 1, 3, 7, 5, 11, 2};
    //int array[8] = {2, 9, 1, 2, 7, 0 ,9,  3};
    //size_t size = 8;
    QuickSort<int> q;
    size_t size = 10000000;
    int * array = new int[size];

    for(size_t i = 0; i < size; ++i){
        array[i] = rand() % 10;
        //std :: cout << array[i] << ' ';
    }

    q.sort(array, size);



    int temp = array[0];
    for(size_t i = 0; i < size; ++i){
        if(temp > array[i]){
            std :: cout << "something went wrong";
            break;
        }

        //std :: cout << array[i] << ' ';
       temp = array[i];
    }

    std :: cout << q.getSortTime();

    return 0;
}
