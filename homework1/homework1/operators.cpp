#include "operators.h"

Operators :: Operators(const char *filePath)
{
    operatorsCount = 0;

    std :: ifstream operatorsFile(filePath, std :: ios :: in);
    std :: string buffer;

    //define operators count
    while( operatorsFile.good() ) {
        std :: getline(operatorsFile, buffer);
        ++operatorsCount;
    }

    operatorsFile.clear();
    operatorsFile.seekg(operatorsFile.beg);
    operatorsCount++;

    operatorsSet = new OperatorConf [operatorsCount];

    size_t maxPriority = 0;
    //read operators and define max priority
    for(size_t i = 0; i < operatorsCount - 2; i++){
        operatorsFile >> operatorsSet[i].symbol;
        operatorsFile >> operatorsSet[i].type;
        operatorsFile >> operatorsSet[i].priority;
        operatorsFile >> operatorsSet[i].associativity;

        maxPriority = std :: max( maxPriority, operatorsSet[i].priority );
    }


    //add brackets as operators with highest priority
    ++maxPriority;

    operatorsSet[ operatorsCount - 2 ].symbol = '(';
    operatorsSet[ operatorsCount - 2 ].type = '(';
    operatorsSet[ operatorsCount - 2 ].priority = maxPriority;
    operatorsSet[ operatorsCount - 2 ].associativity = 1;

    operatorsSet[ operatorsCount - 1 ].symbol = ')';
    operatorsSet[ operatorsCount - 1 ].type = ')';
    operatorsSet[ operatorsCount - 1 ].priority = maxPriority;
    operatorsSet[ operatorsCount - 1 ].associativity = 1;
    operatorsFile.close();

/*
    for(size_t i = 0; i < operatorsCount; ++i){
        std :: cout << operatorsSet[i].symbol << ' '
                    << operatorsSet[i].type << ' '
                    << operatorsSet[i].priority << ' '
                    << operatorsSet[i].associativity << ' '  << std :: endl;
    }
*/
}

Operators :: ~Operators(){
    clear();
}

void Operators :: clear(){
    delete operatorsSet;
}

size_t Operators :: getCount() const{
    return operatorsCount;
}

const OperatorConf Operators::getOperator(char op) const{
    if( !isOperator(op) ){
        ///exception
    }

    //check all operators for coincidence
    for(size_t i = 0; i < operatorsCount; ++i){
        if(op == operatorsSet[i].symbol ){
            return operatorsSet[i];
        }
    }
}

bool Operators :: isOperator(char op) const{
    bool exist = false;

    //check all operators for coincidence
    for(size_t i = 0; i < operatorsCount; ++i){
        if(op == operatorsSet[i].symbol ){
            exist = true;
            break;
        }
    }

    return exist;
}
