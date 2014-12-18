#pragma once
#include <value.h>

class Attribute{
    Value key;
    Value value;
public:
    Attribute(Value k, Value v);
    ~Attribute();

    Value getKey() const;
    Value getValue() const;
};

