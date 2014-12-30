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

XMLtree :: Iterator XMLtree :: begin() const{
    return Iterator(root);
}

XMLtree :: Iterator XMLtree :: end() const{
    return Iterator();
}

void XMLtree :: addTabs(std :: ostream & out, size_t level) const{
    while(level--){
        for(size_t i = 0; i < 4; ++i){
            out << ' ';
        }
    }
}

void XMLtree :: printReadable(std :: ostream & out) const{
    Stack<Value> endTags;

    size_t level = 0;
    for(Iterator i = begin(); i; ++i, ++level){
        addTabs(out, level);
        out << '<' << (*i)->getKey() << '>' << std :: endl;
        addTabs(out, level + 1);
        out<<(*i)->getValue() << std :: endl;

        endTags.push((*i)->getKey());
    }

    while(!endTags.isEmpty()){
        --level;

        addTabs(out, level);
        out << "</" << endTags.pop() << '>' << std :: endl;
    }
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
    ++uselessVar;   //just for stop warning

    tagsQueue.dequeue();

    if(tagsQueue.getSize()){
        tagsQueue.enqueue(tagsQueue.peek()->getChilds());
    }


    return * this;
}

XMLtree :: Iterator & XMLtree :: Iterator :: operator ++(){
    (*this)++;

    return * this;
}

Tag * XMLtree :: Iterator :: operator *(){
    return tagsQueue.peek();
}


bool XMLtree :: Iterator :: operator ==(const Iterator & r) const{

}

XMLtree :: Iterator :: operator bool() const{
    return tagsQueue.getSize();
}

