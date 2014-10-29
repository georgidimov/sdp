#pragma once
#include <iostream>
#include <fstream>
#include <operatorConf.h>

class operators
{
    operatorConf * operatorsSet;
    size_t operatorsCount;

    void readOperators();
    void clear();
public:
    operators(const char * filePath);
    ~operators();


    size_t getCount() const;
    operatorConf getOperator(char op) const;
    bool isOperator(char op) const;
};
