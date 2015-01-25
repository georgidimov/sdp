#include <QCoreApplication>
#include <iostream>
#include <streetgraph.h>

int main()
{
    std :: ifstream in("../homework5/input");
    StreetGraph s(in);
    s.simulate();
    s.print();

    s.simulate();
    s.print();
    in.close();
    return 0;
}
