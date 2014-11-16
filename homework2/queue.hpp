#pragma once
#include <iostream>
#include <list.hpp>

template <class T>
class Queue : private List<T>{
public:
    Queue();
    Queue(const Queue & o);

    Queue(const Queue<T> & o, size_t startIndex);
    ~Queue();

    Queue & operator = (const Queue & o);

    Queue split();

    void enqueue(T newElement);
    T dequeue();
    const T & peek() const;

    size_t getSize() const;

    bool isEmpty() const;
    /*
    class Iterator{
        Node<T> * current;
    public:
        Iterator(Node<T> * startElement);
        const T & operator *() const;

        Iterator & operator ++();
        const Iterator & operator ++() const;

        //bool operator == (const Iterator &) const;
        //bool operator != (const Iterator &) const;
        operator bool() const;
    };

    Iterator begin();           ///add non const
    Iterator begin() const;     ///add non const

    Iterator end();
    Iterator end() const;*/


};

template <class T>
Queue<T> :: Queue() : List<T>(){

}

template <class T>
Queue<T> :: Queue(const Queue & o) : List<T>(o){
    ;
}

template <class T>
Queue<T> :: Queue(const Queue<T> & o, size_t startIndex) : List<T> :: List(o, startIndex){
    ;
}

template <class T>
Queue<T> :: ~Queue(){
    ;
}

template <class T>
Queue<T> & Queue<T> :: operator = (const Queue<T> & o){
    List<T> :: operator =(o);
    return *this;
}

template <class T>
Queue<T> Queue<T> :: split(){
    size_t middle = getSize() / 2;

    Queue<T> secondPart(*this, middle);

    size_t size = getSize();
    for(size_t i = middle; middle < size; ++middle){
        List<T> :: removeAt(i);
    }

    return secondPart;
}

template <class T>
size_t Queue<T> :: getSize() const{
    return List<T> :: getSize();
}

template <class T>
void Queue<T> :: enqueue(T newElement){
    List<T> :: addAt(getSize(), newElement);
}

template <class T>
T Queue<T> :: dequeue(){
    if (!getSize()){
        throw "empty queue";
    }

    return List<T> :: removeAt(0);
}


template <class T>
const T & Queue<T> :: peek() const{
    if (!getSize()){
        throw "empty queue";
    }

    return List<T> :: getAt(0);
}

template <class T>
bool Queue<T> :: isEmpty() const{
    return getSize() == 0;
}
/*
template <class T>
Queue<T> :: Iterator :: Iterator(Node<T> * startElement){
    current = startElement;
}

template <class T>
typename Queue<T> :: Iterator Queue<T> :: begin(){
    return Iterator(first);
}

template <class T>
typename Queue<T> :: Iterator Queue<T> :: begin() const{
    return Iterator(first);
}

template <class T>
typename Queue<T> :: Iterator Queue<T> :: end(){
    return Iterator(last);
}

template <class T>
typename Queue<T> :: Iterator Queue<T> :: end() const{
    return Iterator(last);
}

template <class T>
Queue<T> Queue<T> :: split(){
    size_t newQueueSize = size / 2;

    Node<T> * tempNode = first;

    for(size_t i = 0; i < newQueueSize - 1; ++i){
        if( tempNode ){
            tempNode = tempNode->getNext();
        }else{
            throw "invalid size";
        }
    }

    Queue <T> newQueue(tempNode->getNext(), size - newQueueSize);

    tempNode->setNext(NULL);
    size = newQueueSize;

    return newQueue;
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
Queue<T> :: Iterator :: operator bool() const{
    return current != NULL;
}
*/



