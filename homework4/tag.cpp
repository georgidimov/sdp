#include "tag.h"

Tag :: Tag(Tag * passedParent, Value passedValue){
    parent = passedParent;

    value = passedValue;
}

Tag :: ~Tag(){
    ;
}

void Tag :: clear(){
    ;
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
