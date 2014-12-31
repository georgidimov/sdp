#pragma once
#include <stdexcept>
#include <list.hpp>
#include <attribute.h>

class Tag{
    List<Tag *> childs;

    List<Attribute> attrs;

    Value key;
    Value value;

    void clear();
    size_t findAttrIndex(Value key) const;
public:
    Tag(Value passedKey, Value passedValue);
    ~Tag();

    const Value & getKey() const;
    void setKey(const Value & newKey);

    const Value & getValue() const;
    void setValue(const Value & newValue);

    void addChild(Tag * child);
    void removeChild(const Value & key);
    Tag * findChild(const Value & key) const;
    List<Tag *> & getChilds();
    bool hasChilds() const;


    void addAttribute(Value k, Value v);
    void changeAttribute(Value key, Value newValue);
    void removeAttribute(Value key);
    const List<Attribute> & getAttributes() const;
};
