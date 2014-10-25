#pragma once
#include <iostream>

template <class T>
class Box{
    Box * next;
    Box * prev;
    T value;
public:
    Box();
    Box(Box * newNext, Box * newPrev, T newValue);
    ~Box();

    Box * getNext() const;
    void setNext(Box * newNext);

    Box * getPrev() const;
    void setPrev(Box * newPrev);

    T getValue() const;
    void setValue(T newValue);
};


//constructors
template <class T>
Box <T> :: Box(){
    next = NULL;
    prev = NULL;
}

template <class T>
Box <T> :: Box(Box * newNext, Box * newPrev, T newValue){
    next = newNext;
    prev = newPrev;
    value = newValue;
}
//constructors end

//destructor
template <class T>
Box <T> :: ~Box(){
    next = NULL;
    prev = NULL;
}

//destructor end

//next setter and getter
template <class T>
Box <T> * Box <T> :: getNext() const{
    return next;
}

template <class T>
void  Box <T> :: setNext(Box * newNext){
    next = newNext;
}

//next end


//prev setter and getter
template <class T>
Box <T> * Box <T> :: getPrev() const{
    return prev;
}

template <class T>
void  Box <T> :: setPrev(Box * newPrev){
    prev = newPrev;
}

//prev end


//value setter and getter
template <class T>
T Box <T> :: getValue() const{
    return value;
}

template <class T>
void Box <T> :: setValue(T newValue){
    value = newValue;
}
//value end

