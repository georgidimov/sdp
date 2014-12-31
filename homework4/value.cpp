#include "value.h"

Value :: Value(){
    value = NULL;
}

Value :: Value(char * passedValue){
    value = new char[strlen(passedValue) + 1];
    strcpy(value, passedValue);
}

Value :: Value(const Value &o){
    //check for self-assignment
    if(&o == this){
        throw "invalid assignment";
    }

    value = new char[strlen(o.value) + 1];
    strcpy(value, o.value);
}

Value & Value :: operator =(const Value & o){

    //remove content and copy the new one
    clear();

    value = new char[strlen(o.value) + 1];
    strcpy(value, o.value);

    return *this;
}

Value :: ~Value(){
    clear();
}

void Value :: clear(){
    delete [] value;
    value = NULL;
}

bool Value :: operator ==(const Value & v) const{
    return !strcmp(value, v.value);
}

bool Value :: operator !=(const Value & v) const{
    return !(*this == v);
}

std :: ostream & operator <<(std :: ostream & out, const Value & v){
    out << v.value;

    return out;
}

char * Value :: getValue() const{
    return value;
}
