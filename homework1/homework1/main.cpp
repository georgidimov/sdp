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
    //char input[] = "31 a ( 5 b 32 f 10 e -230 ) c 324 d 17";
    //char input[] = "5 a 2 b 3 c 7";
    //char input[] = "2 * ( 12 - 3 ) + 1 * ( 3 * ( 5 - 2 * ( 1 - 1 ) ) )";
    char input[] = "( ( 3 + 7 ) * 8 ) + 20 ) (";
    try{
        std :: cout << p.calculateExpression(input) << std :: endl;
    }catch(std :: exception & exc){
        std :: cout << "Error: " << exc.what() << std :: endl;
    }


    return 0;
}
