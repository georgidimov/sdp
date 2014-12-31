#include <iostream>
//#include <QCoreApplication>
#include <attribute.h>
#include <tag.h>
#include <value.h>
#include <list.hpp>
#include <queue.hpp>
#include <xmltree.h>
#include <stack.hpp>

int main()
{
/*
    XMLtree t;
    t.addTag(Value((char *) "root"), Value((char *) "person"), Value((char *) ""));
    t.addTag(Value((char *) "root/person"), Value((char *) "s1"), Value((char *) "shits"));
    t.addTag(Value((char *) "root/person"), Value((char *) "s2"), Value((char *) "shits2"));
    t.addTag(Value((char *) "root/person"), Value((char *) "s3"), Value((char *) "shits3"));

    t.addTag(Value((char *) "root"), Value((char *) "person2"), Value((char *) ""));
    t.addTag(Value((char *) "root/person/s2"), Value((char *) "f"), Value((char *) "f"));

    t.addTag(Value((char *) "root/person/s2/f"), Value((char *) "f`"), Value((char *) "f`"));
    t.addTag(Value((char *) "root/person2"), Value((char *) "bitch"), Value((char *) "bitch"));
    t.addTag(Value((char *) "root"), Value((char *) "peson3"), Value((char *) "peson3"));

    t.addTagAttribute(Value((char *) "root/person/s2/f"), Value((char *) "attr1"), Value((char *) "1"));
    t.addTagAttribute(Value((char *) "root/person/s2/f"), Value((char *) "img"), Value((char *) "some/url"));
    t.addTagAttribute(Value((char *) "root/person/s2/f"), Value((char *) "alt"), Value((char *) "dai muu"));
    t.addTagAttribute(Value((char *) "root/person"), Value((char *) "alt"), Value((char *) "dai muu"));
    t.printReadable(std :: cout);

    t.changeTagAttribute(Value((char *) "root/person"), Value((char *) "alt"), Value((char *) "dai muu2"));
    t.removeTag(Value((char *) "root/person"));
    std :: cout << std :: endl;
    t.printReadable(std :: cout);
    std :: cout << std :: endl;
    t.printUnreadable(std :: cout);
*/




    XMLtree t;
    t.addTag(Value((char *) "root"), Value((char *) "person"), Value((char *) ""));

    t.addTag(Value((char *) "root/person"), Value((char *) "name"), Value((char *) "One"));
    t.addTag(Value((char *) "root/person"), Value((char *) "name"), Value((char *) "Something"));
    t.addTag(Value((char *) "root/person"), Value((char *) "email"), Value((char *) ""));

    t.addTag(Value((char *) "root"), Value((char *) "person"), Value((char *) ""));
    t.addTag(Value((char *) "root/person"), Value((char *) "name"), Value((char *) "Two"));;
    t.addTag(Value((char *) "root/person"), Value((char *) "email"), Value((char *) "example@example.com"));

    t.addTagAttribute(Value((char *) "root/person"), Value((char *) "attr1"), Value((char *) "dai muu2"));
    t.changeTagAttribute(Value((char *) "root/person"), Value((char *) "attr1"), Value((char *) "Svetlio"));
    t.printReadable(std :: cout );
    std :: cout << std :: endl << std :: endl;
    t.printUnreadable(std :: cout);

    return 0;
}
