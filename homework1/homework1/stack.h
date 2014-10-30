#pragma once
#include <iostream>
#include <stdexcept>
#include <box.h>

template <class T>
class Stack
{
//prevent using copy constructor and operator =
    Stack(const Stack &);
    Stack & operator= (const Stack &);

    Box <T> * top;
    int boxesCount;
public:
    Stack();
    ~Stack();

    void push(const T & newBox);
    T pop();

    bool isEmpty() const;
};

//constructor
template <class T>
Stack <T> :: Stack(){
    top = NULL;
    boxesCount = 0;
}


//destructor
template <class T>
Stack <T> :: ~Stack(){
    delete top;
    top = NULL;
}

template <class T>
void Stack <T> :: push(const T & value){
    if(boxesCount == 0){    //check if there is at least one box
        top = new Box <T> (NULL, value);
    }else{
        Box <T> * newBox = new Box <T> (top, value);
        top = newBox;
    }

    ++boxesCount;
}
//push end


template <class T>
T Stack <T> :: pop(){
    if( isEmpty() ){
        throw std :: runtime_error("empty stack");
    }

    T tempValue = top->getValue();
    Box <T> * tempBoxPointer = top->getNext();

    top->setNext(NULL);    //detach box from the chain
    delete top;            //and delete the it

    top = tempBoxPointer;
    tempBoxPointer = NULL;
    --boxesCount;

    return tempValue;
}
//pop end


template <class T>
bool Stack <T> :: isEmpty() const{
    return boxesCount == 0;
}
//isEmpty end
