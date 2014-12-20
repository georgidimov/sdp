#pragma once
#include <value.h>

class Attribute{
    Value key;
    Value value;
public:
    Attribute();
    Attribute(Value k, Value v);
    ~Attribute();

    void setValue(Value v);

    Value getKey() const;
    Value getValue() const;
};
