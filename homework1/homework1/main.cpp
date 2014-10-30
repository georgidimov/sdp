#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stack.h>
#include <operators.h>
#include <parser.h>


//int main(int argc, char ** argv){
int main(){
    char filePath[] = "../homework1/files/simpleTest";
    Operators operationSet(filePath);

//    Parser<double> p(argv[1]);
    Parser<double> p(filePath);
    Stack<double> numbers;
    Stack<char> operations;

    char input[] = "3 + 5 * ( 6 - 9 ) - 8 * 2" ;
    try{
        std :: cout << p.calculateExpression(input) << std :: endl;
    }catch(std :: exception & exc){
        std :: cout << "Error: " << exc.what() << std :: endl;
    }


    return 0;
}
