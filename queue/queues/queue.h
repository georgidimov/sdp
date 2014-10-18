#pragma once
#include <iostream>
#include "box.h"

template <class T>
class Queue{
    size_t boxesCount;
    Box<T> * first;
    Box<T> * last;
public:
    Queue();

    ~Queue();

    bool isEmpty() const;
    size_t size() const;
    bool push(Box<T> * newBox);
    Box<T> * pop();

};


template <class T>
Queue<T> :: Queue(){
    boxesCount = 0;
    first = NULL;
    last = NULL;
}

template <class T>
Queue<T> :: ~Queue(){
    boxesCount = 0;
    first = NULL;
    last = NULL;
}


template <class T>
bool Queue<T> :: isEmpty() const{
    return !(bool)boxesCount;
}
