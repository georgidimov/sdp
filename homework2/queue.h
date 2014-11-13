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
