#include "tag.h"

Tag :: Tag(char * k, char * v){
    //copy key and value
    key = new char[strlen(k) + 1];
    strcpy(key, k);

    value = new char[strlen(v) + 1];
    strcpy(value, v);
}

Tag :: ~Tag(){
    delete [] key;
    key = NULL;

    delete [] value;
    value = NULL;
}

void Tag :: getKey(char * & returnedKey) const{
    returnedKey = new char [strlen(key) + 1];
    strcpy(returnedKey, key);
}

void Tag :: getValue(char * & returnedValued) const{
    returnedValued = new char [strlen(value) + 1];
    strcpy(returnedValued, value);
}
