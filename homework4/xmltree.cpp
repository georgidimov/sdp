#include "xmltree.h"

XMLtree :: XMLtree(){
    //root = new Tag(NULL, Value((char *) "root"), Value((char *) ""));
}

XMLtree :: XMLtree(Tag * r){
    root = r;
}


XMLtree :: ~XMLtree(){
    clear();
}

void XMLtree :: clear(){
    delete root;
}

void XMLtree :: addTag(Value parent, Value k, Value v){

}

XMLtree :: Iterator XMLtree :: begin(){
    return Iterator(root);
}

XMLtree :: Iterator XMLtree :: end(){
    //write me
}

///Iterator`s part
XMLtree :: Iterator :: Iterator(Tag * current){
    tagsQueue.enqueue(current);
    tagsQueue.enqueue(current->getChilds());

    /*
    List<Tag *> l = current->getChilds();

    while(l.getSize()){
        std :: cout << l.getAt(0)->getKey() << ' ' << l.getAt(0)->getValue() << std :: endl;
        l.removeAt(0);
    }
    */
}

XMLtree :: Iterator & XMLtree :: Iterator :: operator ++(int uselessVar){
    tagsQueue.dequeue();

    if(tagsQueue.getSize()){
        tagsQueue.enqueue(tagsQueue.peek()->getChilds());
    }
    //tagsQueue.peek()->printChilds();
}

Tag * XMLtree :: Iterator :: operator *(){
    return tagsQueue.peek();
}


bool XMLtree :: Iterator :: operator ==(const Iterator & r) const{
   //write me
}

XMLtree :: Iterator :: operator bool() const{
    return tagsQueue.getSize();
}

