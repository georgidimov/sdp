#include "tag.h"

Tag :: Tag(Tag * passedParent, Value passedKey, Value passedValue){
    parent = passedParent;

    key = passedKey;
    value = passedValue;
}

Tag :: ~Tag(){
    clear();
}

void Tag :: clear(){
    size_t size = childs.getSize();

    for(size_t i = 0; i < size; ++i){
        delete childs[i];
        childs[i] = NULL;
    }
}

size_t Tag :: findAttrIndex(Value key) const{
    size_t size = attrs.getSize();

    for(size_t i = 0; i < size; ++i){
        if(attrs[i].getKey() == key){
            return i;
        }
    }

    throw "invalid key";
}

Tag * Tag :: getParent() const{
    return parent;
}

const Value & Tag::getKey() const{
    return key;
}

const Value & Tag :: getValue() const{
    return value;
}

void Tag :: addChild(Tag * child){
    childs.add(child);
}

Tag * Tag :: findChild(const Value & key) const{
    size_t size = childs.getSize();

    for(size_t i = 0; i < size; ++i){
        if(childs.getAt(i)->getKey() == key){
            return childs[i];
        }
    }

    throw std :: runtime_error("wrong child key");
}

const List<Tag *> & Tag :: getChilds() const{
    return childs;
}

void Tag :: addAttribute(Value k, Value v){
    attrs.add(Attribute(k, v));
}

void Tag :: changeAttribute(Value key, Value newValue){
    size_t index = findAttrIndex(key);

    attrs[index].setValue(newValue);
}

void Tag :: removeAttribute(Value key){
    for(size_t i = 0; i < attrs.getSize(); ++i){
        if(attrs[i].getKey() == key){
            attrs.removeAt(i);
        }
    }
}
