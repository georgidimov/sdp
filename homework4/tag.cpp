#include "tag.h"

Tag :: Tag(Tag * passedParent, char * passedValue){
    parent = passedParent;

    value = new char [strlen(passedValue) + 1];
    strcpy(value, passedValue);
}

Tag :: ~Tag(){
    clear();
}

void Tag :: clear(){
    delete [] value;
    value = NULL;
}

Tag * Tag :: getParent() const{
    return parent;
}

void Tag :: getValue(char * returnedValue) const{
    returnedValue = new char [strlen(value) + 1];
    strcpy(returnedValue, value);
}
