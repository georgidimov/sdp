#pragma once
#include <iostream>
#include <node.hpp>

template <class T>
class List{
    Node<T> * first;
    Node<T> * last;

    size_t size;
    Node<T> * & getNodeAt(int index);
public:
    List();
    List(const List & o);
    //List(Node<T> * newFirst, size_t newSize);
    ~List();

    //List & operator = (const Queue & o);

    void addAt(int index, T newElement);
    T removeAt(int index);
    const T & getAt(int index) const;



   size_t getSize() const;
   bool isEmpty() const;
};


template <class T>
List<T> :: List(){
    first = NULL;
    last = NULL;
    size = 0;
}

template <class T>
List<T> :: List(const List & o){
    if(&o == this){  //check for self-assignment
        throw "invalid assignment";
    }

    first = NULL;
    last = NULL;
    size = 0;

    //for(List<T>::Iterator i = o.begin(); i; ++i){
    //    enqueue(*i);
    //}

}
/*
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
*/
template <class T>
List<T> :: ~List(){
    delete first;
}
/*
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
*/
template <class T>
void List<T> :: addAt(int index, T newElement){
    if(index < 0 || index > size + 1){
        throw "invalid index";
    }

    Node<T> * newNode = new Node<T>(newElement, NULL);

    if(index == 0){
        if(size == 0){
            first = last = newNode;
        }else{
            newNode->setNext(first);
            first = newNode;
        }
    }else{
        Node<T> * beforeNode = getNodeAt(index - 1);
        newNode->setNext(beforeNode->getNext());

        beforeNode->setNext(newNode);
    }

    /*
    Node<T> * newNode = new Node<T>(newElement, NULL);

    if(size == 0){
        first = last = newNode;
    }else{
        last->setNext(newNode);
        last = newNode;
    }
    */
    ++size;
}

template <class T>
T List<T> :: removeAt(int index){
    if(index < 0 || index > size){
        throw "invalid index";
    }

    if(index == 0){
        Node<T> * afterNode = first->getNext();
        first->setNext(NULL);
        T value = first->getValue();
        delete first;
        first = afterNode;
        size--;

        return value;
    }else{
        Node<T> * beforeNode = first;

        for(int i = 0; i < index - 1; ++i){
            beforeNode = beforeNode->getNext();
        }

        T value = beforeNode->getNext()->getValue();

        Node<T> * afterNode = beforeNode->getNext()->getNext();
        beforeNode->getNext()->setNext(NULL);


        delete beforeNode->getNext();

        beforeNode->setNext(afterNode);
        --size;

        return value;
    }
}

template <class T>
const T & List<T> :: getAt(int index) const{
    if (index < 0 || index > size){
        throw "invalid index";
    }

    if(index == 0){
        return first->getValue();
    }else{
        Node<T> * node = first;

        for(int i = 0; i < index; ++i){
            node = node->getNext();
        }

        return node->getValue();
    }
}

template <class T>
Node<T> *&List<T>::getNodeAt(int index){
    if (index < 0 || index > size){
        throw "invalid index";
    }

    if(index == 0){
        return first;
    }else{
        Node<T> * node = first;

        for(int i = 0; i < index; ++i){
            node = node->getNext();
        }

        return node;
    }
}

template <class T>
bool List<T> :: isEmpty() const{
    return size == 0;
}

template <class T>
size_t List<T> :: getSize() const{
    return size;
}
