#pragma once
#include <stdexcept>
#include <list.hpp>

template <class T>
class Stack : private List<T>{
public:
    Stack();
    Stack(const Stack<T> & s);
    Stack & operator = (const Stack & s);
    ~Stack();

    void push(const T & newEl);
    T pop();
    T peek() const;


    bool isEmpty() const;
};

template <class T>
Stack<T> :: Stack() : List<T>(){
    ;
}

template <class T>
Stack<T> :: Stack(const Stack<T> & s) : List<T>(s){
    ;
}

template <class T>
Stack<T> & Stack<T> :: operator = (const Stack<T> & s){
    if(this == s){
        return;
    }

    List<T> :: operator =(s);

    return * this;
}

template <class T>
Stack<T> :: ~Stack(){
    ;
}

template <class T>
void Stack<T> :: push(const T & newEl){
    List<T> :: addAt(0, newEl);
}

template <class T>
T Stack<T>::pop(){
    if( isEmpty() ){
        throw std :: runtime_error("empty stack");
    }

    return List<T> :: removeAt(0);
}

template <class T>
T Stack<T> :: peek() const{
    return List<T> :: getAt(0);
}

template <class T>
bool Stack<T> :: isEmpty() const{
    return List<T> :: getSize() == 0;
}
