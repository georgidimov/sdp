#pragma once
#include <string.h>

class Tag{
    char * key;
    char * value;
public:
    Tag(char * k, char * v);
    ~Tag();

    void getKey(char * & returnedKey) const;
    void getValue(char * & returnedValued) const;
};

