#pragma once
#include <iostream>
#include <string.h>
#include <operators.h>
#include <stack.h>

template <class T>
class Parser{
    const Operators & operationsSet;
    Stack<T> numbers;
    Stack<char> operations;

    T calculateOperator(char op, T leftArg, T rightArg) const;
    bool isDigit(char symbol) const;
    T getNumber(const char * start) const;
    size_t getDigitsCount(T number) const;

    void changeBrackets(char * & expression);
    bool correctBrackets(const char * expression) const;
public:
    Parser(const Operators & operationSetNew);
    ~Parser();

    T calculateExpression(const char * expression);
};

template<class T>
Parser<T> :: Parser(const Operators & operationSetNew) : operationsSet(operationSetNew){
    ;
}

template <class T>
Parser<T> :: ~Parser(){
    ;
}

template <class T>
T Parser<T> :: calculateOperator(char op, T leftArg, T rightArg) const{
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

template <class T>
bool Parser<T> :: isDigit(char symbol) const{
    return symbol >= '0' && symbol <= '9';
}

template <class T>
T Parser<T> :: getNumber(const char * start) const {
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
size_t Parser<T> :: getDigitsCount(T number) const{
    size_t digitsCount = 0;
    if (number < 0){
        ++digitsCount;
        number *= -1;
    }

    digitsCount += ceil( log10(number) );



    return digitsCount;
}

template <class T>
T Parser<T> :: calculateExpression(const char * PassedExpression){
    size_t length = strlen(PassedExpression);

    char * expression = new char[length + 1];
    strcpy(expression, PassedExpression);

    expression[length] = '\0';

    changeBrackets(expression);  //change different brackets to ( )

    if ( !correctBrackets(expression) ){
        delete [] expression;
        throw std :: runtime_error("incorrect brackets");
    }



    T temp;

    for(size_t i = 0; i < length; ++i){
        if( ( expression[i] == '-' && isDigit(expression[i + 1]) ) || isDigit(expression[i]) ){  //check if symbol is number
            temp = getNumber(&expression[i]);
            i += getDigitsCount(temp);

            numbers.push(temp);
        }else if( operationsSet.isOperator(expression[i]) || expression[i] == '(' || expression[i] == ')' ){ //check if symbol is operator
            if( operations.isEmpty() ){  //if stack with operation is empty push any operation
                if(expression[i] == ')'){     //except ")"
                    delete [] expression;
                    throw std :: runtime_error("start with closing bracket");
                }

                operations.push(expression[i]);
            }else{
                if( expression[i] == '(' ){
                    operations.push( expression[i] );
                }else if( expression[i] == ')' ){
                    //if operation is closing bracket calculate everything
                    //until opening bracket
                    char tempOperator = operations.pop();

                    T left, right;

                    while( tempOperator != '(' ){
                        try{
                            right = numbers.pop();
                            left = numbers.pop();
                        }catch( std :: runtime_error & exc ){
                            delete [] expression;
                            throw std :: runtime_error("no numbers in stack");
                        }

                        numbers.push( calculateOperator(tempOperator, left, right) );
                        try{
                            tempOperator = operations.pop();
                        }catch( std :: runtime_error & exc){
                            delete [] expression;
                            throw std :: runtime_error("incorrect brackets");
                        }

                        if(tempOperator == '(' ){
                            break;
                        }
                    }
                }else{
                    OperatorConf currentOp = operationsSet.getOperator(expression[i]);
                    OperatorConf topOp = operationsSet.getOperator( operations.pop() );

                    if( topOp.symbol == '(' ){  //if symbol is opening bracket, skip priority
                        operations.push( topOp.symbol );  //and associativity check
                        operations.push( currentOp.symbol );
                    }else if( currentOp.priority < topOp.priority ){
                        //if current operator is with lower priority than
                        //operator on the top => calculate all operators
                        //with higher priority
                        while(  currentOp.priority < topOp.priority ){
                            T right = numbers.pop();
                            T left = numbers.pop();

                            numbers.push( calculateOperator(topOp.type, left, right) );
                            if ( operations.isEmpty() ){
                                break;
                            }

                            topOp = operationsSet.getOperator( operations.pop() );

                            if( topOp.type == '(' ){
                                break;
                            }
                        }

                        if( !operations.isEmpty() ){
                            operations.push( topOp.symbol );
                        }

                        operations.push( currentOp.symbol );

                    }else if( currentOp.priority == topOp.priority ){
                        //if priority of the current and top operator is equal
                        //then check for associativity => if is different
                        //something is not ok, else continue with expression
                        if( currentOp.associativity != topOp.associativity ){
                            delete [] expression;
                            throw std :: runtime_error("wrong operators associativity");
                        }else{
                            if( currentOp.associativity == 1 ){    //rigth associativity
                                operations.push(topOp.symbol);
                                operations.push(currentOp.symbol);
                            }else{
                                T right = numbers.pop();
                                T left = numbers.pop();

                                numbers.push( calculateOperator(topOp.type, left, right) );

                                operations.push( currentOp.symbol );
                            }
                        }
                    }else{
                        operations.push(topOp.symbol);
                        operations.push(currentOp.symbol);
                    }
                }
            }
        }else if( expression[i] != ' ' ){  //check for incorrect symbols
            delete [] expression;
            throw std :: runtime_error("incorrect symbol in expression");
        }
    }

    //when parsing expression finish => calculate operators in the stacks
    T left, right;
    OperatorConf currentOperator;
    while( !operations.isEmpty() ){
        right = numbers.pop();
        left = numbers.pop();
         currentOperator = operationsSet.getOperator( operations.pop() );

        numbers.push(calculateOperator(currentOperator.type, left, right) );
    }

    T result = numbers.pop();

    if( !operations.isEmpty()){
        delete [] expression;
        throw std :: runtime_error("incorrect expression - more operations then numbers");
    }

    delete [] expression;
    return result;
}

template <class T>
bool Parser<T> :: correctBrackets(const char * expression) const{
    size_t length = strlen(expression);

    Stack<char> brackets;

    for(size_t i = 0; i < length; ++i){
        if(expression[i] == '('){
            brackets.push(expression[i]);
        }

        if(expression[i] == ')'){
            brackets.pop();
        }
    }

    return brackets.isEmpty() == true;
}

template <class T>
void Parser<T> :: changeBrackets(char * & expression){
    size_t length = strlen(expression);

    for(size_t i = 0; i < length; ++i){
        if(expression[i] == '{' || expression[i] == '['){
            expression[i] = '(';
        }

        if(expression[i] == '}' || expression[i] == ']'){
            expression[i] = ')';
        }
    }
}
