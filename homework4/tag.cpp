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
