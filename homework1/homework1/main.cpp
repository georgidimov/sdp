#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stack.h>
#include <operators.h>

template <typename T>
T calculateOperator(char op, T leftArg, T rightArg){
    T result;
    switch (op){
    case '+':
        result = leftArg + rightArg;
        break;
    case '-':
        result = leftArg - rightArg;
        break;
    case '*':
        result = leftArg * rightArg;
        break;
    case '/':
        result = leftArg / rightArg;
    default:
        ///exception
        break;
    }

    return result;
}

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



int main(){

    char filePath[] = "../homework1/files/ops";
    operators op(filePath);
    Stack<int> numbers;
    Stack<char> operations;
    //char input[] = "31 a ( 5 b 32 f 10 e -230 ) c 324 d 17";
    char input[] = "5 a 2 b 3 c 7";

    size_t length = strlen(input);

    int temp;

    for(size_t i = 0; i < length; ++i){
        if( ( input[i] == '-' && isDigit(input[i + 1]) ) || isDigit(input[i]) ){
            temp = getNumber(&input[i]);
            numbers.push(temp);
        }else if( op.isOperator(input[i]) || input[i] == '(' || input[i] == ')' ){
            /// )
            if( operations.isEmpty() ){
                operations.push(input[i]);
            }else{
                operatorConf currentOp = op.getOperator(input[i]);
                operatorConf topOp = op.getOperator( operations.pop() );

                if( currentOp.priority < topOp.priority ){
                    ///operations.push(topOp.symbol);
                    ///operations.push(currentOp.symbol);

                    while(currentOp.priority < topOp.priority ){
                        int right = numbers.pop();
                        int left = numbers.pop();

                        numbers.push( calculateOperator<int>(topOp.type, left, right) );
                        if ( operations.isEmpty() ){
                            break;
                        }

                        topOp = op.getOperator( operations.pop() );
                    }

                    operations.push( currentOp.symbol );
                }else if( currentOp.priority == topOp.priority ){
                    if( currentOp.associativity != topOp.associativity ){
                        ///exception
                    }else{
                        if(currentOp.associativity == 1){    //rigth associativity
                            operations.push(topOp.symbol);
                            operations.push(currentOp.symbol);
                        }else{
                            ///type
                            int right = numbers.pop();
                            int left = numbers.pop();
                            numbers.push( calculateOperator<int>(topOp.type, left, right) );
                            operations.push( currentOp.symbol );
                            //.pop.pop OP pop
                        }
                    }
                }else{
                    operations.push(topOp.symbol);
                    operations.push(currentOp.symbol);
                }
            }
        }else if( input[i] != ' ' ){
            ///exception
        }
    }

    while( !operations.isEmpty() ){
        int right = numbers.pop();
        int left = numbers.pop();
        operatorConf opr = op.getOperator( operations.pop() );
        numbers.push( calculateOperator<int>(opr.type, left, right) );
    }

    std :: cout << "result " << numbers.pop();


  /* while (!numbers.isEmpty()) {
        std :: cout << "! "<< numbers.pop() << std :: endl;
    }

    std :: cout << "operations now" << std :: endl;

    while( !operations.isEmpty() ){
        std :: cout << operations.pop() << std :: endl;
    }
*/
///



    return 0;
}
//    QCoreApplication a(argc, argv);

//    return a.exec();
