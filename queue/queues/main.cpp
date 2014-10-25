#include <iostream>
#include <cstddef>
#include <queue.h>

int main()
{
    Queue<int> q;
    q.push(5);
    q.push(12);
    q.push(13);
    std :: cout << q.pop();
    return 0;
}
