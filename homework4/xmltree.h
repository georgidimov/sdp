#pragma once
#include <tag.h>
#include <queue.hpp>
#include <stack.hpp>

class XMLtree{
    Tag * root;

    void clear();

    void addTabs(std :: ostream & out, size_t level) const;

    Tag * findTag(const Value & path) const;
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


    void addTag(const Value & path, const Value & k, const Value & v);


    Iterator begin() const;
    Iterator end() const;

    void printReadable(std :: ostream & out) const;
};
