#pragma once
#include <list.hpp>
#include <attribute.h>

class Tag{
    Tag * parent;
    List<Tag *> children;

    List<Attribute> attrs;

    char * value;

    void clear();
public:
    Tag(Tag * passedParent, char * passedValue);
    ~Tag();

    Tag * getParent() const;

    void getValue(char * returnedValue) const;
};
