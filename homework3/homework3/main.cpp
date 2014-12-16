#include <iostream>
#include <QCoreApplication>
#include <ExtendedSortTester.hpp>
#include <InsertionSort.hpp>
#include <QuickSort.hpp>
#include <HeapSort.hpp>
#include <MergeSort.hpp>
#include <ShakerSort.hpp>

int main(){
    size_t sortersCount = 5;
    Sorter<int> ** sorters = new Sorter<int> * [sortersCount];
    sorters[0] = new QuickSort<int>;
    sorters[1] = new HeapSort<int>;
    sorters[2] = new InsertionSort<int>;
    sorters[3] = new MergeSort<int>;
    sorters[4] = new ShakerSort<int>;

    ExtendedSortTester<int> tester(sorters, sortersCount);

    tester.getSummary(std :: cout);

    for(size_t i = 0; i < sortersCount; ++i){
       delete sorters[i];
    }

    delete [] sorters;

    //ShakerSort<int> s;





    return 0;
}
