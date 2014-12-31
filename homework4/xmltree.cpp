#include "xmltree.h"

XMLtree :: XMLtree(){
    root = new Tag(NULL, Value((char *)"root"), Value((char *)""));
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

void XMLtree :: DFS(Tag * startTag, Queue<Tag *> & q, Queue<int> & tagsLevel, int level) const{
    q.enqueue(startTag);
    tagsLevel.enqueue(level);

    if(!startTag->hasChilds()){
        return;
    }

    const List<Tag *> & tagChilds = startTag->getChilds();
    size_t childsCount = tagChilds.getSize();

    for(size_t i = 0; i < childsCount; ++i){
        DFS(tagChilds.getAt(i), q, tagsLevel, level + 1);
    }

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

void XMLtree :: addTabs(std :: ostream & out, int level) const{
    if(level < 0){
        return;
    }

    level *= 4;

    for(int i = 0; i < level; ++i){
        out << ' ';
    }
}

void XMLtree :: printReadable(std :: ostream & out) const{
    Queue<Tag *> tagsSequence;
    Queue<int> tagsLevel;


    DFS(root, tagsSequence, tagsLevel, 0);

    Stack<Value> endTags;
    Stack<int> endTagsLevel;

    int level = 0;

    Tag * tempParentTag = root->getParent();
    Tag * currentTag = NULL;
    Value currentTagKey;
    Value currentTagValue;
    int currentTagLevel;

    while(tagsSequence.getSize()){
        currentTag = tagsSequence.dequeue();
        currentTagKey = currentTag->getKey();
        currentTagValue = currentTag->getValue();
        currentTagLevel = tagsLevel.dequeue();

        addTabs(out, currentTagLevel);

        out << '<' << currentTagKey << '>';

        if(currentTagValue != Value((char *) "")){
            out << currentTagValue << "</" << currentTagKey << '>';
        }else{
            endTags.push(currentTagKey);
            endTagsLevel.push(currentTagLevel);
        }

        out << std :: endl;

        if(!tagsLevel.isEmpty() && !endTagsLevel.isEmpty() && tagsLevel.peek() == endTagsLevel.peek()){
            addTabs(out, endTagsLevel.pop());
            out << "</" << endTags.pop() << '>' << std :: endl;
        }

        if(currentTag->getParent() == tempParentTag){
            ++level;
        }

        tempParentTag = currentTag->getParent();
    }

    while(!endTags.isEmpty()){
        addTabs(out, endTagsLevel.pop());
        out << "</" << endTags.pop() << '>' << std :: endl;
    }

/*
    Stack<Value> endTags;

    int level = 0;

    Tag * tempParentNode = root->getParent();

    for(Iterator i = begin(); i; ++i){
        addTabs(out, level);
        out << '<' << (*i)->getKey() << '>';// << std :: endl;

        if((*i)->getValue() == Value((char *)"")){
            out << std :: endl;
            endTags.push((*i)->getKey());

            if(tempParentNode != (*i)->getParent()){
                ++level;
            }
        }else{
            out<<(*i)->getValue() << "</" << (*i)->getValue() << '>' << std :: endl;
        }

        tempParentNode = (*i)->getParent();
    }

    while(!endTags.isEmpty()){
        --level;

        addTabs(out, level);
        out << "</" << endTags.pop() << '>' << std :: endl;
    }
*/
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

