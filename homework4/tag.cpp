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

const char * Tag :: getKey() const{
    return key;
}

const char * Tag :: getValue() const{
    return value;
}
