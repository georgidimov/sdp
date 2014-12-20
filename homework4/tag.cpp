#include "tag.h"

Tag :: Tag(Tag * passedParent, Value passedValue){
    parent = passedParent;

    value = passedValue;
}

Tag :: ~Tag(){
    clear();
}

void Tag :: clear(){
    ;
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

Value Tag :: getValue() const{
    return value;
}

void Tag :: addChild(Tag * child){
    children.add(child);
}

void Tag :: addAttribute(Value k, Value v){
    attrs.add(Attribute(k, v));
}

void Tag :: changeAttribute(Value key, Value newValue){
    size_t index = findAttrIndex(key);

    attrs[index].setValue(newValue);
}
