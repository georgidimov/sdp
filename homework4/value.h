#pragma once
#include <iostream>
#include <string.h>

class Value{
    char * value;
    void clear();
public:
    Value(char * passedValue);
    Value(const Value & o);
    Value & operator=(const Value & o);
    ~Value();


    char * getValue() const;
};

