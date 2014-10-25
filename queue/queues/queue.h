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
    bool push(T newBoxValue);
    T pop();

};


template <class T>
Queue<T> :: Queue(){
    boxesCount = 0;
    first = new Box<T>;
    last = first;
}

template <class T>
Queue<T> :: ~Queue(){
    boxesCount = 0;
    delete first;
    last = NULL;
}


template <class T>
bool Queue<T> :: isEmpty() const{
    return !(bool)boxesCount;
}

template <class T>
size_t Queue<T> :: size() const{
    return boxesCount;
}

template <class T>
bool Queue<T> :: push(T newBoxValue){
/*    Box<T> * newBox = new Box<T>(NULL, newBoxValue, first);
    first->setPrev(newBox);
    first = newBox;
/*    tempPointer->setPrev(NULL);
    tempPointer->setNext(first);
    first->setPrev(tempPointer);
    first = tempPointer;
*/
    boxesCount++;

    return first == NULL;
}

template <class T>
T Queue<T> :: pop(){
    T tempValue = last->getValue();
    last = last->getPrev();
    delete last->getNext();
    last->setNext(NULL);
    return tempValue;
}
