#pragma once
#include <string.h>

class Attribute{
    char * key;
    char * value;
public:
    Attribute(char * k, char * v);
    ~Attribute();

    void getKey(char * & returnedKey) const;
    void getValue(char * & returnedValued) const;
};

