#include "operators.h"

operators :: operators(const char *filePath)
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
    operatorsCount--;

    operatorsSet = new operatorConf[operatorsCount];

    //read all operators
    for(size_t i = 0; i < operatorsCount; i++){
        operatorsFile >> operatorsSet[i].symbol;
        operatorsFile >> operatorsSet[i].type;
        operatorsFile >> operatorsSet[i].priority;
        operatorsFile >> operatorsSet[i].associativity;


/*        std :: cout << operatorsSet[i].symbol << ' '
                    << operatorsSet[i].type << ' '
                    << operatorsSet[i].priority << ' '
                    << operatorsSet[i].associativity << ' '  << std :: endl;
*/
        }


    operatorsFile.close();
}

operators :: ~operators(){
    clear();
}

void operators :: clear(){
    delete operatorsSet;
}

size_t operators :: getCount() const{
    return operatorsCount;
}

operatorConf operators :: getOperator(char op) const{
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

bool operators :: isOperator(char op) const{
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
