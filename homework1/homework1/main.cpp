#include <QCoreApplication>
#include <iostream>
#include <stack.h>

int main()
{
    Stack<int> s;
    s.push(5);

    for(size_t i = 0; i < 10; ++i){
        s.push(i);
    }

    for(size_t i = 0; !s.isEmpty() ; ++i){
       s.pop();
    }
    return 0;
}
//    QCoreApplication a(argc, argv);

//    return a.exec();
