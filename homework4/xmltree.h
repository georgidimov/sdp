#pragma once
#include <tag.h>
#include <queue.hpp>

class XMLtree{
    Tag * root;

    void clear();
//protected:
public:

//public:
    XMLtree();
    ///remove me
    XMLtree(Tag * r);
    ~XMLtree();

    class Iterator{
        Queue<Tag *> tagsQueue;
    public:
        Iterator();
        Iterator(Tag * current);

        Iterator & operator++(int uselessVar);
        Iterator & operator++();

        Tag * operator *();

        bool operator ==(const Iterator & r) const;
        operator bool() const;
    };


    void addTag(Value parent, Value k, Value v);


    Iterator begin();
    Iterator end();


};
