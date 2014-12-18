#pragma once
#include <list.hpp>
#include <attribute.h>

class Tag{
    Tag * parent;
    List<Tag *> children;

    List<Attribute> attrs;

    Value value;

    void clear();
public:
    Tag(Tag * passedParent, Value passedValue);
    ~Tag();

    Tag * getParent() const;
    Value getValue() const;

    void addChild(Tag * child);
};
