#include <QCoreApplication>
#include <iostream>
#include <queue.h>

int main(){
    Queue<int> q;
    for(size_t i = 0; i < 10; ++i){
        q.enqueue(i + 1);
    }

    std :: cout << *q.end()<< "  " << std :: endl << std :: endl << std :: endl;
    for(Queue<int> :: Iterator i = q.begin(); i; ++i){
        std :: cout << *i << ' ';
    }

    std :: cout << q.getSize() << std :: endl << std :: endl;

    //std :: cout << std :: endl << q.begin() << "  " << q.end() << std :: endl
    //              << q.begin() == q.end();
}
