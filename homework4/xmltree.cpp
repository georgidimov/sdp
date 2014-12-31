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

Tag * XMLtree :: findTag(const Value & path) const{
    Tag * tempNode;

    char * tempTagCharP = strtok(path.getValue(), "/");
    Value tempTagPath(tempTagCharP);

    if(root->getKey() != tempTagCharP){
        throw std :: runtime_error("wrong child key");
    }else{
        tempNode = root;
    }

    tempTagCharP = strtok(NULL, "/");

    while(tempTagCharP != NULL){
        tempTagPath = Value(tempTagCharP);

        tempNode = tempNode->findChild(tempTagPath);

        tempTagCharP = strtok(NULL, "/");
    }

    return tempNode;
}

void XMLtree :: addTag(const Value & path, const Value & k, const Value & v){
    /*
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
    }*/

    Tag * parent = findTag(path);

    Tag * newTag = new Tag(parent, k, v);

    parent->addChild(newTag);
}

XMLtree :: Iterator XMLtree :: begin() const{
    return Iterator(root);
}

XMLtree :: Iterator XMLtree :: end() const{
    return Iterator();
}

void XMLtree :: addTabs(std :: ostream & out, size_t level) const{
    level *= 4;

    for(size_t i = 0; i < level; ++i){
        out << ' ';
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

