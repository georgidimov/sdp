#pragma once
#include <iostream>

template <class T>
class Box{
//prevent using copy constructor and operator=
    Box(const Box &);
    Box & operator=(const Box &);

    Box * next;
    T value;
public:
    Box();
    Box(Box * newNext, T newValue);
    ~Box();

    Box * getNext() const;
    void setNext(Box * newNext);

    T getValue() const;
    void setValue(T newValue);
};


//constructors
template <class T>
Box <T> :: Box(){
    next = NULL;
}

template <class T>
Box <T> :: Box(Box * newNext, T newValue){
    next = newNext;
    value = newValue;
}
//constructors end

//destructor
template <class T>
Box <T> :: ~Box(){
    delete next;
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

