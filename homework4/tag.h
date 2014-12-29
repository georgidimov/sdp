#pragma once
#include <list.hpp>
#include <attribute.h>

///Check clear method
class Tag{
    Tag * parent;
    List<Tag *> childs;

    List<Attribute> attrs;

    Value key;
    Value value;

    void clear();
    size_t findAttrIndex(Value key) const;
public:
    Tag(Tag * passedParent, Value passedKey, Value passedValue);
    ~Tag();

    Tag * getParent() const;
    Value getKey() const;
    Value getValue() const;

    void addChild(Tag * child);
    const List<Tag *> & getChilds() const;


    void addAttribute(Value k, Value v);
    void changeAttribute(Value key, Value newValue);
    void removeAttribute(Value key);

    ///REMOVE ME
    void printAttrs() const{
        size_t size = attrs.getSize();

        for(size_t i = 0; i < size; ++i){
            std :: cout << attrs[i].getValue() << ' ';
        }

        std :: cout << std :: endl;
    }
};
