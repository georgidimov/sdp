#include "tag.h"

Tag :: Tag(Value passedKey, Value passedValue){
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

const Value & Tag::getKey() const{
    return key;
}

void Tag :: setKey(const Value & newKey){
    key = newKey;
}

const Value & Tag :: getValue() const{
    return value;
}

void Tag :: setValue(const Value & newValue){
    value = newValue;
}

void Tag :: addChild(Tag * child){
    childs.add(child);
}

void Tag :: removeChild(const Value & key){
    int size = (int)childs.getSize();

    for(--size; size >= 0; --size){
        if(childs.getAt(size)->getKey() == key){
            delete childs[size];
            childs.removeAt(size);
        }
    }
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

List<Tag *> & Tag::getChilds(){
    return childs;
}

bool Tag :: hasChilds() const{
    return childs.getSize();
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

const List<Attribute> & Tag :: getAttributes() const{
    return attrs;
}
