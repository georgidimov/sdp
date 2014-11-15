#pragma once
#include <iostream>
#include <node.hpp>

template <class T>
class List{
    Node<T> * first;
    Node<T> * last;

    size_t size;
public:
    List();
    ~List();
};

template <class T>
List<T> :: List(){
    first = NULL;
    last = NULL;
    size = 0;
}

//template <class T>
//Queue<T> :: Queue(const Queue & o){

//template <class T>
//Queue<T> :: Queue(Node<T> * newFirst, size_t newSize){

template <class T>
List<T> :: ~List(){

}
