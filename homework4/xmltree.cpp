#include "xmltree.h"

XMLtree :: XMLtree(){
    root = new Tag(Value((char *)"root"), Value((char *)""));
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

Tag * XMLtree::findTag(const Value & path) const{
    if(path == Value((char *)"")){
        return NULL;
    }

    Tag * tempNode;

    char * tempTagCharP = strtok(path.getValue(), "/");
    Value tempTagPath(tempTagCharP);

    if(root->getKey() != tempTagCharP){
        throw std :: runtime_error("wrong child key");
    }else{
        tempNode = root;
    }

    //slice path and search for child in current tag
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

Value XMLtree :: sliceTagPath(const Value & path) const{
    char * pathCP = path.getValue();

    //find tag key and parent tag path
    int size = 0;
    for(size = strlen(pathCP) - 1; size >= 0; --size){
        if(pathCP[size] == '/'){
            break;
        }
    }

    if(size <= 0){
        return Value((char *)"");
    }else{
       return Value(pathCP, size);
    }
}

Value XMLtree :: sliceTagKey(const Value & path) const{
    char * pathCP = path.getValue();

    //find tag key and parent tag path
    int size = 0;
    for(size = strlen(pathCP) - 1; size >= 0; --size){
        if(pathCP[size] == '/'){
            break;
        }
    }

    return Value(pathCP + size + 1);
}

void XMLtree :: addTag(const Value & path, const Value & k, const Value & v){
    Value tagKey = sliceTagKey(path);

    Tag * parentTag =  findTag(sliceTagPath(path));
    List<Tag *> & childs = parentTag->getChilds();

    Tag * newTag = new Tag(k, v);

    if(tagKey == Value((char *)"root")){
        root->addChild(newTag);
        return;
    }

    int size = (int)childs.getSize();

    int i = size - 1;
    for(; i >= 0; --i){
        if(childs.getAt(i)->getKey() == tagKey){
            break;
        }
    }

    childs[i]->addChild(newTag);
}

void XMLtree :: removeTag(const Value & path){
    Value currentTag = sliceTagKey(path);
    Value parentTag = sliceTagPath(path);

    Tag * parent = findTag(parentTag);
    parent->removeChild(currentTag);
}

void XMLtree :: changeTagKey(const Value & path, const Value & newKey){
    Value currentTag = sliceTagKey(path);
    Value parentTag = sliceTagPath(path);

    Tag * parent = findTag(parentTag);
    List<Tag *> childs = parent->getChilds();

    size_t size = childs.getSize();

    for(size_t i = 0; i < size; ++i){
        if(childs.getAt(i)->getKey() == currentTag){
            childs[i]->setKey(newKey);
        }
    }
}

void XMLtree :: changeTagValue(const Value & path, const Value & newValue){
    Value currentTag = sliceTagKey(path);
    Value parentTag = sliceTagPath(path);

    Tag * parent = findTag(parentTag);
    List<Tag *> childs = parent->getChilds();

    size_t size = childs.getSize();

    for(size_t i = 0; i < size; ++i){
        if(childs.getAt(i)->getKey() == currentTag){
            childs[i]->setValue(newValue);
        }
    }
}

void XMLtree :: addTagAttribute(const Value & path, const Value & attrKey, const Value & attrValue){
    Value currentTag = sliceTagKey(path);
    Value parentTag = sliceTagPath(path);
    Tag * parent = findTag(parentTag);

    List<Tag *> & childs = parent->getChilds();
    size_t size = childs.getSize();

    for(size_t i = 0; i < size; ++i){
        if(childs.getAt(i)->getKey() == currentTag){
            childs[i]->addAttribute(attrKey, attrValue);
        }
    }
}

void XMLtree :: removeTagAttribute(const Value & path, const Value & attrKey){
    Value currentTag = sliceTagKey(path);
    Value parentTag = sliceTagPath(path);
    Tag * parent = findTag(parentTag);

    List<Tag *> & childs = parent->getChilds();
    size_t size = childs.getSize();

    for(size_t i = 0; i < size; ++i){
        if(childs.getAt(i)->getKey() == currentTag){
            childs[i]->removeAttribute(attrKey);
        }
    }
}

void XMLtree :: changeTagAttribute(const Value & path, const Value & attrKey, const Value & newValue){
    Value currentTag = sliceTagKey(path);
    Value parentTag = sliceTagPath(path);
    Tag * parent = findTag(parentTag);

    List<Tag *> & childs = parent->getChilds();
    size_t size = childs.getSize();

    for(size_t i = 0; i < size; ++i){
        if(childs.getAt(i)->getKey() == currentTag){
            childs[i]->changeAttribute(attrKey, newValue);
        }
    }
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
    //Collect in queue all tags and their depth level
    //After that, start printing tags and if tag has no value
    //and childs push end tag in stack, otherwise print end tag
    //After this just print end tags with proper depth level

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

        if(!currentTag->hasChilds() && currentTag->getValue() == Value((char *) "")){
            out << '<' << currentTagKey;
            printAttributes(out, currentTag);
            out << "/>";
        }else{

            out << '<' << currentTagKey;
            printAttributes(out, currentTag);
            out << '>';

            if(currentTagValue != Value((char *) "")){
                out << currentTagValue << "</" << currentTagKey << '>';
            }else{
                endTags.push(currentTagKey);
                endTagsLevel.push(currentTagLevel);
            }
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

void XMLtree :: printUnreadable(std::ostream & out) const{
    Queue<Tag *> tagsSequence;
    Queue<int> tagsLevel;


    DFS(root, tagsSequence, tagsLevel, 0);

    Stack<Value> endTags;
    Stack<int> endTagsLevel;

    Tag * currentTag = NULL;
    Value currentTagKey;
    Value currentTagValue;

    while(tagsSequence.getSize()){
        currentTag = tagsSequence.dequeue();
        currentTagKey = currentTag->getKey();
        currentTagValue = currentTag->getValue();

        if(!currentTag->hasChilds() && currentTag->getValue() == Value((char *) "")){
            out << '<' << currentTagKey;
            printAttributes(out, currentTag);
            out << "/>";
        }else{

            out << '<' << currentTagKey;
            printAttributes(out, currentTag);
            out << '>';

            if(currentTagValue != Value((char *) "")){
                out << currentTagValue << "</" << currentTagKey << '>';
            }else{
                endTags.push(currentTagKey);
            }
        }

        if(!tagsLevel.isEmpty() && !endTagsLevel.isEmpty() && tagsLevel.peek() == endTagsLevel.peek()){
            out << "</" << endTags.pop() << '>';
        }
    }

    while(!endTags.isEmpty()){
        out << "</" << endTags.pop() << '>';
    }
}



///Iterator`s part

XMLtree :: Iterator XMLtree :: begin() const{
    return Iterator(root);
}

XMLtree :: Iterator XMLtree :: end() const{
    return Iterator();
}

XMLtree :: Iterator :: Iterator(){
    ;
}

XMLtree :: Iterator :: Iterator(Tag * current){
    tagsQueue.enqueue(current);
    tagsQueue.enqueue(current->getChilds());
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


XMLtree :: Iterator :: operator bool() const{
    return tagsQueue.getSize();
}

