#pragma once
#include <iostream>
#include <node.hpp>

template <class T>
class Queue{
    Node<T> * first;
    Node<T> * last;

    size_t size;
public:
    Queue();
    Queue(const Queue & o);
    Queue(Node<T> * newFirst, size_t newSize);
    ~Queue();

    Queue & operator = (const Queue & o);

    void enqueue(T newElement);
    T dequeue();
    const T & peek() const;



    size_t getSize() const;

    bool isEmpty() const;

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
    Iterator end() const;

    Queue split();
};

template <class T>
Queue<T> :: Queue(){
    first = NULL;
    last = NULL;
    size = 0;
}

template <class T>
Queue<T> :: Queue(const Queue & o){
    if(&o == this){  //check for self-assignment
        throw "invalid assignment";
    }

    first = NULL;
    last = NULL;
    size = 0;

    for(Queue<T>::Iterator i = o.begin(); i; ++i){
        enqueue(*i);
    }

}

template <class T>
Queue<T> :: Queue(Node<T> * newFirst, size_t newSize){
    first = newFirst;

    Node<T> * tempNode = first;

    for(size_t i = 0; i < newSize - 1; i++){
        if( tempNode ){
            tempNode = tempNode->getNext();
        }else{
            throw "invalid queue size";
        }
    }


    last = tempNode;
    size = newSize;
}

template <class T>
Queue<T> :: ~Queue(){
    delete first;
}

template <class T>
Queue<T> & Queue<T> :: operator = (const Queue<T> & o){
    if(this == &o){  //check for self-assignment
        return * this;
    }

    //destroy current data
    delete first;
    size = 0;

    for(Queue<T>::Iterator i = o.begin(); i; ++i){
        enqueue(*i);
    }

    return *this;
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
const T & Queue<T> :: peek() const{
    return first->getValue();
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



