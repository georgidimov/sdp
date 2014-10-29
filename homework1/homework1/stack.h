#pragma once
#include <iostream>
#include <box.h>

template <class T>
class Stack
{    
    Box <T> * top;
    int boxesCount;
public:
    Stack();
    ~Stack();

    void push(const T newBox);
    const T pop();

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

//push
template <class T>
void Stack <T> :: push(const T value){
    if(boxesCount == 0){    //check if there is at least one box
        top = new Box <T> (NULL, value);
    }else{
        Box <T> * newBox = new Box <T> (top, value);
        top = newBox;
    }

    ++boxesCount;
}
//push end

//pop
template <class T>
const T Stack <T> :: pop(){
    T tempValue = top->getValue();
    Box <T> * tempBoxPointer = top->getNext();

    top->setNext(NULL);    //detach box from the chain
    delete top;

    top = tempBoxPointer;
    tempBoxPointer = NULL;
    --boxesCount;

    return tempValue;
}
//pop end

template <class T>
bool Stack <T> :: isEmpty() const{
    return !boxesCount;
}
