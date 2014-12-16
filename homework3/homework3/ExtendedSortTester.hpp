#pragma once
#include <SortTester.hpp>

template <class T>
class ExtendedSortTester : public SortTester<T>{
    T * data;
    size_t dataSize;

    Sorter<T> ** sorters;
    size_t sortersCount;

    void applySorting();
public:
    ExtendedSortTester(Sorter<T> ** passedSorters, int count);
    ~ExtendedSortTester();

    size_t getDataSize() const;
    void setDataSize(size_t newData);

    virtual void getSummary(std::ostream & out);
};


template <class T>
ExtendedSortTester<T> :: ExtendedSortTester(Sorter<T> ** passedSorters, int count){
    dataSize = 50000;
    data = new T[dataSize];

    sorters = passedSorters;
    sortersCount = count;

    for(size_t i = 0; i < dataSize; ++i){
        data[i] = rand() % dataSize;
    }
}

template <class T>
ExtendedSortTester<T> :: ~ExtendedSortTester(){
    delete [] data;
}


template <class T>
void ExtendedSortTester<T> :: applySorting(){
    for(size_t i = 0; i < sortersCount; ++i){
        sorters[i]->sort(data, dataSize);
    }
}

template <class T>
void ExtendedSortTester<T> :: getSummary(std::ostream & out){
    applySorting();

    out << "Count of data is: " << dataSize << "\n\n";

    for(size_t i = 0; i < sortersCount; ++i){
        out << "Sorter [" << i << "]" << " work ";
        out << double( (sorters[i]->getSortTime() / 10000.0) / 60.0);
        out << " seconds\n";
    }
}

template <class T>
void ExtendedSortTester<T> :: setDataSize(size_t newData){
    dataSize = newData;
}

template <class T>
size_t ExtendedSortTester<T> :: getDataSize() const{
    return dataSize;
}

