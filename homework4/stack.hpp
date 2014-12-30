#pragma once
#include <list.hpp>

template <class T>
class Stack : public List<T>{
public:
    Stack();
    Stack(const Stack<T> s);
    Stack & operator = (const Stack & s);
    ~Stack();

}
