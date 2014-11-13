#pragma once
#include <iostream>
#include <node.h>

template <class T>
class Queue{
    Node<T> * first;
    Node<T> * last;

    size_t size;
public:
    Queue();
    ~Queue();

    size_t getSize() const;
};

template <class T>
Queue<T> :: Queue(){
    first = NULL;
    last = NULL;
    size = 0;
}

template <class T>
Queue<T> :: ~Queue(){
    delete first;
}

template <class T>
size_t Queue<T> :: getSize() const{
    return size;
}
