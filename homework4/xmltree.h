#pragma once
#include <tag.h>
#include <queue.hpp>

class XMLtree{
    Tag * root;
    Queue<Tag *> iteratorQueue;
    void clear();
//protected:
public:
    class Iterator{
        Tag * current;

    public:
        Iterator(Tag * k);

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
