#pragma once
#include <stdexcept>
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
    const Value & getKey() const;
    const Value & getValue() const;

    void addChild(Tag * child);
    Tag * findChild(const Value & key) const;
    const List<Tag *> & getChilds() const;


    void addAttribute(Value k, Value v);
    void changeAttribute(Value key, Value newValue);
    void removeAttribute(Value key);

    ///REMOVE ME
    void printChilds() const{
        size_t size = childs.getSize();

        std :: cout << std :: endl << size << std :: endl;
        for(size_t i = 0; i < size; ++i){
           std :: cout << childs[i]->getKey() << ' ' << childs[i]->getValue() << std :: endl;
        }
    }
};
