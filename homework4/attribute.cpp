#include <attribute.h>

Attribute :: Attribute(){
    ;
}

Attribute :: Attribute(Value k, Value v){
    key = k;
    value = v;
}

Attribute :: ~Attribute(){
    ;
}

void Attribute :: setValue(Value v){
    value = v;
}

Value Attribute :: getKey() const{
    return key;
}

Value Attribute :: getValue() const{
    return value;
}
