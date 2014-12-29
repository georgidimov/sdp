#pragma once
#include <tag.h>
#include <queue.hpp>

class XMLtree{
    Tag * root;
    void clear();
//protected:
public:
    class Iterator{
        //Tag * current;
        Queue<Tag *> tagsQueue;
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
