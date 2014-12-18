#include <attribute.h>

Attribute :: Attribute(Value k, Value v){
    key = k;
    value = v;
}

Attribute :: ~Attribute(){
    ;
}

Value Attribute :: getKey() const{
    return key;
}

Value Attribute :: getValue() const{
    return value;
}
