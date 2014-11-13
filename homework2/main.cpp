#include <QCoreApplication>
#include <iostream>
#include <queue.h>

int main(){
    Queue<int> q;
    q.enqueue(4);
    q.enqueue(5);

    while( q.getSize() ){
        std :: cout << q.dequeue() << std :: endl;
    }

    return 0;
}
