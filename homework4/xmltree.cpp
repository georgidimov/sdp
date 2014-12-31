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

void XMLtree :: printAttributes(std::ostream & out, Tag * currentTag) const{
    List<Attribute> attrs = currentTag->getAttributes();
    size_t attrsCount = attrs.getSize();

    for(size_t i = 0; i < attrsCount; ++i){
        out << ' ' << attrs.getAt(i).getKey() << '=' << '"' << attrs.getAt(i).getValue() << '"';
    }
}

void XMLtree :: addTag(const Value & path, const Value & k, const Value & v){
    Tag * parent = findTag(path);

    Tag * newTag = new Tag(parent, k, v);

    parent->addChild(newTag);
}

void XMLtree :: removeTag(const Value & path){
    char * pathCP = path.getValue();

    //find tag key and parent tag path
    int size = 0;
    for(size = strlen(pathCP) - 1; size >= 0; --size){
        if(pathCP[size] == '/'){
            break;
        }
    }

    Value currentTag(pathCP + size + 1);
    pathCP[size] = '\0';
    Value parentTagpath(pathCP);

    Tag * parent = findTag(parentTagpath);
    parent->removeChild(currentTag);
}

void XMLtree :: changeTagKey(const Value & path, const Value & newKey){
    Tag * currentTag = findTag(path);
    currentTag->setKey(newKey);
}

void XMLtree :: changeTagValue(const Value & path, const Value & newValue){
    Tag * currentTag = findTag(path);
    currentTag->setValue(newValue);
}

void XMLtree :: addTagAttribute(const Value & path, const Value & attrKey, const Value & attrValue){
    Tag * currentTag = findTag(path);

    currentTag->addAttribute(attrKey, attrValue);
}

void XMLtree :: removeTagAttribute(const Value & path, const Value & attrKey){
    Tag * currentTag = findTag(path);

    currentTag->removeAttribute(attrKey);
}

void XMLtree :: changeTagAttribute(const Value & path, const Value & attrKey, const Value & newValue){
    Tag * currentTag = findTag(path);

    currentTag->changeAttribute(attrKey, newValue);
}



//iterator`s part
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

        out << '<' << currentTagKey;
        printAttributes(out, currentTag);
        out << '>';

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
    }

    while(!endTags.isEmpty()){
        addTabs(out, endTagsLevel.pop());
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

