#pragma once
#include <tag.h>
#include <queue.hpp>
#include <stack.hpp>

class XMLtree{
    Tag * root;

    void clear();

    void addTabs(std :: ostream & out, int level) const;

    Tag * findTag(const Value & path) const;

    void DFS(Tag * startTag, Queue<Tag *> & q, Queue<int> & tagsLevel, int level) const;

    void printAttributes(std :: ostream & out, Tag * currentTag) const;

    Value sliceTagPath(const Value & path) const;
    Value sliceTagKey(const Value & path) const;
public:
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
    void removeTag(const Value & path);
    void changeTagKey(const Value & path, const Value & newKey);
    void changeTagValue(const Value & path, const Value & newValue);

    void addTagAttribute(const Value & path, const Value & attrKey, const Value & attrValue);
    void removeTagAttribute(const Value & path, const Value & attrKey);
    void changeTagAttribute(const Value & path, const Value & attrKey, const Value & newValue);


    Iterator begin() const;
    Iterator end() const;

    void printReadable(std :: ostream & out) const;
    void printUnreadable(std :: ostream & out) const;
};
