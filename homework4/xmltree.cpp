#include "xmltree.h"

XMLtree :: XMLtree(){
    //root = new Tag(NULL, Value((char *) "root"), Value((char *) ""));
}

XMLtree :: ~XMLtree(){
    clear();
}

void XMLtree :: clear(){
    //delete root;
}

void XMLtree :: addTag(Value parent, Value k, Value v){

}

///Iterator`s part
XMLtree :: Iterator :: Iterator(Tag * k){
    tagsQueue.enqueue(k);
    tagsQueue.enqueue(k->getChilds());
}

const XMLtree :: Iterator &  XMLtree :: begin(){
    return Iterator(root);
}

const XMLtree :: Iterator &  XMLtree :: end(){
    //write me
}

const XMLtree :: Iterator & XMLtree :: Iterator :: operator++(){
    //write me
}

const XMLtree :: Iterator & XMLtree :: Iterator :: operator--(){
    //write me
}

bool XMLtree :: Iterator :: operator ==(const XMLtree :: Iterator & rh) const{
    //return current == rh.current;
}

XMLtree :: Iterator :: operator bool() const{
    //return current == NULL;
}
