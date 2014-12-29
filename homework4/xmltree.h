#pragma once
#include <tag.h>

class XMLtree{
    Tag * root;
    void clear();
//protected:
public:
    class Iterator{
        Tag * current;
    public:
        Iterator();
        Iterator(Tag * k);
        Iterator(Value k);

        const Iterator & operator++();

        const Iterator & operator--();
        bool operator ==(const Iterator & rh) const;

        operator bool() const;
    };

//public:
    XMLtree();
    ~XMLtree();
    void addTag(Value parent, Value k, Value v);


    const Iterator & begin();
    const Iterator & end();


};
