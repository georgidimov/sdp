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
    char filePath[] = "../homework1/files/advancedConfig";
    Operators operationSet(filePath);

//    Parser<double> p(argv[1]);
    Parser<double> p(filePath);
    Stack<double> numbers;
    Stack<char> operations;

    char input[] = "-142 q -3186 t 4123 g ( 3119 ) a 2943 c ( 4653 i 1245 j -1766 ) a -803 k ( 2181 i -413 w ( 3873 x ( 1328 p 3511 a -4040 a ( 940 ) o 642 i 3302 r ( 1955 a 3809 a 4048 q 623 s 4775 ) d -2325 p ( -1618 ) d ( -1544 k ( -300 b -3845 u 3070 ) c -4950 ) a -3139 n 1244 o ( 3590 z 2975 k ( -4954 l 4977 q ( -4369 y 2659 h ( 3488 x 3029 x -2547 ) x ( -1630 z -2888 r -278 ) ) ) ) ) ) )";
    try{
        std :: cout << p.calculateExpression(input) << std :: endl;
    }catch(std :: exception & exc){
        std :: cout << "Error: " << exc.what() << std :: endl;
    }


    return 0;
}
