#pragma once
#include <list.hpp>
#include <attribute.h>

///Check clear method
class Tag{
    Tag * parent;
    List<Tag *> children;

    List<Attribute> attrs;

    Value value;

    void clear();
    size_t findAttrIndex(Value key) const;
public:
    Tag(Tag * passedParent, Value passedValue);
    ~Tag();

    Tag * getParent() const;
    Value getValue() const;

    void addChild(Tag * child);


    void addAttribute(Value k, Value v);
    void changeAttribute(Value key, Value newValue);
};
