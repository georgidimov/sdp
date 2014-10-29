#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stack.h>
#include <operators.h>

bool isDigit(char symbol){
    return symbol >= '0' && symbol <= '9';
}

int getNumber(char * start){
    int result = 0;
    int i = 0;
    bool isNegative = false;

    if(start[i] == '-'){
        isNegative = true;
        ++i;
    }

    while( start[i] != ' ' && start[i] != '\0' ){//&& start[i] != NULL ){
        if( isDigit(start[i]) ){
            result *= 10;
            result += start[i] - '0';
        }
        ++i;
    }

    if( isNegative ){
        result *= -1;
    }

    return result;
}

size_t getDigitsCount(int number){
    size_t digitsCount = 0;
    if (number < 0){
        ++digitsCount;
        number *= -1;
    }

    digitsCount += ceil( log10(number) );



    return digitsCount;
}



int main()
{

    char filePath[] = "../homework1/files/operators";
    operators op(filePath);
    /*
    std :: ifstream operatorsFile("../homework1/files/operators", std :: ios :: in);
    std :: string buffer;
    size_t linesCount = 0;

    while (operatorsFile.good()) {
        std :: getline(operatorsFile, buffer);
        ++linesCount;
    }

    operatorsFile.clear();
    operatorsFile.seekg(operatorsFile.beg);
    linesCount--;

    operators op[linesCount];

    for(size_t i = 0; i < linesCount; i++){
        operatorsFile >> op[i].symbol;
        operatorsFile >> op[i].type;
        operatorsFile >> op[i].priority;
        operatorsFile >> op[i].associativity;

        std :: cout << op[i].symbol << ' '
                    << op[i].type << ' '
                    << op[i].priority << ' '
                    << op[i].associativity << ' '  << std :: endl;*/
/*    }

    operatorsFile.close();
    */
    Stack<int> numbers;
    Stack<char> operations;
    char input[] = "31 a ( 5 b 32 f 10 e -230 ) c 324 d 17";
    size_t length = strlen(input);

    int temp;

    for(size_t i = 0; i < length; ++i){
        if( input[i] == '-' && isDigit(input[i + 1]) ){
            temp = getNumber(&input[i]);
            numbers.push(temp);

            i += getDigitsCount(temp);
        }else if( isDigit(input[i]) ){
            temp = getNumber(&input[i]);
            numbers.push(temp);
            i += getDigitsCount(temp);
        }else if( op.isOperator(input[i]) || input[i] == '(' || input[i] == ')' ){
            operations.push(input[i]);
        }else if( input[i] != ' ' ){
            ///exception
        }
    }

    while (!numbers.isEmpty()) {
        std :: cout << numbers.pop() << std :: endl;
    }

    std :: cout << "operations now" << std :: endl;

    while( !operations.isEmpty() ){
        std :: cout << operations.pop() << std :: endl;
    }
    return 0;
}
//    QCoreApplication a(argc, argv);

//    return a.exec();
