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

    void enqueue(T newElement);
    T dequeue();

    size_t getSize() const;

    bool isEmpty() const;

    class Iterator{
        Node<T> * current;
    public:
        Iterator(Node<T> * startElement);
        const T & operator *() const;

        Iterator & operator ++();
        const Iterator & operator ++() const;

        bool operator == (const Iterator & rh) const;
        //bool operator != (const Iterator & rh) const;

        operator bool() const;
    };

    Iterator begin();
    Iterator end();
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

template <class T>
void Queue<T> :: enqueue(T newElement){
    Node<T> * newNode = new Node<T>(newElement, NULL);

    if(size == 0){
        first = last = newNode;
    }

    last->setNext(newNode);
    last = newNode;

    ++size;
}

template <class T>
T Queue<T> :: dequeue(){
    if (!first){
        throw "empty stack";
    }
    Node<T> * tempNode = first;

    //remove first from the chain
    first = first->getNext();
    tempNode->setNext(NULL);

    T firstValue = tempNode->getValue();

    delete tempNode;
    --size;

    return firstValue;
}

template <class T>
bool Queue<T> :: isEmpty() const{
    return size == 0;
}

template <class T>
Queue<T> :: Iterator :: Iterator(Node<T> * startElement){
    current = startElement;
}

template <class T>
typename Queue<T> :: Iterator Queue<T> :: begin(){
    return Iterator(first);
}

template <class T>
typename Queue<T> :: Iterator Queue<T> :: end(){
    return Iterator(last);
}

template <class T>
const T & Queue<T> :: Iterator :: operator * () const{
    if (current != NULL){
        return current->getValue();
    }

    throw "empty queue";
}

template <class T>
typename Queue<T> :: Iterator & Queue<T> :: Iterator :: operator ++(){
    if( current ){
        current = current->getNext();
    }

    return * this;
}

template <class T>
typename Queue<T> :: Iterator const & Queue<T> :: Iterator :: operator ++() const{
    if( current ){
        current = current->getNext();
    }

    return * this;
}

template <class T>
bool Queue<T> :: Iterator :: operator == (const Iterator & rh) const{
    std :: cout << "call";
    return current == rh.current;
}
/*
template <class T>
bool Queue<T> :: Iterator :: operator != (const Iterator & rh) const{
    std :: cout << "call";
    return !this == rh;
}
*/
template <class T>
Queue<T> :: Iterator :: operator bool() const{
    return current != NULL;
}



