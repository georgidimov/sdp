#include "xmltree.h"

XMLtree :: XMLtree(){
    root = NULL;
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

void XMLtree :: addTag(const Value & parentKey, const Value & k, const Value & v){
    if(root == NULL){
        root = new Tag(NULL, k, v);
        return;
    }

    for(Iterator i = begin(); i; ++i){
        if((*i)->getKey() == parentKey){
            Tag * newTag = new Tag(*i, k, v);
            (*i)->addChild(newTag);

            return;
        }
    }
}

XMLtree :: Iterator XMLtree :: begin(){
    return Iterator(root);
}

XMLtree :: Iterator XMLtree :: end(){
    return Iterator();
}




///Iterator`s part
XMLtree :: Iterator :: Iterator(){
    ;
}

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

XMLtree :: Iterator & XMLtree :: Iterator :: operator ++(){
    (*this)++;
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

