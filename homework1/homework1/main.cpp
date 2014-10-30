#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stack.h>
#include <operators.h>
#include <parser.h>
/*
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

template <class T>
T getNumber(char * start){
    T result = 0;
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

template <class T>
size_t getDigitsCount(T number){
    size_t digitsCount = 0;
    if (number < 0){
        ++digitsCount;
        number *= -1;
    }

    digitsCount += ceil( log10(number) );



    return digitsCount;
}

*/

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

 /*   size_t length = strlen(input);

    double temp;

    for(size_t i = 0; i < length; ++i){
        if( ( input[i] == '-' && isDigit(input[i + 1]) ) || isDigit(input[i]) ){  //check if symbol is number
            temp = getNumber<double>(&input[i]);
            i += getDigitsCount(temp);

            numbers.push(temp);
        }else if( operationSet.isOperator(input[i]) || input[i] == '(' || input[i] == ')' ){ //check if symbol is operator
            /// )
            if( operations.isEmpty() ){  //if stack with operation is empty push any operation
                if(input[i] == ')'){     //except ")"
                    ///exception
                }

                operations.push(input[i]);
            }else{
                if( input[i] == '(' ){
                    operations.push( input[i] );
                }else if( input[i] == ')' ){
                    //if operation is closing bracket calculate everything
                    //until opening bracket
                    char tempOperator = operations.pop();

                    double left, right;


                    ///exception if numbers is empty
                    while( tempOperator != '(' ){
                        right = numbers.pop();
                        left = numbers.pop();
                        numbers.push( calculateOperator<double>(tempOperator, left, right) );
                        tempOperator = operations.pop();
                    }


                    ///exception if ( not exist
                }else{
                    OperatorConf currentOp = operationSet.getOperator(input[i]);
                    OperatorConf topOp = operationSet.getOperator( operations.pop() );

                    if( topOp.symbol == '(' ){  //if symbol is opening bracket, skip priority
                        operations.push( topOp.symbol );  //and associativity check
                        operations.push( currentOp.symbol );
                    }else if( currentOp.priority < topOp.priority ){
                        //if current operator is with lower priority than
                        //operator on the top => calculate all operators
                        //with higher priority
                        while(  currentOp.priority < topOp.priority ){
                            double right = numbers.pop();
                            double left = numbers.pop();

                            numbers.push( calculateOperator<double>(topOp.type, left, right) );
                            if ( operations.isEmpty() ){
                                break;
                            }

                            topOp = operationSet.getOperator( operations.pop() );

                            if( topOp.type == '(' ){
                                break;
                            }
                        }
                        ///
                        if( !operations.isEmpty() ){
                            operations.push( topOp.symbol );
                        }

                        operations.push( currentOp.symbol );

                    }else if( currentOp.priority == topOp.priority ){
                        //if priority of the current and top operator is equal
                        //then check for associativity => if is different
                        //something is not ok, else continue with expression
                        if( currentOp.associativity != topOp.associativity ){
                            ///exception
                        }else{
                            if( currentOp.associativity == 1 ){    //rigth associativity
                                operations.push(topOp.symbol);
                                operations.push(currentOp.symbol);
                            }else{
                                ///type
                                double right = numbers.pop();
                                double left = numbers.pop();

                                numbers.push( calculateOperator<double>(topOp.type, left, right) );

                                operations.push( currentOp.symbol );
                            }
                        }
                    }else{
                        operations.push(topOp.symbol);
                        operations.push(currentOp.symbol);
                    }
                }
            }
        }else if( input[i] != ' ' ){  //check for incorrect symbols
            ///exception
        }
    }

    //when parsing expression finish => calculate operators in the stacks
    double left, right;
    OperatorConf currentOperator;
    while( !operations.isEmpty() ){
        right = numbers.pop();
        left = numbers.pop();
         currentOperator = operationSet.getOperator( operations.pop() );

        numbers.push(calculateOperator<double>(currentOperator.type, left, right) );
    }

    ///result
    std::cout << numbers.pop() << std :: endl;
*/
    return 0;
}
