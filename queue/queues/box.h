#pragma once
#include <iostream>

template <class T>
class Box
{
    Box * next;
    Box * prev;

    T value;

protected:
    Box * getNext() const;
    bool setNext(Box * passedNext);

    Box * getPrev() const;
    bool setPrev(Box * passedPrev);

    T getValue() const;
    void setValue(T passedValue);

public:
    Box();
    Box(Box * next, Box * prev, T Value);
    ~Box();
};

template <class T>
Box<T> :: Box(){
    next = NULL;
    prev = NULL;
}

template <class T>
Box<T> :: Box(Box * passedNext, Box * passedPrev, T passedValue){
    next = passedNext;
    prev = passedPrev;
    value = passedValue;
}

template <class T>
Box<T> :: ~Box(){
    next = NULL;
    prev = NULL;
}

template <class T>
Box<T> * Box<T> :: getNext() const{
    return next;
}

template <class T>
bool Box<T> :: setNext(Box<T> * passedNext){
    next = passedNext;
    return next == NULL;
}

template <class T>
Box<T> * Box<T> ::getPrev() const{
    return prev;
}

template <class T>
bool Box<T> ::setPrev(Box<T> * passedPrev){
    prev = passedPrev;
    return prev == NULL;
}

template <class T>
T Box<T> :: getValue() const{
    return value;
}

template <class T>
void Box<T> :: setValue(T passedValue){
    value = passedValue;
}
