#pragma once
#include <string.h>

class Tag{
    char * key;
    char * value;
public:
    Tag(char * k, char * v);
    ~Tag();

    ///FIXME
    const char * getKey() const;
    const char * getValue() const;
};

