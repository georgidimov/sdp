#include <attribute.h>

Attribute :: Attribute(char * k, char * v){
    //copy key and value
    key = new char[strlen(k) + 1];
    strcpy(key, k);

    value = new char[strlen(v) + 1];
    strcpy(value, v);
}

Attribute :: ~Attribute(){
    delete [] key;
    key = NULL;

    delete [] value;
    value = NULL;
}

void Attribute :: getKey(char * & returnedKey) const{
    returnedKey = new char [strlen(key) + 1];
    strcpy(returnedKey, key);
}

void Attribute :: getValue(char * & returnedValued) const{
    returnedValued = new char [strlen(value) + 1];
    strcpy(returnedValued, value);
}
