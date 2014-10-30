#pragma once
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <operatorConf.h>

class Operators
{
//prevent using copy constructor and operator=
    Operators(const Operators&);
    Operators & operator= (const Operators &);

    OperatorConf * operatorsSet;
    size_t operatorsCount;

    void readOperators();
    void clear();
public:
    Operators(const char * filePath);
    ~Operators();


    size_t getCount() const;
    const OperatorConf getOperator(char op) const;
    bool isOperator(char op) const;
};
