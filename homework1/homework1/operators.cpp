#include "operators.h"

operators :: operators(char * filePath)
{

    operatorsCount = 0;

    std :: ifstream operatorsFile(filePath, std :: ios :: in);
    std :: string buffer;

    while (operatorsFile.good()) {
        std :: getline(operatorsFile, buffer);
        ++operatorsCount;
    }

    operatorsFile.clear();
    operatorsFile.seekg(operatorsFile.beg);
    operatorsCount--;

    operatorsSet = new operatorConf[operatorsCount];

    for(size_t i = 0; i < operatorsCount; i++){
        operatorsFile >> operatorsSet[i].symbol;
        operatorsFile >> operatorsSet[i].type;
        operatorsFile >> operatorsSet[i].priority;
        operatorsFile >> operatorsSet[i].associativity;

        std :: cout << operatorsSet[i].symbol << ' '
                    << operatorsSet[i].type << ' '
                    << operatorsSet[i].priority << ' '
                    << operatorsSet[i].associativity << ' '  << std :: endl;
    }

    operatorsFile.close();
}

operators :: ~operators(){
    clear();
}

void operators :: clear(){
    delete operatorsSet;
}
